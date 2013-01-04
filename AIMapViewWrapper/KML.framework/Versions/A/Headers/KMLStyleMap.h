//
//  KMLStyleMap.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractStyleSelector.h"

@class KMLPair;

/** A &lt;StyleMap&gt; maps between two different Styles. 
 Typically a &lt;StyleMap&gt; element is used to provide separate normal and highlighted styles for a placemark, so that the highlighted version appears when the user mouses over the icon in Google Earth.
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLStyleMap : KMLAbstractStyleSelector


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** The Pair child elements of this element. */
@property (strong, nonatomic, readonly) NSArray *pairs;


/// ---------------------------------
/// @name Adding Pair
/// ---------------------------------

/** Inserts a given KMLPair object at the end of the pair array.
 @param pair The KMLPair to add to the end of the pair array.
 */
- (void)addPair:(KMLPair *)pair;

/** Adds the KMLPair objects contained in another given array to the end of the pair array.
 @param array An array of KMLPair objects to add to the end of the pair array.
 */
- (void)addPairs:(NSArray *)array;


/// ---------------------------------
/// @name Removing Pair
/// ---------------------------------

/** Removes all occurrences in the pair array of a given KMLPair object.
 @param pair The KMLPair object to remove from the pair array.
 */
- (void)removePair:(KMLPair *)pair;

@end
