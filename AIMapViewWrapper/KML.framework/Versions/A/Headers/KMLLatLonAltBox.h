//
//  KMLLatLonAltBox.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractObject.h"

/** A bounding box that describes an area of interest defined by geographic coordinates and altitudes. 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLLatLonAltBox : KMLAbstractObject


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Specifies the latitude of the north edge of the bounding box, in decimal degrees from 0 to ±90. */
@property (nonatomic, assign) CGFloat north;

/** Specifies the latitude of the south edge of the bounding box, in decimal degrees from 0 to ±90. */
@property (nonatomic, assign) CGFloat south;

/** Specifies the longitude of the east edge of the bounding box, in decimal degrees from 0 to ±180. */
@property (nonatomic, assign) CGFloat east;

/** Specifies the longitude of the west edge of the bounding box, in decimal degrees from 0 to ±180. */
@property (nonatomic, assign) CGFloat west;

/** Specified in meters (and is affected by the altitude mode specification). */
@property (nonatomic, assign) CGFloat minAltitude;

/** Specified in meters (and is affected by the altitude mode specification). */
@property (nonatomic, assign) CGFloat maxAltitude;

/** Possible values for &lt;altitudeMode&gt; are *clampToGround*, *relativeToGround*, and *absolute*. 

 Also see KMLLatLonBox. */
@property (nonatomic, assign) KMLAltitudeMode altitudeMode;

@end
