//
//  CYBPaginator.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 CYBPaginator class interface.
 This class represents a page interface to operate with server requests.
 */
NS_SWIFT_NAME(Paginator)
@interface CYBPaginator : NSObject

/**
 Skip - to specify the number of objects the server will skip from the very beginning.
 */
@property (nonatomic) NSUInteger skip;

/**
 Limit - to specify the maximum number of objects the server will return.
 
 @remark Default - 100.
 */
@property (nonatomic) NSUInteger limit;

/**
 Total entries - the total number of objects in application.
 */
@property (nonatomic, readonly) NSUInteger totalEntries;

+ (CYBPaginator *)limit:(NSUInteger)limit;

+ (CYBPaginator *)limit:(NSUInteger)limit skip:(NSUInteger)skip;

+ (CYBPaginator *)limit:(NSUInteger)limit skip:(NSUInteger)skip totalEntries:(NSUInteger)totalEntries;

@end

NS_ASSUME_NONNULL_END
