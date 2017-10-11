//
//  OPC3DeviceDelegate.h
//  opkit
//
//  Created by Heine Kristensen on 15/01/16.
//  Copyright © 2016 cortrium. All rights reserved.
//

#import <Foundation/Foundation.h>

@class OPC3Device;
@class OPDeviceInformation;
@class OPC3MiscPackage;
@class OPC3ModePackage;
@class OPC3EcgPackage;
@class OPC3HeartRatePackage;
@class OPC3RespiratoryPackage;
@class OPC3EventPackage;

/*
 *  OPC3DeviceDelegate
 *
 *  Discussion:
 *    Delegate for OPC3Device.
 */
@protocol OPC3DeviceDelegate <NSObject>

@optional

/*
 *  device:didReadDeviceInformation
 *
 *  Discussion:
 *    Invoked when the connected Cortrium device has read the device information.
 */
- (void)device:(OPC3Device*)device didReadDeviceInformation:(OPDeviceInformation*)deviceInformation;

/*
 *  device:didUpdateMiscData
 *
 *  Discussion:
 *    Invoked when the connected Cortrium device has read miscellaneous data.
 */
- (void)device:(OPC3Device*)device didUpdateMiscData:(OPC3MiscPackage*)miscData;

/*
 *  device:didUpdateEcg1Data
 *
 *  Discussion:
 *    Invoked when the connected Cortrium device has a new batch of ECG1 measurements.
 */
- (void)device:(OPC3Device*)device didUpdateEcg1Data:(OPC3EcgPackage*)ecg1Data;

/*
 *  device:didUpdateEcg2Data
 *
 *  Discussion:
 *    Invoked when the connected Cortrium device has a new batch of ECG2 measurements.
 */
- (void)device:(OPC3Device*)device didUpdateEcg2Data:(OPC3EcgPackage*)ecg2Data;

/*
 *  device:didUpdateEcg3Data
 *
 *  Discussion:
 *    Invoked when the connected Cortrium device has a new batch of ECG3 measurements.
 */
- (void)device:(OPC3Device*)device didUpdateEcg3Data:(OPC3EcgPackage*)ecg3Data;

/*
 *  device:registeredEvent
 *
 *  Discussion:
 *    Invoked when the event button of the connected Cortrium device has been pressed.
 */
- (void)device:(OPC3Device*)device registeredEvent:(OPC3EventPackage*)event;

/*
 *  device:didReadCurrentMode
 *
 *  Discussion:
 *    Invoked when the current operating mode has been read from the connected Cortrium device.
 */
- (void)device:(OPC3Device*)device didReadCurrentMode:(OPC3ModePackage*)modeData;

/*
 *  device:didUpdateHeartRate
 *
 *  Discussion:
 *    Invoked when the heart rate has been measured.
 */
- (void)device:(OPC3Device*)device didUpdateHeartRate:(OPC3HeartRatePackage*)heartRate;

/*
 *  device:didUpdateRespiratoryRate
 *
 *  Discussion:
 *    Invoked when the respiratory rate has been measured.
 */
- (void)device:(OPC3Device*)device didUpdateRespiratoryRate:(OPC3RespiratoryPackage*)respiratoryRate;

/*
 *  device:didUpdateRawPayload:forSerial
 *
 *  Discussion:
 *    Invoked when the a complete batch of raw data has been read from the connected Cortrium device for the specified serial number.
 */
- (void)device:(OPC3Device*)device didUpdateRawPayload:(NSData*)rawPayload forSerial:(NSUInteger)serial;

@end
