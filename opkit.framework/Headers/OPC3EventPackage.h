//
//  OPC3EventPackage.h
//  opkit
//
//  Created by Heine Skov Kristensen on 19/05/2017.
//  Copyright © 2017 cortrium. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 *  OPC3EventPackage
 *
 *  Discussion:
 *    The OPC3EventPackage contains information about an event.
 */
@interface OPC3EventPackage : NSObject

/*
 *  @property serial
 *
 *  @discussion Returns the serial number of the event
 */
@property (nonatomic, readonly) unsigned int serial;

/*
 *  @property eventCounter
 *
 *  @discussion Returns the total number of events occurred
 */
@property (nonatomic, readonly) unsigned int eventCounter;


@end
