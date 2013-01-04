//
//  KMLFolder.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractContainer.h"

/** A Folder is used to arrange other Features hierarchically (Folders, Placemarks, NetworkLinks, or Overlays). 
 A Feature is visible only if it and all its ancestors are visible. 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLFolder : KMLAbstractContainer

@end
