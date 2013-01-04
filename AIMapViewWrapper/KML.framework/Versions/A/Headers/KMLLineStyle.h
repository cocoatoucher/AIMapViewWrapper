//
//  KMLLineStyle.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractColorStyle.h"

/** Specifies the drawing style (color, color mode, and line width) for all line geometry. 
 Line geometry includes the outlines of outlined polygons and the extruded "tether" of Placemark icons (if extrusion is enabled). 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLLineStyle : KMLAbstractColorStyle


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Width of the line, in pixels. */
@property (nonatomic, assign) CGFloat width;

@end
