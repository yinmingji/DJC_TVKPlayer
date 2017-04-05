//
//  TVKMediaPlaybackDelegate.h
//  TVKPlayer
//
//  Created by chen selwin on 14-11-4.
//  Copyright (c) 2014年 tencent. All rights reserved.
//

#ifndef TVKPlayer_TVKMediaPlaybackDelegate_h
#define TVKPlayer_TVKMediaPlaybackDelegate_h

#import "TVKMediaDefine.h"
#import <AVFoundation/AVFoundation.h>

@class TVKMediaPlayer;

@protocol TVKMediaPlaybackDelegate <NSObject>

@optional

/**
 *  播放器将播放某个地址时的回调，使用者可返回实际需要播放的地址
 *
 *  @param mediaPlayer 播放器实例
 *  @param url 将要播放的地址
 *
 *  @return 实际播放的地址
 *
 */
- (NSString*)mediaPlayer:(TVKMediaPlayer*)mediaPlayer willPlayUrl:(NSString*)url;

/**
 *  播放器状态变化
 *
 *  @param mediaPlayer 播放器实例
 *  @param state 状态
 *  @param error 播放失败时的错误信息
 *
 */
- (void)mediaPlayer:(TVKMediaPlayer*)mediaPlayer stateChanged:(TVKMediaPlayerState)state withError:(NSError*)error;

/**
 *  播放器全屏改变
 *
 *  @param fullScreen 是否全屏
 *
 */
- (void)mediaPlayer:(TVKMediaPlayer*)mediaPlayer screenChanged:(BOOL)fullScreen;

/**
 *  播放器事件
 *
 *  @param mediaPlayer 播放器实例
 *  @param event 事件
 *
 */
- (void)mediaPlayer:(TVKMediaPlayer*)mediaPlayer eventOccur:(TVKMediaPlayerEvent)event userInfo:(NSDictionary*)userInfo;

/**
 *  播放器进度变化
 *
 *  @param mediaPlayer 播放器实例
 *  @param currentTime 当前播放进度
 *  @param duration 总时长
 */
- (void)mediaPlayer:(TVKMediaPlayer*)mediaPlayer progressUpdated:(NSTimeInterval)currentTime duration:(NSTimeInterval)duration;

/**
 *  播放器进度变化，包含可播放时长
 *
 *  @param mediaPlayer 播放器实例
 *  @param currentTime 当前播放进度
 *  @param playableDuration 可播放时长
 *  @param duration 总时长
 */
- (void)mediaPlayer:(TVKMediaPlayer*)mediaPlayer progressUpdated:(NSTimeInterval)currentTime playableDuration:(NSTimeInterval)playableDuration duration:(NSTimeInterval)duration;

/**
 *  播放器可替换playeritem的回调，使用者可返回添加itemoutput后的item
 *
 *  @param mediaPlayer 播放器实例
 *  @param currentItem 播放器当前playeritem
 *
 *  @return 修改后的item
 *
 */
- (AVPlayerItem*)mediaPlayer:(TVKMediaPlayer*)mediaPlayer updateCurrentItem:(AVPlayerItem*)currentItem;

//弹幕相关回调
- (void)mediaPlayer:(TVKMediaPlayer*)mediaPlayer banabaComes:(NSArray*)array ContentKey:(NSString*)contentKey isLive:(BOOL)isLive;

- (void)mediaPlayer:(TVKMediaPlayer*)mediaPlayer banabaFinishPostBanabaWithErrorCode:(int)code Content:(NSString *)content;

- (void)mediaPlayer:(TVKMediaPlayer*)mediaPlayer banabaModelDidFinishBanabaTargetID:(NSString*)targetId;

@end

#endif
