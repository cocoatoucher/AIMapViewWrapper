//
//  KMLChange.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLElement.h"

@class KMLAbstractObject;

/** Modifies the values in an element that has already been loaded with a KMLNetworkLink. 
 Within the Change element, the child to be modified must include a targetId attribute that references the original element's id.
 This update can be considered a "sparse update": in the modified element, only the values listed in &lt;Change&gt; are replaced; all other values remained untouched. 
 When &lt;Change&gt; is applied to a set of coordinates, the new coordinates replace the current coordinates.
 Children of this element are the element(s) to be modified, which are identified by the targetId attribute. 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLChange : KMLElement


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** The Object child elements of this element. */
@property (strong, nonatomic) KMLAbstractObject *object;

@end
