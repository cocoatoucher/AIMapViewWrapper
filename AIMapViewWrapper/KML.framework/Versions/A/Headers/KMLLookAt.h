//
//  KMLLookAt.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractView.h"

/** Defines a virtual camera that is associated with any element derived from Feature. 
 The LookAt element positions the "camera" in relation to the object that is being viewed. 
 In Google Earth, the view "flies to" this LookAt viewpoint when the user double-clicks an item in the Places panel or double-clicks an icon in the 3D viewer. 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLLookAt : KMLAbstractView


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Longitude of the point the camera is looking at. Angular distance in degrees, relative to the Prime Meridian. Values west of the Meridian range from −180 to 0 degrees. 
 
 Values east of the Meridian range from 0 to 180 degrees */
@property (nonatomic, assign) CGFloat longitude;

/** Latitude of the point the camera is looking at. Degrees north or south of the Equator (0 degrees). 
 
 Values range from −90 degrees to 90 degrees. */
@property (nonatomic, assign) CGFloat latitude;

/** Distance from the earth's surface, in meters. 
 
 Interpreted according to the LookAt's altitude mode. */
@property (nonatomic, assign) CGFloat altitude;

/** Direction (that is, North, South, East, West), in degrees. Default=0 (North). 
 
 Values range from 0 to 360 degrees. */
@property (nonatomic, assign) CGFloat heading;

/** Angle between the direction of the LookAt position and the normal to the surface of the earth. 
 
 Values range from 0 to 90 degrees. Values for &lt;tilt&gt; cannot be negative. 
 A &lt;tilt&gt; value of 0 degrees indicates viewing from directly above. 
 A &lt;tilt&gt; value of 90 degrees indicates viewing along the horizon. */
@property (nonatomic, assign) CGFloat tilt;

/** Distance in meters from the point specified by &lt;longitude&gt;, &lt;latitude&gt;, and &lt;altitude&gt; to the LookAt position. */
@property (nonatomic, assign) CGFloat range;

/** Specifies how the &lt;altitude&gt; specified for the LookAt point is interpreted. Possible values are as follows:

 - *clampToGround* - (default) Indicates to ignore the &lt;altitude&gt; specification and place the LookAt position on the ground.
 - *relativeToGround* - Interprets the &lt;altitude&gt; as a value in meters above the ground.
 - *absolute* - Interprets the &lt;altitude&gt; as a value in meters above sea level. 
 */
@property (nonatomic, assign) KMLAltitudeMode altitudeMode;

@end
