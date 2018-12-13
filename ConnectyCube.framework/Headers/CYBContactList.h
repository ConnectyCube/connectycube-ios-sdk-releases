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
@interface CYBContactList : NSObject<NSSecureCoding, NSCopying>

/**
 Current contacts.
 */
@property (nonatomic, copy, readonly) NSArray<CYBContactListItem *> *contacts;

/**
 Your requests which pending approval.
 */
@property (nonatomic, copy, readonly) NSArray<CYBContactListItem *> *pendingApproval;

@end

NS_ASSUME_NONNULL_END
