//
//  KMLDocument.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractContainer.h"

@class KMLSchema;

/** A Document is a container for features and styles. 
 This element is required if your KML file uses shared styles. 
 It is recommended that you use shared styles, which require the following steps:
 
 Define all Styles in a Document. Assign a unique ID to each Style.
 
 Within a given Feature or StyleMap, reference the Style's ID using a &lt;styleUrl&gt; element.
 
 Note that shared styles are not inherited by the Features in the Document.
 
 Each Feature must explicitly reference the styles it uses in a &lt;styleUrl&gt; element. 
 For a Style that applies to a Document (such as ListStyle), the Document itself must explicitly reference the &lt;styleUrl&gt;. 
 For example:
 
     <Document>
         <Style id="myPrettyDocument">
             <ListStyle> ... </ListStyle>
         </Style>
         <styleUrl#myPrettyDocument">
         ...
     </Document> 

 Do not put shared styles within a Folder.
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLDocument : KMLAbstractContainer


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** The Schema child elements of this element. */
@property (strong, nonatomic, readonly) NSArray *schemata;


/// ---------------------------------
/// @name Adding Schema
/// ---------------------------------

/** Inserts a given KMLSchema object at the end of the schema array.
 @param schema The KMLSchema to add to the end of the schema array.
 */
- (void)addSchema:(KMLSchema *)schema;

/** Adds the KMLSchema objects contained in another given array to the end of the schema array.
 @param array An array of KMLSchema objects to add to the end of the schema array.
 */
- (void)addSchemata:(NSArray *)array;


/// ---------------------------------
/// @name Removing Schema
/// ---------------------------------

/** Removes all occurrences in the schema array of a given KMLSchema object.
 @param schema The KMLSchema object to remove from the styleselector array.
 */
- (void)removeSchema:(KMLSchema *)schema;

@end
