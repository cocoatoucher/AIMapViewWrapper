//
//  KMLResourceMap.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractObject.h"

@class KMLAlias;

/** Specifies 0 or more KMLAlias elements, each of which is a mapping for the texture file path from the original Collada file to the KML or KMZ file that contains the Model. 
 This element allows you to move and rename texture files without having to update the original Collada file that references those textures. 
 One &lt;ResourceMap&gt; element can contain multiple mappings from different (source) Collada files into the same (target) KMZ file. 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLResourceMap : KMLAbstractObject


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** The Alias child elements of this element. */
@property (strong, nonatomic, readonly) NSArray *aliasList;


/// ---------------------------------
/// @name Adding Alias
/// ---------------------------------

/** Inserts a given KMLAlias object at the end of the alias array.
 @param alias The KMLAlias to add to the end of the alias array.
 */
- (void)addAlias:(KMLAlias *)alias;

/** Adds the KMLAlias objects contained in another given array to the end of the alias array.
 @param array An array of KMLAlias objects to add to the end of the alias array.
 */
- (void)addAliasList:(NSArray *)array;


/// ---------------------------------
/// @name Removing Alias
/// ---------------------------------

/** Removes all occurrences in the alias array of a given KMLAlias object.
 @param alias The KMLAlias object to remove from the alias array.
 */
- (void)removeAlias:(KMLAlias *)alias;

@end
