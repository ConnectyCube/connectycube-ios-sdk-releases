//
//  CYBContactListItem.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 Presence subscription state.

 - CYBPresenceSubscriptionStateNone: The user does not have a subscription to the contact's presence information, and the contact does not have a subscription to the user's presence information
 - CYBPresenceSubscriptionStateTo: The user has a subscription to the contact's presence information, but the contact does not have a subscription to the user's presence information
 - CYBPresenceSubscriptionStateFrom: The contact has a subscription to the user's presence information, but the user does not have a subscription to the contact's presence information
 - CYBPresenceSubscriptionStateBoth: Both the user and the contact have subscriptions to each other's presence information
 */
typedef NS_ENUM(NSUInteger, CYBPresenceSubscriptionState) {
    CYBPresenceSubscriptionStateNone = 1,
    CYBPresenceSubscriptionStateTo = 2,
    CYBPresenceSubscriptionStateFrom = 3,
    CYBPresenceSubscriptionStateBoth = 4
} NS_SWIFT_NAME(PresenceSubscriptionState);

/**
 CYBContactListItem class interface.
 Represents user's contact list item.
 */
NS_SWIFT_NAME(ContactListItem)
@interface CYBContactListItem : NSObject

/**
 Unique identifier of user.
 */
@property (nonatomic, assign) NSUInteger userID;

/**
 User status (online/offline).
 */
@property (nonatomic, assign, getter=isOnline) BOOL online;

/**
 User subscription state.
 
 @see http://xmpp.org/rfcs/rfc3921.html#roster
 */
@property (nonatomic, assign) CYBPresenceSubscriptionState subscriptionState;

@end

@interface CYBContactListItem(Internal)

// Helpers: translate subscriptionState to and from string to and from enum
+ (CYBPresenceSubscriptionState)subscriptionStateFromString:(nullable NSString *)subscriptionState;

@end

NS_ASSUME_NONNULL_END
