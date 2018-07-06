//
//  CYBPrivacyList.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CYBPrivacyItem;

NS_ASSUME_NONNULL_BEGIN

/**
 CYBPrivacyList class interface.
 This class structure represents collection for storing objects of CYBPrivacyItem type.
 */
NS_SWIFT_NAME(PrivacyList)
@interface CYBPrivacyList : NSObject

// unavailable initializers
- (instancetype)init NS_UNAVAILABLE;
+ (instancetype)new NS_UNAVAILABLE;

/**
 Init with name.
 
 @param name name of privacy list
 
 @note Name must contain at least one character.
 
 @return CYBPrivacyList instance
 */
- (instancetype)initWithName:(NSString *)name;

/**
 Init with name and items.
 
 @param name Name of privacy list
 @param items Array of privacy items
 
 @note This is designated initializer. Name must contain at least one character.
 
 @return CYBPrivacyList instance
 */
- (instancetype)initWithName:(NSString *)name
                       items:(nullable NSArray<CYBPrivacyItem *> *)items NS_DESIGNATED_INITIALIZER;

/**
 Add privacy item object.
 
 @param privacyItem CYBPrivacyItem privacy item instance
 */
- (void)addObject:(CYBPrivacyItem *)privacyItem;

/**
 Name of privacy list.
 */
@property (nonatomic, copy) NSString *name;

/**
 Privacy items array.
 */
@property (nonatomic, copy) NSArray<CYBPrivacyItem *> *privacyItems;

@end

NS_ASSUME_NONNULL_END
