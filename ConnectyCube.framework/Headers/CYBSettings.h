//
//  CYBSettings.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <ConnectyCube/CYBLoggerTypes.h>

NS_ASSUME_NONNULL_BEGIN

/** 
 CYBSettings class interface.
 Class for framework setup.
 */
NS_SWIFT_NAME(Settings)
@interface CYBSettings : NSObject

/**
 Storing Application ID.
 */
@property (nonatomic, class) NSUInteger applicationID;

/**
 Setting API Key for ConnectyCube API.
 */
@property (nonatomic, class, nullable) NSString *authKey;

/**
 Setting API Secret for ConnectyCube API.
 */
@property (nonatomic, class, nullable) NSString *authSecret;

/**
 Set account key (from admin.connectycube.com).
 
 @note This parameter is skipped for custom endpoints.
 */
@property (nonatomic, class, nullable) NSString *accountKey;

/**
 Setting application group identifier.
 */
@property (nonatomic, class, nullable) NSString *applicationGroupIdentifier;

/**
 Setting Api Endpoint.
 
 @remark Default - https://api.connectycube.com
 */
@property (nonatomic, class, null_resettable) NSString *apiEndpoint;

/**
 Setting Chat endpoint.
 
 @remark Default - chat.connectycube.com
 */
@property (nonatomic, class, null_resettable) NSString *chatEndpoint;

/**
 Load ConnectyCube application settings from CYBSettings-Info.plist.
 
 @warning This method should be used only for Continuous Integration (CI), because of security reasons
 
 @discussion Raises an exception if any configuration step fails.
 
 @note This method should be called after the app is launched and before using ConnectyCube services.
 
 @code
 Required keys:

 applicationID : Number
 authorizationKey : String
 authorizationSecret : String
 accountKey : String
 
 Optional keys:
 
 apiEndpoint : String
 chatEndpoint : String
 autoReconnectEnabled : BOOL
 carbonsEnabled : BOOL
 streamManagementSendMessageTimeout : Integer
 reconnectTimerInterval : Double
 keepAliveInterval : Double
 chatEndpointPort : Integer
 @endcode
 */
+ (void)settingsFromPlist;

/**
 Load ConnectyCube application settings from specific plist with name.
 
 @param name plist file name
 */
+ (void)settingsFromPlistWithName:(NSString *)name;

@end

// MARK: Chat settings

/** Chat settings */

@interface CYBSettings (CYBChat)

/**
 Enable or disable chat auto reconnect.
 
 @remark The default value is YES.
 */
@property (nonatomic, class) BOOL autoReconnectEnabled;

/**
 Enable or disable message carbons.
 
 @remark The default value is YES.
 */
@property (nonatomic, class) BOOL carbonsEnabled;

/**
 Set timeout value for Stream Management send a message operation.
 */
@property (nonatomic, class) NSUInteger streamManagementSendMessageTimeout;

/**
 A reconnect timer may optionally be used to attempt a reconnect periodically.
 
 @remark Default value is 5 seconds
 */
@property (nonatomic, class) NSTimeInterval reconnectTimerInterval;

/**
 Many routers will teardown a socket mapping if there is no activity on the socket.
 For this reason, the stream supports sending keep-alive data.
 This is simply whitespace, which is ignored by the protocol.
 
 @note Keep-alive data is only sent in the absence of any other data being sent/received.
 
 @remark The default value is 20s. The minimum value for TARGET_OS_IPHONE is 10s, else 20s.
 
 @discussion To disable keep-alive, set the interval to zero (or any non-positive number).
 
 The keep-alive timer (if enabled) fires every (keepAliveInterval / 4) seconds.
 Upon firing it checks when data was last sent/received,
 and sends keep-alive data if the elapsed time has exceeded the keepAliveInterval.
 Thus the effective resolution of the keepalive timer is based on the interval.
 */
@property (nonatomic, class) NSTimeInterval keepAliveInterval;

/**
 The port the xmpp server is running on.
 
 @note If you do not explicitly set the port, the default port will be used. If you set the port to zero, the default port will be used.
 
 @remark The default port is 5223.
 **/
@property (nonatomic, class) NSUInteger chatEndpointPort;

@end

// MARK: - UIKit

/** UIKit Settings */
@interface CYBSettings (UIKit)

#if TARGET_OS_IOS

/**
 A Boolean value indicating whether the manager is enabled.
 
 @note If YES, the manager will change status bar network activity indicator according to network
 operation notifications it receives. The default value is NO.
 
 @param enabled
 */

@property (nonatomic, class) BOOL networkIndicatorManagerEnabled;

/**
 A Boolean value indicating whether the network activity indicator is currently displayed in the
 status bar.
 */
+ (BOOL)isNetworkIndicatorVisible;

#endif

@end

// MARK: - Logging

/** Logging Settings*/
@interface CYBSettings (Logging)

/** Set SDK log level (by default: CYBLogLevelDebug). Possible values: CYBLogLevelDebug, CYBLogLevelNothing. */
@property (nonatomic, class) CYBLogLevel logLevel;

/** Enable full XMPP Framework logging to console. By default is disabled. */
+ (void)enableXMPPLogging;

/** Disable full XMPP Framework logging to console. */
+ (void)disableXMPPLogging;

/**
 Enable log to file
 
 The approximate maximum size to allow log files to grow.
 If a log file is larger than this value after a log statement is appended,
 then the log file is rolled.
 
 @param maximumFileSize maximum file size in bytes, for example: 1024 * 1024 * 10 = 10Mb
 */
+ (void)enableFileLoggingWithMaximumFileSize:(unsigned long long)maximumFileSize;

/** Disable logging to file */
+ (void)disableFileLogging;

/**
 Returns log file paths if loggint to file is enabled
 Example name of log file:
 /var/mobile/Containers/Data/Application/<UDID>/Library/Caches/Logs/com.quickblox.<app_name> 2016-03-25 11-23.log
 
 @return Array of log file paths or nil if logging to file is disabled
 */
+ (nullable NSArray<NSString *> *)logFilePaths;

@end

/** NSURLSessionConfiguration */
@interface CYBSettings (NSURLSessionConfiguration)

/**
 Set custom session configuration that will be used for REST API requests.
 '[NSURLSessionConfiguration defaultSessionConfiguration]' is used if nil is passed.
 */
@property (nonatomic, class, nullable) NSURLSessionConfiguration *sessionConfiguration;

@end

NS_ASSUME_NONNULL_END
