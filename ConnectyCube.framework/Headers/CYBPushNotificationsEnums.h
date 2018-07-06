//
//  CYBPushNotificationsEnums.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

// Event types
typedef NS_ENUM(NSUInteger, CYBEventType) {
    
    CYBEventTypeOneShot,
    CYBEventTypeFixedDate,
    CYBEventTypePeriodDate
    
} NS_SWIFT_NAME(EventType);

// Event notification types
typedef NS_ENUM(NSUInteger, CYBNotificationType) {
    
    CYBNotificationTypePush,
    CYBNotificationTypeEmail
    
} NS_SWIFT_NAME(NotificationType);

// Event push types
typedef NS_ENUM(NSUInteger, CYBMPushType) {
    
    CYBMPushTypeUndefined,
    CYBMPushTypeAPNS,
    CYBMPushTypeAPNSVOIP,
    CYBMPushTypeGCM,
    CYBMPushTypeMPNS
    
} NS_SWIFT_NAME(PushType);

// Notification channels
typedef NS_ENUM(NSUInteger, CYBNotificationChannel) {
    
    CYBNotificationChannelEmail,
    CYBNotificationChannelAPNS,
    CYBNotificationChannelAPNSVOIP,
    CYBNotificationChannelGCM,
    CYBNotificationChannelMPNS
    
} NS_SWIFT_NAME(NotificationChannel);
