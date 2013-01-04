//
//  KMLScale.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractObject.h"

/** Scales a model along the x, y, and z axes in the model's coordinate space. 

     <Scale>
         <x>2.5</x>
         <y>2.5</y>
         <z>3.5</z>
     </Scale>
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLScale : KMLAbstractObject


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** x */
@property (nonatomic, assign) CGFloat x;

/** y */
@property (nonatomic, assign) CGFloat y;

/** z */
@property (nonatomic, assign) CGFloat z;

@end
