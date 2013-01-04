//
//  AISampleViewController.m
//  AIMapViewWrapper
//
//  Created by CocoaToucher on 12/19/12.
//  Copyright (c) 2012 CocoaToucher. All rights reserved.
//

#import "AISampleViewController.h"
#import "AIMapViewWrapper.h"
#import <CoreLocation/CoreLocation.h>
#import "AIOverlayRouteView.h"
#import "AIRoute.h"
#import <QuartzCore/QuartzCore.h>
#import <KML/KML.h>


@interface AISampleViewController () < MKMapViewDelegate, AIMapViewWrapperDelegate, AIOverlayRouteViewDelegate >

@property(nonatomic, strong) AIMapViewWrapper *mapWrapper;
@property(nonatomic, strong) IBOutlet MKMapView *mapView;
@property(nonatomic, strong) IBOutlet UISlider *zoomSlider;
@property(nonatomic, strong) IBOutlet UILabel *zoomLevelLabel;
@property(nonatomic, strong) AIRoute *route;
@property(nonatomic, strong) UIBarButtonItem *btnTrack;

- (IBAction)zoomSliderValueChanged:(id)sender;

- (void)onZoomLevelUpdate;

- (NSArray *)sampleFlightCoordinates;

@end

@implementation AISampleViewController

- (void)dealloc {
#if !(__has_feature(objc_arc))
	[_mapWrapper cancelTrackingRoute];
	[_mapWrapper release];
	_mapWrapper = nil;
	[_mapView release];
	_mapView = nil;
	[_zoomSlider release];
	_zoomSlider = nil;
	[_zoomLevelLabel release];
	_zoomLevelLabel = nil;
	[_route release];
	_route = nil;
	[_btnTrack release];
	_btnTrack = nil;
	
	[super dealloc];
#endif
}

- (id)initWithNibName:(NSString *)nibNameOrNil bundle:(NSBundle *)nibBundleOrNil
{
    self = [super initWithNibName:nibNameOrNil bundle:nibBundleOrNil];
    if (self) {
		_btnTrack = [[UIBarButtonItem alloc] initWithTitle:@"Track flight"
													 style:UIBarButtonItemStyleBordered
													target:self
													action:@selector(onTrack:)];
		[self.navigationItem setRightBarButtonItem:_btnTrack];
		_btnTrack.enabled = NO;
    }
    return self;
}

- (void)viewDidLoad
{
    [super viewDidLoad];
	
	AIMapViewWrapper *tWrapper = [[AIMapViewWrapper alloc] initWithMapView:self.mapView];
	self.mapWrapper = tWrapper;
#if !(__has_feature(objc_arc))
	[tWrapper release];
#endif
	
	self.mapView.mapType = MKMapTypeSatellite;
	
	self.mapWrapper.delegate = self;
	
	self.route = [AIRoute routeWithCoordinates:[self sampleFlightCoordinates]];
	[self.mapView addOverlay:self.route];
}

- (void)viewWillAppear:(BOOL)animated {
	self.mapView.centerCoordinate = CLLocationCoordinate2DMake(51.516434, -0.115356);
	[self.mapWrapper setZoomLevel:self.mapWrapper.minZoomLevel + 4];
}

- (void)onTrack:(id)sender {
	if (self.mapWrapper.trackedRoute == nil) {
		self.mapWrapper.trackedRoute = self.route;
		[self.btnTrack setTitle:@"Stop tracking"];
		self.zoomSlider.userInteractionEnabled = NO;
		self.zoomSlider.alpha = 0.5f;
	} else {
		[self.mapWrapper cancelTrackingRoute];
		[self.btnTrack setTitle:@"Track flight"];
		self.zoomSlider.userInteractionEnabled = YES;
		self.zoomSlider.alpha = 1.0f;
	}
}

- (void)didReceiveMemoryWarning
{
    [super didReceiveMemoryWarning];
    // Dispose of any resources that can be recreated.
}

- (void)mapView:(MKMapView *)mapView regionDidChangeAnimated:(BOOL)animated {
	[self onZoomLevelUpdate];
	
	AIOverlayRouteView *routeView = (AIOverlayRouteView *)[mapView viewForOverlay:self.route];
	[routeView layoutWithZoomScale:self.mapWrapper.zoomScale];
}

- (MKOverlayView *)mapView:(MKMapView *)mapView viewForOverlay:(id <MKOverlay>)overlay {
	if ([overlay isKindOfClass:[AIRoute class]]) {
		AIOverlayRouteView *pathView = [[AIOverlayRouteView alloc] initWithRoute:overlay vehicleImage:[UIImage imageNamed:@"plane.png"]];
		pathView.delegate = self;
		pathView.strokeColor = [[UIColor whiteColor] colorWithAlphaComponent:0.7f];
		pathView.lineCap = kCGLineCapRound;
		pathView.lineWidth = 6.0f;
		
#if !(__has_feature(objc_arc))
		[pathView autorelease];
#endif
		
		return pathView;
	}
	return nil;
}

- (IBAction)zoomSliderValueChanged:(id)sender {
	NSUInteger targetZoomLevel = (NSUInteger)roundf(self.zoomSlider.value);
	[self.zoomSlider setValue:(CGFloat)targetZoomLevel animated:NO];
	[self.mapWrapper setZoomLevel:targetZoomLevel];
}

- (void)onZoomLevelUpdate {
	[self.zoomSlider setValue:(CGFloat)self.mapWrapper.zoomLevel animated:NO];
	self.zoomLevelLabel.text = [NSString stringWithFormat:@"zoom level: %d - %d", self.mapWrapper.zoomLevel, 19];
}

- (void)mapViewWrapperMinimumZoomLevelChanged:(AIMapViewWrapper *)wrapper {
	[self onZoomLevelUpdate];
}

- (void)overlayRouteViewIsReadyForAnimation:(AIOverlayRouteView *)routeView {
	[routeView startAnimationWithTotalTravelTime:40000
							 remainingTravelTime:40000];
	_btnTrack.enabled = YES;
}

- (CLLocation *)locationForLat:(CLLocationDegrees)inLat
						   lon:(CLLocationDegrees)inLon
					  altitude:(CLLocationDegrees)altitude {
	CLLocation *loc = [[CLLocation alloc] initWithLatitude:inLat
												 longitude:inLon];
#if !(__has_feature(objc_arc))
	[loc autorelease];
#endif
	return loc;
}

- (NSArray *)sampleFlightCoordinates {
	NSMutableArray *result = [NSMutableArray array];
	
	//sample.kml file is from http://openflights.org
	//KML framework didn't quite work for me, there should be a better way to parse these coordinates
	
	KMLRoot *root = [KMLParser parseKMLAtPath:[[NSBundle mainBundle] pathForResource:@"sample" ofType:@"kml" inDirectory:nil]];
	KMLPlacemark *lgwMbj = [root.placemarks objectAtIndex:21];
	NSArray *rawCoords = [[lgwMbj.geometry.kml substringWithRange:NSMakeRange(88, lgwMbj.geometry.kml.length - 88 - 51)] componentsSeparatedByString:@" "];
	for (NSString *rawCoord in rawCoords) {
		NSArray *locComps = [rawCoord componentsSeparatedByString:@","];
		[result addObject:[self locationForLat:[[locComps objectAtIndex:1] doubleValue]
										   lon:[[locComps objectAtIndex:0] doubleValue]
									  altitude:[[locComps objectAtIndex:2] doubleValue]]];
	}
	
	return result;
}

@end
