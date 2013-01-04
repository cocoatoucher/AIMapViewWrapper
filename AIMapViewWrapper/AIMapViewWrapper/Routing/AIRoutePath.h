//
//  AIRoutePath.h
//  AIMapViewWrapper
//
//  Created by CocoaToucher on 12/24/12.
//  Copyright (c) 2012 CocoaToucher. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface AIRoutePath : NSObject

- (id)initWithKnots:(NSArray *)inKnots;

@property(nonatomic, readonly) CGPathRef path;
@property(nonatomic, readonly) CGPathRef shadowPath;
@property(nonatomic, readonly) CGFloat totalDistance;

- (CGPathRef)newTailWithDistance:(CGFloat)inDistance;

@end
