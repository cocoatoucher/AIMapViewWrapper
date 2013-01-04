//
//  KMLPair.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractObject.h"

@class KMLStyle;

/** Defines a key/value pair that maps a mode (normal or highlight) to the predefined &lt;styleUrl&gt;. 
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLPair : KMLAbstractObject


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** Identifies the key. */
@property (strong, nonatomic) NSString *key;

/** References the style. 
 
 In &lt;styleUrl&gt;, for referenced style elements that are local to the KML document, a simple # referencing is used. 
 For styles that are contained in external files, use a full URL along with # referencing. 
 For example:
 
     <Pair> 
         <key>normal</key> 
         <styleUrl>http://myserver.com/populationProject.xml#example_style_off</styleUrl> 
     </Pair> 
 */
@property (strong, nonatomic) NSString *styleUrl;

/** References the style.
 
 See KMLStyle.*/
@property (strong, nonatomic) KMLStyle *style;

@end
