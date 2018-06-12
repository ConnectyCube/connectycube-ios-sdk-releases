//
//  CYBPushToken.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 CYBPushToken class declaration.
 Class represents push token, that uniquely identifies the application.
 (for APNS - it's token, for GCM - it's registration Id, for MPNS - it's uri).
 */
NS_SWIFT_NAME(PushToken)
@interface CYBPushToken : NSObject <NSSecureCoding, NSCopying>

/**
 The ID of the token
 */
@property (nonatomic) NSUInteger ID;

/**
 The Date and time when the token was created
 */
@property (nonatomic) NSDate *createdAt;

/**
 The Date and time when the token was updated
 */
@property (nonatomic) NSDate *updatedAt;

/** 
 Identifies client device in 3-rd party service like APNS, GCM, MPNS.
 */
@property(nonatomic, copy, nullable) NSString *clientIdentificationSequence;

/** 
 Set custom UDID or use auto-generated UDID if customUDID is nil.
 */
@property(nonatomic, copy, nullable) NSString *customUDID;

/** 
 Create new push token.
 
 @return New instance of CYBPushToken
 */
+ (CYBPushToken *)pushToken;

/** 
 Create new push token.
 
 @return New instance of CYBPushToken with custom UDID
 */
+ (CYBPushToken *)pushTokenWithCustomUDID:(nullable NSString *)customUDID;

@end

NS_ASSUME_NONNULL_END
