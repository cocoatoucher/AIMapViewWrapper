//
//  KMLItemIcon.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractObject.h"

/** Icon used in the List view that reflects the state of a Folder or Link fetch. 
 Icons associated with the open and closed modes are used for Folders and Network Links. 
 Icons associated with the error and fetching0, fetching1, and fetching2 modes are used for Network Links. 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLItemIcon : KMLAbstractObject


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Specifies the current state of the NetworkLink or Folder. 
 
 Possible values are *open*, *closed*, *error*, *fetching0*, *fetching1*, and *fetching2*. 
 These values can be combined by inserting a space between two values (no comma). */
@property (nonatomic, assign) KMLItemIconMode state;

/** Specifies the URI of the image used in the List View for the Feature. */
@property (strong, nonatomic) NSString *href;

@end
