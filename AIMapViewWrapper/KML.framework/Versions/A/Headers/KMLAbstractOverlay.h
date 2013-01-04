//
//  KMLAbstractOverlay.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractFeature.h"

@class KMLIcon;
@class KMLExtendedData;

/** This is an abstract element and cannot be used directly in a KML file. 
 &lt;Overlay&gt; is the base type for image overlays drawn on the planet surface or on the screen. 
 &lt;Icon&gt; specifies the image to use and can be configured to reload images based on a timer or by camera changes. 
 This element also includes specifications for stacking order of multiple overlays and for adding color and transparency values to the base image. 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLAbstractOverlay : KMLAbstractFeature


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Color values are expressed in hexadecimal notation, including opacity (alpha) values.
 
 The order of expression is alpha, blue, green, red (aabbggrr). 
 The range of values for any one color is 0 to 255 (00 to ff). 
 For opacity, 00 is fully transparent and ff is fully opaque. 
 For example, if you want to apply a blue color with 50 percent opacity to an overlay, you would specify the following: 
 &lt;color&gt;7fff0000&lt;/color&gt; 
 
 @warning *Note:* The &lt;geomColor&gt; element has been deprecated. Use &lt;color&gt; instead.
 */
@property (strong, nonatomic) NSString *color;

/** This element defines the stacking order for the images in overlapping overlays. 
 
 Overlays with higher &lt;drawOrder&gt; values are drawn on top of overlays with lower &lt;drawOrder&gt; values. */
@property (nonatomic, assign) NSInteger drawOrder;

/** Defines the image associated with the Overlay. 
 
 See also KMLIcon.
 The &lt;href&gt; element defines the location of the image to be used as the Overlay. 
 This location can be either on a local file system or on a web server. 
 If this element is omitted or contains no &lt;href&gt;, a rectangle is drawn using the color and size defined by the ground or screen overlay. */
@property (strong, nonatomic) KMLIcon *icon;

@end
