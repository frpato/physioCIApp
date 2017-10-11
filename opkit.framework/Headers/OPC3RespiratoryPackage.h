//
//  OPC3RespiratoryPackage.h
//  opkit
//
//  Created by Heine Skov Kristensen on 02/12/16.
//  Copyright © 2016 cortrium. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 *  OPC3RespiratoryPackage
 *
 *  Discussion:
 *    The OPC3RespiratoryPackage represents the measured respiratory rate.
 */
@interface OPC3RespiratoryPackage : NSObject

/*
 *  @property respiratoryRate
 *
 *  @discussion Returns the current respiratory rate.
 */
@property (nonatomic, readonly) unsigned short respiratoryRate;

@end
