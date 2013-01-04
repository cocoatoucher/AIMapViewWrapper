//
//  AIRoutePath.m
//  AIMapViewWrapper
//
//  Created by CocoaToucher on 12/24/12.
//  Copyright (c) 2012 CocoaToucher. All rights reserved.
//

#import "AIRoutePath.h"

double distanceBetweenPoints(CGPoint point1, CGPoint point2) {
	return sqrt(pow(point1.x - point2.x, 2) + pow(point1.y - point2.y, 2));
};

CGFloat angleBetweenPoints(CGPoint point1, CGPoint point2) {
	return atan2f(point2.y - point1.y, point2.x - point1.x);
};

static CGPathRef createShadowPathWithPath(CGPathRef path, CGFloat radians) {
	CGPoint originalEndPoint = CGPathGetCurrentPoint(path);
	
    CGRect bounds = CGPathGetBoundingBox(path);
    CGPoint center = CGPointMake(CGRectGetMidX(bounds), CGRectGetMidY(bounds));
    CGAffineTransform transform = CGAffineTransformIdentity;
	transform = CGAffineTransformTranslate(transform, center.x, center.y);
	transform = CGAffineTransformRotate(transform, radians);
	transform = CGAffineTransformTranslate(transform, -center.x, -center.y);
    
	CGPathRef rotatedPath = CGPathCreateCopyByTransformingPath(path, &transform);
	
	transform = CGAffineTransformMakeScale(1.0, 0.8);
	
	CGPathRef scaledPath = CGPathCreateCopyByTransformingPath(rotatedPath, &transform);
	CGPathRelease(rotatedPath);
	
	transform = CGAffineTransformIdentity;
	transform = CGAffineTransformTranslate(transform, center.x, center.y);
	transform = CGAffineTransformRotate(transform, -radians);
	transform = CGAffineTransformTranslate(transform, -center.x, -center.y);
	
	CGPathRef normalizedPath = CGPathCreateCopyByTransformingPath(scaledPath, &transform);
	CGPathRelease(scaledPath);
	
	CGPoint currentEndPoint = CGPathGetCurrentPoint(normalizedPath);
	
	transform = CGAffineTransformIdentity;
	transform = CGAffineTransformTranslate(transform, originalEndPoint.x - currentEndPoint.x, originalEndPoint.y - currentEndPoint.y);
	
	CGPathRef result = CGPathCreateCopyByTransformingPath(normalizedPath, &transform);
	CGPathRelease(normalizedPath);
	
	return result;
}

@interface AIRoutePath ()

@property(nonatomic, strong, readwrite) NSArray *knots;
@property(nonatomic, strong, readwrite) NSArray *firstCPs;
@property(nonatomic, strong, readwrite) NSArray *secondCPs;
@property(nonatomic, readwrite) CGPathRef path;
@property(nonatomic, readwrite) CGPathRef shadowPath;
@property(nonatomic, readwrite) CGFloat totalDistance;

@end

@implementation AIRoutePath

- (void)dealloc {
#if !(__has_feature(objc_arc))
	CGPathRelease(_path);
	_path = nil;
	CGPathRelease(_shadowPath);
	_shadowPath = nil;
	[_knots release];
	_knots = nil;
	[_firstCPs release];
	_firstCPs = nil;
	[_secondCPs release];
	_secondCPs = nil;
	[super dealloc];
#endif
}

