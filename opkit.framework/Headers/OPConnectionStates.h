//
//  OPConnectionStates.h
//  opkit
//
//  Created by Heine Skov Kristensen on 24/08/16.
//  Copyright © 2016 cortrium. All rights reserved.
//

#ifndef OPConnectionStates_h
#define OPConnectionStates_h

/*!
 *  @enum BleStates
 *
 *  @discussion Specifies the possible connection states of the device.
 *
 */
typedef NS_ENUM(NSInteger, ConnectionStates) {
    ConnectionStateUnknown,
    ConnectionStateDisconnected,
    ConnectionStateScanning,
    ConnectionStateConnecting,
    ConnectionStateConnected
};

#endif /* OPConnectionStates_h */
