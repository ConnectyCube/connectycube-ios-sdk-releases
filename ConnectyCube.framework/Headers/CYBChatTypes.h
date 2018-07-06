//
//  CYBChatTypes.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(PingCompleitonBlock)
typedef void(^CYBPingCompleitonBlock)(NSTimeInterval timeInterval, BOOL success);
NS_SWIFT_NAME(ChatErrorBlock)
typedef void(^CYBChatErrorBlock)(NSError * _Nullable error);
NS_SWIFT_NAME(UserIDBlock)
typedef void(^CYBUserIDBlock)(NSUInteger userID);
NS_SWIFT_NAME(LastActivityBlock)
typedef void(^CYBLastActivityBlock)(NSUInteger seconds, NSError * _Nullable error);

NS_ASSUME_NONNULL_END
