//
//  KMLCreate.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLElement.h"

@class KMLAbstractContainer;

/** Adds new elements to a Folder or Document that has already been loaded via a KMLNetworkLink.
 The &lt;targetHref&gt; element in KMLUpdate specifies the URL of the .kml or .kmz file that contained the original Folder or Document. 
 Within that file, the Folder or Document that is to contain the new data must already have an explicit id defined for it. 
 This id is referenced as the targetId attribute of the Folder or Document within &lt;Create&gt; that contains the element to be added.
 Once an object has been created and loaded into Google Earth, it takes on the URL of the original parent Document of Folder. 
 To perform subsequent updates to objects added with this Update/Create mechanism, set &lt;targetHref&gt; to the URL of the original Document or Folder (not the URL of the file that loaded the intervening updates). 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLCreate : KMLElement


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** The Container child elements of this element. */
@property (strong, nonatomic) KMLAbstractContainer *container;

@end
