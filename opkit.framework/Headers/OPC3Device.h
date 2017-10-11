//
//  OPC3Device.h
//  opkit
//
//  Created by Heine Kristensen on 15/01/16.
//  Copyright © 2016 cortrium. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OPC3DeviceDelegate.h"
#import "OPC3FloatingPointFilter.h"
#import "OPC3DeviceDelegate.h"
#import "OPC3Modes.h"
#import "OPRecording.h"
#import "Blocks.h"
#import "OPRecordingDownloadDelegate.h"
#import "OPC3GainLevels.h"

NS_ASSUME_NONNULL_BEGIN

/*
 *  DeviceModes
 *
 *  Discussion:
 *      Represents the operation modes for the Cortrium device.
 *
 */
typedef NS_ENUM(NSInteger, DeviceModes) {
    // The device is not measuring
    DeviceModeIdle = 0,
    // The device is measuring while connected to a central
    DeviceModeActive = 1,
    // The device is measuring in stand alone mode
    DeviceModeStandAlone = 2,
    // The device is in file transfer mode
    DeviceModeFile = 4
};

@class OPDeviceInformation;
@class OPC3MiscPackage;
@class OPC3ModePackage;
@class OPC3Configuration;

/*
 *  OPC3Device
 *
 *  Discussion:
 *    The OPC3Device object represents a Cortrium device
 */
@interface OPC3Device : NSObject

/*
 *  @property delegate
 *
 *  @discussion The delegate object that will receive events when new measurements are available.
 */
@property (nonatomic, weak) id<OPC3DeviceDelegate> delegate;

/*
 *  @property identifier
 *
 *  @discussion Returns the tnique identifier of the Cortrium device.
 */
@property (nonatomic, readonly, copy) NSString *identifier;

/*
 *  @property name
 *
 *  @discussion Returns the human readable name for the Cortrium device.
 */
@property (nonatomic, readonly, copy) NSString *name;

/*
 *  @property deviceInformation
 *
 *  @discussion Returns information about firmware and hardware of the connected device.
 */
@property (nonatomic, readonly) OPDeviceInformation *deviceInformation;

/*
 *  @property configuration
 *
 *  @discussion Returns the current configuration of the connected device.
 */
@property (nonatomic, readonly) OPC3Configuration *configuration;


/*
 *  @property currentMode
 *
 *  @discussion Returns the current mode of the connected device.
 */
@property (nonatomic, readonly) OPC3Modes currentMode;

/*
 *  @property gainLebel
 *
 *  @discussion Returns the current gain level of the Cortrium device. @see OPC3GainLevels
 */

@property (nonatomic, readonly) OPC3GainLevels gainLevel;

/*
 *  @property filename
 *
 *  @discussion Returns name of the current recording if a recording is started.
 */
@property (nonatomic, readonly) NSString *filename;

/*
 *  @property respiratoryFilters
 *
 *  @discussion Returns a list of the currently active respiratory filters. Filter at index 0 is executed first
 */
@property (nonatomic, readonly, nullable) NSArray<id<OPC3FloatingPointFilter>> *respiratoryFilters;

- (nullable instancetype)init NS_UNAVAILABLE;

/*
 *  initWithName:identifier
 *
 *  Discussion:
 *      Designated initializer
 */
- (nullable instancetype)initWithName:(NSString*)name identifier:(NSString*)identifier NS_DESIGNATED_INITIALIZER;

/*
 *  getRecordingListingWithCompletion:failureBlock
 *
 *  Discussion:
 *      Used to get a list of recordings stored on the SD card of the Cortrium device. If successful an array of the recordings
 *      are returned in the completion block. In case of error the specific error is returned in the failure block
 */
- (void)getRecordingListingWithCompletion:(void (^)(NSArray * _Nonnull))completion failureBlock:(nullable FailureBlock)failureBlock;

/*
 *  deleteRecording:withCompletion:failureBlock
 *
 *  Discussion:
 *      Delete a recording stored on the SD card of the Cortrium device. If successful the completion block is called. In case of error the specific error is returned in the failure block
 */
- (void)deleteRecording:(OPRecording*)recording withCompletion:(nonnull void (^)())completion failureBlock:(FailureBlock)failureBlock;

/*
 *  deleteAllRecordingsWithCompletion:completion:failureBlock
 *
 *  Discussion:
 *      Delete all recordings stored on the SD card of the Cortrium device. If successful the completion block is called. In case of error the specific error is returned in the failure block
 */
- (void)deleteAllRecordingsWithCompletion:(void (^)())completion failureBlock:(FailureBlock)failureBlock;

/*
 *  downloadRecording:recording:downloadDelegate
 *
 *  Discussion:
 *      Initiate a transfer of a specified recording stored on the SD card of the Cortrium device. The downloadDelegate is used 
 *      to track progress of the transfer.
 */
- (void)downloadRecording:(OPRecording*)recording downloadDelegate:(id<OPRecordingDownloadDelegate>)downloadDelegate;

/*
 *  cancelDownload
 *
 *  Discussion:
 *      Cancel a ongoing transfer. The method has no effect is no transfer is currently active
 */
- (void)cancelDownload;

/*
 *  changeMode:modeChangeCompleted:failureBlock
 *
 *  Discussion:
 *      Change the mode of the connected Cortrium device to newMode. If successful the completion block is called with the new mode. In case of error the specific error is returned in the failure block
 */
- (void)changeMode:(OPC3Modes)newMode modeChangeCompleted:(ModeBlock)completion failureBlock:(nullable FailureBlock)failureBlock;

/*
 *  readCurrentModeWithCompletion:failureBlock
 *
 *  Discussion:
 *      Read the currently active mode of the connected Cortrium device. If successful the completion block is called with the current mode. In case of error the specific error is returned in the failure block
 */
- (void)readCurrentModeWithCompletion:(nullable ModeBlock)completion failureBlock:(nullable FailureBlock)failureBlock;

/*
 *  addRespiratoryFilter
 *
 *  Discussion:
 *      Adds a new respiratory filter to the end of the filter chain
 */
- (void)addRespiratoryFilter:(id<OPC3FloatingPointFilter>)filter;

/*
 *  insertRespiratoryFilter:atIndex
 *
 *  Discussion:
 *      Inserts a new respiratory filter at the specified index
 */
- (void)insertRespiratoryFilter:(id<OPC3FloatingPointFilter>)filter atIndex:(NSUInteger)index;

/*
 *  removeRespiratoryFilter
 *
 *  Discussion:
 *      Removes the specified respiratory filter from the filter chain
 */
- (void)removeRespiratoryFilter:(id<OPC3FloatingPointFilter>)filter;

/*
 *  removeAllRespiratoryFilters
 *
 *  Discussion:
 *      Removes all respiratory filters from the filter chain. If the filter chain is empty this call has no effect.
 */
- (void)removeAllRespiratoryFilters;

NS_ASSUME_NONNULL_END

@end
