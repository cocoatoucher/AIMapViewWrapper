//
//  KMLStyle.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractStyleSelector.h"

@class KMLIconStyle;
@class KMLLabelStyle;
@class KMLLineStyle;
@class KMLPolyStyle;
@class KMLBalloonStyle;
@class KMLListStyle;

/** A Style defines an addressable style group that can be referenced by StyleMaps and Features. 
 Styles affect how Geometry is presented in the 3D viewer and how Features appear in the Places panel of the List view. 
 Shared styles are collected in a &lt;Document&gt; and must have an id defined for them so that they can be referenced by the individual Features that use them.

 Use an id to refer to the style from a &lt;styleUrl&gt;. 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLStyle : KMLAbstractStyleSelector


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** See KMLIconStyle. */
@property (strong, nonatomic) KMLIconStyle *iconStyle;

/** See KMLLabelStyle. */
@property (strong, nonatomic) KMLLabelStyle *labelStyle;

/** See KMLLineStyle. */
@property (strong, nonatomic) KMLLineStyle *lineStyle;

/** See KMLPolyStyle. */
@property (strong, nonatomic) KMLPolyStyle *polyStyle;

/** See KMLBalloonStyle. */
@property (strong, nonatomic) KMLBalloonStyle *balloonStyle;

/** See KMLListStyle. */
@property (strong, nonatomic) KMLListStyle *listStyle;

@end
