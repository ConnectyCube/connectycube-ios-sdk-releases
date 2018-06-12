//
//  CYBSubscription.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <ConnectyCube/CYBSubscription.h>
#import <ConnectyCube/CYBPushNotificationsEnums.h>

NS_ASSUME_NONNULL_BEGIN

/** 
 CYBSubscription class interface.
 Class represents user subscription to push channel.
 */
NS_SWIFT_NAME(Subscription)
@interface CYBSubscription : NSObject <NSSecureCoding, NSCopying>

/**
 The ID of the subscription
 */
@property (nonatomic) NSUInteger ID;

/**
 The Date and time when the subcription was created
 */
@property (nonatomic) NSDate *createdAt;

/**
 The Date and time when the subscription was updated
 */
@property (nonatomic) NSDate *updatedAt;

/**
 Declare which notification channels could be used to notify user about events.
 */
@property (nonatomic, assign) CYBNotificationChannel notificationChannel;

/** 
 Device UDID.
 */
@property (nonatomic, copy, nullable) NSString *deviceUDID;

/**
 Device platform name.
 */
@property (nonatomic, copy, nullable) NSString *devicePlatform;

/** 
 Identifies client device in 3-rd party service like APNS, APNSVOIP, GCM, MPNS.
 */
@property(nonatomic, strong, nullable) NSData *deviceToken;

/** 
 Create new subscription.
 
 @return New instance of CYBSubscription
 */
+ (CYBSubscription *)subscription;

@end

NS_ASSUME_NONNULL_END
