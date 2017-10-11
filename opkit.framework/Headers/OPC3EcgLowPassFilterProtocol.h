//
//  OPEcgLowPassFilter.h
//  opkit
//
//  Created by Heine Kristensen on 08/02/16.
//  Copyright © 2016 cortrium. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 *  OPEcgLowPassFilterProtocol
 *
 *  Discussion:
 *    Protocol for ECG lowpass filters.
 */
@protocol OPEcgLowPassFilterProtocol <NSObject>

/*
 *  filterInput:
 *
 *  Discussion:
 *      Filters input
 */
- (short)filterInput:(short)input;

@end
