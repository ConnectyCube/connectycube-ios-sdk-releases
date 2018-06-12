//
//  CYBPrivacyItem.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, CYBPrivacyType) {
    //This type is used to block the user in private chat dialog.
    CYBPrivacyTypeUserID = 1,
    //This type is used to block the user in group chat dialog.
    CYBPrivacyTypeGroupUserID
    
} NS_SWIFT_NAME(PrivacyType);

NS_ASSUME_NONNULL_BEGIN

/**
 CYBPrivacyItem class interface.
 This class structure represents privacy object for managing privacy lists.
 */
NS_SWIFT_NAME(PrivacyItem)
@interface CYBPrivacyItem : NSObject

/**
 Returns privacy type of the item.
 
 @see CYBPrivacyItemType.
 */
@property (assign, nonatomic, readonly) CYBPrivacyType privacyType;

/**
 Returns user ID.
 */
@property (assign, nonatomic, readonly) NSUInteger userID;

/**
 Determines whether item's action is allow or deny.
 */
@property (assign, nonatomic, readonly) BOOL isAllowed;

/**
 Determines whether block is mutual.
 
 @discussion By default user, who is blocking, can send messages and presences to the one he blocked without any errors. To achieve a two-way block set this property to YES. After that the user, who is blocking, will receive errors when will try to communicate with blocked user.
 */
@property (assign, nonatomic) BOOL mutualBlock;

/**
 Init with privacy type, userID and privacy action.

 @param privacyType CYBPrivacyType value (user ID, group user ID, subscription)
 @param userID User ID
 @param allow Determines whether action is to allow or deny user

 @return CYBPrivacyItem instance
 */
- (instancetype)initWithPrivacyType:(CYBPrivacyType)privacyType
                             userID:(NSUInteger)userID
                              allow:(BOOL)allow;

/**
 Unavailable initializer.
 */
- (instancetype)init NS_UNAVAILABLE;
/**
 Unavailable initializer.
 */
+ (instancetype)new NS_UNAVAILABLE;

@end

NS_ASSUME_NONNULL_END
