//
//  KMLSchema.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLElement.h"

@class KMLSimpleField;

/** Specifies a custom KML schema that is used to add custom data to KML Features. 
 &lt;Schema&gt; is always a child of &lt;Document&gt;. 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLSchema : KMLElement


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** The id of schema.

 This attribute is required and must be unique within the KML file. */
@property (strong, nonatomic) NSString *objectID;

/** The name of schema. */
@property (strong, nonatomic) NSString *name;

/** The SimpleField child elements of this element. */
@property (strong, nonatomic, readonly) NSArray *simpleFields;


/// ---------------------------------
/// @name Adding SimpleField
/// ---------------------------------

/** Inserts a given KMLSimpleField object at the end of the simpleField array.
 @param simpleField The KMLSimpleField to add to the end of the simpleField array.
 */
- (void)addSimpleField:(KMLSimpleField *)simpleField;

/** Adds the KMLSimpleField objects contained in another given array to the end of the simpleField array.
 @param array An array of KMLSimpleField objects to add to the end of the simpleField array.
 */
- (void)addSimpleFields:(NSArray *)array;


/// ---------------------------------
/// @name Removing SimpleField
/// ---------------------------------

/** Removes all occurrences in the simpleField array of a given KMLSimpleField object.
 @param simpleField The KMLSimpleField object to remove from the simpleField array.
 */
- (void)removeSimpleField:(KMLSimpleField *)simpleField;

@end
