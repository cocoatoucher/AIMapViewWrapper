//
//  KMLDelete.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLElement.h"

@class KMLAbstractFeature;

/** Deletes features from a complex element that has already been loaded via a KMLNetworkLink. 
 The &lt;targetHref&gt; element in KMLUpdate specifies the .kml or .kmz file containing the data to be deleted. 
 Within that file, the element to be deleted must already have an explicit id defined for it. 
 The &lt;Delete&gt; element references this id in the targetId attribute.
 Child elements for &lt;Delete&gt;, which are the only elements that can be deleted, are Document, Folder, GroundOverlay, Placemark, and ScreenOverlay. 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLDelete : KMLElement


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** The Feature child elements of this element. */
@property (strong, nonatomic) KMLAbstractFeature *feature;

@end
