//
//  CYBCustomObjectFile.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 CYBCustomObjectFile class interface.
 This class represents custom object file interface.
 */
NS_SWIFT_NAME(CustomObjectFile)
@interface CYBCustomObjectFile : NSObject <NSSecureCoding, NSCopying>

/** 
 The name of the file.
 */
@property (nonatomic, copy, nullable) NSString *name;

/**
 The content type of the file.
 */
@property (nonatomic, copy, nullable) NSString *contentType;

/**
 The data of the file.
 */
@property (nonatomic, strong, nullable) NSData *data;

/**
 The Local url of the file.
 */
@property (nonatomic, strong, nullable) NSURL *fileURL;

/** 
 Create file object.
 
 @return New instance of `CYBCustomObjectFile`
 */
+ (instancetype)file;

@end

NS_ASSUME_NONNULL_END
