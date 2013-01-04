//
//  KMLListStyle.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractSubStyle.h"

@class KMLItemIcon;

/** Specifies how a Feature is displayed in the list view. 
 The list view is a hierarchy of containers and children; in Google Earth, this is the Places panel. 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLListStyle : KMLAbstractSubStyle


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Specifies how a Feature is displayed in the list view. 
 
 Possible values are:

 - *check* (default) - The Feature's visibility is tied to its item's checkbox.
 - *radioFolder* - When specified for a Container, only one of the Container's items is visible at a time
 - *checkOffOnly* - When specified for a Container or Network Link, prevents all items from being made visible at once—that is, the user can turn everything in the Container or Network Link off but cannot turn everything on at the same time. This setting is useful for Containers or Network Links containing large amounts of data.
 - *checkHideChildren* - Use a normal checkbox for visibility but do not display the Container or Network Link's children in the list view. A checkbox allows the user to toggle visibility of the child objects in the viewer.
 */
@property (nonatomic, assign) KMLListItemType listItemType;

/** Background color for the Snippet. 
 
 Color and opacity values are expressed in hexadecimal notation. 
 The range of values for any one color is 0 to 255 (00 to ff). 
 For alpha, 00 is fully transparent and ff is fully opaque. 
 The order of expression is aabbggrr, where aa=alpha (00 to ff); bb=blue (00 to ff); gg=green (00 to ff); rr=red (00 to ff). 
 For example, if you want to apply a blue color with 50 percent opacity to an overlay, you would specify the following: &lt;color&gt;7fff0000&lt;/color&gt;, where alpha=0x7f, blue=0xff, green=0x00, and red=0x00. */
@property (strong, nonatomic) NSString *bgColor;

/** Icon used in the List view that reflects the state of a Folder or Link fetch. 
 
 Icons associated with the open and closed modes are used for Folders and Network Links. 
 Icons associated with the error and fetching0, fetching1, and fetching2 modes are used for Network Links. */
@property (strong, nonatomic) KMLItemIcon *itemIcon;

@end
