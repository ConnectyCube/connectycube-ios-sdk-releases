//
//  CYBChatDialog.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CYBChatMessage;

typedef NS_ENUM(NSUInteger, CYBChatDialogType) {
    
    CYBChatDialogTypePublicGroup = 1,
    CYBChatDialogTypeGroup = 2,
    CYBChatDialogTypePrivate = 3
    
} NS_SWIFT_NAME(ChatDialogType);

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(ChatErrorBlock)
typedef void(^CYBChatErrorBlock)(NSError * _Nullable error);
NS_SWIFT_NAME(UserIDBlock)
typedef void(^CYBUserIDBlock)(NSUInteger userID);
NS_SWIFT_NAME(OnlineUsersBlock)
typedef void(^CYBOnlineUsersBlock)(NSMutableArray<NSNumber *> * _Nullable onlineUsers, NSError * _Nullable error);

/**
 The CYBChatDialog class interface.
 This class represents chat dialog model from server.
 */
NS_SWIFT_NAME(ChatDialog)
@interface CYBChatDialog : NSObject <NSSecureCoding, NSCopying>

/**
 The dialog ID.
 */
@property (nonatomic, copy, readonly, nullable) NSString *ID;

/**
 The date of the dialog creation.
 */
@property (nonatomic, strong, nullable) NSDate *createdAt;

/**
 The date of the dialog update.
 */
@property (nonatomic, strong, nullable) NSDate *updatedAt;

/**
 The Room JID.
 
 @note If chat dialog is private, room JID will be nil.
 */
@property (nonatomic, copy, readonly, nullable) NSString *roomJID;

/**
 The type of the dialog.
 
 @see CYBChatDialogType
 */
@property (nonatomic, readonly) CYBChatDialogType type;

/**
 The name of the Group dialog.
 
 @note If chat type is private, name will be nil.
 */
@property (nonatomic, copy, nullable) NSString *name;

/**
 The phone of the Group dialog.
 
 @discussion Can contain a link to a file in Content module, Custom Objects module or just a web link.
 */
@property (nonatomic, copy, nullable) NSString *photo;

/**
 The Last message text of the dialog.
 */
@property (nonatomic, copy, nullable) NSString *lastMessageText;

/**
 The Date of the last message in the dialog.
 */
@property (nonatomic, strong, nullable) NSDate *lastMessageDate;

/**
 The Sender user ID of last message in current chat dialog.
 */
@property (nonatomic, assign) NSUInteger lastMessageUserID;

/**
 The last message ID.
 */
@property (nonatomic, copy, nullable) NSString *lastMessageID;

/**
 The Number of unread messages in the dialog.
 */
@property (nonatomic, assign) NSUInteger unreadMessagesCount;

/**
 The Array of occupatns (users') ids in the dialog.
 
 @note For private chat dialog count is 2.
 */
@property (nonatomic, copy, nullable) NSArray<NSNumber *> *occupantIDs;

/**
 The dictionary that represents the custom data.
 */
@property (nonatomic, copy, nullable) NSDictionary<NSString *, id> *data;

/**
 The user id of the dialog's owner.
 */
@property (nonatomic, assign) NSUInteger userID;

/**
 The Recipient (user) ID for the private dialog.
 
 @note ID of a recipient if type = CYBChatDialogTypePrivate. -1 otherwise. Will always return -1 if CYBSession currentUser is nil.
 
 @discussion Will be retrieved from 'CYBSession.currentSession.currentUser' by subtracting currentUser.ID from occupantsIDs.
 */
@property (nonatomic, readonly) NSInteger recipientID;

/**
 The Occupants (users) ids to be pushed (added) to the dialog.
 */
@property (strong, nonatomic, nullable) NSArray<NSNumber *> *pushOccupantsIDs;

/**
 The Occupants (users) ids to be pulled (removed) from the dialog.
 */
@property (strong, nonatomic, nullable) NSArray<NSNumber *> *pullOccupantsIDs;

/**
 Called whenever sent message was blocked on server.
 */
@property (nonatomic, copy, nullable) CYBChatErrorBlock onBlockedMessage;

/**
 Called whenever user is typing in current dialog.
 */
@property (nonatomic, copy, nullable) CYBUserIDBlock onUserIsTyping;

/**
 Called whenever user has stopped typing in current dialog.
 */
