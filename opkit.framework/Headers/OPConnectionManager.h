//
//  OPBleConnectionManager.h
//  BLE discovery
//
//  Created by Heine Kristensen on 27/10/14.
//  Copyright (c) 2014 Opeon. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "OPConnectionManagerDelegate.h"
#import "OPConnectionStates.h"
#import "OPConnectionManagerStates.h"

extern NSString* const kOPConnectionManagerDeviceTypeC3;    // C3 device
extern NSString* const kOPConnectionManagerDeviceTypeC5;    // C5 device


@class OPC3Device;
/*!
 *  @class OPC3ConnectionManager
 *
 *  @discussion Handles connection to C3 device.
 */

@interface OPConnectionManager : NSObject

/*!
 *  @property connectedDevice
 *
 *  @discussion The currently connected C3 device
 */
@property (nonatomic, readonly) OPC3Device *connectedDevice;

/*!
 *  @property connectionState
 *
 *  @discussion The current connection state of the device.
 */
@property (nonatomic, readonly) ConnectionStates connectionState;

/*!
 *  @property state
 *
 *  @discussion The current state of the manager.
 */
@property (nonatomic, readonly) ConnectionManagerStates state;

/*!
 *  @property delegate
 *
 *  @discussion The delegate object that will receive C3 connection events.
 */
@property (nonatomic, weak) id<OPConnectionManagerDelegate> delegate;

/*!
 *  @method sharedInstance
 *
 *  @discussion Singleton instance for OPC3ConnectionManager.
 */
+ (instancetype)sharedInstance;

/*!
 *  @method startScanning
 *
 *  @discussion Starts scanning for nearby turned on C3 devices.
 *
 */
- (void) startScanning;

/*!
 *  @method startScanningForSpecificDevice:
 *
 *  @discussion Starts scanning for nearby turned on C3 devices with specified deviceIdentifier.
 *
 */
- (void)startScanningForSpecificDevice:(NSString*)deviceIdentifier;

/*!
 *  @method startScanningForDeviceOfType
 *
 *  @discussion Starts scanning for nearby turned on Cortrium devices of specific type.
 *
 */
- (void)startScanningForDeviceOfType:(NSString*)type;

/*!
 *  @method startScanningForDeviceOfType:deviceIdentifier
 *
 *  @discussion Starts scanning for nearby turned on Cortrium devices of specific type with specified deviceIdentifier.
 *
 */
- (void)startScanningForDeviceOfType:(NSString*)type deviceIdentifier:(NSString*)deviceIdentifier;

/*!
 *  @method stopScanning
 *
 *  @discussion Stops scanning for nearby C3 devices. If a C3 device is not connected stopScanning sets connectionState
 *  to disconnected
 *
 */
- (void) stopScanning;

/*!
 *  @method connectDevice:
 *
 *  @param device   A discovered C3 device.
 *
 *  @discussion			Attempts to connect to C3 device.
 *
 *  @see				connectionManager:didConnectToDevice:
 */
- (void) connectDevice:(OPC3Device*)device;

/*!
 *  @method disconnectDevice
 *
 *  @discussion			Disconnects from a currently connected C3 device.
 *
 *  @see				connectionManager:didDisconnectFromDevice:
 */
- (void) disconnectDevice;

@end
