//
//  OPC3Configuration.h
//  opkit
//
//  Created by Heine Kristensen on 15/01/16.
//  Copyright © 2016 cortrium. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 *  OPC3Configuration
 *
 *  Discussion:
 *    The OPC3Configuration object is used to configure the connected Cortrium device.
 */
@interface OPC3Configuration : NSObject

/*
 *  ecg1ChannelEnabled
 *
 *  Discussion:
 *      YES if the ECG1 channel is enabled, otherwise NO.
 */
@property (nonatomic, assign) BOOL ecg1ChannelEnabled;

/*
 *  ecg2ChannelEnabled
 *
 *  Discussion:
 *      YES if the ECG2 channel is enabled, otherwise NO.
 */
@property (nonatomic, assign) BOOL ecg2ChannelEnabled;

/*
 *  ecg3ChannelEnabled
 *
 *  Discussion:
 *      YES if the ECG3 channel is enabled, otherwise NO.
 */
@property (nonatomic, assign) BOOL ecg3ChannelEnabled;

/*
 *  respiratoryRateChannelEnabled
 *
 *  Discussion:
 *      YES if the respiratory rate channel is enabled, otherwise NO.
 */
@property (nonatomic, assign) BOOL respiratoryRateChannelEnabled;

/*
 *  saveDataOnC3Device
 *
 *  Discussion:
 *      YES if data should be stored on the SD card on the Cortrium device, otherwise NO
 */
@property (nonatomic, assign) BOOL saveDataOnC3Device;

/*
 *  defaultConfiguration
 *
 *  Discussion:
 *      Returns a OPC3Configuration object with default configuration values
 */
+ (instancetype)defaultConfiguration;

@end
