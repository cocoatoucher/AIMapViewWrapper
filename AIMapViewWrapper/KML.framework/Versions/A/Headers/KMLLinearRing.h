//
//  KMLLinearRing.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractGeometry.h"

@class KMLCoordinate;

/** Defines a closed line string, typically the outer boundary of a Polygon. 
 Optionally, a LinearRing can also be used as the inner boundary of a Polygon to create holes in the Polygon.
 A Polygon can contain multiple &lt;LinearRing&gt; elements used as inner boundaries. 
 
 @warning *Note:* In Google Earth, a Polygon with an &lt;altitudeMode&gt; of clampToGround follows lines of constant bearing; however, a LinearRing (by itself) with an &lt;altitudeMode&gt; of clampToGround follows great circle lines.
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLLinearRing : KMLAbstractGeometry


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Boolean value. 
 
 Specifies whether to connect the LinearRing to the ground. 
 To extrude this geometry, the altitude mode must be either relativeToGround, relativeToSeaFloor, or absolute. 
 Only the vertices of the LinearRing are extruded, not the center of the geometry. 
 The vertices are extruded toward the center of the Earth's sphere. */
@property (nonatomic, assign) BOOL extrude;

/** Boolean value. 
 
 Specifies whether to allow the LinearRing to follow the terrain. 
 To enable tessellation, the value for &lt;altitudeMode&gt; must be clampToGround or clampToSeaFloor. 
 Very large LinearRings should enable tessellation so that they follow the curvature of the earth (otherwise, they may go underground and be hidden). */
@property (nonatomic, assign) BOOL tessellate;

/** Specifies how altitude components in the &lt;coordinates&gt; element are interpreted. 
 
 Possible values are
 
 - *clampToGround* - (default) Indicates to ignore an altitude specification (for example, in the &lt;coordinates&gt; tag).
 - *relativeToGround* - Sets the altitude of the element relative to the actual ground elevation of a particular location. For example, if the ground elevation of a location is exactly at sea level and the altitude for a point is set to 9 meters, then the elevation for the icon of a point placemark elevation is 9 meters with this mode. However, if the same coordinate is set over a location where the ground elevation is 10 meters above sea level, then the elevation of the coordinate is 19 meters. A typical use of this mode is for placing telephone poles or a ski lift.
 - *absolute* - Sets the altitude of the coordinate relative to sea level, regardless of the actual elevation of the terrain beneath the element. For example, if you set the altitude of a coordinate to 10 meters with an absolute altitude mode, the icon of a point placemark will appear to be at ground level if the terrain beneath is also 10 meters above sea level. If the terrain is 3 meters above sea level, the placemark will appear elevated above the terrain by 7 meters. A typical use of this mode is for aircraft placement. 
 */
@property (nonatomic, assign) KMLAltitudeMode altitudeMode;

/** Four or more tuples, each consisting of floating point values for longitude, latitude, and altitude. 
 
 The altitude component is optional. 
 Do not include spaces within a tuple. 
 The last coordinate must be the same as the first coordinate. 
 Coordinates are expressed in decimal degrees only */
@property (strong, nonatomic, readonly) NSArray *coordinates;


/// ---------------------------------
/// @name Adding StyleSelector
/// ---------------------------------

/** Inserts a given KMLCoordinate object at the end of the coordinate array.
 @param coordinate The KMLCoordinate to add to the end of the coordinate array.
 */
- (void)addCoordinate:(KMLCoordinate *)coordinate;

/** Adds the KMLCoordinate objects contained in another given array to the end of the coordinate array.
 @param array An array of KMLCoordinate objects to add to the end of the coordinate array.
 */
- (void)addCoordinates:(NSArray *)array;


/// ---------------------------------
/// @name Removing StyleSelector
/// ---------------------------------

/** Removes all occurrences in the coordinate array of a given KMLCoordinate object.
 @param coordinate The KMLCoordinate object to remove from the coordinate array.
 */
- (void)removeCoordinate:(KMLCoordinate *)coordinate;

@end
