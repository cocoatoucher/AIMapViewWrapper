//
//  KMLGroundOverlay.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractOverlay.h"

@class KMLLatLonBox;

/** This element draws an image overlay draped onto the terrain. 
 The &lt;href&gt; child of &lt;Icon&gt; specifies the image to be used as the overlay. 
 This file can be either on a local file system or on a web server. 
 If this element is omitted or contains no &lt;href&gt;, a rectangle is drawn using the color and LatLonBox bounds defined by the ground overlay. 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLGroundOverlay : KMLAbstractOverlay


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Specifies the distance above the earth's surface, in meters, and is interpreted according to the altitude mode. */
@property (nonatomic, assign) NSInteger altitude;

/** Specifies how the <altitude>is interpreted. 
 
 Possible values are
 
 - clampToGround - (default) Indicates to ignore the altitude specification and drape the overlay over the terrain.
 - absolute - Sets the altitude of the overlay relative to sea level, regardless of the actual elevation of the terrain beneath the element. For example, if you set the altitude of an overlay to 10 meters with an absolute altitude mode, the overlay will appear to be at ground level if the terrain beneath is also 10 meters above sea level. If the terrain is 3 meters above sea level, the overlay will appear elevated above the terrain by 7 meters. 
 */
@property (nonatomic, assign) KMLAltitudeMode altitudeMode;

/** Specifies where the top, bottom, right, and left sides of a bounding box for the ground overlay are aligned.

 - *<north>* Specifies the latitude of the north edge of the bounding box, in decimal degrees from 0 to ±90.
 - *<south>* Specifies the latitude of the south edge of the bounding box, in decimal degrees from 0 to ±90.
 - *<east>* Specifies the longitude of the east edge of the bounding box, in decimal degrees from 0 to ±180. (For overlays that overlap the meridian of 180° longitude, values can extend beyond that range.)
 - *<west>* Specifies the longitude of the west edge of the bounding box, in decimal degrees from 0 to ±180. (For overlays that overlap the meridian of 180° longitude, values can extend beyond that range.)
 - *<rotation>* Specifies a rotation of the overlay about its center, in degrees. Values can be ±180. The default is 0 (north). Rotations are specified in a counterclockwise direction.
 
     <LatLonBox>
         <north>48.25475939255556</north>
         <south>48.25207367852141</south>
         <east>-90.86591508839973</east>
         <west>-90.8714285289695</west>
         <rotation>39.37878630116985</rotation>
     </LatLonBox>  
 */
@property (strong, nonatomic) KMLLatLonBox *latLonBox;

@end
