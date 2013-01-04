//
//  KMLLod.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractObject.h"

/** Lod is an abbreviation for Level of Detail. 
 &lt;Lod&gt; describes the size of the projected region on the screen that is required in order for the region to be considered "active." 
 Also specifies the size of the pixel ramp used for fading in (from transparent to opaque) and fading out (from opaque to transparent). 
 See diagram below for a visual representation of these parameters.

     <Lod>
         <minLodPixels>256</minLodPixels>
         <maxLodPixels>-1</maxLodPixels>
         <minFadeExtent>0</minFadeExtent>
         <maxFadeExtent>0</maxFadeExtent>
     </Lod>
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLLod : KMLAbstractObject


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Measurement in screen pixels that represents the minimum limit of the visibility range for a given Region. 

 Google Earth calculates the size of the Region when projected onto screen space. 
 Then it computes the square root of the Region's area 
 (if, for example, the Region is square and the viewpoint is directly above the Region, and the Region is not tilted, this measurement is equal to the width of the projected Region). 
 If this measurement falls within the limits defined by &lt;minLodPixels&gt; and &lt;maxLodPixels&gt; (and if the &lt;LatLonAltBox&gt; is in view), the Region is active. 
 If this limit is not reached, the associated geometry is considered to be too far from the user's viewpoint to be drawn.
 */
@property (nonatomic, assign) CGFloat minLodPixels;

/** Measurement in screen pixels that represents the maximum limit of the visibility range for a given Region. 
 
 A value of −1, the default, indicates "active to infinite size." */
@property (nonatomic, assign) CGFloat maxLodPixels;

/** Distance over which the geometry fades, from fully opaque to fully transparent. 
 
 This ramp value, expressed in screen pixels, is applied at the minimum end of the LOD (visibility) limits.*/
@property (nonatomic, assign) CGFloat minFadeExtent;

/** Distance over which the geometry fades, from fully transparent to fully opaque. 
 
 This ramp value, expressed in screen pixels, is applied at the maximum end of the LOD (visibility) limits. */
@property (nonatomic, assign) CGFloat maxFadeExtent;

@end
