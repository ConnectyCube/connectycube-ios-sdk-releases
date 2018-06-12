//
//  CYBContactList.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ConnectyCube/CYBContactListItem.h>

NS_ASSUME_NONNULL_BEGIN

/**
 CYBContactList class interface.
 Represents user's contact list.
 */
NS_SWIFT_NAME(ContactList)
@interface CYBContactList : NSObject

/**
 Current contacts.
 */
@property (nonatomic, readonly, nullable) NSArray<CYBContactListItem *> *contacts;

/**
 *  Your requests which pending approval.
 */
@property (nonatomic, readonly, nullable) NSArray<CYBContactListItem *> *pendingApproval;

@end

NS_ASSUME_NONNULL_END
