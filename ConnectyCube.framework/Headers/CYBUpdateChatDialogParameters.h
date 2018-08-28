//
//  CYBUpdateChatDialogParameters.h
//  ConnectyCube
//
//  Created by ConnectyCube team on 31/07/2018.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/** The CYBUpdateChatDialogParameters class interface. */
NS_SWIFT_NAME(UpdateChatDialogParameters)
@interface CYBUpdateChatDialogParameters : NSObject

/** The name of the chat dialog. */
@property (nonatomic, copy, nullable) NSString *name;

/** The description of the chat dialog. */
@property (nonatomic, copy, nullable) NSString *dialogDescription;

/**
  The photo of the chat dialog.
 
  @discussion Can contain a link to a file in Storage module or just a web link.
 */
@property (nonatomic, copy, nullable) NSString *photo;

/** The dictionary that represents the custom data. */
@property (nonatomic, copy, nullable) NSDictionary<NSString *, id> *data;

/** The Occupants (users) ids to add. */
@property (nonatomic, copy, nullable) NSArray<NSNumber *> *occupantsIDsToAdd;

/** The Occupants (users) ids to remove. */
@property (nonatomic, copy, nullable) NSArray<NSNumber *> *occupantsIDsToRemove;

/** The Pinned messages ids to add. */
@property (nonatomic, copy, nullable) NSArray<NSString *> *pinnedMessagesIDsToAdd;

/** The Pinned messages ids to remove. */
@property (nonatomic, copy, nullable) NSArray<NSString *> *pinnedMessagesIDsToRemove;

@end

NS_ASSUME_NONNULL_END
