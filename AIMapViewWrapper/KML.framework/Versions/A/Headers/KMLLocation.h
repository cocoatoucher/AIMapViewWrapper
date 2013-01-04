//
//  KMLLocation.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractObject.h"

/** Specifies the exact coordinates of the Model's origin in latitude, longitude, and altitude. 
 Latitude and longitude measurements are standard lat-lon projection with WGS84 datum. 
 Altitude is distance above the earth's surface, in meters, and is interpreted according to &lt;altitudeMode&gt; or &lt;gx:altitudeMode&gt;. 
 
     <Location>
         <longitude>39.55375305703105</longitude>  
         <latitude>-118.9813220168456</latitude> 
         <altitude>1223</altitude> 
     </Location> 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLLocation : KMLAbstractObject


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Longitude */
@property (nonatomic, assign) CGFloat longitude;

/** Latitude */
@property (nonatomic, assign) CGFloat latitude;

/** Altitude */
@property (nonatomic, assign) NSInteger altitude;

@end
