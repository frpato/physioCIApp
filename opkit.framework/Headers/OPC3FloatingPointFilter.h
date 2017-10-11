//
//  OPFloatingPointFilter.h
//  opkit
//
//  Created by Heine Kristensen on 26/01/16.
//  Copyright © 2016 cortrium. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 *  OPC3FloatingPointFilter
 *
 *  Discussion:
 *    Protocol for floating point filters.
 */
@protocol OPC3FloatingPointFilter <NSObject>

/*
 *  filterInput:
 *
 *  Discussion:
 *      Filters input
 */
- (float)filterInput:(float)input;

@end
