//
//  CYBRequest+Auth.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ConnectyCube/CYBRequest.h>

@class CYBUser;

NS_ASSUME_NONNULL_BEGIN

@interface CYBRequest (CYBAuth)

/**
 The block with response user.
 
 @param user CYBUser instance
 */
typedef void(^CYBUserBlock)(CYBUser *user);

// MARK: - App authorization

/**
 Session Destroy.
 
 @param successBlock Block with response instance if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)destroySessionWithSuccessBlock:(nullable CYBSuccessBlock)successBlock
                                    errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - LogIn

/**
 User LogIn with login.
 
 @param login Login of CYBUser which authenticates
 @param password Password of CYBUser which authenticates
 @param successBlock Block with response and user instances if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)logInWithUserLogin:(NSString *)login
                          password:(NSString *)password
                      successBlock:(nullable CYBUserBlock)successBlock
                        errorBlock:(nullable CYBErrorBlock)errorBlock;

/**
 User LogIn with email.
 
 @param email Email of CYBUser which authenticates
 @param password Password of CYBUser which authenticates
 @param successBlock Block with response and user instances if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)logInWithUserEmail:(NSString *)email
                          password:(NSString *)password
                      successBlock:(nullable CYBUserBlock)successBlock
                        errorBlock:(nullable CYBErrorBlock)errorBlock;

/**
 User LogIn with social provider's token.
 
 @param provider Social provider. Posible values: facebook, twitter
 @param accessToken Social provider access token
 @param accessTokenSecret Social provider access token secret
 @param successBlock Block with response and user instances if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)logInWithSocialProvider:(NSString *)provider
                            accessToken:(nullable NSString *)accessToken
                      accessTokenSecret:(nullable NSString *)accessTokenSecret
                           successBlock:(nullable CYBUserBlock)successBlock
                             errorBlock:(nullable CYBErrorBlock)errorBlock;

/**
 User login using Firebase (only phone number.
 
 @param projectID Firebase project ID
 @param accessToken Access token
 @param successBlock Block with response and user instances if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @see https://firebase.google.com/docs/auth/ios/phone-auth
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)logInWithFirebaseProjectID:(NSString *)projectID
                               accessToken:(NSString *)accessToken
                              successBlock:(nullable CYBUserBlock)successBlock
                                errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - LogOut

/**
 LogOut current user.
 
 @param successBlock Block with response instance if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)logOutWithSuccessBlock:(nullable CYBSuccessBlock)successBlock
                            errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - Create User

/**
 User sign up.
 
 @param user User to signup
 @param successBlock Block with response and user instances if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @return An instance of CYBRequest. Use this instance to cancel the operation
 */
+ (CYBRequest *)signUp:(CYBUser *)user
          successBlock:(nullable CYBUserBlock)successBlock
            errorBlock:(nullable CYBErrorBlock)errorBlock;

@end

NS_ASSUME_NONNULL_END
