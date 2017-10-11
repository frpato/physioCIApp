//
//  OPRecording.h
//  opkit
//
//  Created by Heine Skov Kristensen on 18/08/16.
//  Copyright © 2016 cortrium. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 *  OPRecording
 *
 *  Discussion:
 *    The OPRecording represents a recording on the Cortrium device.
 */
@interface OPRecording : NSObject

/*
 *  @property filename
 *
 *  @discussion Returns filename of the recording.
 */
@property (nonatomic, readonly) NSString* filename;

/*
 *  @property size
 *
 *  @discussion Returns size of the recording in bytes.
 */
@property (nonatomic, readonly) NSInteger size;

/* Initializer */
- (instancetype)initWithFilename:(NSString*)filename size:(NSUInteger)size;

@end
