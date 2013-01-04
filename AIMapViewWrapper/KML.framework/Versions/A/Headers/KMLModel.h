//
//  KMLModel.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractGeometry.h"

@class KMLLocation;
@class KMLOrientation;
@class KMLScale;
@class KMLLink;
@class KMLResourceMap;

/** A 3D object described in a COLLADA file (referenced in the &lt;Link&gt; tag). 
 COLLADA files have a .dae file extension. 
 Models are created in their own coordinate space and then located, positioned, and scaled in Google Earth. 
 See the "Topics in KML" page on <a href="http://code.google.com/intl/en/apis/kml/documentation/models.html" target="_blank">Models</a> for more detail.

 Google Earth supports the COLLADA common profile, with the following exceptions:
 
 - Google Earth supports only triangles and lines as primitive types. The maximum number of triangles allowed is 21845.
 - Google Earth does not support animation or skinning.
 - Google Earth does not support external geometry references. 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLModel : KMLAbstractGeometry


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Specifies how the &lt;altitude&gt; specified in &lt;Location&gt; is interpreted. 
 
 Possible values are as follows:
 
 - *clampToGround* - (default) Indicates to ignore the &lt;altitude&gt; specification and place the Model on the ground.
 - *relativeToGround* - Interprets the &lt;altitude&gt; as a value in meters above the ground.
 - *absolute* - Interprets the &lt;altitude&gt; as a value in meters above sea level.
 */
@property (nonatomic, assign) KMLAltitudeMode altitudeMode;

/** See KMLLocation. */
@property (strong, nonatomic) KMLLocation *location;

/** See KMLOrientation. */
@property (strong, nonatomic) KMLOrientation *orientation;

/** See KMLScale. */
@property (strong, nonatomic) KMLScale *scale;

/** Specifies the file to load and optional refresh parameters. 
 
 See KMLLink. */
@property (strong, nonatomic) KMLLink *link;

/** See KML ResourceMap. */
@property (strong, nonatomic) KMLResourceMap *resourceMap;

@end
