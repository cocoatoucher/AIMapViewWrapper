//
//  AIMapViewWrapper.m
//  AIMapViewWrapper
//
//  Created by CocoaToucher on 12/19/12.
//  Copyright (c) 2012 CocoaToucher. All rights reserved.
//

#import "AIMapViewWrapper.h"
#import <MapKit/MapKit.h>
#import "AIOverlayRouteView.h"
#import "AIRoute.h"

NSString *AIStringFromMKMapRect(MKMapRect rect) {
	return [NSString stringWithFormat:@"{{%f, %f}, {%f, %f}}", rect.origin.x, rect.origin.y, rect.size.width, rect.size.height];
};

NSString *AIStringFromCLLocationCoordinate2D(CLLocationCoordinate2D coordinate) {
	return [NSString stringWithFormat:@"{%f, %f}", coordinate.latitude, coordinate.longitude];
}

@interface AIMapViewWrapper ()

@property(nonatomic) MKMapRect maxWorldRect;
@property(nonatomic) NSUInteger minZoomLevel;
@property(nonatomic, assign) NSTimer *routeTrackTimer;
@property(nonatomic) CGRect mapFrame;

- (void)updateMaxWorldRect;

@end

@implementation AIMapViewWrapper

- (id)initWithMapView:(MKMapView *)mapView {
	self = [super init];
	if (self) {
#if !(__has_feature(objc_arc))
		_mapView = [mapView retain];
#else
		_mapView = mapView;
#endif
		
		[_mapView addObserver:self
				   forKeyPath:@"frame"
					  options:NSKeyValueObservingOptionNew
					  context:nil];
		
		_mapFrame = _mapView.frame;
		[self updateMaxWorldRect];
	}
	return self;
}

- (void)dealloc {
	[_mapView removeObserver:self
				  forKeyPath:@"frame"];
#if !(__has_feature(objc_arc))
	[_mapView release];
	_mapView = nil;
	[_trackedRoute release];
	_trackedRoute = nil;
	
	[super dealloc];
#endif
}

- (void)observeValueForKeyPath:(NSString *)keyPath ofObject:(id)object change:(NSDictionary *)change context:(void *)context {
	
	if (!CGSizeEqualToSize(self.mapView.frame.size, self.mapFrame.size)) {
		self.mapFrame = self.mapView.frame;
		[self updateMaxWorldRect];
	}
}

- (void)updateMaxWorldRect {
	double minZoomLevel = 1;
	while ((256 * pow(2, minZoomLevel)) < self.mapView.bounds.size.width * 2.0) {
		minZoomLevel += 1;
	}
	
	MKMapRect maxWorldRect = MKMapRectNull;
	maxWorldRect.origin.x = 0.0;
	maxWorldRect.origin.y = 0.0;
	maxWorldRect.size.width = (self.mapView.bounds.size.width * MKMapSizeWorld.width / (256.0 * pow(2, minZoomLevel)));
	maxWorldRect.size.height = maxWorldRect.size.width * (self.mapView.bounds.size.height / self.mapView.bounds.size.width);
	self.maxWorldRect = maxWorldRect;
	
	if (minZoomLevel != self.minZoomLevel) {
		self.minZoomLevel = minZoomLevel;
		[self.delegate mapViewWrapperMinimumZoomLevelChanged:self];
	} else {
		self.minZoomLevel = minZoomLevel;
	}
}

- (MKMapRect)mapRectForCoordinateRegion:(MKCoordinateRegion)region {
	MKMapRect result = MKMapRectNull;
	
	CLLocationCoordinate2D topLeftCoord = CLLocationCoordinate2DMake(-1.0 * (region.center.latitude - region.span.latitudeDelta / 2.0), region.center.longitude - region.span.longitudeDelta / 2.0);
	CLLocationCoordinate2D bottomRightCoord = CLLocationCoordinate2DMake(-1.0 * (region.center.latitude + region.span.latitudeDelta / 2.0), region.center.longitude + region.span.longitudeDelta / 2.0);
	MKMapPoint topLeftPoint = MKMapPointForCoordinate(topLeftCoord);
	MKMapPoint bottomRightPoint = MKMapPointForCoordinate(bottomRightCoord);
	
	result.origin.x = topLeftPoint.x;
	result.origin.y = topLeftPoint.y;
	result.size.width = bottomRightPoint.x - topLeftPoint.x;
	result.size.height = bottomRightPoint.y - topLeftPoint.y;
	
	return result;
}

