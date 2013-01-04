//
//  KMLPhotoOverlay.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractOverlay.h"

@class KMLViewVolume;
@class KMLImagePyramid;
@class KMLPoint;

/** The &lt;PhotoOverlay&gt; element allows you to geographically locate a photograph on the Earth and to specify viewing parameters for this PhotoOverlay. 
 The PhotoOverlay can be a simple 2D rectangle, a partial or full cylinder, or a sphere (for spherical panoramas). 
 The overlay is placed at the specified location and oriented toward the viewpoint.
 
 Because &lt;PhotoOverlay&gt; is derived from &lt;Feature&gt;, it can contain one of the two elements derived from &lt;AbstractView&gt;—either &lt;Camera&gt; or &lt;LookAt&gt;. 
 The Camera (or LookAt) specifies a viewpoint and a viewing direction (also referred to as a view vector). 
 The PhotoOverlay is positioned in relation to the viewpoint. 
 Specifically, the plane of a 2D rectangular image is orthogonal (at right angles to) the view vector. 
 The normal of this plane—that is, its front, which is the part with the photo—is oriented toward the viewpoint.
 
 The URL for the PhotoOverlay image is specified in the &lt;Icon&gt; tag, which is inherited from &lt;Overlay&gt;. 
 The &lt;Icon&gt; tag must contain an &lt;href&gt; element that specifies the image file to use for the PhotoOverlay. 
 In the case of a very large image, the &lt;href&gt; is a special URL that indexes into a pyramid of images of varying resolutions (see KMLImagePyramid).
 
 For more information, see the "Topics in KML" page on <a href="http://code.google.com/intl/en/apis/kml/documentation/photos.html" target="_blank">PhotoOverlay</a>. 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLPhotoOverlay : KMLAbstractOverlay

/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Adjusts how the photo is placed inside the field of view. 
 
 This element is useful if your photo has been rotated and deviates slightly from a desired horizontal view. */
@property (nonatomic, assign) CGFloat rotation;

/** Defines how much of the current scene is visible. 
 
 See KMLViewVolume.*/
@property (strong, nonatomic) KMLViewVolume *viewVolume;

/** For very large images, you'll need to construct an image pyramid, which is a hierarchical set of images, each of which is an increasingly lower resolution version of the original image. 
 
 See KMLImagePyramid.
 */
@property (strong, nonatomic) KMLImagePyramid *imagePyramid;

/** The &lt;Point&gt; element acts as a &lt;Point&gt; inside a &lt;Placemark&gt; element.
 
 See KMLPoint.*/
@property (strong, nonatomic) KMLPoint *point;

/** The PhotoOverlay is projected onto the &lt;shape&gt;. 
 See KMLShape.*/
@property (nonatomic, assign) KMLShape shape;

@end
