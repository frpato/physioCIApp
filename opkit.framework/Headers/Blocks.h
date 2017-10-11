//
//  Blocks.h
//  opkit
//
//  Created by Heine Skov Kristensen on 19/08/16.
//  Copyright © 2016 cortrium. All rights reserved.
//

#ifndef Blocks_h
#define Blocks_h

#import "OPC3Modes.h"

typedef void (^ModeBlock)(OPC3Modes mode);
typedef void (^FailureBlock)(NSError *error);
typedef void (^EmptyBlock)();

#endif /* Blocks_h */
