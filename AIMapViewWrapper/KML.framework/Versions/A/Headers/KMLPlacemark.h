//
//  KMLPlacemark.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractFeature.h"

@class KMLAbstractGeometry;

/** A Placemark is a Feature with associated Geometry. 
 In Google Earth, a Placemark appears as a list item in the Places panel. 
 A Placemark with a Point has an icon associated with it that marks a point on the Earth in the 3D viewer. 
 (In the Google Earth 3D viewer, a Point Placemark is the only object you can click or roll over. 
  Other Geometry objects do not have an icon in the 3D viewer. 
  To give the user something to click in the 3D viewer, you would need to create a MultiGeometry object that contains both a Point and the other Geometry object.) 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLPlacemark : KMLAbstractFeature


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Returns the KMLAbstractGeometry of this element.
 @return The KMLAbstractGeometry object or nil if object not found.
 */
@property (strong, nonatomic) KMLAbstractGeometry *geometry;

@end
