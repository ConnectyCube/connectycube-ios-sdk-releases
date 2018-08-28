//
//  CYBContactListItem.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/** Presence subscription state. */
typedef NS_ENUM(NSUInteger, CYBPresenceSubscriptionState) {
    
    /**
     The user does not have a subscription to the contact's presence information,
     and the contact does not have a subscription to the user's presence information
     */
    CYBPresenceSubscriptionStateNone = 1,
    
    /**
     The user has a subscription to the contact's presence information,
     but the contact does not have a subscription to the user's presence information
     */
    CYBPresenceSubscriptionStateTo = 2,
    
    /**
     The contact has a subscription to the user's presence information,
     but the user does not have a subscription to the contact's presence information
     */
    CYBPresenceSubscriptionStateFrom = 3,
    
    /**
     Both the user and the contact have subscriptions to each other's presence information
     */
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

NS_ASSUME_NONNULL_END
