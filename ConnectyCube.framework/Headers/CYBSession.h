//
//  CYBSession.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CYBUser;
@class CYBSessionDetails;

NS_ASSUME_NONNULL_BEGIN

//Posted immediately after logout from connectycube and session destruction;
FOUNDATION_EXPORT NSNotificationName const kCYBLogoutNotification;

/**
 CYBSession class interface.
 This class represents session information.
 */
@interface CYBSession : NSObject <NSSecureCoding>

/** The current session instance. */
@property (nonatomic, strong, readonly, class) CYBSession *currentSession;

/** Session user */
@property (nonatomic, readonly, copy, nullable) CYBUser *currentUser;

/** Returns YES if token has expired */
@property (nonatomic, readonly) BOOL tokenHasExpired;

/** Current User ID. If user id > 0 session is write*/
@property (nonatomic, readonly) NSUInteger currentUserID;

/** Session details */
@property (nonatomic, readonly, nullable) CYBSessionDetails *sessionDetails;

/** Session expiration date */
@property (nonatomic, readonly, nullable) NSDate *sessionExpirationDate;

@end

@interface CYBSession (ManualSession)

/**
 Start updated session with details
 Use this method to update session details
 
 @note updateSessionBlock block executes synchronously on background thread and you are allowed to execute
 synchronous URL request and to block a background thread from executing until you receive updated credentials
 
 @note call this method after first session start with startSessionWithDetails:updateSessionBlock:
 @note updateSessionBlock must be already set
 
 @param session CYBSessionDetails instance with updated credentials
 */
- (void)startSessionWithDetails:(CYBSessionDetails *)session;

/**
 Start session with details

 @param session CYBSessionDetails instance, token, applicationID, userID are required fields
 @param sessionDate expiration date
 */
- (void)startSessionWithDetails:(CYBSessionDetails *)session expirationDate:(NSDate *)sessionDate;

/**
 Start session with details
 Disables auto create session
 
 @note updateSessionBlock executes synchronously on background thread and you are allowed to execute
 synchronous URL request and to block a background thread from executing until you receive updated credentials
 
 @note by the end of updateSessionBlock you should call startSessionWithDetails: with updated credentials
 
 @param session CYBSessionDetails instance
 @param updateSessionBlock updateSessionBlock before the end of this block you should call startSessionWithDetails:
 */
- (void)startSessionWithDetails:(CYBSessionDetails *)session updateSessionBlock:(dispatch_block_t)updateSessionBlock;

@end

NS_ASSUME_NONNULL_END
