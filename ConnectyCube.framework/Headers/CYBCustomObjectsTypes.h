//
//  CYBCustomObjectsTypes.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// Permissions access types
extern NSString * const kCYBCustomObjectPermissionsAccessOpen NS_SWIFT_NAME(CustomObjectPermissionsAccessOpen);
extern NSString * const kCYBCustomObjectkPermissionsAccessOwner NS_SWIFT_NAME(CustomObjectkPermissionsAccessOwner);
extern NSString * const kCYBCustomObjectPermissionsAccessOpenForUsersIDs NS_SWIFT_NAME(CustomObjectPermissionsAccessOpenForUsersIDs);
extern NSString * const kCYBCustomObjectPermissionsAccessOpenForGroups NS_SWIFT_NAME(CustomObjectPermissionsAccessOpenForGroups);

typedef NS_ENUM(NSUInteger, CYBCustomObjectAggregationOperator) {
    
    CYBCustomObjectAggregationOperatorNone,
    CYBCustomObjectAggregationOperatorAverage,
    CYBCustomObjectAggregationOperatorMinimum,
    CYBCustomObjectAggregationOperatorMaximum,
    CYBCustomObjectAggregationOperatorSummary

} NS_SWIFT_NAME(CustomObjectAggregationOperator);

typedef NS_ENUM(NSUInteger,  CYBCustomObjectPermissionsAccess) {
    
    CYBCustomObjectPermissionsAccessOpen,
    CYBCustomObjectPermissionsAccessOwner,
    CYBCustomObjectPermissionsAccessNotAllowed,
    CYBCustomObjectPermissionsAccessOpenForUsersIDs,
    CYBCustomObjectPermissionsAccessOpenForGroups,
    
} NS_SWIFT_NAME(CustomObjectPermissionsAccess);

NS_ASSUME_NONNULL_END
