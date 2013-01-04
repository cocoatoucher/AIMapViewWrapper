//
//  KMLParser.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>

@class KMLRoot;


/** Instances of this class parse KML documents.
 */
@interface KMLParser : NSObject


/// ---------------------------------
/// @name Parsing
/// ---------------------------------

/** Parsing the KML content referenced by the given URL.

 @param url An NSURL object specifying a URL. The URL must be fully qualified and refer to a scheme that is supported by the NSURL class.
 @return An initialized KMLRoot object or nil if an error occurs.
 */
+ (KMLRoot *)parseKMLAtURL:(NSURL *)url;

/** Parsing the KML content referenced by the given File path.
 
 @param path The absolute path of the file from which to read KML data.
 @return An initialized KMLRoot object or nil if an error occurs.
 */
+ (KMLRoot *)parseKMLAtPath:(NSString *)path;

/** Parsing the KML content referenced by the given KML string.
 
 @param string The KML string.
 @return An initialized KMLRoot object or nil if an error occurs.
 */
+ (KMLRoot *)parseKMLWithString:(NSString*)string;

/** Parsing the KML content referenced by the given data.
 
 @param data The data from which to read KML data.
 @return An initialized KMLRoot object or nil if an error occurs.
 */
+ (KMLRoot *)parseKMLWithData:(NSData*)data;

@end
