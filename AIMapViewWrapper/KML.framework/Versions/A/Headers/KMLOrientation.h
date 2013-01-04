//
//  KMLOrientation.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractObject.h"

/** Describes rotation of a 3D model's coordinate system to position the object in Google Earth. 
 
     <Orientation> 
         <heading>45.0</heading> 
         <tilt>10.0</tilt> 
         <roll>0.0</roll> 
     </Orientation> 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLOrientation : KMLAbstractObject


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Rotation about the z axis (normal to the Earth's surface). A value of 0 (the default) equals North. 
 
 A positive rotation is clockwise around the z axis and specified in degrees from 0 to 360. */
@property (nonatomic, assign) CGFloat heading;

/** Rotation about the x axis. 
 
 A positive rotation is clockwise around the x axis and specified in degrees from 0 to 180. */
@property (nonatomic, assign) CGFloat tilt;

/** Rotation about the y axis. 
 
 A positive rotation is clockwise around the y axis and specified in degrees from 0 to 180. */
@property (nonatomic, assign) CGFloat roll;

@end
