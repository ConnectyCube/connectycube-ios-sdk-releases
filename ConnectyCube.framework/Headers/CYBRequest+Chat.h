//
//  CYBRequest+Chat.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ConnectyCube/CYBRequest.h>
#import <ConnectyCube/CYBCompletionTypes.h>

NS_ASSUME_NONNULL_BEGIN

@class CYBUpdateChatDialogParameters;

/** Methods that provide chat functionality */

@interface CYBRequest (CYBChat)

//MARK: Retrieve chat dialogs

/**
 Retrieve chat dialogs with paginator.
 
 @param paginator The object to pass a pagination parameters to server. It is useful in implementing paginated results
 @param extendedRequest Set of request parameters
 @param successBlock Block with array of chat dialogs and chat dialogs users IDs and paginator instance if the request is succeeded
 @param errorBlock Block with NSError instance if the request is failed
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)dialogsWithPaginator:(nullable CYBPaginator *)paginator
                     extendedRequest:(nullable NSDictionary<NSString *, NSString *> *)extendedRequest
                        successBlock:(nullable CYBChatDialogsBlock)successBlock
                          errorBlock:(nullable CYBErrorBlock)errorBlock;

//MARK: Create/Update/Delete chat dialog

/**
 Create chat dialog.
 
 @param dialog chat dialog instance
 @param successBlock Block with created chat dialog instances if the request is succeeded
 @param errorBlock Block with NSError instance if the request is failed
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)createDialog:(CYBChatDialog *)dialog
                successBlock:(nullable CYBChatDialogBlock)successBlock
                  errorBlock:(nullable CYBErrorBlock)errorBlock;

/**
 Update existing chat dialog.
 
 @param dialogID The chat dialog ID
 @param updateParameters Update parame
 @param successBlock Block with updated chat dialog instances if the request is succeeded
 @param errorBlock Block with NSError instance if the request is failed
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)updateDialogWithID:(NSString *)dialogID
                  updateParameters:(CYBUpdateChatDialogParameters *)updateParameters
                      successBlock:(nullable CYBChatDialogBlock)successBlock
                        errorBlock:(nullable CYBErrorBlock)errorBlock;

/**
 Delete dialogs.
 
 @discussion Passing YES to 'forAllUsers' requires current user to be owner of the dialog! If current user is not the owner - request fails.
 
 @param dialogIDs The IDs of a dialogs to delete
 @param forAllUsers Delete dialog for current user or remove it for all users
 @param successBlock Block which is called in case of success response
 @param errorBlock Block with NSError instance if the request is failed
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)deleteDialogsWithIDs:(NSSet<NSString *> *)dialogIDs
                         forAllUsers:(BOOL)forAllUsers
                        successBlock:(nullable CYBDeleteChatDialogBlock)successBlock
                          errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: Subsribe/Unsubsribe public Group

/**
 Subscribe to public dialog
 
 @param dialogID ID of a dialog
 @param successBlock Block which is called in case of success response
 @param errorBlock Block with NSError instance if the request is failed
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)subscribeToPublicDialogWithID:(NSString *)dialogID
                                 successBlock:(nullable CYBChatDialogBlock)successBlock
                                   errorBlock:(nullable CYBErrorBlock)errorBlock;


/**
 Unsubscribe to public dialog
 
 @param dialogID ID of a dialog
 @param successBlock Block which is called in case of success response
 @param errorBlock Block with NSError instance if the request is failed
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)unsubscribeFromPublicDialogWithID:(NSString *)dialogID
                                     successBlock:(nullable CYBSuccessBlock)successBlock
                                       errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: Add/Remove Admins

/**
 Add admins to dialog

 @param dialogID ID of a dialog
 @param adminsUserIDs An array of user IDs to add as admins
 @param successBlock Block which is called in case of success response
 @param errorBlock Block with NSError instance if the request is failed
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)addAdminsToDialogWithID:(NSString *)dialogID
                          adminsUserIDs:(NSArray<NSNumber *> *)adminsUserIDs
                           successBlock:(nullable CYBChatDialogBlock)successBlock
                             errorBlock:(nullable CYBErrorBlock)errorBlock;

/**
 Remove admins from dialog
 
 @param dialogID ID of a dialog
 @param adminsUserIDs An array of user IDs to remove from admins
 @param successBlock Block which is called in case of success response
 @param errorBlock Block with NSError instance if the request is failed
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)removeAdminsFromDialogWithID:(NSString *)dialogID
                               adminsUserIDs:(NSArray<NSNumber *> *)adminsUserIDs
                                successBlock:(nullable CYBChatDialogBlock)successBlock
                                  errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: Retrieve messages

/**
 Retrieve chat messages within particular dialog.
 
 @discussion By default all messages retrieved from server is marked as read, if you need another behaviour please use mark_as_read parameter in extendedParameters dictionary.
 
 @code
    extendedParameters[@"mark_as_read"] = 0;
 @endcode
 
 @param dialogID ID of a dialog
 @param extendedParameters A set of additional request parameters
 @param paginator The object to pass a pagination parameters to server. It is useful in implementing paginated results
 @param successBlock Block with array of chat messages and paginator if the request is succeeded
 @param errorBlock Block with NSError instance if the request is failed
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)messagesWithDialogID:(NSString *)dialogID
                     extendedRequest:(nullable NSDictionary<NSString *, NSString *> *)extendedParameters
                           paginator:(nullable CYBPaginator *)paginator
                        successBlock:(nullable CYBChatMessagesBlock)successBlock
                          errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: Create/Send/Mark/Delete messages

/**
 Create chat message.
 
 @param message Сhat message instance to create
 @param successBlock Block with created chat message instance if the request is succeeded
 @param errorBlock Block with NSError instance if the request is failed
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)createMessage:(CYBChatMessage *)message
                 successBlock:(nullable CYBChatMessageBlock)successBlock
                   errorBlock:(nullable CYBErrorBlock)errorBlock;

/**
 Create and send message to chat.
 
 @param message Сhat message instance to create
 @param successBlock Block chat message instance if the request is succeeded
 @param errorBlock Block with NSError instance if the request is failed
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)sendMessage:(CYBChatMessage *)message
               successBlock:(nullable CYBChatMessageBlock)successBlock
                 errorBlock:(nullable CYBErrorBlock)errorBlock;
/**
 Mark messages as read.
 
 @note Updates message "read" status only on server.
 
 @param messagesIDs Set of chat message IDs to mark as read. If messageIDs is nil then all messages in dialog will be marked as read
 @param dialogID dialog ID
 @param successBlock Block which is called in case of success response
 @param errorBlock Block with NSError instance if the request is failed
 @return An instance, which conforms Cancelable protocol. Use this instance to cancel the operation
 */
