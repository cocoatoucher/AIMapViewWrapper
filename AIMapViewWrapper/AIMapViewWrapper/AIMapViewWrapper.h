//
//  AIMapViewWrapper.h
//  AIMapViewWrapper
//
//  Created by CocoaToucher on 12/19/12.
//  Copyright (c) 2012 CocoaToucher. All rights reserved.
//

#import <MapKit/MapKit.h>

@class AIRoute;
@protocol AIMapViewWrapperDelegate;

extern NSString *AIStringFromMKMapRect(MKMapRect rect);
extern NSString *AIStringFromCLLocationCoordinate2D(CLLocationCoordinate2D coordinate);

/**
 AIMapViewWrapper provides handy functions for MKMapView
 like getting and setting a Google maps zoom 
 getting MKZoomScale from the map view
 */
@interface AIMapViewWrapper : NSObject

/**
 @param map view to be wrapped
 */
- (id)initWithMapView:(MKMapView *)mapView;

/**
 Wrapped map view
 */
@property(nonatomic, strong, readonly) MKMapView *mapView;

@property(nonatomic, assign) id<AIMapViewWrapperDelegate> delegate;

/**
 Google maps zoom level for the map
 Apple uses a range between a minZoomLevel(see below) and 19
 Zoom level values less than minZoomLevel or bigger than 19 are clamped to these values
 Center coordinate of the map doesn't change after zoom level changes
 */
@property(nonatomic) NSUInteger zoomLevel;

/**
 Sets Google maps zoom level of the map view with animation
 Center coordinate of the map doesn't change after zoom level changes
 @param zoom level
 @param animated: YES if the zoom level should be set animated; otherwise, NO.
 */
- (void)setZoomLevel:(NSUInteger)zoomLevel
			animated:(BOOL)animated;

/**
 Sets Google maps zoom level of the map view with a center coordinate and animation
 @param zoomLevel, desired zoom level
 @param inCenter, center coordinate
 @param animated, YES if the zoom level should be set animated; otherwise, NO.
 */
- (void)setZoomLevel:(NSUInteger)zoomLevel
withCenterCoordinate:(CLLocationCoordinate2D)inCenter
			animated:(BOOL)animated;

/**
 Minimum zoom level value that can be set on map view
 Value of this property changes according to the frame size of the map view
 */
@property(nonatomic, readonly) NSUInteger minZoomLevel;

/**
 Zoom scale of the map view that Apple sends as a parameter to drawMapRect:zoomScale:inContext:
 and similar methods of its MKOverlayViews
 You can use this to layout subviews of your MKOverlayView subclasses
 */
@property(nonatomic, readonly) MKZoomScale zoomScale;

/**
 By setting this property you can track the vehicle on the route of an AIOverlayRouteView
 If trackedRoute's overlay route view's isAnimating property is NO, this method does nothing
 After trackedRoute is set, a timer with 0.2 sec fixed interval is started to set map view's center coordinate while the vehicle's position is changing
 Set to nil or call cancelTracking below to stop tracking
 You should make mapViewWrapper stop tracking the route before its owner is deallocated
 Map view's user interaction is disabled after a trackedRoute is set, and enabled again once the tracked route is set to nil
 */
@property(nonatomic, strong) AIRoute *trackedRoute;

/**
 Invalidates the route track timer instance and stops updating map view center coordinate
 by setting the trackedRoute property to nil
 */
- (void)cancelTrackingRoute;

/**
 Use this method to get the MKMapRect that includes all the given annotations' map rectangles
 Then you can use MKMapView's setVisibleMapRect: method to make all these annotations visible on the screen
 @param annotations, array of id<MKAnnotation> objects
 */
- (MKMapRect)mapRectThatFitsAnnotations:(NSArray *)annotations;

/**
 If there is only single annotation in the parameter this method zooms map view to level:14 with the single annotation's center coordinate
 For multiple annotations it uses mapRectThatFitsAnnotations: method and set's map view's visibleMapRect to the returning value
 @param annotations, array of id<MKAnnotation> objects
 */
- (void)zoomToFitMapAnnotations:(NSArray *)annotations
					   animated:(BOOL)animated;

/**
 This method makes the UIApplication open either Apple maps URL or Google maps URL for directions between two coordinates depending on the iOS version
 @param fromCoor, source coordinate
 @param toCoor, destination coordinate
 */
- (void)launchDirectionsFromCoordinate:(CLLocationCoordinate2D)fromCoor
						  toCoordinate:(CLLocationCoordinate2D)toCoor;

/**
 This does the reverse job of MKCoordinateRegionForMapRect() method from MKGeometry
 @param region to be converted to MKMapRect
 */
- (MKMapRect)mapRectForCoordinateRegion:(MKCoordinateRegion)region;

@end

@protocol AIMapViewWrapperDelegate <NSObject>

@optional
/**
 When map view's frame size changes either via autoresizing or setFrame:, minZoomLevel value changes
 Use this delegate method to be informed of this change
 */
- (void)mapViewWrapperMinimumZoomLevelChanged:(AIMapViewWrapper *)wrapper;

@end
