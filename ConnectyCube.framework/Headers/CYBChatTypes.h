//
//  CYBChatTypes.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^CYBPingCompleitonBlock)(NSTimeInterval timeInterval, BOOL success);
typedef void(^CYBChatErrorBlock)(NSError * _Nullable error);
typedef void(^CYBUserIDBlock)(NSUInteger userID);
typedef void(^CYBLastActivityBlock)(NSUInteger seconds, NSError * _Nullable error);

NS_ASSUME_NONNULL_END
