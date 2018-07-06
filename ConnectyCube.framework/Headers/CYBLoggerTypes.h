//
//  CYBLoggerTypes.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 Logging level.

 - CYBLogLevelNothing: Nothing in Log
 - CYBLogLevelErrors: Can see Errors
 - CYBLogLevelWarnings: Can see Warnings
 - CYBLogLevelInfo: Some Information Loggs
 - CYBLogLevelNetwork: Network logs
 - CYBLogLevelDebug: Full debug logs
 */
typedef NS_ENUM(NSUInteger, CYBLogLevel) {
    
    CYBLogLevelNothing   =      0,
    CYBLogLevelErrors    = 1 << 0,
    CYBLogLevelWarnings  = 1 << 1,
    CYBLogLevelInfo      = 1 << 2,
    CYBLogLevelNetwork   = 1 << 3,
    CYBLogLevelDebug     = NSUIntegerMax
    
} NS_SWIFT_NAME(LogLevel);
