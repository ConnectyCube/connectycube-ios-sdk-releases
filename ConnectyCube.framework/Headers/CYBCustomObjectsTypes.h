//
//  CYBCustomObjectsTypes.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

// Permissions access types
extern NSString *const kCYBCustomObjectPermissionsAccessOpen;
extern NSString *const kCYBCustomObjectkPermissionsAccessOwner;
extern NSString *const kCYBCustomObjectPermissionsAccessOpenForUsersIDs;
extern NSString *const kCYBCustomObjectPermissionsAccessOpenForGroups;

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
