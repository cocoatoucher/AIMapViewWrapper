//
//  AIRoute.m
//  AIMapViewWrapper
//
//  Created by CocoaToucher on 12/24/12.
//  Copyright (c) 2012 CocoaToucher. All rights reserved.
//

#import "AIRoute.h"

@interface AIRoute ()

@property(nonatomic, strong, readwrite) NSArray *coordinates;
@property(nonatomic, readwrite) MKMapRect boundingMapRect;

@end

@implementation AIRoute

+ (AIRoute *)routeWithCoordinates:(NSArray *)inCoordinates {
	AIRoute *result = [[AIRoute alloc] init];
#if !(__has_feature(objc_arc))
	[result autorelease];
#endif
	result.coordinates = inCoordinates;
	
	return result;
}

- (void)setCoordinates:(NSArray *)coordinates {
	if (coordinates != _coordinates) {
#if !(__has_feature(objc_arc))
		[_coordinates release];
		_coordinates = [coordinates retain];
#else
		_coordinates = coordinates;
#endif
	}
	
	CLLocationCoordinate2D leftMostCoordinate = CLLocationCoordinate2DMake(0, 0);
	CLLocationCoordinate2D bottomCoordinate = CLLocationCoordinate2DMake(0, 0);
	CLLocationCoordinate2D topCoordinate = CLLocationCoordinate2DMake(0, 0);
	CLLocationCoordinate2D rightMostCoordinate = CLLocationCoordinate2DMake(0, 0);
	
	CLLocationDegrees minLat = 90;
	CLLocationDegrees minLon = 180;
	CLLocationDegrees maxLat = -90;
	CLLocationDegrees maxLon = -180;
	
	for (int idx = 0; idx < _coordinates.count; idx++) {
		CLLocation *currentLocation = [_coordinates objectAtIndex:idx];
		
		if(currentLocation.coordinate.latitude > maxLat) {
			maxLat = currentLocation.coordinate.latitude;
			topCoordinate.latitude = maxLat;
			topCoordinate.longitude = currentLocation.coordinate.longitude;
		}
		if(currentLocation.coordinate.latitude < minLat) {
			minLat = currentLocation.coordinate.latitude;
			bottomCoordinate.latitude = minLat;
			bottomCoordinate.longitude = currentLocation.coordinate.longitude;
		}
		if(currentLocation.coordinate.longitude > maxLon) {
			maxLon = currentLocation.coordinate.longitude;
			rightMostCoordinate.longitude = maxLon;
			rightMostCoordinate.latitude = currentLocation.coordinate.latitude;
		}
		if(currentLocation.coordinate.longitude < minLon) {
			minLon = currentLocation.coordinate.longitude;
			leftMostCoordinate.longitude = minLon;
			leftMostCoordinate.latitude = currentLocation.coordinate.latitude;
		}
	}
	
	CLLocationCoordinate2D upperLeftCoord = CLLocationCoordinate2DMake(topCoordinate.latitude, leftMostCoordinate.longitude);
	MKMapPoint upperLeftPoint = MKMapPointForCoordinate(upperLeftCoord);
	
	CLLocationCoordinate2D bottomRightCoord = CLLocationCoordinate2DMake(bottomCoordinate.latitude, rightMostCoordinate.longitude);
	MKMapPoint bottomRightPoint = MKMapPointForCoordinate(bottomRightCoord);
	
	MKMapRect boundingRect = MKMapRectNull;
	boundingRect.origin.x = upperLeftPoint.x;
	boundingRect.origin.y = upperLeftPoint.y;
	boundingRect.size.width = fabs(upperLeftPoint.x - bottomRightPoint.x);
	boundingRect.size.height = fabs(upperLeftPoint.y - bottomRightPoint.y);
	self.boundingMapRect = boundingRect;
}

- (CLLocationCoordinate2D)coordinate {
	
	MKMapRect boundingRect = [self boundingMapRect];
	MKMapPoint center = MKMapPointMake(boundingRect.origin.x + boundingRect.size.width / 2.0f, boundingRect.origin.y + boundingRect.size.height / 2.0f);
	
	return MKCoordinateForMapPoint(center);
}

@end
