//
//  AIOverlayRouteView.h
//  AIMapViewWrapper
//
//  Created by CocoaToucher on 12/23/12.
//  Copyright (c) 2012 CocoaToucher. All rights reserved.
//

#import <MapKit/MapKit.h>

@class AIRoute;
@protocol AIOverlayRouteViewDelegate;

/**
 Custom overlay path view for showing an animated vehicle on a path on MKMapView
 */
@interface AIOverlayRouteView : MKOverlayPathView

/**
 AIOverlayRouteView needs to be initialized with an AIRoute overlay
 and an image for the vehicle that will be animated on that route
 */
- (id)initWithRoute:(AIRoute *)route
	   vehicleImage:(UIImage *)inImage;

@property(nonatomic, assign, readwrite) id<AIOverlayRouteViewDelegate> delegate;

/**
 Check if this property is YES before calling startAnimationWithTotalTravelTime:remainingTravelTime:
 */
@property(nonatomic, readonly) BOOL isReadyForAnimation;

/**
 Returns whether the vehicle view has an active position animation
 */
@property(nonatomic, readonly) BOOL isAnimating;

/**
 Velocity value calculated with total and remaining travel times provided with
 startAnimationWithTotalTravelTime:remainingTravelTime: method
 */
@property(nonatomic, readonly) double velocity;

/**
 Current coordinate of the vehicle view on its route overlay
 Do not rely on this value if the overlay view is not yet drawn, you can check if isReadyForAnimation is YES
 */
@property(nonatomic, readonly) CLLocationCoordinate2D currentVehicleCoordinate;

/**
 Call this method in map view's mapView:regionDidChangeAnimated: method to layout vehicle subview according to appropriate zoomScale of mapView
 @param zoomScale, current zoomScale of MKMapView, see AIMapViewWrapper class
 */
- (void)layoutWithZoomScale:(MKZoomScale)zoomScale;

/**
 Start the position animation for vehicle view on the route overlay's path
 If isAnimating is YES, or isReadyForAnimation is NO this method does not start an animation
 remainingTime should be smaller than or equal to totalTime, otherwise no effect of method
 Animation starts from the appropriate section of the total path according to given remainingTime
 @param totalTime, total travel time for the vehicle on its path
 @param remainingTime, remaining travel time for the vehicle on its path
 */
- (void)startAnimationWithTotalTravelTime:(CFTimeInterval)totalTime
					  remainingTravelTime:(CFTimeInterval)remainingTime;

/**
 Stops the position animation of vehicle view on the route overlay's path
 isAnimating is set to NO after a call to this method
 */
- (void)stopAnimation;

@end

@protocol AIOverlayRouteViewDelegate <NSObject>

/**
 AIOverlayRouteView tells the delegate that it is ready for animation after it is partially or completely drawn on the map
 Overlay route view's isReadyForAnimation property is set to YES prior to calling this delegate method
 This delegate method is called once in the overlay view's lifetime
 */
- (void)overlayRouteViewIsReadyForAnimation:(AIOverlayRouteView *)routeView;

@end
