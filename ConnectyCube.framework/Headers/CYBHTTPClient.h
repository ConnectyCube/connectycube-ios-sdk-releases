//
//  CYBHTTPClient.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@class CYBRequest;

/** Block with NSURLSessionDataTask instance */
NS_SWIFT_NAME(TaskBlock)
typedef void(^CYBTaskBlock)(NSURLSessionDataTask *task);

/** Block with NSURLSessionDataTask and NSData instances */
NS_SWIFT_NAME(TaskDataBlock)
typedef void(^CYBTaskDataBlock)(NSURLSessionDataTask *task, NSData *responseObject);

/** Block with NSURLSessionDataTask and NSError instances */
NS_SWIFT_NAME(TaskErrorBlock)
typedef void(^CYBTaskErrorBlock)(NSURLSessionDataTask * _Nullable task, NSError *error);

/** Block with NSProgress instance */
NS_SWIFT_NAME(TaskProgressBlock)
typedef void(^CYBTaskProgressBlock)(NSProgress *downloadProgress);

/**
 CYBHTTPClient class interface.
 This class is designed to perform http requests to the endpoint.
 */
NS_SWIFT_NAME(HTTPClient)
@interface CYBHTTPClient : NSObject

/**
 Current NSURLSession
 */
@property (readonly, nonatomic) NSURLSession *session;

/**
 The dispatch queue for `completionBlock`. If `NULL` (default), the main queue is used.
 */
@property (nonatomic, nullable) dispatch_queue_t completionQueue;

/** - init is unavailable */
- (id)init NS_UNAVAILABLE;

/** + new is unavailable */
+ (instancetype)new NS_UNAVAILABLE;

/**
 Initializes an `CYBHTTPClient` object with the specified base URL.
 
 @param url The base URL for the HTTP client
 
 @return The newly-initialized HTTP client
 */
- (instancetype)initWithBaseURL:(nullable NSURL *)url;

/**
 Initializes an `CYBHTTPClient` object with the specified base URL.
 
 @remark This is the designated initializer.
 
 @param url The base URL for the HTTP client
 @param configuration The configuration used to create the managed session
 
 @return The newly-initialized HTTP client
 */
- (instancetype)initWithBaseURL:(nullable NSURL *)url
           sessionConfiguration:(nullable NSURLSessionConfiguration *)configuration NS_DESIGNATED_INITIALIZER;

/**
 Creates and runs an `CYBRequest` with a `GET` request.
 
 @param URLString The URL string used to create the request URL
 @param parameters The parameters to be encoded according to the client request serializer
 @param downloadProgress A block object to be executed when the download progress is updated. Note this block is called on the session queue, not the main queue
 @param success A block object to be executed when the task finishes successfully. This block has no return value and takes two arguments: the data task, and the response object
 @param failure A block object to be executed when the task finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes a two arguments: the data task and the error describing the network or parsing error that occurred
 */
- (CYBRequest *)GET:(NSString *)URLString
         parameters:(nullable id)parameters
           progress:(nullable CYBTaskProgressBlock)downloadProgress
            success:(nullable CYBTaskDataBlock)success
            failure:(nullable CYBTaskErrorBlock)failure;

/**
 Creates and runs an `CYBRequest` with a `HEAD` request.
 
 @param URLString The URL string used to create the request URL
 @param parameters The parameters to be encoded according to the client request serializer
 @param success A block object to be executed when the task finishes successfully. This block has no return value and takes a single arguments: the data task
 @param failure A block object to be executed when the task finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes a two arguments: the data task and the error describing the network or parsing error that occurred
 */
- (CYBRequest *)HEAD:(NSString *)URLString
          parameters:(nullable id)parameters
             success:(nullable CYBTaskBlock)success
             failure:(nullable CYBTaskErrorBlock)failure;

/**
 Creates and runs an `CYBRequest` with a `POST` request.
 
 @param URLString The URL string used to create the request URL
 @param parameters The parameters to be encoded according to the client request serializer
 @param uploadProgress A block object to be executed when the upload progress is updated. Note this block is called on the session queue, not the main queue
 @param success A block object to be executed when the task finishes successfully. This block has no return value and takes two arguments: the data task, and the response object created by the client response serializer
 @param failure A block object to be executed when the task finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes a two arguments: the data task and the error describing the network or parsing error that occurred
 */
- (CYBRequest *)POST:(NSString *)URLString
          parameters:(nullable id)parameters
            progress:(nullable CYBTaskProgressBlock)uploadProgress
             success:(nullable CYBTaskDataBlock)success
             failure:(nullable CYBTaskErrorBlock)failure;

/**
 Creates and runs an `CYBRequest` with a `PUT` request.
 
 @param URLString The URL string used to create the request URL
 @param parameters The parameters to be encoded according to the client request serializer
 @param success A block object to be executed when the task finishes successfully. This block has no return value and takes two arguments: the data task, and the response object created by the client response serializer
 @param failure A block object to be executed when the task finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes a two arguments: the data task and the error describing the network or parsing error that occurred
 */
- (CYBRequest *)PUT:(NSString *)URLString
         parameters:(nullable id)parameters
            success:(nullable CYBTaskDataBlock)success
            failure:(nullable CYBTaskErrorBlock)failure;

/**
 Creates and runs an `CYBRequest` with a `PATCH` request.
 
 @param URLString The URL string used to create the request URL
 @param parameters The parameters to be encoded according to the client request serializer
 @param success A block object to be executed when the task finishes successfully. This block has no return value and takes two arguments: the data task, and the response object created by the client response serializer
 @param failure A block object to be executed when the task finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes a two arguments: the data task and the error describing the network or parsing error that occurred
 */
- (CYBRequest *)PATCH:(NSString *)URLString
           parameters:(nullable id)parameters
              success:(nullable CYBTaskDataBlock)success
              failure:(nullable CYBTaskErrorBlock)failure;

/**
 Creates and runs an `CYBRequest` with a `DELETE` request.
 
 @param URLString The URL string used to create the request URL
 @param parameters The parameters to be encoded according to the client request serializer
 @param success A block object to be executed when the task finishes successfully. This block has no return value and takes two arguments: the data task, and the response object created by the client response serializer
 @param failure A block object to be executed when the task finishes unsuccessfully, or that finishes successfully, but encountered an error while parsing the response data. This block has no return value and takes a two arguments: the data task and the error describing the network or parsing error that occurred
 */
- (CYBRequest *)DELETE:(NSString *)URLString
            parameters:(nullable id)parameters
               success:(nullable CYBTaskDataBlock)success
               failure:(nullable CYBTaskErrorBlock)failure;
@end

NS_ASSUME_NONNULL_END
