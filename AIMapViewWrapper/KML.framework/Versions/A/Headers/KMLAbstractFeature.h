//
//  KMLAbstractFeature.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "KMLAbstractObject.h"

@class KMLAbstractView;
@class KMLAbstractTimePrimitive;
@class KMLRegion;
@class KMLMetadata;
@class KMLExtendedData;
@class KMLMetadata;
@class KMLStyle;
@class KMLAbstractStyleSelector;


/** This is an abstract element and cannot be used directly in a KML file. 

 The following diagram shows how some of a Feature's elements appear in Google Earth.
 
 <img src="../docs/ScreenLabels.gif" />
 
 The KML Framework follows KML standard specification. 
 You can see the Google's KML reference at http://code.google.com/apis/kml/documentation/kmlreference.html
 */
@interface KMLAbstractFeature : KMLAbstractObject


/// ---------------------------------
/// @name Accessing Properties
/// ---------------------------------

/** User-defined text displayed in the 3D viewer as the label for the object (for example, for a Placemark, Folder, or NetworkLink). */
@property (strong, nonatomic) NSString *name;

/** Boolean value. 
 
 Specifies whether the feature is drawn in the 3D viewer when it is initially loaded.
 In order for a feature to be visible, the &lt;visibility&gt; tag of all its ancestors must also be set to 1. 
 In the Google Earth List View, each Feature has a checkbox that allows the user to control visibility of the Feature. */
@property (nonatomic, assign) BOOL visibility;

/** Boolean value. 

 Specifies whether a Document or Folder appears closed or open when first loaded into the Places panel. 
 0=collapsed (the default), 1=expanded. See also KMLListStyle. 
 This element applies only to Document, Folder, and NetworkLink.
 */
@property (nonatomic, assign) BOOL open;

/** KML 2.2 supports new elements for including data about the author and related website in your KML file. 

 This information is displayed in geo search results, both in Earth browsers such as Google Earth, and in other applications such as Google Maps. 
 The ascription elements used in KML are as follows:
 
 - *atom:author element* - parent element for atom:name
 - *atom:name element* - the name of the author
 - *atom:link element* - contains the href attribute
 - *href attribute* - URL of the web page containing the KML/KMZ file
 
 These elements are defined in the Atom Syndication Format. 

 The complete specification is found at http://atompub.org.
 The &lt;atom:author&gt; element is the parent element for &lt;atom:name&gt;, which specifies the author of the KML feature.
 */
@property (strong, nonatomic) NSString *atomAuthor;

/** Specifies the URL of the website containing this KML or KMZ file. 

 Be sure to include the namespace for this element in any KML file that uses it: 
 xmlns:atom="http://www.w3.org/2005/Atom".
 */
@property (strong, nonatomic) NSString *atomLink;

/** A string value representing an unstructured address written as a standard street, city, state address, and/or as a postal code. 

 You can use the &lt;address&gt; tag to specify the location of a point instead of using latitude and longitude coordinates. 
 (However, if a KMLPoint is provided, it takes precedence over the &lt;address&gt;.) 
 To find out which locales are supported for this tag in Google Earth, go to the <a href="http://maps.google.com/support/bin/answer.py?answer=16634" target="_blank">Google Maps Help</a>.
 */
@property (strong, nonatomic) NSString *address;

/** A structured address, formatted as xAL, or eXtensible Address Language, an international standard for address formatting.

 &lt;xal:AddressDetails&gt; is used by KML for geocoding in Google Maps only. 
 For details, see the Google Maps API documentation. Currently, Google Earth does not use this element; use &lt;address&gt; instead. 
 Be sure to include the namespace for this element in any KML file that uses it: xmlns:xal="urn:oasis:names:tc:ciq:xsdschema:xAL:2.0"
 */
@property (strong, nonatomic) NSString *xalAddressDetails;

/** A string value representing a telephone number. 

 This element is used by Google Maps Mobile only. 
 The industry standard for Java-enabled cellular phones is RFC2806. 
 
 For more information, see http://www.ietf.org/rfc/rfc2806.txt. */
@property (strong, nonatomic) NSString *phoneNumber;

/** A short description of the feature. In Google Earth, this description is displayed in the Places panel under the name of the feature. 

 If a Snippet is not supplied, the first two lines of the &lt;description&gt; are used. 
 In Google Earth, if a Placemark contains both a description and a Snippet, the &lt;Snippet&gt; appears beneath the Placemark in the Places panel, and the &lt;description&gt; appears in the Placemark's description balloon. 
 This tag does not support HTML markup. 
 &lt;Snippet&gt; has a *maxLines* attribute, an integer that specifies the maximum number of lines to display.
 */
