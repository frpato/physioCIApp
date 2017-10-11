//
//  OPModePackage.h
//  opkit
//
//  Created by Heine Kristensen on 26/01/16.
//  Copyright © 2016 cortrium. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 *  OPC3ModePackage
 *
 *  Discussion:
 *    The OPC3ModePackage represents current mode and configuration of the connected Cortrium device.
 */
@interface OPC3ModePackage : NSObject

/*
 *  @property mode
 *
 *  @discussion Returns the current mode of the connected Cortrium device. @see OPC3Modes
 */
@property (nonatomic, readonly) OPC3Modes mode;

/*
 *  @property configuration
 *
 *  @discussion Returns the raw configuration data.
 */
@property (nonatomic, readonly) unsigned char configuration;

/*
 *  @property filename
 *
 *  @discussion Returns the filename of the current ongoing recording.
 */
@property (nonatomic, readonly) NSString *filename;

@end
