//
//  KMLVec2.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLElement.h"

/** vec2 field type. 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLVec2 : KMLElement


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** x */
@property (nonatomic, assign) CGFloat x;

/** y */
@property (nonatomic, assign) CGFloat y;

/** xunits */
@property (nonatomic, assign) KMLUnits xunits;

/** yunits */
@property (nonatomic, assign) KMLUnits yunits;

@end
