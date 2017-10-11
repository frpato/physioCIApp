//
//  OPBleConnectionManagerDelegate.h
//  opkit
//
//  Created by Heine Kristensen on 15/01/16.
//  Copyright © 2016 cortrium. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OPConnectionStates.h"
#import "OPConnectionManagerStates.h"

@class OPConnectionManager;
@class OPC3Device;

/*
 *  OPConnectionManagerDelegate
 *
 *  Discussion:
 *    Delegate for OPConnectionManager.
 */
@protocol OPConnectionManagerDelegate <NSObject>

@optional

/*
 *  connectionManagerDidStartScanning:
 *
 *  Discussion:
 *    Invoked when the connectionmanager starts scanning for devices.
 */
- (void)connectionManagerDidStartScanning:(OPConnectionManager*)manager;

/*
 *  connectionManagerDidStopScanning:
 *
 *  Discussion:
 *    Invoked when the connectionmanager stops scanning for devices.
 */
- (void)connectionManagerDidStopScanning:(OPConnectionManager*)manager;

/*
 *  connectionManager:didDiscoverC3Device:
 *
 *  Discussion:
 *    Invoked when the connectionmanager discovers a Cortrium device.
 */
- (void)connectionManager:(OPConnectionManager*)manager didDiscoverC3Device:(OPC3Device*)device estimatedSignalStrength:(NSNumber*)signalStrength;

/*
 *  connectionManager:willConnectToDevice:
 *
 *  Discussion:
 *    Invoked just before the connectionmanager connects to the specified device.
 */
- (void)connectionManager:(OPConnectionManager*)manager willConnectToDevice:(OPC3Device*)device;

/*
 *  connectionManager:didConnectToDevice:
 *
 *  Discussion:
 *    Invoked just after the connectionmanager has established a connection to the Cortrium device
 */
- (void)connectionManager:(OPConnectionManager*)manager didConnectToDevice:(OPC3Device*)device;

/*
 *  connectionManager:didFailToConnectToDevice:error:
 *
 *  Discussion:
 *    Invoked if an error occurs while the connectionmanager tries to connect to device.
 */
- (void)connectionManager:(OPConnectionManager *)manager didFailToConnectToDevice:(OPC3Device *)device error:(NSError*)error;

/*
 *  connectionManager:willDisconnectFromDevice:
 *
 *  Discussion:
 *    Invoked just before the connectionmanager disconnects from the device.
 */
- (void)connectionManager:(OPConnectionManager*)manager willDisconnectFromDevice:(OPC3Device*)device;

/*
 *  connectionManager:didDisconnectFromDevice:
 *
 *  Discussion:
 *    Invoked just after the connectionmanager has disconnected from the device.
 */
- (void)connectionManager:(OPConnectionManager*)manager didDisconnectFromDevice:(OPC3Device*)device;

/*
 *  connectionManager:willReconnectToDevice:
 *
 *  Discussion:
 *    Invoked before the connection will been reestablished to a previously connected device.
 */
- (void)connectionManager:(OPConnectionManager*)manager willReconnectToDevice:(OPC3Device*)device;

/*
 *  connectionManager:didReconnectToDevice:
 *
 *  Discussion:
 *    Invoked after the connection has been reestablished to a previously connected device.
 */
- (void)connectionManager:(OPConnectionManager*)manager didReconnectToDevice:(OPC3Device*)device;

/*
 *  connectionManager:didChangeFromOldConnectionState:toNewConnectionState:
 *
 *  Discussion:
 *    Invoked when the connection state of the connected device changes.
 */
- (void)connectionManager:(OPConnectionManager*)manager didChangeFromOldConnectionState:(ConnectionStates)oldConnectionState toNewConnectionState:(ConnectionStates)newConnectionState;

/*
 *  connectionManagerIsReady:
 *
 *  Discussion:
 *    Invoked when the connection manager is ready to start scanning for Cortrium devices.
 *    If scanning is started before this method is invoked, no devices will be discovered.
 */
- (void)connectionManagerIsReady:(OPConnectionManager *)manager;

/*
 *  connectionManager:didUpdateState:
 *
 *  Discussion:
 *    Invoked whenever the connection manager's state has been updated. Commands should only be issued when the state is
 *                  <code>StatePoweredOn</code>. A state below <code>StatePoweredOn</code>
 *                  implies that scanning has stopped and any connected peripherals have been disconnected.
 */
- (void)connectionManager:(OPConnectionManager*)manager didUpdateState:(ConnectionManagerStates)state;

@end
