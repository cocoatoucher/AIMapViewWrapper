//
//  KMLIcon.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractObject.h"

/** Defines an image associated with an Icon style or overlay.
 The required &lt;href&gt; child element defines the location of the image to be used as the overlay or as the icon for the placemark. 
 This location can either be on a local file system or a remote web server. 
 The &lt;gx:x&gt;, &lt;gx:y&gt;, &lt;gx:w&gt;, and &lt;gx:h&gt; elements are used to select one icon from an image that contains multiple icons (often referred to as an icon palette.
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLIcon : KMLAbstractObject


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** An HTTP address or a local file specification used to load an icon. */
@property (strong, nonatomic) NSString *href;

/** see KMLLink. */
@property (nonatomic, assign) KMLRefreshMode refreshMode;

/** see KMLLink. */
@property (nonatomic, assign) CGFloat refreshInterval;

/** see KMLLink. */
@property (nonatomic, assign) KMLViewRefreshMode viewRefreshMode;

/** see KMLLink. */
@property (nonatomic, assign) CGFloat viewRefreshTime;

/** see KMLLink. */
@property (nonatomic, assign) CGFloat viewBoundScale;

/** see KMLLink. */
@property (strong, nonatomic) NSString *viewFormat;

/** see KMLLink. */
@property (strong, nonatomic) NSString *httpQuery;

@end
