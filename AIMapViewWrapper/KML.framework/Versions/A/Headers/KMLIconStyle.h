//
//  KMLIconStyle.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractColorStyle.h"

@class KMLIcon;
@class KMLVec2;

/** Specifies how icons for point Placemarks are drawn, both in the Places panel and in the 3D viewer of Google Earth. 
 The &lt;Icon&gt; element specifies the icon image. 
 The &lt;scale&gt; element specifies the x, y scaling of the icon. 
 The color specified in the &lt;color&gt; element of &lt;IconStyle&gt; is blended with the color of the &lt;Icon&gt;. 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLIconStyle : KMLAbstractColorStyle


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Resizes the icon. 
 
 @warning *Note:* The &lt;geomScale&gt; tag has been deprecated. Use &lt;scale&gt; instead.
 */
@property (nonatomic, assign) CGFloat scale;

/** Direction (that is, North, South, East, West), in degrees. Default=0 (North).
 
 Values range from 0 to 360 degrees. */
@property (nonatomic, assign) CGFloat heading;

/** See KMLIcon. */
@property (strong, nonatomic) KMLIcon *icon;

/** Specifies the position within the Icon that is "anchored" to the &lt;Point&gt; specified in the Placemark. 
 
 The x and y values can be specified in three different ways: as pixels (*"pixels"*), as fractions of the icon (*"fraction"*), or as inset pixels (*"insetPixels"*), which is an offset in pixels from the upper right corner of the icon. 
 The x and y positions can be specified in different ways—for example, x can be in pixels and y can be a fraction. 
 The origin of the coordinate system is in the lower left corner of the icon.

 - *x* - Either the number of pixels, a fractional component of the icon, or a pixel inset indicating the x component of a point on the icon.
 - *y* - Either the number of pixels, a fractional component of the icon, or a pixel inset indicating the y component of a point on the icon.
 - *xunits* - Units in which the x value is specified. A value of *fraction* indicates the x value is a fraction of the icon. A value of *pixels* indicates the x value in pixels. A value of *insetPixels* indicates the indent from the right edge of the icon.
 - *yunits* - Units in which the y value is specified. A value of *fraction* indicates the y value is a fraction of the icon. A value of *pixels* indicates the y value in pixels. A value of *insetPixels* indicates the indent from the top edge of the icon. 
 */
@property (strong, nonatomic) KMLVec2 *hotSpot;

@end
