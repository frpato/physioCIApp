//
//  OPC3HeartRatePackage.h
//  opkit
//
//  Created by Heine Kristensen on 11/03/16.
//  Copyright © 2016 cortrium. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 *  OPC3HeartRatePackage
 *
 *  Discussion:
 *    The OPC3HeartRatePackage represents an ECG sample batch.
 */
@interface OPC3HeartRatePackage : NSObject

/*
 *  @property isValid
 *
 *  @discussion Returns wether the package contains valid data.
 */
@property (nonatomic, readonly) BOOL isValid;

/*
 *  @property heartRate
 *
 *  @discussion Returns the current heart rate.
 */
@property (nonatomic, readonly) unsigned short heartRate;

/*
 *  @property rrInterval
 *
 *  @discussion Returns the current RR interval.
 */
@property (nonatomic, readonly) unsigned rrInterval;

/*
 *  @property beatType
 *
 *  @discussion Returns the current beat type.
 */
@property (nonatomic, readonly) unsigned short beatType;

/*
 *  @property beatDelay
 *
 *  @discussion Returns the current beat delay.
 */
@property (nonatomic, readonly) int beatDelay;

@end
