//
//  CYBLoggerTypes.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

/** Logging level. */
typedef NS_ENUM(NSUInteger, CYBLogLevel) {
    /** Nothing in Log */
    CYBLogLevelNothing = 0,
    /** Can see Errors */
    CYBLogLevelErrors = 1 << 0,
    /** Can see Warnings */
    CYBLogLevelWarnings = 1 << 1,
    /** Some Information Loggs */
    CYBLogLevelInfo = 1 << 2,
    /** Network logs */
    CYBLogLevelNetwork = 1 << 3,
    /** Full debug logs */
    CYBLogLevelDebug = NSUIntegerMax
    
} NS_SWIFT_NAME(LogLevel);
