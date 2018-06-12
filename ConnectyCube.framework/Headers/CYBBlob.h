//
//  CYBBlob.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ConnectyCube/CYBStorageTypes.h>

@class CYBBlobObjectAccess;

NS_ASSUME_NONNULL_BEGIN

/**
 CYBBlob class interface.
 This class represents File in Content module. Limitations: max size of file is 100mb.
 */
NS_SWIFT_NAME(Blob)
@interface CYBBlob : NSObject <NSSecureCoding, NSCopying>

/**
 The ID of the blob
 */
@property (nonatomic) NSUInteger ID;

/**
 The Date and time when the blob was created
 */
@property (nonatomic) NSDate *createdAt;

/**
 The Date and time when the blob was updated
 */
@property (nonatomic) NSDate *updatedAt;
/**
 Content type in mime format.
 */
@property (nonatomic, copy, nullable) NSString *contentType;

/**
 File name.
 */
@property (nonatomic, copy, nullable) NSString *name;

/**
 Status of the File.
 */
@property (nonatomic) CYBBlobStatus status;

/**
 Date when the file upload has been completed.
 */
@property (nonatomic, nullable) NSDate *completedAt;

/**
 The size of file in bytes, readonly
 */
@property (nonatomic) NSUInteger size;

/**
 File unique identifier.
 */
@property (nonatomic, copy, nullable) NSString *UID;

/**
 Last read file time.
 */
@property (nonatomic, nullable) NSDate *lastReadAccessTs;

/**
 An instance of BlobObjectAccess.
 */
@property (nonatomic, nullable) CYBBlobObjectAccess *blobObjectAccess;

/**
 Coma separated string with file's tags.
 */
@property (nonatomic, copy, nullable) NSString *tags;

/**
 File's visibility.
 */
@property (nonatomic) BOOL isPublic;

/**
 Set as YES if you want to update blob's file.
 */
@property (nonatomic) BOOL isNew;

/**
 Create new blob.
 
 @return New CYBBlob instance
 */
+ (CYBBlob *)blob;

/**
 Get file's public url (available within Internet), if blob is public.
 
 @return Public url for file
 */
- (nullable NSString *)publicUrl;

/**
 Get file's public url (available within Internet), if blob is public.
 
 @param fileUID File unique identifier
 
 @return Public url to file
 */
+ (nullable NSString *)publicUrlForFileUID:(NSString *)fileUID;

/**
 Get file's private url (available only with ConnectyCube token), if blob is private.
 
 @return Private url for file
 */
- (nullable NSString *)privateUrl;

/**
 Get file's private url (available only with ConnectyCube token), if blob is private.

 @param fileUID File unique identifier
 
 @return Private url to file
 */
+ (nullable NSString *)privateUrlForFileUID:(NSString *)fileUID;

@end

NS_ASSUME_NONNULL_END
