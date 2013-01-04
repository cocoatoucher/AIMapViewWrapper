//
//  KMLScreenOverlay.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractOverlay.h"

@class KMLVec2;

/** This element draws an image overlay fixed to the screen. 
 Sample uses for ScreenOverlays are compasses, logos, and heads-up displays. 
 ScreenOverlay sizing is determined by the &lt;size&gt; element. 
 Positioning of the overlay is handled by mapping a point in the image specified by &lt;overlayXY&gt; to a point on the screen specified by &lt;screenXY&gt;. 
 Then the image is rotated by &lt;rotation&gt; degrees about a point relative to the screen specified by &lt;rotationXY&gt;.
 
 The &lt;href&gt; child of &lt;Icon&gt; specifies the image to be used as the overlay. 
 This file can be either on a local file system or on a web server. 
 If this element is omitted or contains no &lt;href&gt;, a rectangle is drawn using the color and size defined by the screen overlay.
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLScreenOverlay : KMLAbstractOverlay


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Specifies a point on (or outside of) the overlay image that is mapped to the screen coordinate (&lt;screenXY&gt;). 
 
 It requires x and y values, and the units for those values.

 The x and y values can be specified in three different ways: as pixels (*"pixels"*), as fractions of the image (*"fraction"*), or as inset pixels (*"insetPixels"*), which is an offset in pixels from the upper right corner of the image. 
 The x and y positions can be specified in different ways—for example, x can be in pixels and y can be a fraction. 
 The origin of the coordinate system is in the lower left corner of the image.
 
 - *x* - Either the number of pixels, a fractional component of the image, or a pixel inset indicating the x component of a point on the overlay image.
 - *y* - Either the number of pixels, a fractional component of the image, or a pixel inset indicating the y component of a point on the overlay image.
 - *xunits* - Units in which the x value is specified. A value of *"fraction"* indicates the x value is a fraction of the image. A value of *"pixels"* indicates the x value in pixels. A value of *"insetPixels"* indicates the indent from the right edge of the image.
 - *yunits* - Units in which the y value is specified. A value of *"fraction"* indicates the y value is a fraction of the image. A value of *"pixels"* indicates the y value in pixels. A value of *"insetPixels"* indicates the indent from the top edge of the image.
 
 See KMLVec2.*/
@property (strong, nonatomic) KMLVec2 *overlayXY;

/** Specifies a point relative to the screen origin that the overlay image is mapped to. 
 
 The x and y values can be specified in three different ways: as pixels (*"pixels"*), as fractions of the screen (*"fraction"*), or as inset pixels (*"insetPixels"*), which is an offset in pixels from the upper right corner of the screen. 
 The x and y positions can be specified in different ways—for example, x can be in pixels and y can be a fraction. 
 The origin of the coordinate system is in the lower left corner of the screen.
 
 - *x* - Either the number of pixels, a fractional component of the screen, or a pixel inset indicating the x component of a point on the screen.
 - *y* - Either the number of pixels, a fractional component of the screen, or a pixel inset indicating the y component of a point on the screen.
 - *xunits* - Units in which the x value is specified. A value of *"fraction"* indicates the x value is a fraction of the screen. A value of *"pixels"* indicates the x value in pixels. A value of *"insetPixels"* indicates the indent from the right edge of the screen.
 - *yunits* - Units in which the y value is specified. A value of *"fraction"* indicates the y value is a fraction of the screen. A value of *"pixels"* indicates the y value in pixels. A value of *"insetPixels"* indicates the indent from the top edge of the screen.
 
 For example, <screenXY x=".5" y=".5" xunits="fraction" yunits="fraction"/> indicates a point in the middle of the screen.
 
 Here are some examples:
 
 Center the image:
 
     <ScreenOverlay>
         <overlayXY x="0.5" y="0.5" xunits="fraction" yunits="fraction"/>
         <screenXY x="0.5" y="0.5" xunits="fraction" yunits="fraction"/>
     </ScreenOverlay>
 
 Place the image on the top left:
 
     <ScreenOverlay>
         <overlayXY x="0" y="1" xunits="fraction" yunits="fraction"/>
         <screenXY x="0" y="1" xunits="fraction" yunits="fraction"/>
     </ScreenOverlay> 
 
 Place the image at the right of the screen:
 
     <ScreenOverlay>
         <overlayXY x="1" y="1" xunits="fraction" yunits="fraction"/>
         <screenXY x="1" y="1" xunits="fraction" yunits="fraction"/>
     </ScreenOverlay>  
 
 See KMLVec2.*/
@property (strong, nonatomic) KMLVec2 *screenXY;

/** Point relative to the screen about which the screen overlay is rotated.
 
 See KMLVec2.*/
@property (strong, nonatomic) KMLVec2 *rotationXY;

/** Specifies the size of the image for the screen overlay,
 
 as follows:
 
 - A value of −1 indicates to use the native dimension
 - A value of 0 indicates to maintain the aspect ratio
 - A value of n sets the value of the dimension
 
 For example:
 
 To force the image to retain its original x and y dimensions, set the values to −1:
 
    <size x="-1" y="-1" xunits="fraction" yunits="fraction"/> 
 
 To force the image to retain its horizontal dimension, but to take up 20 percent of the vertical screen space:
 
    <size x="-1" y="0.2" xunits="fraction" yunits="fraction"/> 
 
 To force the image to resize to 100px by 500px:
 
    <size x="100" y="500" xunits="pixels" yunits="pixels"/> 
 
 See KMLVec2.*/
@property (strong, nonatomic) KMLVec2 *size;

/** Indicates the angle of rotation of the parent object. A value of 0 means no rotation. 
 
 The value is an angle in degrees counterclockwise starting from north. Use ±180 to indicate the rotation of the parent object from 0. 
 The center of the &lt;rotation&gt;, if not (.5,.5), is specified in &lt;rotationXY&gt;.
 */
@property (nonatomic, assign) CGFloat rotation;

@end
