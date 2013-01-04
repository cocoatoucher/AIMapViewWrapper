//
//  KMLPoint.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreLocation/CoreLocation.h>
#import "KMLAbstractGeometry.h"

@class KMLCoordinate;

/** A geographic location defined by longitude, latitude, and (optional) altitude. 
 When a Point is contained by a Placemark, the point itself determines the position of the Placemark's name and icon. 
 When a Point is extruded, it is connected to the ground with a line. 
 This "tether" uses the current LineStyle. 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLPoint : KMLAbstractGeometry


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Boolean value. 
 
 Specifies whether to connect the point to the ground with a line. 
 To extrude a Point, the value for &lt;altitudeMode&gt; must be either relativeToGround, relativeToSeaFloor, or absolute. 
 The point is extruded toward the center of the Earth's sphere. */
@property (nonatomic, assign) BOOL extrude;

/** Specifies how altitude components in the &lt;coordinates&gt; element are interpreted. 

 Possible values are
 
 - *clampToGround* - (default) Indicates to ignore an altitude specification (for example, in the &lt;coordinates&gt; tag).
 - *relativeToGround* - Sets the altitude of the element relative to the actual ground elevation of a particular location. For example, if the ground elevation of a location is exactly at sea level and the altitude for a point is set to 9 meters, then the elevation for the icon of a point placemark elevation is 9 meters with this mode. However, if the same coordinate is set over a location where the ground elevation is 10 meters above sea level, then the elevation of the coordinate is 19 meters. A typical use of this mode is for placing telephone poles or a ski lift.
 - *absolute* - Sets the altitude of the coordinate relative to sea level, regardless of the actual elevation of the terrain beneath the element. For example, if you set the altitude of a coordinate to 10 meters with an *absolute* altitude mode, the icon of a point placemark will appear to be at ground level if the terrain beneath is also 10 meters above sea level. If the terrain is 3 meters above sea level, the placemark will appear elevated above the terrain by 7 meters. A typical use of this mode is for aircraft placement. 
 */
@property (nonatomic, assign) KMLAltitudeMode altitudeMode;

/** A single tuple consisting of floating point values for longitude, latitude, and altitude (in that order). 
 
 Longitude and latitude values are in degrees, where
 
 - longitude ≥ −180 and <= 180
 - latitude ≥ −90 and ≤ 90
 - altitude values (optional) are in meters above sea level
 
 Do not include spaces between the three values that describe a coordinate.
 */
@property (strong, nonatomic) KMLCoordinate *coordinate;

@end
