//
//  CYBRequest+PushNotifications.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ConnectyCube/CYBRequest.h>

@class CYBPushToken;
@class CYBSubscription;
@class CYBEvent;
@class CYBPaginator;
@class CYBPushMessage;

NS_ASSUME_NONNULL_BEGIN

@interface CYBRequest (PushNotifications)

/**
 Create subscription.
 
 @param subscription An instance of CYBSubscription
 @param successBlock Block with response and subscriber instances if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)createSubscription:(CYBSubscription *)subscription
                      successBlock:(nullable void (^)(NSArray<CYBSubscription *> *objects))successBlock
                        errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - Get Subscriptions

/**
 Retrieve all subscriptions.
 
 @param successBlock Block with response and subscribers instances if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)subscriptionsWithSuccessBlock:(nullable void (^)(NSArray<CYBSubscription *> *objects))successBlock
                                   errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - Delete Subscription with ID

/**
 Delete subscription with ID.
 
 @param ID An ID of instance of CYBSubscription that will be deleted
 @param successBlock Block with response instance if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)deleteSubscriptionWithID:(NSUInteger)ID
                            successBlock:(nullable CYBSuccessBlock)successBlock
                              errorBlock:(nullable CYBErrorBlock)errorBlock;
// MARK: - Create Event

/**
 Create an event.
 
 @param event An instance of CYBEvent to create
 @param successBlock Block with response and event instances if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)createEvent:(CYBEvent *)event
               successBlock:(nullable void (^)(NSArray<CYBEvent *> *events))successBlock
                 errorBlock:(nullable CYBErrorBlock)errorBlock;

/**
 Retrieve all events which were created by current user (with extended set of pagination parameters).
 
 @param paginator The object to pass a pagination parameters to server. It is useful in implementing paginated results
 @param successBlock Block with response, page, events instances if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @see CYBPaginator
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)eventsWithPaginator:(nullable CYBPaginator *)paginator
                       successBlock:(nullable void (^)(CYBPaginator *paginator, NSArray<CYBEvent *> *events))successBlock
                         errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - Get Event with ID

/**
 Get an event with ID.
 
 @param ID ID of CYBEvent to be retrieved
 @param successBlock Block with response and event instances if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)eventWithID:(NSUInteger)ID
               successBlock:(nullable void (^)(CYBEvent *event))successBlock
                 errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - Update Event

/**
 Update an event.
 
 @param event An instance of CYBEvent to update
 @param successBlock Block with response and event instances if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)updateEvent:(CYBEvent *)event
               successBlock:(nullable void (^)(CYBEvent *event))successBlock
                 errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - Delete Event with ID

/**
 Get an event with ID.
 
 @param ID ID of CYBEvent to be deleted
 @param successBlock Block with response instance if the request is succeeded
 @param errorBlock Block with response instance if the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly.
 */
+ (CYBRequest *)deleteEventWithID:(NSUInteger)ID
                     successBlock:(nullable CYBSuccessBlock)successBlock
                       errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - Send push Tasks

/**
 Send Apple based push notification to users.
 
 @param pushMessage Composed push message to send
 @param usersIDs Users identifiers who will get the message
 @param successBlock Block with response and event instances if the request is succeeded
 @param errorBlock Block with error if request failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)sendPush:(CYBPushMessage *)pushMessage
                 toUsers:(NSArray <NSNumber *> *)usersIDs
            successBlock:(nullable void(^)(CYBEvent *event))successBlock
              errorBlock:(nullable CYBErrorBlock)errorBlock;

/**
 Send apns-voip push notification to users.
 
 @param pushMessage Composed push message to send
 @param usersIDs Users identifiers who will get the message
 @param successBlock Block with response and event instances if the request is succeeded
 @param errorBlock Block with error if request failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)sendVoipPush:(CYBPushMessage *)pushMessage
                     toUsers:(NSArray <NSNumber *> *)usersIDs
                successBlock:(nullable void(^)(CYBEvent *event))successBlock
                  errorBlock:(nullable CYBErrorBlock)errorBlock;
/**
 Send simple push notification to users.
 
 @param text composed push notification's text to send
 @param usersIDs users identifiers who will get the message
 @param successBlock Block with response and event instances if the request is succeeded
 @param errorBlock Block with error if request failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)sendPushWithText:(NSString *)text
                         toUsers:(NSArray <NSNumber *> *)usersIDs
                    successBlock:(nullable void(^)(NSArray<CYBEvent *> *events))successBlock
                      errorBlock:(nullable CYBErrorBlock)errorBlock;

/**
 Send Apple based push notification to users with tags.
 
 @param pushMessage composed push message to send
 @param usersTags users tags who will get the message. Contain a string of users tags divided by comas
 @param successBlock Block with response and event instances if the request is succeeded
 @param errorBlock Block with error if request failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)sendPush:(CYBPushMessage *)pushMessage
toUsersWithAnyOfTheseTags:(NSString *)usersTags
            successBlock:(nullable void(^)(CYBEvent *event))successBlock
              errorBlock:(nullable CYBErrorBlock)errorBlock;

/**
 Send apns-voip push notification to users with tags.
 
 @param pushMessage composed push message to send
 @param usersTags users tags who will get the message. Contain a string of users tags divided by comas
 @param successBlock Block with response and event instances if the request is succeeded
 @param errorBlock Block with error if request failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)sendVoipPush:(CYBPushMessage *)pushMessage
   toUsersWithAnyOfTheseTags:(NSString *)usersTags
                successBlock:(nullable void(^)(CYBEvent *event))successBlock
                  errorBlock:(nullable CYBErrorBlock)errorBlock;

/**
 Send simple push notification to users with tags.
 
 @param text composed push notification's text to send
 @param usersTags users tags who will get the message. Contain a string of users tags divided by comas
 @param successBlock Block with response and token instances if the request is succeeded
 @param errorBlock Block with response instance and CYBEvent instance if request failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)sendPushWithText:(NSString *)text
       toUsersWithAnyOfTheseTags:(NSString *)usersTags
                    successBlock:(nullable void(^)(NSArray<CYBEvent *> *events))successBlock
                      errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: - Unregister and Register Subscription Tasks

/**
 Remove subscription for a specific device. This method remove subscription for a specific device.
 
 @param uniqueDeviceIdentifier The device unique identifier
 @param successBlock Block with response instance if the request is succeeded
 @param errorBlock Block with error if request failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)unregisterSubscriptionForUniqueDeviceIdentifier:(NSString *)uniqueDeviceIdentifier
                                                   successBlock:(nullable CYBSuccessBlock)successBlock
                                                     errorBlock:(nullable CYBErrorBlock)errorBlock;
@end

NS_ASSUME_NONNULL_END
