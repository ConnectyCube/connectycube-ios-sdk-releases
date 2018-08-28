//
//  CYBCompletionTypes.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CYBChatDialog;
@class CYBPaginator;
@class CYBChatMessage;

NS_ASSUME_NONNULL_BEGIN

/** Block with created or updated chat dialog instances */
NS_SWIFT_NAME(ChatDialogBlock)
typedef void(^CYBChatDialogBlock)(CYBChatDialog *dialog);

/** Block with array of chat dialogs and chat dialogs users IDs and page instance */
NS_SWIFT_NAME(ChatDialogsBlock)
typedef void(^CYBChatDialogsBlock)(NSArray<CYBChatDialog *> *dialogs,
                                   NSSet<NSNumber *> *dialogsUsersIDs,
                                   CYBPaginator *paginator);

/** Block with deleted objects ids, not found objects ids and wrong permissions objects ids. */
NS_SWIFT_NAME(DeleteChatDialogBlock)
typedef void(^CYBDeleteChatDialogBlock)(NSArray<NSString *> *deletedObjectsIDs,
                                        NSArray<NSString *> *notFoundObjectsIDs,
                                        NSArray<NSString *> *wrongPermissionsObjectsIDs);

/** Block with chat message instance */
NS_SWIFT_NAME(ChatMessageBlock)
typedef void(^CYBChatMessageBlock)(CYBChatMessage *message);

/** Block with array of chat messages and paginator */
NS_SWIFT_NAME(ChatMessagesBlock)
typedef void(^CYBChatMessagesBlock)(NSArray<CYBChatMessage *> *messages,
                                    CYBPaginator *paginator);

/** Block with total unread count and dialogs dictionary. */
NS_SWIFT_NAME(UnreadChatMessagesBlock)
typedef void(^CYBUnreadChatMessagesBlock)(NSUInteger count,
                                          NSDictionary <NSString *, id> *dialogs);

/** Block with count */
NS_SWIFT_NAME(CountBlock)
typedef void(^CYBCountBlock)(NSUInteger count);

NS_ASSUME_NONNULL_END
