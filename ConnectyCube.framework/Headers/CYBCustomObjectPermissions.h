//
//  CYBCustomObjectPermissions.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <ConnectyCube/CYBCustomObjectsTypes.h>

NS_ASSUME_NONNULL_BEGIN

/** 
 CYBCustomObjectPermissions class interface.
 This class represents ConnectyCube custom object permissions.
 */
NS_SWIFT_NAME(CustomObjectPermissions)
@interface CYBCustomObjectPermissions : NSObject <NSSecureCoding, NSCopying>

/** 
 Record ID.
 */
@property (nonatomic, copy, nullable) NSString *recordID;

/** 
 Read access.
 */
@property (nonatomic, assign) CYBCustomObjectPermissionsAccess readAccess;

/** 
 Update access.
 */
@property (nonatomic, assign) CYBCustomObjectPermissionsAccess updateAccess;

/** 
 Delete access.
 */
@property (nonatomic, assign) CYBCustomObjectPermissionsAccess deleteAccess;

/** 
 Users IDs for read access.
 */
@property (nonatomic, strong, nullable) NSArray<NSString *> *usersIDsForReadAccess;

/** 
 Users groups for read access.
 */
@property (nonatomic, strong, nullable) NSArray<NSString *> *usersGroupsForReadAccess;

/** 
 Users IDs for update access.
 */
@property (nonatomic, strong, nullable) NSArray<NSString *> *usersIDsForUpdateAccess;

/** 
 Users groups for update access.
 */
@property (nonatomic, strong, nullable) NSArray<NSString *> *usersGroupsForUpdateAccess;

/** 
 Users IDs for delete access.
 */
@property (nonatomic, strong, nullable) NSArray<NSString *> *usersIDsForDeleteAccess;

/**
 Users groups for delete access.
 */
@property (nonatomic, strong, nullable) NSArray<NSString *> *usersGroupsForDeleteAccess;

/** 
 Create permissions object.
 
 @return New instance of CYBCustomObjectPermissions
 */
+ (instancetype)permissions;

// MARK: - Converters

+ (CYBCustomObjectPermissionsAccess)permissionsAccessFromString:(NSString *)permissionsAccess;
+ (nullable NSString *)permissionsAccessToString:(CYBCustomObjectPermissionsAccess)permissionsAccess;

@end

NS_ASSUME_NONNULL_END
