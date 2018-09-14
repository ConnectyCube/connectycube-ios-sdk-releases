//
//  CYBRequest.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CYBRequest;

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSInteger, CYBErrorCode) {
    
    CYBErrorCodeCancelled = NSURLErrorCancelled,
    CYBErrorCodeUnknown = -1,
    CYBErrorCodeAccepted = 202,
    CYBErrorCodeCreated = 201,
    CYBErrorCodeForbidden = 403,
    CYBErrorCodeNotFound = 404,
    CYBErrorCodeOK = 200,
    CYBErrorCodeBadRequest = 400,
    CYBErrorCodeServerError = 500,
    CYBErrorCodeUnAuthorized = 401,
    CYBErrorCodeValidationFailed = 422
} NS_SWIFT_NAME(ErrorCode);

/** Block with progress */
NS_SWIFT_NAME(ProgressBlock)
typedef void(^CYBProgressBlock)(float progress);

/** Block with error */
NS_SWIFT_NAME(ErrorBlock)
typedef void(^CYBErrorBlock)(NSError *error);

/** Success block */
NS_SWIFT_NAME(SuccessBlock)
typedef void(^CYBSuccessBlock)(void);

/**
 CYBRequest class interface.
 This class represents all requests to ConnectyCube API.
 */
NS_SWIFT_NAME(Request)
@interface CYBRequest : NSObject

/**
 The NSURLSessionTask class is the base class for tasks in a URL session.
 */
@property (nonatomic, readonly) NSURLSessionTask *task;

/**
 Determines if NSURLSessionTask was canceled.
 */
@property (nonatomic, getter=isCancelled, readonly) BOOL canceled;

/** - init is unavailable */
- (id)init NS_UNAVAILABLE;

/** + new is unavailable */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Cancels NSURLSessionTask associated with request.
 */
- (void)cancel;

/**
 Cancel all request

 @param completion completion callback
 */
+ (void)cancelAllRequests:(dispatch_block_t)completion;

@end

NS_ASSUME_NONNULL_END