- (id)initWithKnots:(NSArray *)inKnots {
	self = [super init];
	if (self) {
#if !(__has_feature(objc_arc))
		_knots = [inKnots retain];
#else
		_knots = inKnots;
#endif
		
		if (_knots.count > 1) {
			
			NSArray *controlPoints = [AIRoutePath curveControlPointsForKnots:_knots];
#if !(__has_feature(objc_arc))
			_firstCPs = [[controlPoints objectAtIndex:0] retain];
			_secondCPs = [[controlPoints objectAtIndex:1] retain];
#else
			_firstCPs = [controlPoints objectAtIndex:0];
			_secondCPs = [controlPoints objectAtIndex:1];
#endif
			
			CGMutablePathRef path = CGPathCreateMutable();
			CGPoint startPoint = [[_knots objectAtIndex:0] CGPointValue];
			CGPathMoveToPoint(path, nil, startPoint.x, startPoint.y);
			
			CGFloat totalDistance = 0.0f;
			
			CGPoint lastEndPoint = startPoint;
			for (int i = 0; i < [_firstCPs count]; i++) {
				CGPoint nextPoint = [[_knots objectAtIndex:i + 1] CGPointValue];
				
				CGPoint firstCP = [[_firstCPs objectAtIndex:i] CGPointValue];
				CGPoint secondCP = [[_secondCPs objectAtIndex:i] CGPointValue];
				
				CGFloat distance1 = distanceBetweenPoints(lastEndPoint, firstCP);
				CGFloat distance2 = distanceBetweenPoints(firstCP, secondCP);
				CGFloat distance3 = distanceBetweenPoints(secondCP, nextPoint);
				
				CGFloat circleDistance = distance1 + distance2 + distance3;
				totalDistance += circleDistance;
				
				if (distance1 / circleDistance < 0.2 ||
					distance2 / circleDistance < 0.2 ||
					distance3 / circleDistance < 0.2) {
					
					CGPathAddLineToPoint(path, nil, nextPoint.x, nextPoint.y);
					
					lastEndPoint = nextPoint;
					
					continue;
				}
				
				CGPathAddCurveToPoint(path, nil, firstCP.x, firstCP.y, secondCP.x, secondCP.y, nextPoint.x, nextPoint.y);
				
				lastEndPoint = nextPoint;
			}
			
			_totalDistance = totalDistance;
			
			_path = path;
			
			_shadowPath = createShadowPathWithPath(path, -angleBetweenPoints(lastEndPoint, startPoint));
		}
	}
	return self;
}

- (CGPathRef)newTailWithDistance:(CGFloat)inDistance {
	CGMutablePathRef path = CGPathCreateMutable();
	
	CGFloat consumedDistance = self.totalDistance - inDistance;
	
	CGFloat currentDistance = 0.0f;
	
	BOOL pathStarted = NO;
	
	CGPoint startPoint = [[self.knots objectAtIndex:0] CGPointValue];
	CGPoint lastEndPoint = startPoint;
	
	for (int i = 0; i < [self.firstCPs count]; i++) {
		CGPoint firstCP = [[self.firstCPs objectAtIndex:i] CGPointValue];
		CGPoint secondCP = [[self.secondCPs objectAtIndex:i] CGPointValue];
		
		CGPoint nextPoint = [[self.knots objectAtIndex:i + 1] CGPointValue];
		
		if (!pathStarted && currentDistance >= consumedDistance) {
			pathStarted = YES;
			CGPathMoveToPoint(path, nil, lastEndPoint.x, lastEndPoint.y);
		}
		
		CGFloat distance1 = distanceBetweenPoints(lastEndPoint, firstCP);
		CGFloat distance2 = distanceBetweenPoints(firstCP, secondCP);
		CGFloat distance3 = distanceBetweenPoints(secondCP, nextPoint);
		CGFloat circleDistance = distance1 + distance2 + distance3;
		
		if (pathStarted) {
			
			if (distance1 / circleDistance < 0.2 ||
				distance2 / circleDistance < 0.2 ||
				distance3 / circleDistance < 0.2) {
				
				CGPathAddLineToPoint(path, nil, nextPoint.x, nextPoint.y);
			} else {
				CGPathAddCurveToPoint(path, nil, firstCP.x, firstCP.y, secondCP.x, secondCP.y, nextPoint.x, nextPoint.y);
			}
		}
		
		currentDistance += circleDistance;
		
		lastEndPoint = nextPoint;
	}
	
	return path;
}

