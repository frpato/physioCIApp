//
//  OPConnectionManagerStates.h
//  opkit
//
//  Created by Heine Skov Kristensen on 27/09/16.
//  Copyright © 2016 cortrium. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
*  @constant StateUnknown       State unknown, update imminent.
*  @constant StateResetting     The connection with the system service was momentarily lost, update imminent.
*  @constant StateUnsupported   The platform doesn't support the Bluetooth Low Energy Central/Client role.
*  @constant StateUnauthorized  The application is not authorized to use the Bluetooth Low Energy Central/Client role.
*  @constant StatePoweredOff    Bluetooth is currently powered off.
*  @constant StatePoweredOn     Bluetooth is currently powered on and available to use.
*/
typedef NS_ENUM(NSInteger, ConnectionManagerStates) {
    StateUnknown = 0,
    StateResetting,
    StateUnsupported,
    StateUnauthorized,
    StatePoweredOff,
    StatePoweredOn
};
