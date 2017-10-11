//
//  OPC3SessionDelegate.h
//  opkit
//
//  Created by Heine Kristensen on 28/01/16.
//  Copyright © 2016 cortrium. All rights reserved.
//

#import <Foundation/Foundation.h>

@class OPC3Device;
@class OPDeviceInformation;
@class OPC3MiscPackage;
@class OPC3ModePackage;
@class OPC3EcgPackage;
@class OPC3Session;
@class OPC3HeartRatePackage;
@class OPC3RespiratoryPackage;
@class OPC3EventPackage;

/*
 *  OPC3SessionDelegate
 *
 *  Discussion:
 *    Delegate for OPC3SessionDelegate.
 */
@protocol OPC3SessionDelegate <NSObject>

@optional

/*
 *  session:didReadDeviceInformation:forDevice
 *
 *  Discussion:
 *    Invoked when the connected Cortrium device has read the device information.
 */
- (void)session:(OPC3Session*)session didReadDeviceInformation:(OPDeviceInformation*)deviceInformation forDevice:(OPC3Device*)device;

/*
 *  session:didUpdateMiscData:forDevice
 *
 *  Discussion:
 *    Invoked when the connected Cortrium device has read miscellaneous data.
 */
- (void)session:(OPC3Session*)session didUpdateMiscData:(OPC3MiscPackage*)miscData forDevice:(OPC3Device*)device;

/*
 *  session:didUpdateEcg1Data:forDevice
 *
 *  Discussion:
 *    Invoked when the connected Cortrium device has a new batch of ECG1 measurements.
 */
- (void)session:(OPC3Session*)session didUpdateEcg1Data:(OPC3EcgPackage*)ecg1Data forDevice:(OPC3Device*)device;

/*
 *  session:didUpdateEcg2Data:forDevice
 *
 *  Discussion:
 *    Invoked when the connected Cortrium device has a new batch of ECG2 measurements.
 */
- (void)session:(OPC3Session*)session didUpdateEcg2Data:(OPC3EcgPackage*)ecg2Data forDevice:(OPC3Device*)device;

/*
 *  session:didUpdateEcg3Data:forDevice
 *
 *  Discussion:
 *    Invoked when the connected Cortrium device has a new batch of ECG3 measurements.
 */
- (void)session:(OPC3Session*)session didUpdateEcg3Data:(OPC3EcgPackage*)ecg3Data forDevice:(OPC3Device*)device;

/*
 *  session:didRegisterEvent:forDevice
 *
 *  Discussion:
 *    Invoked when the event button of the connected Cortrium device has been pressed.
 */
- (void)session:(OPC3Session*)sesstion didRegisterEvent:(OPC3EventPackage*)event forDevice:(OPC3Device*)device;

/*
 *  session:didUpdateHeartRate:forDevice
 *
 *  Discussion:
 *    Invoked when the heart rate has been measured.
 */
- (void)session:(OPC3Session*)session didUpdateHeartRate:(OPC3HeartRatePackage*)heartRate forDevice:(OPC3Device*)device;

/*
 *  session:didUpdateRespiratoryRate:forDevice
 *
 *  Discussion:
 *    Invoked when the respiratory rate has been measured.
 */
- (void)session:(OPC3Session*)session didUpdateRespiratoryRate:(OPC3RespiratoryPackage*)respiratoryRate forDevice:(OPC3Device*)device;

/*
 *  session:didReadCurrentMode:forDevice
 *
 *  Discussion:
 *    Invoked when the current operating mode has been read from the connected Cortrium device.
 */
- (void)session:(OPC3Session*)session didReadCurrentMode:(OPC3ModePackage*)modeData forDevice:(OPC3Device*)device;

/*
 *  session:didUpdateRawPayload:withSerial:forDevice
 *
 *  Discussion:
 *    Invoked when the a complete batch of raw data has been read from the connected Cortrium device for the specified serial number.
 */
- (void)session:(OPC3Session*)session didUpdateRawPayload:(NSData*)rawPayload withSerial:(NSUInteger)serial forDevice:(OPC3Device*)device;

@end
