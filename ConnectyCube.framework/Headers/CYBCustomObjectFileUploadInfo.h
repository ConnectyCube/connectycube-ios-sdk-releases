//
//  CYBCustomObjectFileUploadInfo.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(CustomObjectFileUploadInfo)
@interface CYBCustomObjectFileUploadInfo : NSObject <NSSecureCoding, NSCopying>

/**
 Unique file ID.
 */
@property (nonatomic, copy, nullable) NSString *fileIdentifier;

/**
 Size of uploaded file, in bytes.
 */
@property (nonatomic, assign) NSUInteger size;

/**
 File name (min 1 chars. max 100 chars)
 */
@property (nonatomic, copy, nullable) NSString *name;

/**
 Portable Network Graphics; mime content type (max 50 chars).
 */
@property (nonatomic, copy, nullable) NSString *contentType;

@end

NS_ASSUME_NONNULL_END
