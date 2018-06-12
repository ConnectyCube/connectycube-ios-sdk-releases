//
//  CYBBlobObjectAccess.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ConnectyCube/CYBStorageTypes.h>

/**
 CYBBlobObjectAccess class interface.
 This class represents entity that uses for upload file to server.
 */
NS_SWIFT_NAME(BlobObjectAccess)
@interface CYBBlobObjectAccess : NSObject <NSSecureCoding, NSCopying>

/**
 Blob ID.
 */
@property (nonatomic, assign) NSUInteger blobID;

/** 
 Link access type.
 */
@property (nonatomic, assign) CYBBlobObjectAccessType type;

/** 
 Reference expiration time.
 */
@property (nonatomic, strong, nullable) NSDate *expires;

/** 
 Url with params.
 
 @discussion Use it for upload file.
 */
@property (nonatomic, copy, nullable) NSString *urlWithParams;

/**
 Params.
 
 @discussion Use them for upload file.
 */
@property (nonatomic, copy, nullable) NSDictionary *params;

/** 
 Url with params.
 
 @discussion Use it for upload file.
 */
@property (nonatomic, strong, nullable) NSURL *url;

/** 
 Check link expiration date.
 
 @return YES if link is expired, otherwise NO
 */
@property (nonatomic, readonly) BOOL expired;

@end
