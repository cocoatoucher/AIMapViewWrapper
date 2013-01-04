//
//  KMLLink.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractObject.h"

/** &lt;Link&gt; specifies the location of any of the following:
 
 - KML files fetched by network links
 - Image files used in any Overlay (the &lt;Icon&gt; element specifies the image in an Overlay; &lt;Icon&gt; has the same fields as &lt;Link&gt;)
 - Model files used in the &lt;Model&gt; element
 
 The file is conditionally loaded and refreshed, depending on the refresh parameters supplied here. 
 Two different sets of refresh parameters can be specified: one set is based on time (&lt;refreshMode&gt; and &lt;refreshInterval&gt;) and one is based on the current "camera" view (&lt;viewRefreshMode&gt; and &lt;viewRefreshTime&gt;). 
 In addition, Link specifies whether to scale the bounding box parameters that are sent to the server (&lt;viewBoundScale&gt; and provides a set of optional viewing parameters that can be sent to the server (&lt;viewFormat&gt;) as well as a set of optional parameters containing version and language information.
 
 When a file is fetched, the URL that is sent to the server is composed of three pieces of information:
 
 - the href (Hypertext Reference) that specifies the file to load.
 - an arbitrary format string that is created from (a) parameters that you specify in the &lt;viewFormat&gt; element or (b) bounding box parameters (this is the default and is used if no &lt;viewFormat&gt; element is included in the file).
 - a second format string that is specified in the &lt;httpQuery&gt; element.
 
 If the file specified in &lt;href&gt; is a local file, the &lt;viewFormat&gt; and &lt;httpQuery&gt; elements are not used.
 
 The &lt;Link&gt; element replaces the &lt;Url&gt; element of &lt;NetworkLink&gt; contained in earlier KML releases and adds functionality for the KMLRegion element (introduced in KML 2.1). 
 In Google Earth releases 3.0 and earlier, the &lt;Link&gt; element is ignored.
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
*/
@interface KMLLink : KMLAbstractObject


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** A URL (either an HTTP address or a local file specification). 
 
 When the parent of &lt;Link&gt; is a NetworkLink, &lt;href&gt; is a KML file. 
 When the parent of &lt;Link&gt; is a Model, &lt;href&gt; is a COLLADA file. 
 When the parent of KMLIcon (same fields as &lt;Link&gt;) is an Overlay, &lt;href&gt; is an image. 
 Relative URLs can be used in this tag and are evaluated relative to the enclosing KML file. 
 See <a href="http://code.google.com/apis/kml/documentation/kmzarchives.html" target="_blank">KMZ Files</a> for details on constructing relative references in KML and KMZ files. */
@property (strong, nonatomic) NSString *href;

/** Specifies a time-based refresh mode, 
 
 which can be one of the following:
 
 - *onChange* - refresh when the file is loaded and whenever the Link parameters change (the default).
 - *onInterval* - refresh every n seconds (specified in &lt;refreshInterval&gt;).
 - *onExpire* - refresh the file when the expiration time is reached. If a fetched file has a NetworkLinkControl, the &lt;expires&gt; time takes precedence over expiration times specified in HTTP headers. If no &lt;expires&gt; time is specified, the HTTP max-age header is used (if present). If max-age is not present, the Expires HTTP header is used (if present). (See Section RFC261b of the Hypertext Transfer Protocol - HTTP 1.1 for details on HTTP header fields.) 
 */
@property (nonatomic, assign) KMLRefreshMode refreshMode;

/** Indicates to refresh the file every n seconds. */
@property (nonatomic, assign) CGFloat refreshInterval;

/** Specifies how the link is refreshed when the "camera" changes.

 Can be one of the following:
 
 - *never* (default) - Ignore changes in the view. Also ignore &lt;viewFormat&gt; parameters, if any.
 - *onStop* - Refresh the file n seconds after movement stops, where n is specified in &lt;viewRefreshTime&gt;.
 - *onRequest* - Refresh the file only when the user explicitly requests it. (For example, in Google Earth, the user right-clicks and selects Refresh in the Context menu.)
 - *onRegion* - Refresh the file when the Region becomes active. See KMLRegion. 
 */
@property (nonatomic, assign) KMLViewRefreshMode viewRefreshMode;

/** After camera movement stops, specifies the number of seconds to wait before refreshing the view. 
 
 (See &lt;viewRefreshMode&gt; and *onStop* above.) */
@property (nonatomic, assign) CGFloat viewRefreshTime;

/** Scales the BBOX parameters before sending them to the server. 
 
 A value less than 1 specifies to use less than the full view (screen). 
 A value greater than 1 specifies to fetch an area that extends beyond the edges of the current view. */
@property (nonatomic, assign) CGFloat viewBoundScale;

/** Specifies the format of the query string that is appended to the Link's &lt;href&gt; before the file is fetched.
 
 (If the &lt;href&gt; specifies a local file, this element is ignored.)

 If you specify a &lt;viewRefreshMode&gt; of onStop and do not include the &lt;viewFormat&gt; tag in the file, the following information is automatically appended to the query string:
 
 - *BBOX=[bboxWest],[bboxSouth],[bboxEast],[bboxNorth]*
 
 This information matches the Web Map Service (WMS) bounding box specification.

 If you specify an empty &lt;viewFormat&gt; tag, no information is appended to the query string.
 
 You can also specify a custom set of viewing parameters to add to the query string. If you supply a format string, it is used *instead of* the BBOX information. 
 If you also want the BBOX information, you need to add those parameters along with the custom parameters.
 
 You can use any of the following parameters in your format string (and Google Earth will substitute the appropriate current value at the time it creates the query string):
 
 - *[lookatLon], [lookatLat]* - longitude and latitude of the point that &lt;LookAt&gt; is viewing
 - *[lookatRange], [lookatTilt], [lookatHeading]* - values used by the &lt;LookAt&gt; element (see descriptions of &lt;range&gt;, &lt;tilt&gt;, and &lt;heading&gt; in KMLLookAt)
 - *[lookatTerrainLon], [lookatTerrainLat], [lookatTerrainAlt]* - point on the terrain in degrees/meters that &lt;LookAt&gt; is viewing
 - *[cameraLon], [cameraLat], [cameraAlt]* - degrees/meters of the eyepoint for the camera
 - *[horizFov], [vertFov]* - horizontal, vertical field of view for the camera
 - *[horizPixels], [vertPixels]* - size in pixels of the 3D viewer
 - *[terrainEnabled]* - indicates whether the 3D viewer is showing terrain
 */
@property (strong, nonatomic) NSString *viewFormat;

/** Appends information to the query string, based on the parameters specified. 
 
 (Google Earth substitutes the appropriate current value at the time it creates the query string.) 
 The following parameters are supported:
 
 - *[clientVersion]*
 - *[kmlVersion]*
 - *[clientName]*
 - *[language]*
 */
@property (strong, nonatomic) NSString *httpQuery;

@end
