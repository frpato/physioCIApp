//
//  OPC3Session.h
//  opkit
//
//  Created by Heine Kristensen on 15/01/16.
//  Copyright © 2016 cortrium. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "OPC3SessionDelegate.h"
#import "Blocks.h"

/*
 *  SessionModes
 *
 *  Discussion:
 *      Represents the session mode for the Cortrium device.
 *
 */
typedef NS_ENUM (NSUInteger, SessionModes) {
    SessionModeStopRecordingAndPowerOffDevice = 1,
    SessionModeContinueRecordingAndDisconnect = 2
};

@class OPC3Configuration, OPC3Device, OPConnectionManager;
/*
 *  OPC3Session
 *
 *  Discussion:
 *    The OPC3Session object represents a recording session from a connected Cortrium device
 */
@interface OPC3Session : NSObject

/*
 *  @property delegate
 *
 *  @discussion The delegate object that will receive events when new measurements are available.
 */
@property (nonatomic, weak) id<OPC3SessionDelegate> delegate;

/*
 *  @property currentDevice
 *
 *  @discussion Returns the currently connected Cortrium device.
 */
@property (nonatomic, readonly) OPC3Device *currentDevice;

/*
 *  @property currentConfiguration
 *
 *  @discussion Returns the current configuration of the connected Cortrium device.
 */
@property (nonatomic, readonly) OPC3Configuration *currentConfiguration;

/*
 *  @property started
 *
 *  @discussion Returns a date/time representing the start of the session.
 */
@property (nonatomic, readonly) NSDate *started;

/*
 *  @property ended
 *
 *  @discussion Returns a date/time representing the end of the session. If a session is ongoing this will return nil.
 */
@property (nonatomic, readonly) NSDate *ended;

/*
 *  @property sessionName
 *
 *  @discussion Returns the name of the active session. This will also be the filename of the recording on the Cortrium device.
 */
@property (nonatomic, readonly, copy) NSString *sessionName;

/* Initializers */
- (instancetype)init NS_UNAVAILABLE;
- (instancetype)initWithDevice:(OPC3Device *)device configuration:(OPC3Configuration *)configuration connectionManager:(OPConnectionManager*)connectionManager;

/*
 *  startSession
 *
 *  @discussion Starts a new recording session.
 */
- (void)startSession;

/*
 *  endSessionWithMode:completion:failureBlock
 *
 *  @discussion Ends a recording session with the specified mode.
 */
- (void)endSessionWithMode:(SessionModes)mode completion:(EmptyBlock)completion failureBlock:(FailureBlock)failure;

@end