@property (nonatomic, copy, nullable) CYBUserIDBlock onUserStoppedTyping;

/**
 Called whenever occupant has joined to the current Group or Public group dialog.
 */
@property (nonatomic, copy, nullable) CYBUserIDBlock onJoinOccupant;

/**
 Called whenever occupant has left the current Group or Public group dialog.
 */
@property (nonatomic, copy, nullable) CYBUserIDBlock onLeaveOccupant;

/**
 Called whenever occupant has updated his presence status in the current Group or Public group dialog.
 */
@property (nonatomic, copy, nullable) CYBUserIDBlock onUpdateOccupant;

// Unavailable initializers
- (id)init NS_UNAVAILABLE;
+ (id)new NS_UNAVAILABLE;

/**
 Init with dialog ID and type.
 
 @param dialogID dialog ID string
 @param type dialog type
 
 @see CYBChatDialogType
 
 @discussion Pass nil for dialogID if you are creating a new dialog.
 
 @return CYBChatDialog instance.
 */
- (instancetype)initWithDialogID:(nullable NSString *)dialogID type:(CYBChatDialogType)type;

// MARK: - Send message

/**
 Sends chat message with completion block.
 
 @param message Chat message to send
 @param completion Completion block with failure error
 */
- (void)sendMessage:(CYBChatMessage *)message completionBlock:(nullable CYBChatErrorBlock)completion;

/**
 Sends group chat message to room, without room join.
 
 @param message Chat message to send
 @param completion Completion block with failure error.
 
 @note Available only for 'Enterprise' clients.
 */
- (void)sendGroupChatMessageWithoutJoin:(CYBChatMessage *)message completion:(nullable CYBChatErrorBlock)completion;

/**
 Edit message text with ID.
 
 @note User can edit a message he sent. In this case other parties (user or group chat) should be
 notified about this and correct the message at their side as well.
 
 @param ID Unique identifier of message
 @param text New message text.
 @param last The attribute is optional and can be included inly if you edit last message in chat thread.
 @param completion Completion block with failure error.
 */
- (void)editMessageWithID:(NSString *)ID text:(NSString *)text last:(BOOL)last completion:(nullable CYBChatErrorBlock)completion;

/**
 Remove Message with ID.
 
 @note If user is an owner of chat message (he sent it) then he can delete the message completely.
 In this case other parties (user or group chat) should be notified about this and delete
 the message at their side as well.
 
 @param ID Message ID.
 @param completion Completion block with failure error.
 */
- (void)removeMessageWithID:(NSString *)ID completion:(nullable CYBChatErrorBlock)completion;


// MARK: - Join/leave

/**
 Join status of the room.
 
 @return YES if user is joined to room, otherwise - no
 */
- (BOOL)isJoined;

/**
 Join to room.
 
 @param completion Completion block with failure error.
 */
- (void)joinWithCompletionBlock:(nullable CYBChatErrorBlock)completion;

/**
 Leave joined room.
 
 @param completion Completion block with failure error.
 */
- (void)leaveWithCompletionBlock:(nullable CYBChatErrorBlock)completion;

/**
 Clears dialog occupants status blocks.
 
 @discussion Call this method if you don't want to recieve join/leave/update for this dialog.
 */
- (void)clearDialogOccupantsStatusBlock;

// MARK: - Users status

/**
 Requests users who are joined to room.
 
 @param completion Completion block with failure error and array of user ids.
 */
- (void)requestOnlineUsersWithCompletionBlock:(nullable CYBOnlineUsersBlock)completion;

// MARK: - Now typing

/**
 Sends is typing message to occupants.
 
 @note Available only for 'Enterprise' clients.
 */
- (void)sendUserIsTypingWithoutJoin;

/**
 Sends is typing message to occupants.
 */
- (void)sendUserIsTyping;

/**
 Sends stopped typing message to occupants.
 */
- (void)sendUserStoppedTyping;

/**
 Sends stopped typing message to occupants.
 
 @note Available only for 'Enterprise' clients.
 */
- (void)sendUserStoppedTypingWithoutJoin;

/**
 Clears typing status blocks.
 
 @discussion Call this method if you don't want to recieve typing statuses for this dialog.
 */
- (void)clearTypingStatusBlocks;

@end

NS_ASSUME_NONNULL_END
