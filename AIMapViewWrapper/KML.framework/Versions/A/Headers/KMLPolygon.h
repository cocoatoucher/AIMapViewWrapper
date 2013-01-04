//
//  KMLPolygon.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractGeometry.h"

@class KMLLinearRing;

/** A Polygon is defined by an outer boundary and 0 or more inner boundaries. 
 The boundaries, in turn, are defined by LinearRings. 
 When a Polygon is extruded, its boundaries are connected to the ground to form additional polygons, which gives the appearance of a building or a box. 
 Extruded Polygons use KMLPolyStyle for their color, color mode, and fill.
 The &lt;coordinates&gt; for polygons must be specified in counterclockwise order. 
 Polygons follow the "right-hand rule," which states that if you place the fingers of your right hand in the direction in which the coordinates are specified, your thumb points in the general direction of the geometric normal for the polygon. 
 (In 3D graphics, the geometric normal is used for lighting and points away from the front face of the polygon.) 
 Since Google Earth fills only the front face of polygons, you will achieve the desired effect only when the coordinates are specified in the proper order. 
 Otherwise, the polygon will be gray. 

 @warning *Note:* In Google Earth, a Polygon with an &lt;altitudeMode&gt; of clampToGround follows lines of constant bearing; however, a LinearRing (by itself) with an &lt;altitudeMode&gt; of clampToGround follows great circle lines.
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLPolygon : KMLAbstractGeometry


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Boolean value. 

 Specifies whether to connect the Polygon to the ground. 
 To extrude a Polygon, the altitude mode must be either relativeToGround, relativeToSeaFloor, or absolute. 
 Only the vertices are extruded, not the geometry itself (for example, a rectangle turns into a box with five faces). 
 The vertices of the Polygon are extruded toward the center of the Earth's sphere.
*/
@property (nonatomic, assign) BOOL extrude;

/** This field is not used by Polygon. 
 
 To allow a Polygon to follow the terrain (that is, to enable tessellation) specify an altitude mode of clampToGround or clampToSeaFloor. */
@property (nonatomic, assign) BOOL tessellate;

/** Specifies how altitude components in the &lt;coordinates&gt; element are interpreted. 
 
 Possible values are
 
 - *clampToGround* - (default) Indicates to ignore an altitude specification (for example, in the &lt;coordinates&gt; tag).
 - *relativeToGround* - Sets the altitude of the element relative to the actual ground elevation of a particular location. For example, if the ground elevation of a location is exactly at sea level and the altitude for a point is set to 9 meters, then the elevation for the icon of a point placemark elevation is 9 meters with this mode. However, if the same coordinate is set over a location where the ground elevation is 10 meters above sea level, then the elevation of the coordinate is 19 meters. A typical use of this mode is for placing telephone poles or a ski lift.
 - *absolute* - Sets the altitude of the coordinate relative to sea level, regardless of the actual elevation of the terrain beneath the element. For example, if you set the altitude of a coordinate to 10 meters with an absolute altitude mode, the icon of a point placemark will appear to be at ground level if the terrain beneath is also 10 meters above sea level. If the terrain is 3 meters above sea level, the placemark will appear elevated above the terrain by 7 meters. A typical use of this mode is for aircraft placement. 
 */
@property (nonatomic, assign) KMLAltitudeMode altitudeMode;

/** Contains a KMLLinearRing element. */
@property (strong, nonatomic) KMLLinearRing *outerBoundaryIs;

/** Contains a KMLLinearRing element. 
 
 A Polygon can contain multiple &lt;innerBoundaryIs&gt; elements, which create multiple cut-outs inside the Polygon. */
@property (strong, nonatomic, readonly) NSArray *innerBoundaryIsList;


/// ---------------------------------
/// @name Adding InnerBoundaryIs
/// ---------------------------------

/** Inserts a given KMLLinearRing object at the end of the InnerBoundaryIs array.
 @param object The KMLLinearRing to add to the end of the InnerBoundaryIs array.
 */
- (void)addInnerBoundaryIs:(KMLLinearRing *)object;

/** Adds the KMLLinearRing objects contained in another given array to the end of the InnerBoundaryIs array.
 @param array An array of KMLLinearRing objects to add to the end of the InnerBoundaryIs array.
 */
- (void)addInnerBoundaryIsList:(NSArray *)array;


/// ---------------------------------
/// @name Removing InnerBoundaryIs
/// ---------------------------------

/** Removes all occurrences in the InnerBoundaryIs array of a given KMLLinearRing object.
 @param object The KMLLinearRing object to remove from the InnerBoundaryIs array.
 */
- (void)removeInnerBoundaryIs:(KMLLinearRing *)object;

@end
