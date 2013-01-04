//
//  KMLTimeSpan.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractTimePrimitive.h"

/** Represents an extent in time bounded by begin and end dateTimes.
 If &lt;begin&gt; or &lt;end&gt; is missing, then that end of the period is unbounded (see Example below).
 The dateTime is defined according to XML Schema time (see <a href="http://www.w3.org/TR/xmlschema-2/#isoformats" target="_blank">XML Schema Part 2: Datatypes Second Edition</a>).
 The value can be expressed as yyyy-mm-ddThh:mm:sszzzzzz, where T is the separator between the date and the time, and the time zone is either Z (for UTC) or zzzzzz, which represents ±hh:mm in relation to UTC. 
 Additionally, the value can be expressed as a date only. 
 See KMLTimeStamp for examples.
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLTimeSpan : KMLAbstractTimePrimitive


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Describes the beginning instant of a time period. 
 
 If absent, the beginning of the period is unbounded. */
@property (strong, nonatomic) NSDate *begin;

/** Describes the ending instant of a time period. 
 
 If absent, the end of the period is unbounded. */
@property (strong, nonatomic) NSDate *end;

@end
