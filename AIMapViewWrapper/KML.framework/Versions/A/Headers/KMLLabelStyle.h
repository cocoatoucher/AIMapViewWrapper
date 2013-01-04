//
//  KMLLabelStyle.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractColorStyle.h"

/** Specifies how the &lt;name&gt; of a Feature is drawn in the 3D viewer. 
 A custom color, color mode, and scale for the label (name) can be specified. 
 
 @warning *Note:* The &lt;labelColor&gt; tag is deprecated. Use &lt;LabelStyle&gt; instead.
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLLabelStyle : KMLAbstractColorStyle


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Resizes the label. */
@property (nonatomic, assign) CGFloat scale;

@end
