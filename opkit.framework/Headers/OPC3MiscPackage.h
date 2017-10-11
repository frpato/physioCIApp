//
//  MiscPackage.h
//  opkit
//
//  Created by Heine Kristensen on 18/01/16.
//  Copyright © 2016 cortrium. All rights reserved.
//

/*
 *  OPC3MiscPackage
 *
 *  Discussion:
 *    The OPC3MiscPackage represents miscellaneous data from the Cortrium device.
 */
#import <Foundation/Foundation.h>

@interface OPC3MiscPackage : NSObject

/*
 *  @property batteryLevel
 *
 *  @discussion Returns the current battery level (0-100%).
 */
@property (nonatomic, readonly) unsigned char batteryLevel;

/*
 *  @property isCharging
 *
 *  @discussion Returns wether the device is currently charing.
 */
@property (nonatomic, readonly) BOOL isCharging;

/*
 *  @property leadOff
 *
 *  @discussion Returns wether the connected device has leadoff. It's currently not possible to detect which lead
 *  has a lead off, so for now there's leadoff if leadOff != 0.
 */
@property (nonatomic, readonly) unsigned char leadOff;

/*
 *  @property serial
 *
 *  @discussion Returns the current serial number.
 */
@property (nonatomic, readonly) unsigned int serial;

/*
 *  @property rawRespSample
 *
 *  @discussion Returns a raw respiratory rate sample.
 *  Sampled at 41.66 hz
 */
@property (nonatomic, readonly) float rawRespSample;

/*
 *  @property filteredRespSample
 *
 *  @discussion Returns a filtered respiratory rate sample. The filtering is decided by the filter chain set up on the device.
 *  Sampled at 41.66 hz
 */
@property (nonatomic, readonly) float filteredRespSample;

/*
 *  @property accelY
 *
 *  @discussion Returns a sample from the accelerometer Y axis.
 *  Sampled at 41.66 hz
 */
@property (nonatomic, readonly) float accelY;

/*
 *  @property accelX
 *
 *  @discussion Returns a sample from the accelerometer X axis.
 *  Sampled at 41.66 hz
 */
@property (nonatomic, readonly) float accelX;

/*
 *  @property accelZ
 *
 *  @discussion Returns a sample from the accelerometer Z axis.
 *  Sampled at 41.66 hz
 */
@property (nonatomic, readonly) float accelZ;

/*
 *  @property ambientTemperature
 *
 *  @discussion Returns the current surface temperature of the individual wearing the device.
 */
@property (nonatomic, readonly) float ambientTemperature;

/*
 *  @property deviceTemperature
 *
 *  @discussion Returns the current internal temperature of the device.
 */
@property (nonatomic, readonly) float deviceTemperature;

/*
 *  @property eventCounter
 *
 *  @discussion Returns the number of events logged by pressing the C3 button.
 */
@property (nonatomic, readonly) short eventCounter;

@end
