//
//  KMLRoot.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLElement.h"

@class KMLNetworkLinkControl;
@class KMLAbstractFeature;
@class KMLStyle;

/** The root element of a KML file.This element is required. 
 It follows the xml declaration at the beginning of the file. 
 The hint attribute is used as a signal to Google Earth to display the file as celestial data.
 
 The &lt;kml&gt; element may also include the namespace for any external XML schemas that are referenced within the file.
 
 A basic &lt;kml&gt; element contains 0 or 1 Feature and 0 or 1 NetworkLinkControl:
 
    <kml xmlns="http://www.opengis.net/kml/2.2">
        <NetworkLinkControl> ... </NetworkLinkControl>
        <!-- 0 or 1 Feature elements -->
    </kml>
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLRoot : KMLElement

/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** The namespace for external XML schemas. */
@property (strong, nonatomic, readonly) NSString *schema;

/** The hint attribute is used as a signal to Google Earth to display the file as celestial data. */
@property (strong, nonatomic) NSString *hint;

/** The NetworkLinkControl child element of this element. */
@property (strong, nonatomic) KMLNetworkLinkControl *networkLinkControl;

/** The Feature child element of this element. */
@property (strong, nonatomic) KMLAbstractFeature *feature;


/// ---------------------------------
/// @name Placemarks
/// ---------------------------------

/** Return the all plcemarks.
 @return The KMLPlacemark objects.
 */
- (NSArray *)placemarks;

@end
