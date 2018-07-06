//
//  CYBRequest+Users.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ConnectyCube/CYBRequest.h>

@class CYBUser;
@class CYBPaginator;
@class CYBUpdateUserParameters;

NS_ASSUME_NONNULL_BEGIN

@interface CYBRequest (CYBUsers)

NS_SWIFT_NAME(UsersPageBlock)
typedef void(^CYBUsersPageBlock)(CYBPaginator *paginator, NSArray<CYBUser *> *users);

NS_SWIFT_NAME(UserBlock)
typedef void(^CYBUserBlock)(CYBUser *user);

// MARK: - Get all Users for current account

/**
 Retrieve all Users for current account (with extended set of pagination parameters).
 
 @param paginator The object to pass a pagination parameters to server. It is useful in implementing paginated results
 @param successBlock Block with response, page and users instances if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @see CYBPaginator
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)usersWithPaginator:(nullable CYBPaginator *)paginator
                      successBlock:(nullable CYBUsersPageBlock)successBlock
                        errorBlock:(nullable CYBErrorBlock)errorBlock;

/**
 Retrieve all Users for current account with extended request.
 
 @param extendedRequest Dictionary with extended request
 @param paginator Pagination parameters
 @param successBlock Block with response, page and users instances if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @see CYBPaginator
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)usersWithExtendedRequest:(NSDictionary<NSString *, id> *)extendedRequest
                               paginator:(nullable CYBPaginator *)paginator
                            successBlock:(nullable CYBUsersPageBlock)successBlock
                              errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - Get User with ID

/**
 Retrieve User by identifier.
 
 @param userID ID of CYBUser to be retrieved
 @param successBlock Block with response and user instances if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)userWithID:(NSUInteger)userID
              successBlock:(nullable CYBUserBlock)successBlock
                errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - Get Users with IDs

/**
 Retrieve users with ids (with extended set of pagination parameters).
 
 @param IDs IDs of users which you want to retrieve
 @param paginator The object to pass a pagination parameters to server. It is useful in implementing paginated results
 @param successBlock Block with response, page and users instances if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @see CYBPaginator
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)usersWithIDs:(NSArray<NSNumber *> *)IDs
                   paginator:(nullable CYBPaginator *)paginator
                successBlock:(nullable CYBUsersPageBlock)successBlock
                  errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - Get User with login

/**
 Retrieve User by login.
 
 @param userLogin Login of user to be retrieved
 @param successBlock Block with response and user instances if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)userWithLogin:(NSString *)userLogin
                 successBlock:(nullable CYBUserBlock)successBlock
                   errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - Get Users with Logins

/**
 Retrieve users with logins (with extended set of pagination parameters).
 
 @param logins Logins of users which you want to retrieve
 @param paginator The object to pass a pagination parameters to server. It is useful in implementing paginated results
 @param successBlock Block with response, page and users instances if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @see CYBPaginator
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)usersWithLogins:(NSArray<NSString *> *)logins
                      paginator:(nullable CYBPaginator *)paginator
                   successBlock:(nullable CYBUsersPageBlock)successBlock
                     errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - Get Users with full name

/**
 Retrieve Users by full name for current account (with extended set of pagination parameters).
 
 @param userFullName Full name of users to be retrieved
 @param paginator The object to pass a pagination parameters to server. It is useful in implementing paginated results
 @param successBlock Block with response, page and users instances if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @see CYBPaginator
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)usersWithFullName:(NSString *)userFullName
                        paginator:(nullable CYBPaginator *)paginator
                     successBlock:(nullable CYBUsersPageBlock)successBlock
                       errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - Get Users with tags

/**
 Retrieve Users by tags for current account (with extended set of pagination parameters).
 
 @param tags Tags of users to be retrieved
 @param paginator The object to pass a pagination parameters to server. It is useful in implementing paginated results
 @param successBlock Block with response, page and users instances if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @see CYBPaginator
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)usersWithTags:(NSArray<NSString *> *)tags
                    paginator:(nullable CYBPaginator *)paginator
                 successBlock:(nullable CYBUsersPageBlock)successBlock
                   errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - Get Users with phone numbers

/**
 Retrieve users with phone numbers (with extended set of pagination parameters).
 
 @param phoneNumbers Pnone numbers of users which you want to retrieve
 @param paginator The object to pass a pagination parameters to server. It is useful in implementing paginated results
 @param successBlock Block with response, page and users instances if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @see CYBPaginator
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)usersWithPhoneNumbers:(NSArray<NSString *> *)phoneNumbers
                            paginator:(nullable CYBPaginator *)paginator
                         successBlock:(nullable CYBUsersPageBlock)successBlock
                           errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - Get User with Facebook ID

/**
 Retrieve User by Facebook ID.
 
 @param userFacebookID Facebook ID of user to be retrieved
 @param successBlock Block with response and user instances if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)userWithFacebookID:(NSString *)userFacebookID
                      successBlock:(nullable CYBUserBlock)successBlock
                        errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - Get Users Facebook IDs

/**
 Retrieve users with facebook ids (with extended set of pagination parameters).
 
 @param facebookIDs Facebook IDs of users which you want to retrieve
 @param paginator The object to pass a pagination parameters to server. It is useful in implementing paginated results
 @param successBlock Block with response, page and users instances if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @see CYBPaginator
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)usersWithFacebookIDs:(NSArray<NSString *> *)facebookIDs
                           paginator:(nullable CYBPaginator *)paginator
                        successBlock:(nullable CYBUsersPageBlock)successBlock
                          errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - Get User with Twitter ID

/**
 Retrieve User by Twitter ID.
 
 @param userTwitterID Twitter ID of user to be retrieved
 @param successBlock Block with response and user instances if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)userWithTwitterID:(NSString *)userTwitterID
                     successBlock:(nullable CYBUserBlock)successBlock
                       errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - Get Users Twitter IDs

/**
 Retrieve users with twitter ids (with extended set of pagination parameters).
 
 @param twitterIDs Twitter IDs of users which you want to retrieve
 @param paginator The object to pass a pagination parameters to server. It is useful in implementing paginated results
 @param successBlock Block with response, page and users instances if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @see CYBPaginator
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)usersWithTwitterIDs:(NSArray <NSString *> *)twitterIDs
                          paginator:(nullable CYBPaginator *)paginator
                       successBlock:(nullable CYBUsersPageBlock)successBlock
                         errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - Get User with email

/**
 Retrieve User by Email.
 
 @param userEmail Email of user to be retrieved
 @param successBlock Block with response and user instances if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)userWithEmail:(NSString *)userEmail
                 successBlock:(nullable CYBUserBlock)successBlock
                   errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - Get Users with emails

/**
 Retrieve users with email (with extended set of pagination parameters).
 
 @param emails Emails of users which you want to retrieve
 @param paginator The object to pass a pagination parameters to server. It is useful in implementing paginated results
 @param successBlock Block with response, page and users instances if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @see CYBPaginator
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)usersWithEmails:(NSArray<NSString *> *)emails
                      paginator:(nullable CYBPaginator *)paginator
                   successBlock:(nullable CYBUsersPageBlock)successBlock
                     errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - Get User with external ID

/**
 Retrieve User by External identifier.
 
 @param userExternalID External ID of user to be retrieved
 @param successBlock Block with response and user instances if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)userWithExternalID:(NSUInteger)userExternalID
                      successBlock:(nullable CYBUserBlock)successBlock
                        errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - Update User

/**
 Update current session user.
 
 @param parameters   User parameters that could be updated
 @param successBlock Block with response and user instances if the request is succeeded
 @param errorBlock   Block with response instance if the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)updateCurrentUser:(CYBUpdateUserParameters *)parameters
                     successBlock:(nullable CYBUserBlock)successBlock
                       errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - Delete Current User

/**
 Delete Current User.
 
 @note You should login firstly in order to delete current user
 
 @param successBlock Block with response instance if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)deleteCurrentUserWithSuccessBlock:(nullable CYBSuccessBlock)successBlock
                                       errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - Reset password

/**
 Reset user's password. User with this email will retrieve an email instruction for reset password.
 
 @param email User's email
 @param successBlock Block with response instance if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)resetUserPasswordWithEmail:(NSString *)email
                              successBlock:(nullable CYBSuccessBlock)successBlock
                                errorBlock:(nullable CYBErrorBlock)errorBlock;
@end

NS_ASSUME_NONNULL_END
