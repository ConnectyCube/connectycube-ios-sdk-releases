//
//  CYBStorageTypes.h
//  ConnectyCube
//
//  Copyright © 2018 ConnectyCube. All rights reserved.
//

#import <Foundation/Foundation.h>

typedef NS_ENUM(NSUInteger, CYBBlobStatus) {
    
    CYBBlobStatusNew,
    CYBBlobStatusLocked,
    CYBBlobStatusCompleted
    
} NS_SWIFT_NAME(BlobStatus);

typedef NS_ENUM(NSUInteger, CYBBlobObjectAccessType) {
    
    CYBBlobObjectAccessTypeRead,
    CYBBlobObjectAccessTypeWrite
    
} NS_SWIFT_NAME(BlobObjectAccessType);
