//
//  CYBMulticastDelegate.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 CYBMulticastDelegate class interface.
 This class represents a manager, that is designed to work with multiple delegates at a time.
 */
NS_SWIFT_NAME(MulticastDelegate)
@interface CYBMulticastDelegate : NSObject

/**
 Adds the given delegate implementation to the list of observers.
 
 @param delegate delegate to add
 
 @note All delegates are called on the main thread asynchronously.
 */
- (void)addDelegate:(id)delegate;

/**
 Removes the given delegate implementation from the list of observers.
 
 @param delegate delegate to remove
 */
- (void)removeDelegate:(id)delegate;

/**
 Removes all delegates.
 */
- (void)removeAllDelegates;

/**
 Hashtable of all delegates.
 */
- (NSHashTable *)delegates;

@end

NS_ASSUME_NONNULL_END
