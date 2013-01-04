//
//  KMLRegion.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractObject.h"

@class KMLLatLonAltBox;
@class KMLLod;

/** A region contains a bounding box (KMLLatLonAltBox) that describes an area of interest defined by geographic coordinates and altitudes. 
 In addition, a Region contains an LOD (level of detail) extent (KMLLod) that defines a validity range of the associated Region in terms of projected screen size. 
 A Region is said to be "active" when the bounding box is within the user's view and the LOD requirements are met. 
 Objects associated with a Region are drawn only when the Region is active. 
 When the &lt;viewRefreshMode&gt; is onRegion, the Link or Icon is loaded only when the Region is active. 
 See the "Topics in KML" page on <a href="http://code.google.com/intl/en/apis/kml/documentation/regions.html" target="_blank">Regions</a> for more details. 
 In a Container or NetworkLink hierarchy, this calculation uses the Region that is the closest ancestor in the hierarchy. 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLRegion : KMLAbstractObject


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** See KMLLatLonAltBox. */
@property (strong, nonatomic) KMLLatLonAltBox *latLonAltBox;

/** See KMLLod. */
@property (strong, nonatomic) KMLLod *lod;

@end
