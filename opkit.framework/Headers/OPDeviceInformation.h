//
//  OPDeviceInformation.h
//  opeon
//
//  Created by Heine Kristensen on 29/06/15.
//  Copyright (c) 2015 opeon. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 *  OPDeviceInformation
 *
 *  Discussion:
 *    The OPDeviceInformation object contains information about the connected device.
 */
@interface OPDeviceInformation : NSObject

/*
 *  firmwareRevision
 *
 *  Discussion:
 *      Firmware revision number of the firmware.
 */
@property (nonatomic, readonly) NSString *firmwareRevision;

/*
 *  hardwareRevision
 *
 *  Discussion:
 *      Hardware revision number of the hardware.
 */
@property (nonatomic, readonly) NSString *hardwareRevision;

/*
 *  softwareRevision
 *
 *  Discussion:
 *      Software revision number of the firmware.
 */
@property (nonatomic, readonly) NSString *softwareRevision;

/*
 *  softwareRevision
 *
 *  Discussion:
 *      Software revision number of the firmware.
 */


- (BOOL)informationComplete;

@end
