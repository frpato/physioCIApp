//
//  OPFilter.h
//  opkit
//
//  Created by Heine Kristensen on 18/01/16.
//  Copyright © 2016 cortrium. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 *  OPC3EcgHighPassFilterProtocol
 *
 *  Discussion:
 *    Protocol for ECG highpass filters.
 */
@protocol OPC3EcgHighPassFilterProtocol <NSObject>

/*
 *  filterInput:
 *
 *  Discussion:
 *      Filters input
 */
- (short)filterInput:(int)input;

@end
