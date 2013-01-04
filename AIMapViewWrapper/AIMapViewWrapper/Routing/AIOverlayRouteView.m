//
//  AIOverlayRouteView.m
//  AIMapViewWrapper
//
//  Created by CocoaToucher on 12/23/12.
//  Copyright (c) 2012 CocoaToucher. All rights reserved.
//

#import "AIOverlayRouteView.h"
#import "AIRoute.h"
#import "AIRoutePath.h"
#import <QuartzCore/QuartzCore.h>


@interface AIOverlayRouteView ()

@property(nonatomic, strong) UIImageView *vehicleView;
@property(nonatomic, strong) AIRoutePath *routePath;
@property(nonatomic, readwrite) BOOL isReadyForAnimation;
@property(nonatomic, readwrite) BOOL isAnimating;
@property(nonatomic, readwrite) CFTimeInterval totalTravelTime;
@property(nonatomic, readwrite) CFTimeInterval remainingTravelTime;
@property(nonatomic) BOOL vehicleScaleInitialized;
@property(nonatomic) MKZoomScale lastZoomScale;

- (void)startAnimationWithTotalTravelTime:(CFTimeInterval)totalTime
					  remainingTravelTime:(CFTimeInterval)inRemainingTime;

@end

@implementation AIOverlayRouteView

- (id)initWithRoute:(AIRoute *)route
	   vehicleImage:(UIImage *)inImage {
	self = [super initWithOverlay:route];
	if (self) {
		_vehicleView = [[UIImageView alloc] initWithFrame:CGRectMake(0.0f, 0.0f, inImage.size.width, inImage.size.height)];
		_vehicleView.image = inImage;
		_vehicleView.alpha = 0.0f;
		[self addSubview:_vehicleView];
	}
	return self;
}

- (void)createPath {
	AIRoute *route = (AIRoute *)self.overlay;
	
	NSMutableArray *knots = [NSMutableArray arrayWithCapacity:route.coordinates.count];
	for (int i = 0; i < route.coordinates.count; i++) {
		CLLocation *currentLocation = [route.coordinates objectAtIndex:i];
		[knots addObject:[NSValue valueWithCGPoint:[self pointForMapPoint:MKMapPointForCoordinate(currentLocation.coordinate)]]];
	}
	
	AIRoutePath *tPath = [[AIRoutePath alloc] initWithKnots:knots];
	self.routePath = tPath;
#if !(__has_feature(objc_arc))
	[tPath release];
#endif
	
	self.path = self.routePath.path;
	
	BOOL oldValue = _isReadyForAnimation;
	self.isReadyForAnimation = YES;
	if (oldValue != _isReadyForAnimation) {
		[self.delegate overlayRouteViewIsReadyForAnimation:self];
		
		CLLocation *startLocation = [route.coordinates objectAtIndex:0];
		
		_vehicleView.layer.position = [self pointForMapPoint:MKMapPointForCoordinate(startLocation.coordinate)];
	}
}

- (BOOL)canDrawMapRect:(MKMapRect)mapRect
             zoomScale:(MKZoomScale)zoomScale {
	return YES;
}

- (void)drawMapRect:(MKMapRect)mapRect zoomScale:(MKZoomScale)zoomScale inContext:(CGContextRef)context {
	
	CGContextBeginPath(context);
	
	CGContextAddPath(context, self.routePath.shadowPath);
	CGContextSetStrokeColorWithColor(context, [[[UIColor blackColor] colorWithAlphaComponent:0.2f] CGColor]);
	CGContextSetLineWidth(context, self.lineWidth / zoomScale);
	CGContextSetLineCap(context, self.lineCap);
	CGContextStrokePath(context);
	
	[super drawMapRect:mapRect zoomScale:zoomScale inContext:context];
}

