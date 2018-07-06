//
//  CYBEvent.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ConnectyCube/CYBPushNotificationsEnums.h>

NS_ASSUME_NONNULL_BEGIN

/** 
 CYBEvent class interface.
 Event representation. If you want to send Apple push - use the CYBApplePushEvent subclass.
 */
NS_SWIFT_NAME(Event)
@interface CYBEvent : NSObject <NSSecureCoding, NSCopying>

/**
 The ID of the event.
 */
@property (nonatomic) NSUInteger ID;

/**
 The Date and time when the event was created.
 */
@property (nonatomic) NSDate *createdAt;

/**
 The Date and time when the event was updated.
 */
@property (nonatomic) NSDate *updatedAt;

/** 
 Event state.
 
 @discussion If you want to send specific notification more than once - just edit Event & set this field to 'YES', Then push will be send immediately, without creating a new one Event.
 */
@property (nonatomic, assign) BOOL active;

/** 
 Notification type.
 */
@property (nonatomic, assign) CYBNotificationType notificationType;

/** 
 Push type.
 */
@property (nonatomic, assign) CYBMPushType pushType;

/** 
 Recipients user IDs.
 */
@property (nonatomic, copy, nullable) NSArray <NSNumber *> *usersIDs;

/** 
 Recipients - should contain a string of user external ids divided by comas.
 */
@property (nonatomic, copy, nullable) NSString *usersExternalIDs;

/** 
 Recipients tags - should contain a string of user tags divided by comas.
 
 @note Recipients (users) must have at LEAST ONE tag that specified in list.
 */
@property (nonatomic, copy, nullable) NSString *usersTagsAny;

/** 
 Recipients tags - should contain a string of user tags divided by comas.
 
 @note Recipients (users) must exactly have ONLY ALL tags that specified in list.
 */
@property (nonatomic, copy, nullable) NSString *usersTagsAll;

/** 
 Recipients tags - should contain a string of user tags divided by comas.
 
 @note Recipients (users) mustn't have tags that specified in list.
 */
@property (nonatomic, copy, nullable) NSString *usersTagsExclude;

/** 
 The name of the event.
 
 @note Service information. Only for the user.
 */
@property (nonatomic, copy, nullable) NSString *name;

/** 
 Event message.
 */
@property (nonatomic, copy, nullable) id message;

/** 
 Event type.
 */
@property (nonatomic, assign) CYBEventType type;

/** 
 The date of the event when it'll fire.
 
 @note Required: No, if the envent's 'type' = CYBEventTypeOneShot or CYBEventTypeMultiShot. Yes, if the envent's 'type' = CYBEventTypeFixedDate or CYBEventTypePeriodDate.
 */
@property (nonatomic, strong, nullable) NSDate *date;

/** 
 Date of completion of the event.
 
 @note Can't be less than the 'date'. Required: Yes, if the envent's  'type' = CYBEventTypeMultiShot and 'notificationType' = CYBNotificationTypePull
 */
@property (nonatomic, strong, nullable) NSDate *endDate;

/**
 The period of the event in seconds.
 
 @remark Possible values:
            86400 (1 day)
            604800 (1 week)
            2592000 (1 month)
            31557600 (1 year).
 
 @note Required: No, if the envent's 'type' = CYBEventTypeOneShot, CYBEventTypeMultiShot or CYBEventTypeFixedDate. Yes, if the envent's 'type' = CYBEventTypePeriodDate
 */
@property (nonatomic, assign) NSUInteger period;

/** 
 Event's occured count.
 */
@property (nonatomic, assign) NSUInteger occuredCount;

/** 
 Event's sender ID.
 */
@property (nonatomic, assign) NSUInteger senderID;

/** 
 Create new event.
 
 @return New instance of CYBEvent
 */
+ (CYBEvent *)event;

// MARK: - Converters

+ (CYBEventType)eventTypeFromString:(nullable NSString *)eventType;
+ (nullable NSString *)eventTypeToString:(CYBEventType)eventType;

+ (CYBNotificationType)notificationTypeFromString:(nullable NSString *)notificationType;
+ (nullable NSString*)notificationTypeToString:(CYBNotificationType)notificationType;

+ (CYBMPushType)pushTypeFromString:(nullable NSString *)pushType;
+ (nullable NSString *)pushTypeToString:(CYBMPushType)pushType;

+ (NSString *)messageToString:(nullable NSDictionary<NSString *, NSString *> *)message;
+ (nullable NSDictionary<NSString *, NSString *> *)messageFromString:(nullable NSString *)message;

@end

NS_ASSUME_NONNULL_END
