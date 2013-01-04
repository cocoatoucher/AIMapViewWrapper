//
//  KMLNetworkLink.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractFeature.h"

@class KMLLink;

/** References a KML file or KMZ archive on a local or remote network. 
 Use the KMLLink element to specify the location of the KML file. 
 Within that element, you can define the refresh options for updating the file, based on time and camera change. 
 NetworkLinks can be used in combination with Regions to handle very large datasets efficiently.
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLNetworkLink : KMLAbstractFeature

/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Boolean value. 
 
 A value of 0 leaves the visibility of features within the control of the Google Earth user. 
 Set the value to 1 to reset the visibility of features each time the NetworkLink is refreshed. 
 For example, suppose a Placemark within the linked KML file has &lt;visibility&gt; set to 1 and the NetworkLink has &lt;refreshVisibility&gt; set to 1. 
 When the file is first loaded into Google Earth, the user can clear the check box next to the item to turn off display in the 3D viewer. 
 However, when the NetworkLink is refreshed, the Placemark will be made visible again, since its original visibility state was TRUE.*/
@property (nonatomic, assign) BOOL refreshVisibility;

/** Boolean value.
 
 A value of 1 causes Google Earth to fly to the view of the LookAt or Camera in the NetworkLinkControl (if it exists). 
 If the NetworkLinkControl does not contain an AbstractView element, Google Earth flies to the LookAt or Camera element in the Feature child within the &lt;kml&gt; element in the refreshed file. 
 If the &lt;kml&gt; element does not have a LookAt or Camera specified, the view is unchanged. 
 For example, Google Earth would fly to the &lt;LookAt&gt; view of the parent Document, not the &lt;LookAt&gt; of the Placemarks contained within the Document. */
@property (nonatomic, assign) BOOL flyToView;

/** (required). See KMLLink.
 @warning *tip:* To display the top-level Folder or Document within a Network Link in the List View, assign an ID to the Folder or Document. Without this ID, only the child object names are displayed in the List View.
 */
@property (strong, nonatomic) KMLLink *link;

@end
