//
//  KMLSimpleField.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLElement.h"

/** The declaration of the custom field. 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLSimpleField : KMLElement


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Type of the field.

 This attribute can be one of the following:
 
 - string
 - int
 - uint
 - short
 - ushort
 - float
 - double
 - bool
 */
@property (strong, nonatomic) NSString *type;

/** Name of the field. */
@property (strong, nonatomic) NSString *name;

/** The name, if any, to be used when the field name is displayed to the Google Earth user. 
 
 Use the [CDATA] element to escape standard HTML markup. */
@property (strong, nonatomic) NSString *displayName;

@end
