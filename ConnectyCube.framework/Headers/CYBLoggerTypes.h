//
//  CYBLogerTypes.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, CYBLogLevel) {
    
    CYBLogLevelNothing   =      0,  //  0 - Nothing in Log
    CYBLogLevelErrors    = 1 << 0,  //  1 - Can see Errors
    CYBLogLevelWarnings  = 1 << 1,  //  2 - Can see Warnings
    CYBLogLevelInfo      = 1 << 2,  //  4 - Some Information Loggs
    CYBLogLevelNetwork   = 1 << 3,  //  8 - Network Logs
    CYBLogLevelDebug     = NSUIntegerMax
    
} NS_SWIFT_NAME(LogLevel);
