//
//  KMLType.h
//  KML Framework
//
//  Created by NextBusinessSystem on 12/04/06.
//  Copyright (c) 2012 NextBusinessSystem Co., Ltd. All rights reserved.
//

typedef enum KMLAltitudeMode {
    KMLAltitudeModeClampToGround = 0,
    KMLAltitudeModeRelativeToGround,
    KMLAltitudeModeAbsolute,
} KMLAltitudeMode;

typedef enum KMLColorMode {
    KMLColorModeNormal = 0,
    KMLColorModeRandom,
} KMLColorMode;

typedef enum KMLDisplayMode {
    KMLDisplayModeDefault = 0,
    KMLDisplayModeHide,
} KMLDisplayMode;

typedef enum KMLRefreshMode {
    KMLRefreshModeOnChange = 0,
    KMLRefreshModeOnInterval,
    KMLRefreshModeOnExpire,
} KMLRefreshMode;

typedef enum KMLShape {
    KMLShapeRectangle = 0,
    KMLShapeCylinder,
    KMLShapeSphere,
} KMLShape;

typedef enum KMLStyleState {
    KMLStyleStateNormal = 0,
    KMLStyleStateHighlight,
} KMLStyleState;

typedef enum KMLUnits {
    KMLUnitsFraction = 0,
    KMLUnitsPixels,
    KMLUnitsInsetPixels
} KMLUnits;

typedef enum KMLViewRefreshMode {
	KMLViewRefreshModeNever = 0,
    KMLViewRefreshModeOnRequest,
    KMLViewRefreshModeOnStop,
    KMLViewRefreshModeOnRegion,
} KMLViewRefreshMode;

typedef enum KMLListItemType {
    KMLListItemTypeCheck = 0,
    KMLListItemTypeRadioFolder,
    KMLListItemTypeCheckOffOnly,
    KMLListItemTypeCheckHideChildren,
} KMLListItemType;

typedef enum KMLItemIconMode {
    KMLItemIconModeOpen = 0,
    KMLItemIconModeClosed,
    KMLItemIconModeError,
    KMLItemIconModeFetching0,
    KMLItemIconModeFetching1,
    KMLItemIconModeFetching2,
} KMLItemIconMode;

typedef enum KMLGridOrigin {
    KMLGridOriginLowerLeft = 0,
    KMLGridOriginUpperLeft,
} KMLGridOrigin;


/** Convinience methods for KML Value types.
 */
@interface KMLType : NSObject


/// ---------------------------------
/// @name Field elment types
/// ---------------------------------

/** Return the KMLAltitudeMode object from a given string.
 @param value The string which to convert KMLAltitudeMode.
 @return A KMLAltitudeMode from a value.
 */
+ (KMLAltitudeMode)altitudeMode:(NSString *)value;

/** Return the NSString object from a given KMLALtitudeMode.
 @param altitudeMode The AltitudeMode which to convert NSString.
 @return A NSString from a altitudeMode.
 */
+ (NSString *)valueForAltitudeMode:(KMLAltitudeMode)altitudeMode;

/** Return the KMLColorMode object from a given string.
 @param value The string which to convert KMLColorMode.
 @return A KMLColorMode from a value.
 */
+ (KMLColorMode)colorMode:(NSString *)value;

/** Return the NSString object from a given KMLColorMode.
 @param colorMode The KMLColorMode which to convert NSString.
 @return A NSString from a colorMode.
 */
+ (NSString *)valueForColorMode:(KMLColorMode)colorMode;

/** Return the KMLDisplayMode object from a given string.
 @param value The string which to convert KMLDisplayMode.
 @return A KMLDisplayMode from a value.
 */
+ (KMLDisplayMode)displayMode:(NSString *)value;

/** Return the NSString object from a given KMLDisplayMode.
 @param displayMode The KMLDisplayMode which to convert NSString.
 @return A NSString from a displayMode.
 */
+ (NSString *)valueForDisplayMode:(KMLDisplayMode)displayMode;

/** Return the KMLRefreshMode object from a given string.
 @param value The string which to convert KMLRefreshMode.
 @return A KMLRefreshMode from a value.
 */
