//
//  CYBRequest+AddressBook.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ConnectyCube/CYBRequest.h>

@class CYBAddressBookContact;
@class CYBAddressBookUpdates;
@class CYBUser;

NS_ASSUME_NONNULL_BEGIN

@interface CYBRequest (CYBAddressBook)

NS_SWIFT_NAME(AdressBookContactsBlock)
typedef void(^CYBAdressBookContactsBlock)(NSArray<CYBAddressBookContact *> *contacts);
NS_SWIFT_NAME(AdressBookUpdatesBlock)
typedef void(^CYBAdressBookUpdatesBlock)(CYBAddressBookUpdates *updates);
NS_SWIFT_NAME(UsersBlock)
typedef void(^CYBUsersBlock)(NSArray<CYBUser *> *users);

/**
 Retrieves address book contacts for specified user device.
 
 @param udid User's device identifier. If specified - all operations will be in this context. Max length 64 symbols
 @param successBlock The block to be executed when address book contact items are retrieved
 @param errorBlock The block to be executed when the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)addressBookWithUdid:(nullable NSString *)udid
                       successBlock:(nullable CYBAdressBookContactsBlock)successBlock
                         errorBlock:(nullable CYBErrorBlock)errorBlock;

/**
 Uploads fresh address book (force update).
 
 @param udid User's device identifier. If specified - all operations will be in this context. Max length 64 symbols
 @param addressBook Set with address book contact items (phone - unique)
 @param force Rewrite mode. If set YES all previous contacts for device context will be replaced by new ones
 @param successBlock The block to be executed after successfuly address book updates
 @param errorBlock The block to be executed when the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly.
 */
+ (CYBRequest *)uploadAddressBookWithUdid:(nullable NSString *)udid
                              addressBook:(nullable NSOrderedSet<CYBAddressBookContact *> *)addressBook
                                    force:(BOOL)force
                             successBlock:(nullable CYBAdressBookUpdatesBlock)successBlock
                               errorBlock:(nullable CYBErrorBlock)errorBlock;

/**
 Retrieves registered users from address book.
 
 @param udid User's device identifier. If specified - all operations will be in this context. Max length 64 symbols
 @param compact if YES - server will return only `id` and `phone` fields of User. Otherwise - all User's fields will be returned
 @param successBlock The block to be executed when registered users are retrieved
 @param errorBlock The block to be executed when the request is failed
 
 @return An instance of CYBRequest for cancel operation mainly
 */
+ (CYBRequest *)registeredUsersFromAddressBookWithUdid:(nullable NSString *)udid
                                             isCompact:(BOOL)compact
                                          successBlock:(nullable CYBUsersBlock)successBlock
                                            errorBlock:(nullable CYBErrorBlock)errorBlock;

@end

NS_ASSUME_NONNULL_END
