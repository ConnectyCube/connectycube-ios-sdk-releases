//
//  CYBPushMessage.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <ConnectyCube/CYBPushMessageBase.h>

NS_ASSUME_NONNULL_BEGIN

/**
 CYBPushMessage class interface.
 Push message representation.
 */
NS_SWIFT_NAME(PushMessage)
@interface CYBPushMessage : CYBPushMessageBase <NSSecureCoding, NSCopying>

/** 
 Alert body text.
 */
@property (nonatomic, copy, nullable) NSString *alertBody;

/** 
 Badge number.
 */
@property (nonatomic, strong, nullable) NSNumber *badge;

/** 
 Sound file name.
 */
@property (nonatomic, copy, nullable) NSString *soundFile;

/** 
 Localized body key may be used instead of alert body to make push message appear on local language.
 */
@property (nonatomic, copy, nullable) NSString *localizedBodyKey;

/** 
 Substitute strings for placeholders in alert text.
 */
@property (nonatomic, copy, nullable) NSArray *localizedBodyArguments;

/**
 Localization key for name of the alert action button.
 */
@property (nonatomic, copy, nullable) NSString *localizedActionKey;

/** 
 Dictionary of additional information.
 */
@property (nonatomic, copy, nullable) NSDictionary<NSString *, NSString *> *additionalInfo;

/** 
 Create new push message.
 
 @return New instance of CYBPushMessage
 */
+ (CYBPushMessage *)pushMessage;

@end

NS_ASSUME_NONNULL_END
