//
//  CYBPushNotificationsConsts.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const CYBEventMessagePayloadKey;

extern NSString * const CYBEventMessagePushAlertKey;
extern NSString * const CYBEventMessagePushBadgeKey;
extern NSString * const CYBEventMessagePushSoundKey;

// Push message dict keys
extern NSString * const CYBPushMessageAdditionalInfoKey;
extern NSString * const CYBPushMessageApsKey;
extern NSString * const CYBPushMessageAlertKey;
extern NSString * const CYBPushMessageAlertBodyKey;
extern NSString * const CYBPushMessageAlertActionLocKey;
extern NSString * const CYBPushMessageAlertLocKey;
extern NSString * const CYBPushMessageAlertLocArgsKey;
extern NSString * const CYBPushMessageAlertLaunchImageKey;
extern NSString * const CYBPushMessageBadgeKey;
extern NSString * const CYBPushMessageSoundKey;
extern NSString * const CYBPushMessageRichContentKey;

// Event types
extern NSString * const kCYBEventTypeOneShot;
extern NSString * const kCYBEventTypeFixedDate;
extern NSString * const kCYBEventTypePeriodDate;
extern NSString * const kCYBEventTypeMultiShot;

// Notification channels
extern NSString * const kCYBNotificationChannelsEmail;
extern NSString * const kCYBNotificationChannelsAPNS;
extern NSString * const kCYBNotificationChannelsAPNSVOIP;
extern NSString * const kCYBNotificationChannelsGCM;
extern NSString * const kCYBNotificationChannelsMPNS;

// Notification type
extern NSString * const kCYBNotificationTypePush;
extern NSString * const kCYBNotificationTypeEmail;

// Push type
extern NSString * const kCYBMPushTypeAPNS;
extern NSString * const kCYBMPushTypeAPNSVOIP;
extern NSString * const kCYBMPushTypeGCM;
extern NSString * const kCYBMPushTypeMPNS;

NS_ASSUME_NONNULL_END