+ (KMLRefreshMode)refreshMode:(NSString *)value;

/** Return the NSString object from a given KMLRefreshMode.
 @param refreshMode The KMLRefreshMode which to convert NSString.
 @return A NSString from a refreshMode.
 */
+ (NSString *)valueForRefreshMode:(KMLRefreshMode)refreshMode;

/** Return the KMLShape object from a given string.
 @param value The string which to convert KMLShape.
 @return A KMLShape from a value.
 */
+ (KMLShape)shape:(NSString *)value;

/** Return the NSString object from a given KMLShape.
 @param shape The KMLShape which to convert NSString.
 @return A NSString from a shape.
 */
+ (NSString *)valueForShape:(KMLShape)shape;

/** Return the KMLStyleState object from a given string.
 @param value The string which to convert KMLStyleState.
 @return A KMLStyleState from a value.
 */
+ (KMLStyleState)styleState:(NSString *)value;

/** Return the NSString object from a given KMLStyleState.
 @param styleState The KMLStyleState which to convert NSString.
 @return A NSString from a styleState.
 */
+ (NSString *)valueForStyleState:(KMLStyleState)styleState;

/** Return the KMLUnits object from a given string.
 @param value The string which to convert KMLUnits.
 @return A KMLUnits from a value.
 */
+ (KMLUnits)units:(NSString *)value;

/** Return the NSString object from a given KMLUnits.
 @param units The KMLUnits which to convert NSString.
 @return A NSString from a units.
 */
+ (NSString *)valueForUnits:(KMLUnits)units;

/** Return the KMLViewRefreshMode object from a given string.
 @param value The string which to convert KMLViewRefreshMode.
 @return A KMLViewRefreshMode from a value.
 */
+ (KMLViewRefreshMode)viewRefreshMode:(NSString *)value;

/** Return the NSString object from a given KMLViewRefreshMode.
 @param viewRefreshMode The KMLViewRefreshMode which to convert NSString.
 @return A NSString from a viewRefreshMode.
 */
+ (NSString *)valueForViewRefreshMode:(KMLViewRefreshMode)viewRefreshMode;

/** Return the KMLListItemType object from a given string.
 @param value The string which to convert KMLListItemType.
 @return A KMLListItemType from a value.
 */
+ (KMLListItemType)listItemType:(NSString *)value;

/** Return the NSString object from a given KMLListItemType.
 @param listItemType The KMLListItemType which to convert NSString.
 @return A NSString from a listItemType.
 */
+ (NSString *)valueForListItemType:(KMLListItemType)listItemType;

/** Return the KMLItemIconMode object from a given string.
 @param value The string which to convert KMLItemIconMode.
 @return A KMLItemIconMode from a value.
 */
+ (KMLItemIconMode)itemIconMode:(NSString *)value;

/** Return the NSString object from a given KMLItemIconMode.
 @param itemIconMode The KMLItemIconMode which to convert NSString.
 @return A NSString from a itemIconMode.
 */
+ (NSString *)valueForItemIconMode:(KMLItemIconMode)itemIconMode;

/** Return the KMLGridOrigin object from a given string.
 @param value The string which to convert KMLGridOrigin.
 @return A KMLGridOrigin from a value.
 */
+ (KMLGridOrigin)gridOrigin:(NSString *)value;

/** Return the NSString object from a given KMLGridOrigin.
 @param gridOrigin The KMLGridOrigin which to convert NSString.
 @return A NSString from a gridOrigin.
 */
+ (NSString *)valueForGridOrigin:(KMLGridOrigin)gridOrigin;

