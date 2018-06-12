//
//  CYBPushMessageBase.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

NS_SWIFT_NAME(PushMessageBase)
@interface CYBPushMessageBase : NSObject <NSSecureCoding, NSCopying>

@property (nonatomic, strong, nullable) NSMutableDictionary<NSString *, id> *payloadDict;

- (instancetype)initWithPayload:(NSDictionary<NSString *, NSString *> *)payload;
- (nullable NSString *)json;

@end

NS_ASSUME_NONNULL_END