- (void)layoutWithZoomScale:(MKZoomScale)zoomScale {
	if (zoomScale == self.lastZoomScale) {
		self.lastZoomScale = zoomScale;
		return;
	}
	
	if (!self.vehicleScaleInitialized) {
		self.vehicleView.layer.transform = CATransform3DMakeScale(1.0f / zoomScale, 1.0f / zoomScale, 1.0f);
		self.vehicleScaleInitialized = YES;
		self.vehicleView.alpha = 1.0f;
		return;
	}
	
	CALayer *presentationLayer = (CALayer *)self.vehicleView.layer.presentationLayer;
	CATransform3D t = presentationLayer.transform;
	
	CABasicAnimation *scaleXAnimation = [CABasicAnimation animationWithKeyPath:@"transform.scale.x"];
	scaleXAnimation.fromValue = [NSNumber numberWithFloat:sqrtf((t.m11 * t.m11) + (t.m12 * t.m12) + (t.m13 * t.m13))];
	scaleXAnimation.toValue = [NSNumber numberWithFloat:1.0 / zoomScale];
	
	CABasicAnimation *scaleYAnimation = [CABasicAnimation animationWithKeyPath:@"transform.scale.y"];
	scaleYAnimation.fromValue = [NSNumber numberWithFloat:sqrtf((t.m21 * t.m21) + (t.m22 * t.m22) + (t.m23 * t.m23))];
	scaleYAnimation.toValue = [NSNumber numberWithFloat:1.0 / zoomScale];
	
	CAAnimationGroup *animationGroup = [CAAnimationGroup animation];
	animationGroup.duration = 0.1;
	animationGroup.timingFunction = [CAMediaTimingFunction functionWithName:kCAMediaTimingFunctionEaseIn];
	animationGroup.animations = [NSArray arrayWithObjects:scaleXAnimation, scaleYAnimation, nil];
	animationGroup.removedOnCompletion = NO;
	animationGroup.fillMode = kCAFillModeForwards;
	
	[self.vehicleView.layer addAnimation:animationGroup forKey:@"scale"];
}

- (double)velocity {
	return self.routePath.totalDistance / self.totalTravelTime;
}

- (void)dealloc {
#if !(__has_feature(objc_arc))
	[_vehicleView release];
	_vehicleView = nil;
	[_routePath release];
	_routePath = nil;
	
	[super dealloc];
#endif
}

- (CAKeyframeAnimation *)pathAnimationForPath:(CGPathRef)animationPath
									 duration:(CFTimeInterval)inDuration
{
	CAKeyframeAnimation *pathAnimation;
	pathAnimation = [CAKeyframeAnimation animationWithKeyPath:@"position"];
	pathAnimation.removedOnCompletion = NO;
	pathAnimation.fillMode = kCAFillModeForwards;
	pathAnimation.calculationMode = kCAAnimationPaced;
	pathAnimation.path = animationPath;
	pathAnimation.rotationMode = kCAAnimationRotateAuto;
	pathAnimation.delegate = self;
	
	pathAnimation.duration = inDuration;
	
	return pathAnimation;
}

- (void)animationDidStop:(CAAnimation *)theAnimation finished:(BOOL)flag {
	
	@synchronized ([self class]) {
		CAAnimation *pathAnimation = [self.vehicleView.layer animationForKey:@"pathAnimation"];
		
		if (flag == YES &&
			[pathAnimation isEqual:theAnimation]) {
			self.isAnimating = NO;
		}
	}
}

- (void)startAnimationWithTotalTravelTime:(CFTimeInterval)totalTime
					  remainingTravelTime:(CFTimeInterval)remainingTime {
	@synchronized ([self class]) {
		if (self.isReadyForAnimation == NO) {
			return;
		}
		
		if (self.isAnimating == YES) {
			return;
		}
		
		CGFloat remainingDistance = (self.routePath.totalDistance * remainingTime) / totalTime;
		
		if (remainingDistance <= 0.0f)
			return;
		
		CGPathRef subPath = [self.routePath newTailWithDistance:remainingDistance];
		
		self.isAnimating = YES;
		
		[self.vehicleView.layer addAnimation:[self pathAnimationForPath:subPath
															   duration:remainingTime]
									  forKey:@"pathAnimation"];
		CGPathRelease(subPath);
	}
}

- (void)stopAnimation {
	@synchronized ([self class]) {
		[self.vehicleView.layer removeAnimationForKey:@"pathAnimation"];
		self.isAnimating = NO;
	}
}

- (CLLocationCoordinate2D)currentVehicleCoordinate {
	@synchronized ([self class]) {
		
		CALayer *presentationLayer = (CALayer *)self.vehicleView.layer.presentationLayer;
		CGPoint currentPoint = presentationLayer.position;
		
		return MKCoordinateForMapPoint([self mapPointForPoint:currentPoint]);
	}
}

@end
