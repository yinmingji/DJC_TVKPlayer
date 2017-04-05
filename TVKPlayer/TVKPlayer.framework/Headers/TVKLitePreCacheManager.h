//
//  TVKLitePreCacheManager.h
//  TVKPlayerLite
//
//  Created by GHL on 16/7/8.
//  Copyright © 2016年 Tencent Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@class TVKLitePreCacheManager;

@protocol TVKLitePreCacheManagerDelegate <NSObject>

- (void)startPreCacheTaskCallbackForVid:(NSString*)vid ResultPlayId:(int)playId FileID:(NSString*)fileID;

@end

@interface TVKLitePreCacheManager : NSObject

+ (TVKLitePreCacheManager*)sharedInstance;

@property(nonatomic,weak) id<TVKLitePreCacheManagerDelegate> delegate;

@property (nonatomic, assign) int currentServiceType;

@property (nonatomic, assign) BOOL saveDisk;

- (void)startPreCacheTaskForVid:(NSString*)vid;

- (int)startPreCacheLoadForPlayId:(int)playId ClipNo:(int)clip PreCacheDuration:(int)duration;

- (int)stopPreCacheForPlayId:(int)playId;

@end
