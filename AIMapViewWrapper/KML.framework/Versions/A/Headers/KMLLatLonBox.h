//
//  KMLLatLonBox.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractObject.h"

/** Specifies where the top, bottom, right, and left sides of a bounding box for the ground overlay are aligned. 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLLatLonBox : KMLAbstractObject


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Specifies the latitude of the north edge of the bounding box, in decimal degrees from 0 to ±90. */
@property (nonatomic, assign) CGFloat north;

/** Specifies the latitude of the south edge of the bounding box, in decimal degrees from 0 to ±90. */
@property (nonatomic, assign) CGFloat south;

/** Specifies the longitude of the east edge of the bounding box, in decimal degrees from 0 to ±180. 
 
 (For overlays that overlap the meridian of 180° longitude, values can extend beyond that range.) */
@property (nonatomic, assign) CGFloat east;

/** Specifies the longitude of the west edge of the bounding box, in decimal degrees from 0 to ±180. 
 (For overlays that overlap the meridian of 180° longitude, values can extend beyond that range.) */
@property (nonatomic, assign) CGFloat west;

/** Specifies a rotation of the overlay about its center, in degrees. 
 
 Values can be ±180. The default is 0 (north). 
 Rotations are specified in a counterclockwise direction. */
@property (nonatomic, assign) CGFloat rotation;

@end
