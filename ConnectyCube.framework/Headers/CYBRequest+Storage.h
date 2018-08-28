//
//  CYBRequest+Storage.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ConnectyCube/CYBRequest.h>

@class CYBBlob;
@class CYBBlobObjectAccess;
@class CYBPaginator;

NS_ASSUME_NONNULL_BEGIN

/** Block with CYBBlob instance */
NS_SWIFT_NAME(BlobBlock)
typedef void(^CYBBlobBlock)(CYBBlob *blob);

/** Block with NSData instance */
NS_SWIFT_NAME(FileDataBlock)
typedef void(^CYBFileDataBlock)(NSData *data);

/** Block with paginator and array of CYBBlob instances */
NS_SWIFT_NAME(BlobsPageBlock)
typedef void(^CYBBlobsPageBlock)(CYBPaginator *paginator, NSArray<CYBBlob *> * blobs);

/** Block with CYBBlobObjectAccess instance */
NS_SWIFT_NAME(BlobObjectAccessBlock)
typedef void(^CYBBlobObjectAccessBlock)(CYBBlobObjectAccess *objectAccess);

/** Methods that provide Storage functionality */
@interface CYBRequest (Storage)

// MARK: - Create Blob

/**
 Create blob.
 
 @param blob An instance of CYBBlob, describing the file to be uploaded
 @param successBlock Block with created blob instance if the request is succeeded
 @param errorBlock Block with error instance if the request is failed
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)createBlob:(CYBBlob *)blob
              successBlock:(nullable CYBBlobBlock)successBlock
                errorBlock:(nullable CYBErrorBlock)errorBlock;


// MARK: - Get Blob with ID

/**
 Retrieve blob with ID.
 
 @param blobID Unique blob identifier, value of ID property of the CYBBlob instance
 @param successBlock Block blob instance if the request is succeeded
 @param errorBlock Block with NSError instance if the request is failed
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)blobWithID:(NSUInteger)blobID
              successBlock:(nullable CYBBlobBlock)successBlock
                errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - Get list of blobs for the current user

/**
 Get list of blob for the current User (with extended set of pagination parameters).
 
 @param paginator The object to pass a pagination parameters to server. It is useful in implementing paginated results
 @param successBlock Block with paginator and blobs instances if the request is succeeded
 @param errorBlock Block with NSError instance if the request is failed
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)blobsWithPaginator:(nullable CYBPaginator *)paginator
                      successBlock:(nullable CYBBlobsPageBlock)successBlock
                        errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - Update Blob

/**
 Update Blob.
 
 @param blob An instance of CYBBlob to be updated
 @param successBlock Block with updated blob instance if the request is succeeded
 @param errorBlock Block with NSError instance if the request is failed
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)updateBlob:(CYBBlob *)blob
              successBlock:(nullable CYBBlobBlock)successBlock
                errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - Delete Blob with ID

/**
 Delete Blob.
 
 @param blobID Unique blob identifier, value of ID property of the CYBBlob instance
 @param successBlock The block is called if the request succeeded
 @param errorBlock Block with NSError instance if the request is failed
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)deleteBlobWithID:(NSUInteger)blobID
                    successBlock:(nullable CYBSuccessBlock)successBlock
                      errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - Get File by ID as BlobObjectAccess

/**
 Get File by ID as BlobObjectAccess with read access.
 
 @param blobID Unique blob identifier, value of ID property of the CYBBlob instance
 @param successBlock Block with blob instances if the request is succeeded
 @param errorBlock Block with NSError instance if the request is failed
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)blobObjectAccessWithBlobID:(NSUInteger)blobID
                              successBlock:(nullable void(^)(CYBBlobObjectAccess *objectAccess))successBlock
                                errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - Upload file using BlobObjectAccess

/**
 Upload file using BlobObjectAccess.
 
 @param data File data
 @param blobWithWriteAccess An instance of CYBBlobObjectAccess
 @param progressBlock Block with upload/download progress
 @param successBlock Block which is called in case of success response
 @param errorBlock  Block with NSError instance if the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)uploadFileWithData:(NSData *)data
               blobWithWriteAccess:(CYBBlob *)blobWithWriteAccess
                     progressBlock:(nullable CYBProgressBlock)progressBlock
                      successBlock:(nullable CYBSuccessBlock)successBlock
                        errorBlock:(nullable CYBErrorBlock)errorBlock;

/**
 Upload file using BlobObjectAccess.
 
 @param url File URL
 @param blobWithWriteAccess An instance of CYBBlobObjectAccess
 @param progressBlock Block with upload/download progress
 @param successBlock Block which is called in case of success response
 @param errorBlock Block with NSError instance if the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)uploadFileWithUrl:(NSURL *)url
              blobWithWriteAccess:(CYBBlob *)blobWithWriteAccess
                    progressBlock:(nullable CYBProgressBlock)progressBlock
                     successBlock:(nullable CYBSuccessBlock)successBlock
                       errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: -  Download file

/**
 Download file.
 
 @param UID File unique identifier, value of UID property of the CYBBlob instance
 @param progressBlock Block with download progress
 @param successBlock Block which is called in case of success response
 @param errorBlock Block with NSError instance if the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)downloadFileWithUID:(NSString *)UID
                      progressBlock:(nullable CYBProgressBlock)progressBlock
                       successBlock:(nullable CYBFileDataBlock)successBlock
                         errorBlock:(nullable CYBErrorBlock)errorBlock;

/**
 Download file using background NSURLSession.
 
 @discussion If download is triggered by 'content-available' push - blocks will not be fired.
 
 @param UID File unique identifier, value of UID property of the CYBBlob instance
 @param progressBlock Block with download progress
 @param successBlock The block is called if the request succeeded
 @param errorBlock Block with NSError instance if the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)backgroundDownloadFileWithUID:(NSString *)UID
                                progressBlock:(nullable CYBProgressBlock)progressBlock
                                 successBlock:(nullable CYBFileDataBlock)successBlock
                                   errorBlock:(nullable CYBErrorBlock)errorBlock;

/**
 Download File by file identifier.
 
 @param fileID File identifier
 @param progressBlock Block with download progress
 @param successBlock Block with fileData if the request is succeeded
 @param errorBlock Block with NSError instance if the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)downloadFileWithID:(NSUInteger)fileID
                     progressBlock:(nullable CYBProgressBlock)progressBlock
                      successBlock:(nullable CYBFileDataBlock)successBlock
                        errorBlock:(nullable CYBErrorBlock)errorBlock;

/**
 Download File by file identifier using background NSURLSession.
 
 @discussion If download is triggered by 'content-available' push - blocks will not be fired.
 
 @param fileID File identifier
 @param progressBlock Block with download progress
 @param successBlock Block with file Data if the request is succeeded
 @param errorBlock  Block with NSError instance if the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)backgroundDownloadFileWithID:(NSUInteger)fileID
                               progressBlock:(nullable CYBProgressBlock)progressBlock
                                successBlock:(nullable CYBFileDataBlock)successBlock
                                  errorBlock:(nullable CYBErrorBlock)errorBlock;
// MARK: - Tasks

/**
 Upload File task. Contains 3 requests: Create Blob, upload file, declaring file uploaded.
 
 @param data File to be uploaded
 @param fileName Name of the file
 @param contentType Type of the content in mime format
 @param isPublic Blob's visibility
 @param progressBlock Block with upload progress
 @param successBlock Block which is called in case of success response
 @param errorBlock Block with NSError instance if the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)uploadFileWithData:(NSData *)data
                          fileName:(NSString *)fileName
                       contentType:(NSString *)contentType
                          isPublic:(BOOL)isPublic
                     progressBlock:(nullable CYBProgressBlock)progressBlock
                      successBlock:(nullable CYBBlobBlock)successBlock
                        errorBlock:(nullable CYBErrorBlock)errorBlock;

/**
 Upload File task. Contains 3 requests: Create Blob, upload file, declaring file uploaded.
 
 @param url File url to be uploaded
 @param fileName Name of the file
 @param contentType Type of the content in mime format
 @param isPublic Blob's visibility
 @param progressBlock Block with upload progress
 @param successBlock Block which is called in case of success response
 @param errorBlock Block with NSError instance if the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)uploadFileWithUrl:(NSURL *)url
                         fileName:(NSString *)fileName
                      contentType:(NSString *)contentType
                         isPublic:(BOOL)isPublic
                    progressBlock:(nullable CYBProgressBlock)progressBlock
                     successBlock:(nullable CYBBlobBlock)successBlock
                       errorBlock:(nullable CYBErrorBlock)errorBlock;
/**
 Update File task. Contains 3 quieries: Update Blob, Upload file, Declaring file uploaded.
 
 @param data File to be uploaded
 @param file File which needs to be updated
 @param progressBlock Block with upload progress
 @param successBlock Block which is called in case of success response
 @param errorBlock Block with NSError instance if the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)updateFileWithData:(NSData *)data
                              file:(CYBBlob *)file
                     progressBlock:(nullable CYBProgressBlock)progressBlock
                      successBlock:(nullable CYBSuccessBlock)successBlock
                        errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - Declaring Blob uploaded with ID

/**
 Declaring Blob uploaded with ID.
 
 @param blobID Unique blob identifier, value of ID property of the CYBBlob instance
 @param size Size of uploaded file, in bytes
 @param successBlock Block which is called in case of success response
 @param errorBlock Block with NSError instance if the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)completeBlobWithID:(NSUInteger)blobID
                              size:(NSUInteger)size
                      successBlock:(nullable CYBSuccessBlock)successBlock
                        errorBlock:(nullable CYBErrorBlock)errorBlock;

@end

NS_ASSUME_NONNULL_END
