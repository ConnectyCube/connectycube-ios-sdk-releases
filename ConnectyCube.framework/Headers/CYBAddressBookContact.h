//
//  CYBAddressBookContact.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 CYBAddressBookContact class interface.
 This class represents a user's address book item.
 */
NS_SWIFT_NAME(AddressBookContact)
@interface CYBAddressBookContact : NSObject <NSSecureCoding, NSCopying>

/**
 The name of address book contact item.
 
 @note Required only for create/update.
 
 @remark Min 1 max 255 symbols
 */
@property (nonatomic, copy) NSString *name;

/**
 The phone number of address book contact item.
 
 @note Required.
 
 @remark Min 10 max 15 symbols
 */
@property (nonatomic, copy) NSString *phone;

/**
 The flag to destroy the address book contact item.
 
 @note Not required.
 */
@property (nonatomic) BOOL destroy;

@end

NS_ASSUME_NONNULL_END
