//
//  OPC3Modes.h
//  opkit
//
//  Created by Heine Kristensen on 11/03/16.
//  Copyright © 2016 cortrium. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 *  OPC3Modes
 *
 *  Discussion:
 *      Represents the operation modes for the Cortrium device.
 *
 */
typedef NS_ENUM(NSInteger, OPC3Modes) {
    OPC3ModeIdle = 0,
    OPC3ModeActive = 1,
    OPC3ModeHolter = 2,
    OPC3ModeFile = 3,
    OPC3ModeFileActive = 4,
    OPC3ModeDisconnect = 5
};