//Original implementation of this method is from:
//http://www.codeproject.com/Articles/31859/Draw-a-Smooth-Curve-through-a-Set-of-2D-Points-wit
+ (NSArray *)curveControlPointsForKnots:(NSArray *)knots {
	NSMutableArray *firstControlPoints = [NSMutableArray array];
	NSMutableArray *secondControlPoints = [NSMutableArray array];
	NSArray *result = [NSArray arrayWithObjects:firstControlPoints, secondControlPoints, nil];
	
	int n = knots.count - 1;
	if (n < 1)
		return nil;
	
	if (n == 1)
	{ // Special case: Bezier curve should be a straight line.
		
		// 3P1 = 2P0 + P3
		CGPoint firstPoint = [[knots objectAtIndex:0] CGPointValue];
		CGPoint secondPoint = [[knots objectAtIndex:1] CGPointValue];
		
		CGFloat firstX = (2 * firstPoint.x + secondPoint.x) / 3;
		CGFloat firstY = (2 * firstPoint.y + secondPoint.y) / 3;
		
		CGPoint firstControlPoint = CGPointMake(firstX, firstY);
		[firstControlPoints addObject:[NSValue valueWithCGPoint:firstControlPoint]];
		
		// P2 = 2P1 – P0
		CGFloat secondX = 2 * firstControlPoint.x - firstPoint.x;
		CGFloat secondY = 2 * firstControlPoint.y - firstPoint.y;
		CGPoint secondControlPoint = CGPointMake(secondX, secondY);
		[secondControlPoints addObject:[NSValue valueWithCGPoint:secondControlPoint]];
		
		return result;
	}
	
	// Calculate first Bezier control points
	// Right hand side vector
	double *rhs = (double *)malloc(n * sizeof(double));
	
	// Set right hand side X values
	for (int i = 1; i < n - 1; ++i) {
		CGPoint currentPoint = [[knots objectAtIndex:i] CGPointValue];
		CGPoint nextPoint = [[knots objectAtIndex:i + 1] CGPointValue];
		rhs[i] = 4 * currentPoint.x + 2 * nextPoint.x;
	}
	
	CGPoint firstPoint = [[knots objectAtIndex:0] CGPointValue];
	CGPoint secondPoint = [[knots objectAtIndex:1] CGPointValue];
	
	rhs[0] = firstPoint.x + 2 * secondPoint.x;
	rhs[n - 1] = (8 * [[knots objectAtIndex:n - 1] CGPointValue].x + [[knots objectAtIndex:n] CGPointValue].x) / 2.0;
	
	// Get first control points X-values
	double *x = [self firstControlPoints:rhs length:n];
	
	// Set right hand side Y values
	for (int i = 1; i < n - 1; ++i) {
		CGPoint currentPoint = [[knots objectAtIndex:i] CGPointValue];
		CGPoint nextPoint = [[knots objectAtIndex:i + 1] CGPointValue];
		rhs[i] = 4 * currentPoint.y + 2 * nextPoint.y;
	}
	
	rhs[0] = firstPoint.y + 2 * secondPoint.y;
	rhs[n - 1] = (8 * [[knots objectAtIndex:n - 1] CGPointValue].y + [[knots objectAtIndex:n] CGPointValue].y) / 2.0;
	// Get first control points Y-values
	double *y = [self firstControlPoints:rhs length:n];
	free(rhs);
	
	// Fill output arrays.
	for (int i = 0; i < n; ++i)
	{
		// First control point
		CGPoint newPoint = CGPointMake(x[i], y[i]);
		[firstControlPoints addObject:[NSValue valueWithCGPoint:newPoint]];
		
		// Second control point
		if (i < n - 1) {
			CGPoint nextPoint = [[knots objectAtIndex:i + 1] CGPointValue];
			newPoint = CGPointMake(2 * nextPoint.x - x[i + 1], 2 * nextPoint.y - y[i + 1]);
			[secondControlPoints addObject:[NSValue valueWithCGPoint:newPoint]];
		} else {
			CGPoint lastPoint = [[knots objectAtIndex:n] CGPointValue];
			newPoint = CGPointMake((lastPoint.x + x[n - 1]) / 2, (lastPoint.y + y[n - 1]) / 2);
			[secondControlPoints addObject:[NSValue valueWithCGPoint:newPoint]];
		}
	}
	
	free(x);
	free(y);
	
	return result;
}

//Original implementation of this method is from:
//http://www.codeproject.com/Articles/31859/Draw-a-Smooth-Curve-through-a-Set-of-2D-Points-wit
+ (double *)firstControlPoints:(double *)rhs length:(int)n {
	double *x = (double *)malloc(n * sizeof(double)); // Solution vector.
	double *tmp = (double *)malloc(n * sizeof(double)); // Temp workspace.
	
	double b = 2.0;
	x[0] = rhs[0] / b;
	for (int i = 1; i < n; i++) // Decomposition and forward substitution.
	{
		tmp[i] = 1 / b;
		b = (i < n - 1 ? 4.0 : 3.5) - tmp[i];
		x[i] = (rhs[i] - x[i - 1]) / b;
	}
	for (int i = 1; i < n; i++)
		x[n - i - 1] -= tmp[n - i] * x[n - i]; // Backsubstitution.
	
	free(tmp);
	
	return x;
}

@end