+ (CYBRequest *)markMessagesAsRead:(nullable NSSet<NSString *> *)messagesIDs
                          dialogID:(NSString *)dialogID
                      successBlock:(nullable CYBSuccessBlock)successBlock
                        errorBlock:(nullable CYBErrorBlock)errorBlock;

/**
 Mark messages as Delivered.
 
 @note Updates message "delivered" status only on server.
 
 @param messagesIDs Set of chat message IDs to mark as delivered. If messageIDs is nil then all messages in dialog will be marked as delivered
 @param dialogID dialog ID
 @param successBlock Block which is called in case of success response
 @param errorBlock Block with NSError instance if the request is failed
 @return An instance, which conforms Cancelable protocol. Use this instance to cancel the operation
 */
+ (CYBRequest *)markMessagesAsDelivered:(nullable NSSet<NSString *> *)messagesIDs
                               dialogID:(NSString *)dialogID
                           successBlock:(nullable CYBSuccessBlock)successBlock
                             errorBlock:(nullable CYBErrorBlock)errorBlock;

/**
 Delete existent chat messages completely for all users.
 
 @discussion Passing YES to 'forAllUsers' requires current user to be the owner of the message! If the current user is not the owner - request fails.
 
 @param messageIDs The IDs of messages to delete
 @param forAllUsers Delete message for the current user or remove it for all users
 @param successBlock Block which is called in case of success response
 @param errorBlock Block which is called in case of success response
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)deleteMessagesWithIDs:(NSSet<NSString *> *)messageIDs
                          forAllUsers:(BOOL)forAllUsers
                         successBlock:(nullable CYBSuccessBlock)successBlock
                           errorBlock:(nullable CYBErrorBlock)errorBlock;

// MARK: Count of dialogs/messages

/**
 Returns count of dialogs.
 
 @param parameters Dialogs filter parameters
 @param successBlock Block with count of dialogs if the request is succeeded
 @param errorBlock Block with NSError instance if the request is failed
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)countOfDialogsWithExtendedRequest:(nullable NSDictionary<NSString *, NSString *> *)parameters
                                     successBlock:(nullable CYBCountBlock) successBlock
                                       errorBlock:(nullable CYBErrorBlock)errorBlock;

/**
 Returns count of messages for dialog.
 
 @param dialogID Dialog ID of the chat messages
 @param parameters Messages filter parameters
 @param successBlock Block with count of messages if the request is succeeded
 @param errorBlock Block with NSError instance if the request is failed
 @return An instance of CYBRequest for cancel operation mainly
 */

