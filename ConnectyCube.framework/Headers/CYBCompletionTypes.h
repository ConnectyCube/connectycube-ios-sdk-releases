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
/**
 Block with response and created or updated chat dialog instances
 */
typedef void(^CYBChatDialogBlock) (CYBChatDialog *dialog);
/**
 Block with response instance, arrays of chat dialogs and chat dialogs users IDs and page instance
 */
typedef void(^CYBChatDialogsBlock)(NSArray<CYBChatDialog *> *dialogs,
                                   NSSet<NSNumber *> *dialogsUsersIDs,
                                   CYBPaginator *paginator);
/**
 Block with response deleted objects ids, not found objects ids and wrong permissions objects ids.
 */
typedef void(^CYBDeleteChatDialogBlock)(NSArray<NSString *> *deletedObjectsIDs,
                                        NSArray<NSString *> *notFoundObjectsIDs,
                                        NSArray<NSString *> *wrongPermissionsObjectsIDs);
/**
 Block with response and chat message instance
 */
typedef void(^CYBChatMessageBlock)(CYBChatMessage *message);
/**
 Block with array of chat messages and paginator
 */
typedef void(^CYBChatMessagesBlock)(NSArray<CYBChatMessage *> *messages,
                                    CYBPaginator *paginator);
/**
 Block with response instance total unread count and dialogs dictionary.
 */
typedef void(^CYBUnreadChatMessagesBlock)(NSUInteger count,
                                          NSDictionary <NSString *, id> *dialogs);
/**
 Block with response instance and count
 */
typedef void(^CYBCountBlock)(NSUInteger count);

NS_ASSUME_NONNULL_END
