//
//  NAKLMultiGeometry.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractGeometry.h"

/** A container for zero or more geometry primitives associated with the same feature. 
 
 @warning *Note:* The &lt;GeometryCollection&gt; tag has been deprecated. Use &lt;MultiGeometry&gt; instead.
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLMultiGeometry : KMLAbstractGeometry


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** The Geometry child elements of this element. */
@property (strong, nonatomic, readonly) NSArray *geometries;


/// ---------------------------------
/// @name Adding Geometry
/// ---------------------------------

/** Inserts a given KMLAbstractGeometry object at the end of the geometry array.
 @param geometry The KMLAbstractGeometry to add to the end of the geometry array.
 */
- (void)addGeometry:(KMLAbstractGeometry *)geometry;

/** Adds the KMLAbstractGeometry objects contained in another given array to the end of the geometry array.
 @param array An array of KMLAbstractGeometry objects to add to the end of the geometry array.
 */
- (void)addGeometries:(NSArray *)array;


/// ---------------------------------
/// @name Removing Geometry
/// ---------------------------------

/** Removes all occurrences in the geometry array of a given KMLAbstractGeometry object.
 @param geometry The KMLAbstractGeometry object to remove from the geometry array.
 */
- (void)removeGeometry:(KMLAbstractGeometry *)geometry;

@end
