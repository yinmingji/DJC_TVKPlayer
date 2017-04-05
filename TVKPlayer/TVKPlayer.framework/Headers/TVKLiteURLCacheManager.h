//
//  TVKLiteURLCacheManager.h
//  TVKPlayerLite
//
//  Created by elonliu on 16/6/3.
//  Copyright © 2016年 Tencent Inc. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface TVKLiteURLCacheManager : NSObject

//最大url缓存文件大小，单位是KB，默认值是10M
@property (nonatomic, assign) unsigned long long maxCacheFileSize;

+ (TVKLiteURLCacheManager*)sharedInstance;

- (void)setUrlInfoForFileID:(NSString*)fileID Urls:(NSArray*)urls Times:(NSArray*)times;

//更新所有缓存，超过两小时的会被清理掉
- (void)updateAllInfo;

//是否能获取对应fileID的缓存
- (BOOL)couldGetInfoForFileID:(NSString*)fileID;

//获取对应fileID的URL缓存，超过两小时的返回是空
- (NSArray*)getUrlsForFileID:(NSString*)fileID;

//获取对应fileID的时长缓存，超过两小时的返回是空
- (NSArray*)getTimesForFileID:(NSString*)fileID;

//清理所有缓存
- (void)cleanAllInfo;

//获取当前vinfo缓存文件的大小，单位KB
- (long long)getCurrentCacheFileSize;

@end
