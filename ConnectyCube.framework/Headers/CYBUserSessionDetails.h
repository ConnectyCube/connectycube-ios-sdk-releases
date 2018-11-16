//
//  CYBUserSessionDetails.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface CYBUserSessionDetails : NSObject

/** IP address */
@property (nonatomic, copy) NSString *ip;

/** Last Activity */
@property (nonatomic, strong) NSDate *lastActivity;

/** Location */
@property (nonatomic, copy) NSString *location;

/** Session identifier*/
@property (nonatomic, assign) NSUInteger sessionID;

/** User agent */
@property (nonatomic, copy) NSString *userAgent;

@end

NS_ASSUME_NONNULL_END
