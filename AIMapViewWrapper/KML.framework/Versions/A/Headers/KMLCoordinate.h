//
//  KMLCoordinate.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLElement.h"

/** Coordinate type. 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLCoordinate : KMLElement


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Latitude */
@property (nonatomic, assign) CGFloat latitude;

/** Longitude */
@property (nonatomic, assign) CGFloat longitude;

/** Altitude */
@property (nonatomic, assign) CGFloat altitude;


/// ---------------------------------
/// @name Initialize Element
/// ---------------------------------

/** Returns the new receiver of KMLCoordinate.
 @param text Four or more tuples, each consisting of floating point values for longitude, latitude, and altitude.Do not include spaces within a tuple.
 @return KMLCoordinate.
 */
- (id)initWithText:(NSString *)text;

@end
