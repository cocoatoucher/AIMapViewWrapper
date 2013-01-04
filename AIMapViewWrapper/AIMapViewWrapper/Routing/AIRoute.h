//
//  AIRoute.h
//  AIMapViewWrapper
//
//  Created by CocoaToucher on 12/24/12.
//  Copyright (c) 2012 CocoaToucher. All rights reserved.
//

#import <MapKit/MapKit.h>

@interface AIRoute : NSObject < MKOverlay >

/**
 inCoordinates array should include at least more than 1 CLLocation object
 @param array of CLLocation objects
 @returns the route overlay
 */
+ (AIRoute *)routeWithCoordinates:(NSArray *)inCoordinates;

/**
 Always returns the coordinate for the center point of boundingMapRect
 */
@property(nonatomic, readonly) CLLocationCoordinate2D coordinate;

/**
 Calculated with coordinates array provided in initialization method
 */
@property(nonatomic, readonly) MKMapRect boundingMapRect;

/**
 Array of CLLocation objects given in class constructor method
 */
@property(nonatomic, strong, readonly) NSArray *coordinates;

@end
