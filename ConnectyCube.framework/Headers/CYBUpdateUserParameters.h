//
//  CYBUpdateUserParameters.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

/**
 CYBUpdateUserParameters class interface.
 This class represents interfae for updating user parameters.
 */
NS_SWIFT_NAME(UpdateUserParameters)
@interface CYBUpdateUserParameters : NSObject

/** 
 ID of User in external system.
 */
@property (nonatomic, assign) NSUInteger externalUserID;

/** 
 ID of User associated blob (for example, ID of user's photo).
 */
@property (nonatomic, assign) NSUInteger blobID;

/** 
 ID of User in Facebook.
 */
@property (nonatomic, copy, nullable) NSString *facebookID;

/** 
 ID of User in Twitter.
 */
@property (nonatomic, copy, nullable) NSString *twitterID;

/** 
 User's full name.
 */
@property (nonatomic, copy, nullable) NSString *fullName;

/** 
 User's email.
 */
@property (nonatomic, copy, nullable) NSString *email;

/** 
 User's login.
 */
@property (nonatomic, copy, nullable) NSString *login;

/** 
 User's phone.
 */
@property (nonatomic, copy, nullable) NSString *phone;

/** 
 User's website.
 */
@property (nonatomic, copy, nullable) NSString *website;

/**
 User's tags.
 */
@property (nonatomic, strong, nullable) NSArray<NSString *> *tags;

/** 
 User's password.
 */
@property (nonatomic, copy, nullable) NSString *password;

/** 
 User's old password.
 */
@property (nonatomic, copy, nullable) NSString *oldPassword;

/** 
 User's custom data field.
 */
@property (nonatomic, copy, nullable) NSString *customData;

/**
 User's avatar.
 */
@property (nonatomic, copy, nullable) NSString *avatar;

@end

NS_ASSUME_NONNULL_END
