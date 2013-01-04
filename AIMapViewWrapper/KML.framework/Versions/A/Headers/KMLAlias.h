//
//  KMLAlias.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractObject.h"

/** Contains a mapping from a &lt;sourceHref&gt; to a &lt;targetHref&gt;. 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLAlias : KMLAbstractObject


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Specifies the texture file to be fetched by Google Earth. 
 
 This reference can be a relative reference to an image file within the .kmz archive, or it can be an absolute reference to the file (for example, a URL) */
@property (strong, nonatomic) NSString *targetHref;

/** Is the path specified for the texture file in the Collada .dae file. 

 In Google Earth, if this mapping is not supplied, the following rules are used to locate the textures referenced in the Collada (.dae) file:
 
 - *No path*: If the texture name does not include a path, Google Earth looks for the texture in the same directory as the .dae file that references it.
 - *Relative path*: If the texture name includes a relative path (for example, ../images/mytexture.jpg), Google Earth interprets the path as being relative to the .dae file that references it.
 - *Absolute path*: If the texture name is an absolute path (c:\mytexture.jpg) or a network path (for example, http://myserver.com/mytexture.jpg), Google Earth looks for the file in the specified location, regardless of where the .dae file is located.
 */
@property (strong, nonatomic) NSString *sourceHref;

@end
