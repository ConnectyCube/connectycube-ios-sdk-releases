//
//  CYBAddressBookRejectDetails.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 CYBAddressBookRejectDetails class interface.
 This class represents the reject details of an address book item.
 */
NS_SWIFT_NAME(AddressBookRejectDetails)
@interface CYBAddressBookRejectDetails : NSObject

/** The index of rejected object */
@property (nonatomic, assign) NSUInteger index;

/** The reject reason details*/
@property (nonatomic, copy) NSString *details;

@end

NS_ASSUME_NONNULL_END