@property (strong, nonatomic) NSString *snippet;

/** User-supplied content that appears in the description balloon.

 The supported content for the &lt;description&gt; element changed from Google Earth 4.3 to 5.0. Specific information for each version is listed out below, followed by information common to both.
 
 *Google Earth 5.0*
 
 Google Earth 5.0 (and later) supports plain text content, as well as full HTML and JavaScript, within description balloons. Contents of the description tag are rendered by the WebKit open source web browser engine, and are displayed as they would be in any WebKit-based browser.
 
 *General restrictions*
 
 Links to local files are generally not allowed. This prevents malicious code from damaging your system or accessing your data. Should you wish to allow access to your local filesystem, select Preferences &gt; Allow access to local files and personal data. Links to image files on the local filesystem are always allowed, if contained within an &lt;img&gt; tag.
 
 Content that has been compressed into a KMZ file can be accessed, even if on the local filesystem.
 
 Cookies are enabled, but for the purposes of the same-origin policy, local content does not share a domain with any other content (including other local content).
 
 *HTML*

 HTML is mostly rendered as it would be in any WebKit browser.
 
 Targets are ignored when included in HTML written directly into the KML; all such links are opened as if the target is set to _blank. Any specified targets are ignored.
 
 HTML that is contained in an iFrame, however, or dynamically generated with JavaScript or DHTML, will use target="_self" as the default. Other targets can be specified and are supported.
 
 The contents of KMZ files, local anchor links, and ;flyto methods cannot be targeted from HTML contained within an iFrame.
 
 If the user specifies width="100%" for the width of an iFrame, then the iFrame's width will be dependent on all the other content in the balloon—it should essentially be ignored while calculating layout size. This rule applies to any other block element inside the balloon as well.
 
 *JavaScript*
 
 Most JavaScript is supported. Dialog boxes can not be created - functions such as alert() and prompt() will not be displayed. They will, however, be written to the system console,	as will other errors and exceptions.
 
 *CSS*
 
 CSS is allowed. As with CSS in a regular web browser, CSS can be used to style text, page elements, and to control the size and appearance of the description balloon.
 
 *Google Earth 4.3*
 
 The &lt;description&gt; element supports plain text as well as a subset of HTML formatting elements, including tables (see KML example below). It does not support other web-based technology, such as dynamic page markup (PHP, JSP, ASP), scripting languages (VBScript, Javascript), nor application languages (Java, Python). In Google Earth release 4.2, video is supported. (See Example below.)
 
 *Common information*
 
 If your description contains no HTML markup, Google Earth attempts to format it, replacing newlines with &lt;br&gt; and wrapping URLs with anchor tags. A valid URL string for the World Wide Web is automatically converted to a hyperlink to that URL (e.g., http://www.google.com). Consequently, you do not need to surround a URL with the &lt;a href="http://.."&gt;&lt;/a&gt; tags in order to achieve a simple link.
 
 When using HTML to create a hyperlink around a specific word, or when including images in the HTML, you must use HTML entity references or the CDATA element to escape angle brackets, apostrophes, and other special characters. The CDATA element tells the XML parser to ignore special characters used within the brackets. This element takes the form of:
 
     <![CDATA[
         special characters here
     ]]> 

 If you prefer not to use the CDATA element, you can use entity references to replace all the special characters.
 
     <description>
         <![CDATA[
             This is an image 
                 <img src="icon.jpg"> 
             and we have a link http://www.google.com.
         ]]>
     </description>

 Other Behavior Specified Through Use of the &lt;a&gt; Element

 KML supports the use of two attributes within the &lt;a&gt; element: *href* and *type*.
 
 The anchor element &lt;a&gt; contains an href attribute that specifies a URL.
 
 If the href is a KML file and has a .kml or .kmz file extension, Google Earth loads that file directly when the user clicks it. If the URL ends with an extension not known to Google Earth (for example, .html), the URL is sent to the browser.
 
 The href can be a fragment URL (that is, a URL with a # sign followed by a KML identifier). When the user clicks a link that includes a fragment URL, by default the browser flies to the Feature whose ID matches the fragment. If the Feature has a LookAt or Camera element, the Feature is viewed from the specified viewpoint.
 
 The behavior can be further specified by appending one of the following three strings to the fragment URL:
 
 - ;flyto (default) - fly to the Feature
 - ;balloon - open the Feature's balloon but do not fly to the Feature
 - ;balloonFlyto - open the Feature's balloon and fly to the Feature
 
 For example, the following code indicates to open the file CraftsFairs.kml, fly to the Placemark whose ID is "Albuquerque," and open its balloon:
 
     <description>
         <![CDATA[ 
             <a href="http://myServer.com/CraftsFairs.kml#Albuquerque;balloonFlyto">
             One of the Best Art Shows in the West</a>
         ]]>
     </description> 
 
 The type attribute is used within the &lt;a&gt; element when the href does not end in .kml or .kmz, but the reference needs to be interpreted in the context of KML. Specify the following:

    type="application/vnd.google-earth.kml+xml" 

 For example, the following URL uses the type attribute to notify Google Earth that it should attempt to load the file, even though the file extension is .php:
 
     <a href="myserver.com/cgi-bin/generate-kml.php#placemark123"
     type="application/vnd.google-earth.kml+xml">
 */