/** Return the NSDate object from a given string.
 
 pecifies a single moment in time. The value is a dateTime, which can be one of the following:

 - *gYear* gives year resolution
 - *gYearMonth* gives month resolution
 - *date gives* day resolution
 - *dateTime* gives second resolution

 
 *gYear (YYYY)*

    <TimeStamp>
        <when>1997</when>
    </TimeStamp>

 *gYearMonth (YYYY-MM)*

    <TimeStamp>
        <when>1997-07</when>
    </TimeStamp> 

 *date (YYYY-MM-DD)*
 
    <TimeStamp>
        <when>1997-07-16</when>
    </TimeStamp> 
 
 *dateTime (YYYY-MM-DDThh:mm:ssZ)*

 Here, T is the separator between the calendar and the hourly notation of time, and Z indicates UTC. (Seconds are required.)
 
    <TimeStamp>
        <when>1997-07-16T07:30:15Z</when>
    </TimeStamp>
 
 *dateTime (YYYY-MM-DDThh:mm:sszzzzzz)*

 This example gives the local time and then the ± conversion to UTC.
 
    <TimeStamp>
        <when>1997-07-16T10:30:15+03:00</when>
    </TimeStamp>
 
 @param value The string which to convert NSDate.
 @return A NSDate from a value.
 */
+ (NSDate *)dateTime:(NSString *)value;

/** Return the NSString object from a given NSDate.
 @param date The NSDate which to convert NSString.
 @return A dateTime (YYYY-MM-DDThh:mm:ssZ) value from a date.
 */
+ (NSString *)valueForDateTime:(NSDate *)date;

/** Return the BOOL object from a given string.
 @param value The string which to convert BOOL.
 @return A BOOL from a value.
 */
+ (BOOL)boolean:(NSString *)value;

/** Return the BOOL object from a given string.
 @param value The string which to convert BOOL.
 @param defaultValue The BOOL value for default.
 @return A BOOL from a value or defaultValue if value is nil.
 */
+ (BOOL)boolean:(NSString *)value defaultValue:(BOOL)defaultValue;

/** Return the NSString object from a given BOOL.
 @param boolean The BOOL which to convert NSString.
 @return A NSString from a boolean.
 */
+ (NSString *)valueForBoolean:(BOOL)boolean;

/** Return the CGFloat object from a given string.
 @param value The string which to convert CGFloat. A value ≥−90 and ≤90.
 @return A CGFloat from a value.
 */
+ (CGFloat)angle90:(NSString *)value;

/** Return the NSString object from a given CGFloat.
 @param angle90 The CGFloat which to convert NSString. A value ≥−90 and ≤90.
 @return A NSString from a angle90.
 */
+ (NSString *)valueForAngle90:(CGFloat)angle90;

/** Return the CGFloat object from a given string.
 @param value The string which to convert CGFloat. A value ≥0 and ≤90.
 @return A CGFloat from a value.
 */
+ (CGFloat)anglepos90:(NSString *)value;

/** Return the NSString object from a given CGFloat.
 @param anglepos90 The CGFloat which to convert NSString. A value ≥0 and ≤90.
 @return A NSString from a anglepos90.
 */
+ (NSString *)valueForAnglepos90:(CGFloat)anglepos90;

/** Return the CGFloat object from a given string.
 @param value The string which to convert CGFloat. A value ≥−180 and ≤180.
 @return A CGFloat from a value.
 */
+ (CGFloat)angle180:(NSString *)value;

/** Return the NSString object from a given CGFloat.
 @param angle180 The CGFloat which to convert NSString. A value ≥−180 and ≤180.
 @return A NSString from a angle180.
 */
+ (NSString *)valueForAngle180:(CGFloat)angle180;

/** Return the CGFloat object from a given string.
 @param value The string which to convert CGFloat. A value ≥0 and ≤180.
 @return A CGFloat from a value.
 */
+ (CGFloat)anglepos180:(NSString *)value;

/** Return the NSString object from a given CGFloat.
 @param anglepos180 The CGFloat which to convert NSString. A value ≥0 and ≤180.
 @return A NSString from a anglepos180.
 */
+ (NSString *)valueForAnglepos180:(CGFloat)anglepos180;

/** Return the CGFloat object from a given string.
 @param value The string which to convert CGFloat. A value ≥−360 and ≤360.
 @return A CGFloat from a value.
 */
+ (CGFloat)angle360:(NSString *)value;

/** Return the NSString object from a given CGFloat.
 @param angle360 The CGFloat which to convert NSString. A value ≥−360 and ≤360.
 @return A NSString from a angle360.
 */
+ (NSString *)valueForAngle360:(CGFloat)angle360;

@end
