//
//  KMLData.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLElement.h"

/** An untyped name/value pair. 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLData : KMLElement


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Name of the data pair. 
 
 This attribute is used to identify the data pair within the KML file. 
 */
@property (strong, nonatomic) NSString *name;

/** An optional formatted version of name, to be used for display purposes. */
@property (strong, nonatomic) NSString *displayName;

/** Value of the data pair. */
@property (strong, nonatomic) NSString *value;

@end
