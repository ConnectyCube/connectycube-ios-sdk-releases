//
//  CYBChatTypes.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/** Block with time interval and success flag */
NS_SWIFT_NAME(PingCompleitonBlock)
typedef void(^CYBPingCompleitonBlock)(NSTimeInterval timeInterval, BOOL success);

/** Block with Error */
NS_SWIFT_NAME(ChatErrorBlock)
typedef void(^CYBChatErrorBlock)(NSError * _Nullable error);

/** Block with user ID */
NS_SWIFT_NAME(UserIDBlock)
typedef void(^CYBUserIDBlock)(NSUInteger userID);

/** Block with seconds and error */
NS_SWIFT_NAME(LastActivityBlock)
typedef void(^CYBLastActivityBlock)(NSUInteger seconds, NSError * _Nullable error);

NS_ASSUME_NONNULL_END
