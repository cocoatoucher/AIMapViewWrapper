//
//  KMLAbstractContainer.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractFeature.h"

/** This is an abstract element and cannot be used directly in a KML file. 
 A Container element holds one or more Features and allows the creation of nested hierarchies. 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLAbstractContainer : KMLAbstractFeature


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** The Feature child elements of this element. */
@property (strong, nonatomic, readonly) NSArray *features;


/// ---------------------------------
/// @name Adding Feature
/// ---------------------------------

/** Inserts a given KMLAbstractFeature object at the end of the feature array.
 @param feature The KMLAbstractFeature to add to the end of the feature arrayt.
 */
- (void)addFeature:(KMLAbstractFeature *)feature;

/** Adds the KMLAbstractFeature objects contained in another given array to the end of the feature array.
 @param array An array of KMLAbstractFeature objects to add to the end of the feature array.
 */
- (void)addFeatures:(NSArray *)array;



/// ---------------------------------
/// @name Removing Feature
/// ---------------------------------

/** Removes all occurrences in the feature array of a given KMLAbstractFeature object.
 @param feature The KMLAbstractFeature object to remove from the feature array.
 */
- (void)removeFeature:(KMLAbstractFeature *)feature;

@end
