//
//  TVKMediaUrlRequest.h
//  TVKMediaUrl
//
//  Created by chen selwin on 14-7-16.
//  Copyright (c) 2014年 chen selwin. All rights reserved.
//


#import <Foundation/Foundation.h>
#import "TVKMediaUrlDefine.h"
#import "TVKMediaDefine.h"

/**
 *  视频请求地址回调
 */
@class TVKMediaUrlRequest;
@protocol TVKMediaUrlRequestDelegate <NSObject>

@optional

/**
 *  获取视频地址成功
 *
 *  @param request        请求实例
 *  @param videoUrls      分片mp4地址列表或hls地址，由request的mediaType决定
 *  @param videoDurations 分片mp4地址的时间列表，hls为空
 */
- (void)didMediaUrlRequestFinished:(TVKMediaUrlRequest*)request videoUrls:(NSArray*)videoUrls viedoDurations:(NSArray*)videoDurations;

/**
 *  获取视频清晰度列表成功
 *
 *  @param request        请求实例
 *  @param videoFormatList      清晰度列表
 */
- (void)didMediaUrlRequestFinished:(TVKMediaUrlRequest*)request videoFormatList:(NSArray*)videoFormatList;

/**
 *  更新视频地址
 *  若使用第一片地址带vkey的方式（默认不用），则用该回调更新地址
 *
 *  @param request   请求实例
 *  @param videoUrls 分片mp4带校验信息带地址列表
 *  @param videoDurations 分片mp4地址的时间列表，hls为空
 */
- (void)didMediaUrlRequestUpdated:(TVKMediaUrlRequest*)request videoUrls:(NSArray*)videoUrls viedoDurations:(NSArray*)videoDurations;

/**
 *  获取视频地址失败
 *
 *  @param request 请求实例
 *  @param error   错误描述
 */
- (void)didMediaUrlRequestFailed:(TVKMediaUrlRequest*)request error:(NSError*)error;

@end

/**
 *  获取视频地址请求类
 */
@interface TVKMediaUrlRequest : NSObject

/**
 *  请求回调
 */
@property(nonatomic,weak) id<TVKMediaUrlRequestDelegate> delegate;

/**
 *  请求地址类型，参考TVKMediaUrlType定义
 *  默认值为TVKMediaUrlType_Unknown
 */
@property(nonatomic,assign) TVKMediaUrlType mediaUrlType;
/**
 *是否是仅仅用来请求getvinfo. ?
 */
@property(nonatomic,assign) BOOL  forGetVinfoOnly;

/**
 *  请求视频清晰度类型，参考TVKMediaFormatType定义
 *  默认值为TVKMediaFormatType_AUTO
 */
@property(nonatomic,assign) TVKMediaFormatType mediaFormatType;

/**
 *  实际获取到的清晰度类型
 */
@property(nonatomic,readonly) TVKMediaFormatType receivedMediaFormatType;

/**
 *  点播的视频id.用于预缓存存储
 */
@property(nonatomic,readonly) NSString* vid;

/**
 *  获得请求点播视频地址的请求实例
 *
 *  @param videoID 视频videoID，若空则函数返回nil
 *
 *  @return 视频地址请求实例
 */
+ (TVKMediaUrlRequest*)requestWithVideoID:(NSString*)videoID;

/**
 *  获得请求直播视频地址的请求实例
 *  
 *  @param channelID 直播频道ID，若空则函数返回nil
 *
 *  @return 视频地址请求实例
 */
+ (TVKMediaUrlRequest*)requestWithChannelID:(NSString*)channelID;

/**
 *  发起请求
 */
- (void)sendRequest;

/**
 *  取消请求
 */
- (void)cancelRequest;

/**
 *  设置请求地址附加参数
 *
 *  @param key   键
 *  @param value 值
 */
- (void)setUrlExParamWithKey:(NSString*)key value:(NSString*)value;

@end
