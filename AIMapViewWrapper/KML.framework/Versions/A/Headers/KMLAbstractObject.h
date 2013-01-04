//
//  KMLAbstractObject.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLElement.h"

/** This is an abstract base class and cannot be used directly in a KML file. 
 It provides the id attribute, which allows unique identification of a KML element, and the targetId attribute, which is used to reference objects that have already been loaded into Google Earth. 
 The id attribute must be assigned if the Update mechanism is to be used.

 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLAbstractObject : KMLElement

/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** The unique identification of a KML element. */
@property (strong, nonatomic) NSString *objectID;

/** This is used to reference objects that have already been loaded into app. */
@property (strong, nonatomic) NSString *targetID;

@end