@property (strong, nonatomic) NSString *descriptionValue;

/** Defines a viewpoint associated with any element derived from Feature. 

 See KMLCamera and KMLLookAt. */
@property (strong, nonatomic) KMLAbstractView *abstractView;

/** Associates this Feature with a period of time (KMLTimeSpan) or a point in time (KMLTimeStamp). */
@property (strong, nonatomic) KMLAbstractTimePrimitive *timePrimitive;

/** URL of a KMLStyle or KMLStyleMap defined in a Document. 

 If the style is in the same file, use a # reference. 
 If the style is defined in an external file, use a full URL along with # referencing. 
 Examples are 

    <styleUrl>#myIconStyleID</styleUrl>
 
    <styleUrl>http://someserver.com/somestylefile.xml#restaurant</styleUrl>
 
    <styleUrl>eateries.kml#my-lunch-spot</styleUrl>
 */
@property (strong, nonatomic) NSString *styleUrl;

/** One or more Styles and StyleMaps can be defined to customize the appearance of any element derived from Feature or of the Geometry in a Placemark. 

 (See KMLBalloonStyle, KMLListStyle, KMLStyleSelector, and the styles derived from KMLColorStyle.) 
 A style defined within a Feature is called an "inline style" and applies only to the Feature that contains it. 
 A style defined as the child of a &lt;Document&gt; is called a "shared style." 
 A shared style must have an id defined for it. 
 This id is referenced by one or more Features within the &lt;Document&gt;. 
 In cases where a style element is defined both in a shared style and in an inline style for a Feature—that is, a Folder, GroundOverlay, NetworkLink, Placemark, or ScreenOverlay—the value for the Feature's inline style takes precedence over the value for the shared style. */
@property (strong, nonatomic, readonly) NSArray *styleSelectors;

/** Features and geometry associated with a Region are drawn only when the Region is active.
 
 See KMLRegion.
 */
@property (strong, nonatomic) KMLRegion *region;

/** Allows you to add custom data to a KML file.
 
 *Deprecated in KML 2.2; Use extendedData instead */
@property (strong, nonatomic) KMLMetadata *metadata;

/** Allows you to add custom data to a KML file.

 This data can be (1) data that references an external XML schema, (2) untyped data/value pairs, or (3) typed data.
 A given KML Feature can contain a combination of these types of custom data. */
@property (strong, nonatomic) KMLExtendedData *extendedData;


/// ---------------------------------
/// @name Adding StyleSelector
/// ---------------------------------

/** Inserts a given KMLAbstractStyleSelector object at the end of the styleselector array.
 @param styleSelector The KMLAbstractStyleSelector to add to the end of the styleselector array.
 */
- (void)addStyleSelector:(KMLAbstractStyleSelector *)styleSelector;

/** Adds the KMLAbstractStyleSelector objects contained in another given array to the end of the styleselector array.
 @param array An array of KMLAbstractStyleSelector objects to add to the end of the styleselector array.
 */
- (void)addStyleSelectors:(NSArray *)array;


/// ---------------------------------
/// @name Removing StyleSelector
/// ---------------------------------

/** Removes all occurrences in the styleselector array of a given KMLAbstractStyleSelector object.
 @param styleSelector The KMLAbstractStyleSelector object to remove from the styleselector array.
 */
- (void)removeStyleSelector:(KMLAbstractStyleSelector *)styleSelector;


/// ---------------------------------
/// @name Accessing Style
/// ---------------------------------

/** Returns the KMLStyle of this element.
 @return The KMLStyle object or nil if object not found.
 */
- (KMLStyle *)style;


/// ---------------------------------
/// @name Accessing ExtendedData
/// ---------------------------------

/** Returns the Data value.
 @param name The name of the Data.
 */
- (NSString *)extendedDataValueForName:(NSString *)name;


/// ---------------------------------
/// @name Adding ExtendedData
/// ---------------------------------

/** Adds Data object to ExtendedData child object of this element.
 @param name The name of the Data.
 @param value The value of the Data.
 */
- (void)addExtendedDataWithName:(NSString *)name value:(NSString *)value;


@end
