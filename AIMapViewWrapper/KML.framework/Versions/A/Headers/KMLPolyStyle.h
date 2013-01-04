//
//  KMLPolyStyle.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractColorStyle.h"

/** Specifies the drawing style for all polygons, including polygon extrusions (which look like the walls of buildings) and line extrusions (which look like solid fences).
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLPolyStyle : KMLAbstractColorStyle


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Boolean value. 
 
 Specifies whether to fill the polygon. */
@property (nonatomic, assign) BOOL fill;

/** Boolean value. 
 
 Specifies whether to outline the polygon. 
 Polygon outlines use the current LineStyle. */
@property (nonatomic, assign) BOOL outline;

@end
