//
//  OPEcgPackage.h
//  opkit
//
//  Created by Heine Kristensen on 26/01/16.
//  Copyright © 2016 cortrium. All rights reserved.
//

#import <Foundation/Foundation.h>

/*
 *  OPC3EcgPackage
 *
 *  Discussion:
 *    The OPC3EcgPackage represents an ECG sample batch.
 */
@interface OPC3EcgPackage : NSObject

/*
 *  @property isFillerSamples
 *
 *  @discussion Returns wether the samples are filler samples (because of lost packages).
 */
@property (nonatomic, readonly) BOOL isFillerSamples;

/*
 *  @property ecgRawSamples
 *
 *  @discussion Returns the raw unfiltered ECG samples.
 */
@property (nonatomic, readonly) const int8_t* ecgRawSamples;

/*
 *  @property ecgFilteredSamples
 *
 *  @discussion Returns the filtered ECG samples.
 */
@property (nonatomic, readonly) short* ecgFilteredSamples;

@end
