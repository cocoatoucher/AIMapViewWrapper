//
//  KMLAbstractView.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractObject.h"

@class KMLAbstractTimePrimitive;

/** This is an abstract element and cannot be used directly in a KML file. 
 This element is extended by the KMLCamera and KMLLookAt elements. 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLAbstractView : KMLAbstractObject


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** See KMLAbstractTimePrimitive. */
@property (strong, nonatomic) KMLAbstractTimePrimitive *timePrimitive;

@end
