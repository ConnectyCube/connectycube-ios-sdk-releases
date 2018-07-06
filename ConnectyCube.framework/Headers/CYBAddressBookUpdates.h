//
//  CYBAddressBookUpdates.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CYBAddressBookRejectDetails;

NS_ASSUME_NONNULL_BEGIN

/**
 CYBAddressBookUpdates class interface.
 This class represents the update details of an address book item.
 */
NS_SWIFT_NAME(AddressBookUpdates)
@interface CYBAddressBookUpdates : NSObject

/**
 The number of created objects.
 */
@property (nonatomic, assign) NSUInteger created;

/**
 The number of deleted objects.
 */
@property (nonatomic, assign) NSUInteger deleted;

/**
 The number of updated objects.
 */
@property (nonatomic, assign) NSUInteger updated;

/**
 The array of rejected objects.
 */
@property (nonatomic, strong, nullable) NSArray<CYBAddressBookRejectDetails *> *rejected;

@end

NS_ASSUME_NONNULL_END
