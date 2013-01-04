//
//  KMLCamera.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractView.h"

/** Defines the virtual camera that views the scene. 
 This element defines the position of the camera relative to the Earth's surface as well as the viewing direction of the camera. The camera position is defined by &lt;longitude&gt;, &lt;latitude&gt;, &lt;altitude&gt;, and either &lt;altitudeMode&gt; or &lt;gx:altitudeMode&gt;. 
 The viewing direction of the camera is defined by &lt;heading&gt;, &lt;tilt&gt;, and &lt;roll&gt;. &lt;Camera&gt; can be a child element of any Feature or of &lt;NetworkLinkControl&gt;. 
 A parent element cannot contain both a &lt;Camera&gt; and a &lt;LookAt&gt; at the same time.
 
 &lt;Camera&gt; provides full six-degrees-of-freedom control over the view, so you can position the Camera in space and then rotate it around the X, Y, and Z axes.
 Most importantly, you can tilt the camera view so that you're looking above the horizon into the sky.
 
 &lt;Camera&gt; can also contain a TimePrimitive (&lt;gx:TimeSpan&gt; or &lt;gx:TimeStamp&gt;). 
 Time values in Camera affect historical imagery, sunlight, and the display of time-stamped features. For more information, read <a href="http://code.google.com/apis/kml/documentation/time.html#abstractviews" target="_blank">Time with AbstractViews</a> in the *Time and Animation* chapter of the Developer's Guide. 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLCamera : KMLAbstractView


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Longitude of the virtual camera (eye point). Angular distance in degrees, relative to the Prime Meridian. 
 
 Values west of the Meridian range from −180 to 0 degrees. Values east of the Meridian range from 0 to 180 degrees. */
@property (nonatomic, assign) CGFloat longitude;

/** Latitude of the virtual camera. Degrees north or south of the Equator (0 degrees). 
 
 Values range from −90 degrees to 90 degrees.*/
@property (nonatomic, assign) CGFloat latitude;

/** Distance of the camera from the earth's surface, in meters. 
 
 Interpreted according to the Camera's &lt;altitudeMode&gt; or &lt;gx:altitudeMode&gt;. */
@property (nonatomic, assign) CGFloat altitude;

/** Direction (azimuth) of the camera, in degrees. Default=0 (true North). 
 
 Values range from 0 to 360 degrees. */
@property (nonatomic, assign) CGFloat heading;

/** Rotation, in degrees, of the camera around the X axis. 
 
 A value of 0 indicates that the view is aimed straight down toward the earth (the most common case). 
 A value for 90 for &lt;tilt&gt; indicates that the view is aimed toward the horizon. Values greater than 90 indicate that the view is pointed up into the sky. Values for &lt;tilt&gt; are clamped at +180 degrees. */
@property (nonatomic, assign) CGFloat tilt;

/** Rotation, in degrees, of the camera around the *Z* axis. 
 
 Values range from −180 to +180 degrees. */
@property (nonatomic, assign) CGFloat roll;

/** Specifies how the &lt;altitude&gt; specified for the Camera is interpreted. 
 
 Possible values are as follows:
 
 - *relativeToGround* - (default) Interprets the &lt;altitude&gt; as a value in meters above the ground. If the point is over water, the &lt;altitude&gt; will be interpreted as a value in meters above sea level. See &lt;gx:altitudeMode&gt; below to specify points relative to the sea floor.
 - *clampToGround* - For a camera, this setting also places the camera relativeToGround, since putting the camera exactly at terrain height would mean that the eye would intersect the terrain (and the view would be blocked).
 - *absolute* - Interprets the &lt;altitude&gt; as a value in meters above sea level.
 */
@property (nonatomic, assign) KMLAltitudeMode altitudeMode;

@end
