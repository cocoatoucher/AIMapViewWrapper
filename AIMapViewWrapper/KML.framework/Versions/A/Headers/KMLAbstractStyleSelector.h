//
//  KMLAbstractStyleSelector.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractObject.h"

/** This is an abstract element and cannot be used directly in a KML file. 
 It is the base type for the &lt;Style&gt; and &lt;StyleMap&gt; elements. 
 The StyleMap element selects a style based on the current mode of the Placemark. 
 An element derived from StyleSelector is uniquely identified by its id and its url.
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLAbstractStyleSelector : KMLAbstractObject

@end