- (MKMapRect)mapRectWithZoomLevel:(NSUInteger)zoomLevel
				 centerCoordinate:(CLLocationCoordinate2D)inCenter {
	double zoomScale = 1 / pow(2, zoomLevel);
	
	double scaledWidth = self.maxWorldRect.size.width * zoomScale;
	double scaledHeight = self.maxWorldRect.size.height * zoomScale;
	
	//arrange center
	MKMapPoint centerPoint = MKMapPointForCoordinate(inCenter);
	
	double scaledOriginX = centerPoint.x - (scaledWidth / 2.0);
	double scaledOriginY = centerPoint.y - (scaledHeight / 2.0);
	
	return MKMapRectMake(scaledOriginX, scaledOriginY, scaledWidth, scaledHeight);
}

#pragma mark -
#pragma mark Public methods

- (NSUInteger)zoomLevel {
	MKMapRect visibleRect = self.mapView.visibleMapRect;
	
	double zoomScale = visibleRect.size.width / self.maxWorldRect.size.width;
	zoomScale = MIN(zoomScale, 1.0);
	
	NSUInteger result = round(log10(1 / zoomScale) / log10(2));
	
	return result + self.minZoomLevel;
}

- (void)setZoomLevel:(NSUInteger)zoomLevel {
	[self setZoomLevel:zoomLevel
			  animated:NO];
}

- (void)setZoomLevel:(NSUInteger)zoomLevel
			animated:(BOOL)animated
{
	[self setZoomLevel:zoomLevel
  withCenterCoordinate:self.mapView.centerCoordinate
			  animated:animated];
}

- (void)setZoomLevel:(NSUInteger)zoomLevel
withCenterCoordinate:(CLLocationCoordinate2D)inCenter
			animated:(BOOL)animated {
	NSInteger converted = zoomLevel - self.minZoomLevel;
	zoomLevel = MAX(converted, 0);
	zoomLevel = MIN(zoomLevel, 19 - self.minZoomLevel);
	
	MKMapRect newRect = [self mapRectWithZoomLevel:zoomLevel
								  centerCoordinate:inCenter];
	
	[self.mapView setVisibleMapRect:newRect animated:animated];
}

- (MKZoomScale)zoomScale {
	@synchronized ([self class]) {
		CGFloat minZoomLevel = log10f((self.mapView.bounds.size.width * 2.0) / 256) / log10f(2);
		
		MKMapRect visibleRect = self.mapView.visibleMapRect;
		
		CGFloat zoomScale = visibleRect.size.width / (MKMapSizeWorld.width / 2.0f);
		
		CGFloat result = log10f(1 / zoomScale) / log10f(2);
		
		return 1.0f / (powf(2.0f, 20.0f - (result + minZoomLevel)));
	}
}

- (MKMapRect)mapRectThatFitsAnnotations:(NSArray *)annotations {
	MKMapRect fitRect = MKMapRectNull;
	
	for (id <MKAnnotation> annotation in annotations) {
		
		UIView *annotationView = [self.mapView viewForAnnotation:annotation];
		
		MKCoordinateRegion viewRegion = [self.mapView convertRect:annotationView.frame toRegionFromView:self.mapView];
		
		MKMapRect annotationRect = [self mapRectForCoordinateRegion:viewRegion];
		
		if (MKMapRectIsNull(fitRect)) {
			fitRect = annotationRect;
		} else {
			fitRect = MKMapRectUnion(fitRect, annotationRect);
		}
	}
	
	return [self.mapView mapRectThatFits:fitRect];
}

