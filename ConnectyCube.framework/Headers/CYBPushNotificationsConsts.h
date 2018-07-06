//
//  CYBPushNotificationsConsts.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString * const CYBEventMessagePayloadKey NS_SWIFT_NAME(EventMessagePayloadKey);

extern NSString * const CYBEventMessagePushAlertKey NS_SWIFT_NAME(EventMessagePushAlertKey);
extern NSString * const CYBEventMessagePushBadgeKey NS_SWIFT_NAME(EventMessagePushBadgeKey);
extern NSString * const CYBEventMessagePushSoundKey NS_SWIFT_NAME(EventMessagePushSoundKey);

// Push message dict keys
extern NSString * const CYBPushMessageAdditionalInfoKey NS_SWIFT_NAME(PushMessageAdditionalInfoKey);
extern NSString * const CYBPushMessageApsKey NS_SWIFT_NAME(PushMessageApsKey);
extern NSString * const CYBPushMessageAlertKey NS_SWIFT_NAME(PushMessageAlertKey);
extern NSString * const CYBPushMessageAlertBodyKey NS_SWIFT_NAME(PushMessageAlertBodyKey);
extern NSString * const CYBPushMessageAlertActionLocKey NS_SWIFT_NAME(PushMessageAlertActionLocKey);
extern NSString * const CYBPushMessageAlertLocKey NS_SWIFT_NAME(PushMessageAlertLocKey);
extern NSString * const CYBPushMessageAlertLocArgsKey NS_SWIFT_NAME(PushMessageAlertLocArgsKey);
extern NSString * const CYBPushMessageAlertLaunchImageKey NS_SWIFT_NAME(PushMessageAlertLaunchImageKey);
extern NSString * const CYBPushMessageBadgeKey NS_SWIFT_NAME(PushMessageBadgeKey);
extern NSString * const CYBPushMessageSoundKey NS_SWIFT_NAME(PushMessageSoundKey);
extern NSString * const CYBPushMessageRichContentKey NS_SWIFT_NAME(PushMessageRichContentKey);

// Event types
extern NSString * const kCYBEventTypeOneShot NS_SWIFT_NAME(EventTypeOneShot);
extern NSString * const kCYBEventTypeFixedDate NS_SWIFT_NAME(EventTypeFixedDate);
extern NSString * const kCYBEventTypePeriodDate NS_SWIFT_NAME(EventTypePeriodDate);
extern NSString * const kCYBEventTypeMultiShot NS_SWIFT_NAME(EventTypeMultiShot);

// Notification channels
extern NSString * const kCYBNotificationChannelsEmail NS_SWIFT_NAME(NotificationChannelsEmail);
extern NSString * const kCYBNotificationChannelsAPNS NS_SWIFT_NAME(NotificationChannelsAPNS);
extern NSString * const kCYBNotificationChannelsAPNSVOIP NS_SWIFT_NAME(NotificationChannelsAPNSVOIP);
extern NSString * const kCYBNotificationChannelsGCM NS_SWIFT_NAME(NotificationChannelsGCM);
extern NSString * const kCYBNotificationChannelsMPNS NS_SWIFT_NAME(NotificationChannelsMPNS);

// Notification type
extern NSString * const kCYBNotificationTypePush NS_SWIFT_NAME(NotificationTypePush);
extern NSString * const kCYBNotificationTypeEmail NS_SWIFT_NAME(NotificationTypeEmail);

// Push type
extern NSString * const kCYBPushTypeAPNS NS_SWIFT_NAME(PushTypeAPNS);
extern NSString * const kCYBPushTypeAPNSVOIP NS_SWIFT_NAME(PushTypeAPNSVOIP);
extern NSString * const kCYBPushTypeGCM NS_SWIFT_NAME(PushTypeGCM);
extern NSString * const kCYBPushTypeMPNS NS_SWIFT_NAME(PushTypeMPNS);

NS_ASSUME_NONNULL_END
