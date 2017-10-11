//
//  OPSensorFileDownloadDelegate.h
//  opkit
//
//  Created by Heine Kristensen on 26/08/15.
//  Copyright (c) 2015 Cortrium. All rights reserved.
//

#import <Foundation/Foundation.h>

@class OPC3Device, OPRecording, OPBleDownloadChunk;

/*
 *  OPRecordingDownloadDelegate
 *
 *  Discussion:
 *    Delegate for tracking progress of downloading a recording from the Cortrium device.
 */
@protocol OPRecordingDownloadDelegate <NSObject>

@optional

/*
 *  device:didStartDownloadingFile
 *
 *  Discussion:
 *    Invoked when download of a recording has been initiated.
 */
- (void)device:(OPC3Device*)device didStartDownloadingFile:(OPRecording*)file;

/*
 *  device:didReportProgress:forDownloadingFile
 *
 *  Discussion:
 *    Invoked when progress information is available during download of a recording.
 */
- (void)device:(OPC3Device*)device didReportProgress:(float)progress forDownloadingFile:(OPRecording*)file;

/*
 *  device:downloadChunkAvailable:serial:forDownloadingFile
 *
 *  Discussion:
 *    Invoked when a datachunk has been downloaded.
 */
- (void)device:(OPC3Device*)device downloadChunkAvailable:(OPBleDownloadChunk*)chunk serial:(NSUInteger)serial forDownloadingFile:(OPRecording*)file;

/*
 *  device:didFinishDownloadingFile
 *
 *  Discussion:
 *    Invoked when the download process has completed.
 */
- (void)device:(OPC3Device*)device didFinishDownloadingFile:(OPRecording*)file;

/*
 *  device:didCancelDownloadingFile
 *
 *  Discussion:
 *    Invoked when the download process has cancelled.
 */
- (void)device:(OPC3Device*)device didCancelDownloadingFile:(OPRecording *)file;

/*
 *  device:failedDownloadingFile
 *
 *  Discussion:
 *    Invoked when the download process has failed.
 */
- (void)device:(OPC3Device*)device failedDownloadingFile:(OPRecording*)file;

@end