- (void)zoomToFitMapAnnotations:(NSArray *)annotations
					   animated:(BOOL)animated {
	
    if (annotations.count == 0)
		return;
	
	if (annotations.count == 1) {
		id <MKAnnotation> annotation = [annotations objectAtIndex:0];
		
		[self setZoomLevel:14
	  withCenterCoordinate:annotation.coordinate
				  animated:YES];
		
		return;
	}
	
    MKMapRect zoomRect = MKMapRectNull;
	for (id <MKAnnotation> annotation in annotations) {
		
		UIView *annotationView = [self.mapView viewForAnnotation:annotation];
		
		//convert annotation coordinates to pixel point in map
		MKMapPoint annotationPoint = MKMapPointForCoordinate(annotation.coordinate);
		
		MKMapRect pointRect = MKMapRectMake(annotationPoint.x - floorf(annotationView.bounds.size.width / 2.0f), annotationPoint.y - (annotationView.bounds.size.height), annotationView.bounds.size.width, annotationView.bounds.size.height);
		if (MKMapRectIsNull(zoomRect)) {
			zoomRect = pointRect;
		} else {
			zoomRect = MKMapRectUnion(zoomRect, pointRect);
		}
	}
	
	[self.mapView setVisibleMapRect:zoomRect
						   animated:YES];
}


- (void)launchDirectionsFromCoordinate:(CLLocationCoordinate2D)fromCoor
						  toCoordinate:(CLLocationCoordinate2D)toCoor {
	NSString *mapsDomain = @"maps.apple.com";
	if ([[[UIDevice currentDevice] systemVersion] doubleValue] < 6.0) {
		mapsDomain = @"maps.google.com";
	}
	
	NSString *urlStr = [[NSString stringWithFormat:@"http://%@/maps?saddr=%f,%f&daddr=%f,%f",
						 mapsDomain,
						 fromCoor.latitude,
						 fromCoor.longitude,
						 toCoor.latitude,
						 toCoor.longitude]
						stringByAddingPercentEscapesUsingEncoding:NSUTF8StringEncoding];
	
	NSURL *mapsURL = [NSURL URLWithString:urlStr];
	
	[[UIApplication sharedApplication] openURL:mapsURL];
}

#pragma mark -
#pragma mark Route tracking
- (void)cancelTrackingRoute {
	self.trackedRoute = nil;
}

- (void)setTrackedRoute:(AIRoute *)trackedRoute {
	if (trackedRoute != _trackedRoute) {
#if !(__has_feature(objc_arc))
		[_trackedRoute release];
		_trackedRoute = [trackedRoute retain];
#else
		_trackedRoute = trackedRoute;
#endif
	}
	
	[_routeTrackTimer invalidate];
	_routeTrackTimer = nil;
	self.mapView.userInteractionEnabled = YES;
	
	if (_trackedRoute) {
		self.mapView.userInteractionEnabled = NO;
		
		AIOverlayRouteView *routeView = (AIOverlayRouteView *)[self.mapView viewForOverlay:(id<MKOverlay>)_trackedRoute];
		
		[self setZoomLevel:13.0
	  withCenterCoordinate:[routeView currentVehicleCoordinate]
				  animated:NO];
		
		self.routeTrackTimer = [NSTimer timerWithTimeInterval:0.2
													   target:self
													 selector:@selector(onTrackRoute:)
													 userInfo:nil
													  repeats:YES];
		[[NSRunLoop currentRunLoop] addTimer:self.routeTrackTimer forMode:NSRunLoopCommonModes];
		[self onTrackRoute:self.routeTrackTimer];
	}
}

- (void)onTrackRoute:(NSTimer *)inTimer {
	AIOverlayRouteView *routeView = (AIOverlayRouteView *)[self.mapView viewForOverlay:(id<MKOverlay>)self.trackedRoute];
	CLLocationCoordinate2D currentCoordinate = [routeView currentVehicleCoordinate];
	
	[self.mapView setCenterCoordinate:currentCoordinate animated:YES];
	
	if (routeView.isAnimating == NO) {
		[_routeTrackTimer invalidate];
		_routeTrackTimer = nil;
		self.mapView.userInteractionEnabled = YES;
	}
}

@end