+ (CYBRequest *)countOfMessagesForDialogID:(NSString *)dialogID
                           extendedRequest:(nullable NSDictionary<NSString *, NSString *> *)parameters
                              successBlock:(nullable CYBCountBlock) successBlock
                                errorBlock:(nullable CYBErrorBlock)errorBlock;

/**
 Returns unread message count for dialogs with ids. Includes total count for all dialogs for user also.
 
 @param dialogIDs Array of dialog IDs
 @param successBlock Block with total unread count and dialogs dictionary
 @param errorBlock Block with NSError instance if the request is failed
 @return An instance of CYBRequest for cancel operation mainly
 */

+ (CYBRequest *)totalUnreadMessageCountForDialogsWithIDs:(NSSet <NSString *> *)dialogIDs
                                            successBlock:(nullable CYBUnreadChatMessagesBlock)successBlock
                                              errorBlock:(nullable CYBErrorBlock)errorBlock;
// MARK: Chat dialog notifications settings

/**
 Get the notifications settings status.
 
 @param dialogID Dialog ID
 @param successBlock Block with current status of notifications settings
 @param errorBlock Block with NSError instance if the request is failed
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)notificationsSettingsForDialogID:(NSString *)dialogID
                                    successBlock:(nullable void(^)(BOOL enabled))successBlock
                                      errorBlock:(nullable CYBErrorBlock)errorBlock;

/**
 User can turn YES/NO push notifications for offline messages in a dialog.
 
 @note By default when a user is offline and other user sent a message to him then he will receive a push notification. It is possible to disable this feature.
 
 @remark Default value is YES.
 
 @param dialogID Dialog ID
 @param enable YES / NO
 @param successBlock Block with current status of notifications settings
 @param errorBlock Block with NSError instance if the request is failed
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)updateNotificationsSettingsForDialogID:(NSString *)dialogID
                                                enable:(BOOL)enable
                                          successBlock:(nullable void(^)(BOOL enabled))successBlock
                                            errorBlock:(nullable CYBErrorBlock)errorBlock;

/**
 Retrieving occupants of public chat dialog.

 @param dialogID Public dialog identifier
 @param paginator The object to pass a pagination parameters to server. It is useful in implementing paginated results
 @param successBlock Block with array of occupants (users) and paginator if the request is succeeded
 @param errorBlock  Block with NSError instance if the request is failed
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)occupantsForPublicDialogID:(NSString *)dialogID
                                 paginator:(nullable CYBPaginator *)paginator
                              successBlock:(nullable CYBChatUsersBlock)successBlock
                                errorBlock:(nullable CYBErrorBlock)errorBlock;

@end

// MARK: DEPRECATED

/** Chat Deprecations */
@interface CYBRequest (CHAT_DEPRECATED)

/**
 Update existing chat dialog.
 
 @param dialog The dialog instance to update
 @param successBlock Block with updated chat dialog instances if the request is succeeded
 @param errorBlock Block with NSError instance if the request is failed
 @warning Deprecated in 1.2. Use updateDialogWithID:updateParameters:successBlock:errorBlock:.
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)updateDialog:(CYBChatDialog *)dialog
                successBlock:(nullable CYBChatDialogBlock)successBlock
                  errorBlock:(nullable CYBErrorBlock)errorBlock
DEPRECATED_MSG_ATTRIBUTE("Deprecated in 1.2. Use updateDialogWithID:updateParameters:successBlock:errorBlock:.");

@end

NS_ASSUME_NONNULL_END
