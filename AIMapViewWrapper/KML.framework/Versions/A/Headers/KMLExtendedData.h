//
//  NAKMMLExtendedData.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLElement.h"

@class KMLData;
@class KMLSchemaData;

/** The ExtendedData element offers three techniques for adding custom data to a KML Feature (NetworkLink, Placemark, GroundOverlay, PhotoOverlay, ScreenOverlay, Document, Folder). 
 These techniques are
 
 - Adding untyped data/value pairs using the &lt;Data&gt; element (basic)
 - Declaring new typed fields using the &lt;Schema&gt; element and then instancing them using the &lt;SchemaData&gt; element (advanced)
 - Referring to XML elements defined in other namespaces by referencing the external namespace within the KML file (basic)
 
 These techniques can be combined within a single KML file or Feature for different pieces of data.

 For more information, see <a href="http://code.google.com/intl/en/apis/kml/documentation/extendeddata.html" target="_blank">Adding Custom Data</a> in "Topics in KML."
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLExtendedData : KMLElement


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** The Data child elements of this element. */
@property (strong, nonatomic, readonly) NSArray *dataList;

/** The SchemaData child elements of this element. */
@property (strong, nonatomic, readonly) NSArray *schemaDataList;


/// ---------------------------------
/// @name Adding Data
/// ---------------------------------

/** Inserts a given KMLData object at the end of the data array.
 @param data The KMLData to add to the end of the data array.
 */
- (void)addData:(KMLData *)data;

/** Adds the KMLData objects contained in another given array to the end of the data array.
 @param array An array of KMLData objects to add to the end of the data array.
 */
- (void)addDataList:(NSArray *)array;


/// ---------------------------------
/// @name Removing Data
/// ---------------------------------

/** Removes all occurrences in the data array of a given KMLData object.
 @param data The KMLData object to remove from the data array.
 */
- (void)removeData:(KMLData *)data;


/// ---------------------------------
/// @name Adding SchemaData
/// ---------------------------------

/** Inserts a given KMLSchemaData object at the end of the schemaData array.
 @param schemaData The KMLSchemaData to add to the end of the schemaData array.
 */
- (void)addSchemaData:(KMLSchemaData *)schemaData;

/** Adds the KMLSchemaData objects contained in another given array to the end of the schemaData array.
 @param array An array of KMLSchemaData objects to add to the end of the schemaData array.
 */
- (void)addSchemaDataList:(NSArray *)array;


/// ---------------------------------
/// @name Removing SchemaData
/// ---------------------------------

/** Removes all occurrences in the schemaData array of a given KMLSchemaData object.
 @param schemaData The KMLSchemaData object to remove from the schemaData array.
 */
- (void)removeSchemaData:(KMLSchemaData *)schemaData;

@end
