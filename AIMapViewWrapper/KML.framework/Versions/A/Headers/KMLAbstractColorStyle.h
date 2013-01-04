//
//  KMLAbstractColorStyle.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractSubStyle.h"

/** This is an abstract element and cannot be used directly in a KML file. 
 It provides elements for specifying the color and color mode of extended style types. 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLAbstractColorStyle : KMLAbstractSubStyle


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Color and opacity (alpha) values are expressed in hexadecimal notation. 
 
 The range of values for any one color is 0 to 255 (00 to ff). 
 For alpha, 00 is fully transparent and ff is fully opaque. 
 The order of expression is aabbggrr, where aa=alpha (00 to ff); bb=blue (00 to ff); gg=green (00 to ff); rr=red (00 to ff). 
 For example, if you want to apply a blue color with 50 percent opacity to an overlay, you would specify the following: &lt;color&gt;7fff0000&lt;/color&gt;, where alpha=0x7f, blue=0xff, green=0x00, and red=0x00. */
@property (strong, nonatomic) NSString *color;

/** Values for &lt;colorMode&gt; are *normal* (no effect) and *random*. 
 
 A value of *random* applies a random linear scale to the base &lt;color&gt; as follows.
 
 - To achieve a truly random selection of colors, specify a base &lt;color&gt; of white (ffffffff).
 -  If you specify a single color component (for example, a value of ff0000ff for red), random color values for that one component (red) will be selected. In this case, the values would range from 00 (black) to ff (full red).
 - If you specify values for two or for all three color components, a random linear scale is applied to each color component, with results ranging from black to the maximum values specified for each component.
 - The opacity of a color comes from the alpha component of &lt;color&gt; and is never randomized.
 */
@property (nonatomic, assign) KMLColorMode colorMode;


/// ---------------------------------
/// @name UIColor
/// ---------------------------------

/** Returns The UIColor from color string.
 @return UIColor.
 */
- (UIColor *)UIColor;

/** Set UIColor to color string.
 @param color The UIColor.
 */
- (void)setUIColor:(UIColor *)color;

@end
