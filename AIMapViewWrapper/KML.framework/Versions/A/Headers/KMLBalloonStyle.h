//
//  KMLBalloonStyle.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractSubStyle.h"

/** Specifies how the description balloon for placemarks is drawn. 
 The &lt;bgColor&gt;, if specified, is used as the background color of the balloon. 
 See KMLAbstractFeature for a diagram illustrating how the default description balloon appears in Google Earth.
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLBalloonStyle : KMLAbstractSubStyle


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Background color of the balloon (optional). 
 
 Color and opacity (alpha) values are expressed in hexadecimal notation. 
 The range of values for any one color is 0 to 255 (00 to ff). 
 The order of expression is aabbggrr, where aa=alpha (00 to ff); bb=blue (00 to ff); gg=green (00 to ff); rr=red (00 to ff). 
 For alpha, 00 is fully transparent and ff is fully opaque. 
 For example, if you want to apply a blue color with 50 percent opacity to an overlay, you would specify the following: &lt;bgColor&gt;7fff0000&lt;/bgColor&gt;, where alpha=0x7f, blue=0xff, green=0x00, and red=0x00. 
 The default is opaque white (ffffffff). 
 
 @warning *Note:* The use of the &lt;color&gt; element within &lt;BalloonStyle&gt; has been deprecated. Use &lt;bgColor&gt; instead.
 */
@property (strong, nonatomic) NSString *bgColor;

/** Foreground color for text. 
 
 The default is black (ff000000). */
@property (strong, nonatomic) NSString *textColor;

/** Text displayed in the balloon. 
 
 If no text is specified, Google Earth draws the default balloon (with the Feature &lt;name&gt; in boldface, the Feature &lt;description&gt;, links for driving directions, a white background, and a tail that is attached to the point coordinates of the Feature, if specified).
 You can add entities to the &lt;text&gt; tag using the following format to refer to a child element of Feature: *$[name], $[description], $[address], $[id], $[Snippet]*. 
 Google Earth looks in the current Feature for the corresponding string entity and substitutes that information in the balloon. 
 To include To here - From here driving directions in the balloon, use the $[geDirections] tag. 
 To prevent the driving directions links from appearing in a balloon, include the <text> element with some content, or with $[description] to substitute the basic Feature &lt;description&gt;.
 
 For example, in the following KML excerpt, *$[name]* and *$[description]* fields will be replaced by the <name> and &lt;description&gt; fields found in the Feature elements that use this BalloonStyle:
 
    <text>This is $[name], whose description is:<br/>$[description]</text>
 */
@property (strong, nonatomic) NSString *text;

/** If &lt;displayMode&gt; is default, Google Earth uses the information supplied in &lt;text&gt; to create a balloon.
 
 If &lt;displayMode&gt; is hide, Google Earth does not display the balloon. 
 In Google Earth, clicking the List View icon for a Placemark whose balloon's &lt;displayMode&gt; is hide causes Google Earth to fly to the Placemark. */
@property (nonatomic, assign) KMLDisplayMode displayMode;

@end
