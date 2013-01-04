//
//  KMLViewVolume.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLElement.h"

/** Defines how much of the current scene is visible. 
 Specifying the field of view is analogous to specifying the lens opening in a physical camera. 
 A small field of view, like a telephoto lens, focuses on a small part of the scene. 
 A large field of view, like a wide-angle lens, focuses on a large part of the scene. 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLViewVolume : KMLElement


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Angle, in degrees, between the camera's viewing direction and the left side of the view volume. */
@property (nonatomic, assign) CGFloat leftFov;

/** Angle, in degrees, between the camera's viewing direction and the right side of the view volume. */
@property (nonatomic, assign) CGFloat rightFov;

/** Angle, in degrees, between the camera's viewing direction and the bottom side of the view volume. */
@property (nonatomic, assign) CGFloat bottomFov;

/** Angle, in degrees, between the camera's viewing direction and the top side of the view volume. */
@property (nonatomic, assign) CGFloat topFov;

/** Measurement in meters along the viewing direction from the camera viewpoint to the PhotoOverlay shape. */
@property (nonatomic, assign) CGFloat near;

@end
