//
//  KMLNetworkLinkControl.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLElement.h"

@class KMLUpdate;
@class KMLAbstractView;

/** Controls the behavior of files fetched by a KMLNetworkLink. 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLNetworkLinkControl : KMLElement


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Specified in seconds, &lt;minRefreshPeriod&gt; is the minimum allowed time between fetches of the file. 
 
 This parameter allows servers to throttle fetches of a particular file and to tailor refresh rates to the expected rate of change to the data. 
 For example, a user might set a link refresh to 5 seconds, but you could set your minimum refresh period to 3600 to limit refresh updates to once every hour. */
@property (nonatomic, assign) CGFloat minRefreshPeriod;

/** Specified in seconds, &lt;maxSessionLength&gt; is the maximum amount of time for which the client NetworkLink can remain connected. 

 The default value of -1 indicates not to terminate the session explicitly. */
@property (nonatomic, assign) CGFloat maxSessionLength;

/** Use this element to append a string to the URL query on the next refresh of the network link. 
 
 You can use this data in your script to provide more intelligent handling on the server side, including version querying and conditional file delivery. */
@property (strong, nonatomic) NSString *cookie;

/** You can deliver a pop-up message, such as usage guidelines for your network link. 
 
 The message appears when the network link is first loaded into Google Earth, or when it is changed in the network link control. */
@property (strong, nonatomic) NSString *message;

/** You can control the name of the network link from the server, so that changes made to the name on the client side are overridden by the server. */
@property (strong, nonatomic) NSString *linkName;

/** You can control the description of the network link from the server, so that changes made to the description on the client side are overridden by the server. */
@property (strong, nonatomic) NSString *linkDescription;

/** You can control the snippet for the network link from the server, so that changes made to the snippet on the client side are overridden by the server.

 &lt;linkSnippet&gt; has a maxLines attribute, an integer that specifies the maximum number of lines to display. */
@property (strong, nonatomic) NSString *linkSnippet;

/** You can specify a date/time at which the link should be refreshed. 
 
 This specification takes effect only if the &lt;refreshMode&gt; in &lt;Link&gt; has a value of onExpire. 
 See &lt;refreshMode&gt; */
@property (strong, nonatomic) NSDate *expires;

/** With KMLUpdate, you can specify any number of Change, Create, and Delete tags for a .kml file or .kmz archive that has previously been loaded with a network link. 

 See KMLUpdate. */
@property (strong, nonatomic) KMLUpdate *update;

/** See KMLAbstractView. */
@property (strong, nonatomic) KMLAbstractView *abstractView;

@end
