//
//  KMLSimpleData.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLElement.h"

/** This element assigns a value to the custom data field identified by the name attribute. 
 The type and name of this custom data field are declared in the &lt;Schema&gt; element.
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLSimpleData : KMLElement


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Name of the SimpleData. */
@property (strong, nonatomic) NSString *name;

/** Value of the SimpleData. */
@property (strong, nonatomic) NSString *value;

@end
