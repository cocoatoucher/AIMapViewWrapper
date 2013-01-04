//
//  KMLSchemaData.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractObject.h"

@class KMLSimpleData;

/** This element is used in conjunction with &lt;Schema&gt; to add typed custom data to a KML Feature. 
 The Schema element (identified by the schemaUrl attribute) declares the custom data type. 
 The actual data objects ("instances" of the custom data) are defined using the SchemaData element.
 
 The Schema element is always a child of Document. 
 The ExtendedData element is a child of the Feature that contains the custom data.
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLSchemaData : KMLAbstractObject


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** The URL of schema.
 
 The &lt;schemaURL&gt; can be a full URL, a reference to a Schema ID defined in an external KML file, or a reference to a Schema ID defined in the same KML file.
 All of the following specifications are acceptable: 
 
    schemaUrl="http://host.com/PlacesIHaveLived.kml#my-schema-id"
 
    schemaUrl="AnotherFile.kml#my-schema-id"
 
    schemaUrl="#schema-id"   <!-- same file -->
 
*/
@property (strong, nonatomic) NSString *schemaUrl;

/** The SimpleData child elements of this element. */
@property (strong, nonatomic, readonly) NSArray *simpleDataList;


/// ---------------------------------
/// @name Adding SimpleData
/// ---------------------------------

/** Inserts a given KMLSimpleData object at the end of the simpleData array.
 @param simpleData The KMLSimpleData to add to the end of the simpleData array.
 */
- (void)addSimpleData:(KMLSimpleData *)simpleData;

/** Adds the KMLSimpleData objects contained in another given array to the end of the simpleData array.
 @param array An array of KMLSimpleData objects to add to the end of the simpleData array.
 */
- (void)addSimpleDataList:(NSArray *)array;


/// ---------------------------------
/// @name Removing SimpleData
/// ---------------------------------

/** Removes all occurrences in the simpleData array of a given KMLSimpleData object.
 @param simpleData The KMLSimpleData object to remove from the simpleData array.
 */
- (void)removeSimpleData:(KMLSimpleData *)simpleData;

@end
