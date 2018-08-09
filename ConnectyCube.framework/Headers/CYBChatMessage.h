//
//  CYBChatMessage.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

@class CYBChatAttachment;

NS_ASSUME_NONNULL_BEGIN

/**
 CYBChatMessage class interface.
 Represents message object for peer-to-peer chat.
 
 @note Please set only text, recipientID & senderID values since ID is setted automatically by CYBChat.
 */
NS_SWIFT_NAME(ChatMessage)
@interface CYBChatMessage : NSObject <NSSecureCoding, NSCopying>

/** Unique identifier of message (sequential number). */
@property (nonatomic, copy, nullable) NSString *ID;

/** Message text. */
@property (nonatomic, copy, nullable) NSString *text;

/** Save to history. Default - YES. */
@property (nonatomic, assign) BOOL saveToHistory;

/** Message receiver ID. */
@property (nonatomic, assign) NSUInteger recipientID;

/**
 Message sender ID.
 
 @discussion Use only for 1-1 Chat.
 */
@property (nonatomic, assign) NSUInteger senderID;

/** Sender resource. */
@property (nonatomic, copy, nullable) NSString *senderResource;

/** A flag which tells that the message was edited. Chat server also updates the message's body in history storage if YES. */
@property (nonatomic, assign, readonly) BOOL edited;

/** A flag which tells that the message was removed. Chat server also delete the message from history storage if YES. */
@property (nonatomic, assign, readonly) BOOL removed;

/** An interval in seconds after which the message must be destroyed on both sender and receiver's sides. Used for self destruct chat messages feature. */
@property (nonatomic, assign) NSUInteger destroyAfterInterval;

/** Is message carbon. */
@property (nonatomic, assign, readonly) BOOL carbon;

/** Message date sent. */
@property (nonatomic, nullable) NSDate *dateSent;

/** Array of attachments. Array of CYBChatAttachment instances. */
@property (nonatomic, strong, nullable) NSArray <CYBChatAttachment *> *attachments;

/** Determines whether message was delayed. */
@property (nonatomic, assign) BOOL delayed;

/** Determines whether message is markable. */
@property (nonatomic, assign) BOOL markable;

/** Unique identifier of chat dialog. */
@property (nonatomic, copy, nullable) NSString *dialogID;

/** Created date. */
@property (nonatomic, strong, nullable) NSDate *createdAt;

/** Updated date. */
@property (nonatomic, strong, nullable) NSDate *updatedAt;

/** The array of user's ids who read this message. */
@property (nonatomic, copy, nullable) NSArray<NSNumber *> *readIDs;

/** The array of user's ids who received this message. */
@property (nonatomic, copy, nullable) NSArray<NSNumber *> *deliveredIDs;

/**
 Create new message.
 
 @return new CYBChatMessage instance
 */
+ (instancetype)message;

/**
 Create new markable message.
 
 @return new markable CYBChatMessage instance
 */
+ (instancetype)markableMessage;

@end

@interface CYBChatMessage(KeySubscripting)

/** Message custom parameters. Don't use 'body' & 'delay' as keys for parameters. */
@property (nonatomic, readonly) NSMutableDictionary<NSString *, NSString *> *customParameters;

// MARK: Keyed subscripting for customParameters

- (nullable NSString *)objectForKeyedSubscript:(NSString *)key;
- (void)setObject:(nullable NSString *)obj forKeyedSubscript:(NSString *)key;

@end

@interface CYBChatMessage(LocalParameters)

/** A dictionary of chat message local parameters for internal purpose, e.g. to store additional data for chat message in local database. */
@property (nonatomic, readonly) NSMutableDictionary<NSString *, id> *localParameters;

@end

NS_ASSUME_NONNULL_END
