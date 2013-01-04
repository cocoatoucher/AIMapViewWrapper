//
//  KMLUpdate.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLElement.h"

@class KMLAbstractObject;

/** Specifies an addition, change, or deletion to KML data that has already been loaded using the specified URL. 
 The &lt;targetHref&gt; specifies the .kml or .kmz file whose data (within Google Earth) is to be modified. 
 &lt;Update&gt; is always contained in a NetworkLinkControl. 
 Furthermore, the file containing the NetworkLinkControl must have been loaded by a NetworkLink. 
 See the "Topics in KML" page on <a href="http://code.google.com/intl/en/apis/kml/documentation/updates.html" target="_blank">Updates</a> for a detailed example of how Update works. 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLUpdate : KMLElement


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** A URL that specifies the .kml or .kmz file whose data (within Google Earth) is to be modified by an KMLUpdate element. 
 
 This KML file must already have been loaded via a KMLNetworkLink. 
 In that file, the element to be modified must already have an explicit id attribute defined for it. */
@property (strong, nonatomic) NSString *targetHref;

/** The Object child elements of this element. */
@property (strong, nonatomic, readonly) NSArray *objects;


/// ---------------------------------
/// @name Adding Object
/// ---------------------------------

/** Inserts a given KMLAbstractObject object at the end of the object array.
 @param object The KMLAbstractObject to add to the end of the object array.
 */
- (void)addObject:(KMLAbstractObject *)object;

/** Adds the KMLAbstractObject objects contained in another given array to the end of the object array.
 @param array An array of KMLAbstractObject objects to add to the end of the object array.
 */
- (void)addObjects:(NSArray *)array;


/// ---------------------------------
/// @name Removing Object
/// ---------------------------------

/** Removes all occurrences in the object array of a given KMLAbstractObject object.
 @param object The KMLAbstractObject object to remove from the object array.
 */
- (void)removeObject:(KMLAbstractObject *)object;

@end
