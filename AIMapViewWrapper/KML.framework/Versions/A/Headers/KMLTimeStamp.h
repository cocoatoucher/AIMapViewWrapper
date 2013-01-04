//
//  KMLTimeStamp.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractTimePrimitive.h"

/** Represents a single moment in time. 
 This is a simple element and contains no children. 
 Its value is a dateTime, specified in XML time (see <a href="http://www.w3.org/TR/xmlschema-2/#isoformats" target="_blank">XML Schema Part 2: Datatypes Second Edition</a>). 
 The precision of the TimeStamp is dictated by the dateTime value in the &lt;when&gt; element. 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLTimeStamp : KMLAbstractTimePrimitive


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Specifies a single moment in time. */
@property (strong, nonatomic) NSDate *when;

@end
