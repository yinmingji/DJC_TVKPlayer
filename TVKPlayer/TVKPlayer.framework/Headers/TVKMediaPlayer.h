//
//  TVKMediaPlayer.h
//  TVKPlayer
//
//  Created by chen selwin on 14-11-4.
//  Copyright (c) 2014年 tencent. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "TVKMediaPlaybackDelegate.h"
#import "TVKMediaDefine.h"
#import "TVKMediaViewController.h"
#import "TVHttpProxyManager.h"


@interface TVKMediaPlayer : NSObject

/**
 *  回调
 */
@property(nonatomic,weak) id<TVKMediaPlaybackDelegate> delegate;

/**
 *  播放器的UIViewController
 *  注：不可直接使用此controller进行present等操作
 */
@property(nonatomic,readonly) TVKMediaViewController* viewController;

/**
 *  播放器控制方式
 */
@property(nonatomic,readonly) TVKMediaPlayerControlMode controlModel;

/**
 *  设置是否需要缺省控制UI，默认YES
 */
@property(nonatomic,assign) BOOL defaultUI;

/**
 *  播放器状态
 */
@property(nonatomic,readonly) TVKMediaPlayerState state;

/**
 *  是否处于全屏状态
 */
@property(nonatomic,readonly) BOOL isFullScreen;

/**
 *  视频时长
 */
@property(nonatomic,readonly) NSTimeInterval duration;

/**
 *  可播放时长
 */
@property(nonatomic,readonly) NSTimeInterval playableDuration;

/**
 *  当前播放进度
 */
@property(nonatomic,readonly) NSTimeInterval currentPlaybackTime;

/**
 *  视频播放默认清晰度
 */
@property(nonatomic,assign) TVKMediaFormatType defaultMediaFormat;

/**
 *  当前视频播放的清晰度
 */
@property(nonatomic,readonly) TVKMediaFormatType currentMediaFormat;

/**
 *  当前视频的清晰度列表
 */
@property(nonatomic,readonly) NSArray* mediaFormatList;

/**
 *  当前视频标题
 */
@property(nonatomic,strong) NSString* videoTitle;

/**
 *  当前视频标题后标记（例如：独播）
 */
@property(nonatomic,strong) NSString* videoTitleMark;

/**
 *  是否为直播
 */
@property(nonatomic,readonly) BOOL isLive;

/**
 *  歌手ID（QQ音乐用，需要在打开播放前设置）
 */
@property(nonatomic,strong) NSString* singerID;

/**
 *  设置全屏和小窗播放器之间是否自动旋转，YES-不旋转，NO-旋转，默认旋转
 */
@property(nonatomic,assign) BOOL screenLock;

/**
 *  设置全屏播放器是否旋转，YES-不旋转，NO-旋转，默认旋转
 */
@property(nonatomic,assign) BOOL fullScreenLock;

/**
 *  设置全屏播放器否锁定返回小窗， YES-不返回, NO-返回，点击返回按钮或调用强制旋转方法会设为NO。
 */
@property(nonatomic,assign) BOOL switchScreenLock;

/**
 *  获取DLNA状态
 *  YES-激活 NO-非激活
 */
@property(nonatomic,readonly) BOOL isDLNAActive;

/**
 *  获取airplay状态
 *  YES-激活 NO-非激活
 */
@property(nonatomic,readonly) BOOL isAirPlayActive;

/**
 *  显示直播倒计时
 *  YES-显示 NO-不现实，默认显示
 */
@property(nonatomic,assign) BOOL showFreeLiveCutDown;

/**
 *  打开模式正在播放的广告界面元素（倒计时等按钮）将隐藏，后续播放将无广告
 *  默认NO
 */
@property(nonatomic,assign) BOOL weakenAdMode;

/**
 *  播放器上报的透传扩展信息，由app设置，将会在上报事件时带上，大小限制1k字节
 */
@property(nonatomic,strong) NSString* reportInfoEx;

/**
 *  设置播放器present依据的viewController
 *
 */
@property(nonatomic,assign) UIViewController* presentViewController;

/**
 *  弹幕开关
 *
 */
@property (nonatomic, assign) BOOL isBanabaSwitchOn;

/**
 *  selfControlMode,自己控制全屏切换,不再使用SDK切换全屏的方法
 *
 */
@property(nonatomic,assign) BOOL selfControlMode;

/**
 *  通知播放器是否进入了mini窗口
 *
 */
@property(nonatomic,assign) BOOL enterMiniView;

/**
 *  播放器是否进入了全屏播放器
 *
 */
@property(nonatomic,assign,readonly) BOOL enterFullScreen;

/**
 *  播放器是否在显示结束推荐面板
 *
 */
@property(nonatomic,assign,readonly) BOOL isShowingRecommendPanel;

@property (nonatomic, assign) BOOL enableBackgroundPlay;;

@property (nonatomic, assign) CGFloat playerRate;

/**
 *  设置各业务的serviceType，需在init下载组件前设置
 */
@property(nonatomic,assign) int serviceType;

/**
 *  通知播放器将要进入全屏播放器
 *
 */
- (void)willEnterOrLeaveFullScreen:(BOOL)enter;

/**
 *  通知播放器已经进入全屏播放器
 *
 */
- (void)didEnterOrLeaveFullScreen:(BOOL)enter;

/**
 *  刷新进入全屏的UI
 *
 */
- (void)lauchFullScreenManually;

/**
 *  设置播放器frame大小
 *
 */
- (void)setPlayerFrame:(CGRect)frame;


/**
 *  初始化播放器的基本数据，需要在程序启动时调用
 */
+ (void)initializeTVKPlayer;

/**
 *  获取播放器共享实例，一般情况下程序内部只会存在一个播放器实例
 *
 *  @return TVKMediaPlayer的共享实例
 */
+ (TVKMediaPlayer*)sharedInstance;

/**
 *  启动点播单个视频
 *
 *  @param videoID 视频ID
 *  @param mediaType 视频流请求类型
 *  @param startPosition 视频播放的起始时间
 *
 */
- (void)openMediaPlayerWithVideoID:(NSString*)videoID mediaType:(TVKMediaType)mediaType startPosition:(NSTimeInterval)startPosition;

/**
 *  启动点播某个专辑
 *
 *  @param coverID 专辑ID
 *  @param videoID 播放专辑中的视频ID
 *  @param mediaType 视频流请求类型
 *  @param startPosition 视频播放的起始时间
 *
 */
- (void)openMediaPlayerWithCoverID:(NSString*)coverID videoID:(NSString*)videoID mediaType:(TVKMediaType)mediaType startPosition:(NSTimeInterval)startPosition;

/**
 *  启动直播
 *
 *  @param channelID 直播ID
 *
 */
- (void)openMediaPlayerWithChannelID:(NSString*)channelID;

/**
 *  启动带pid的直播
 *
 *  @param channelID 直播ID
 *  @param pid 对应的pid
 *
 */
- (void)openMediaPlayerWithChannelID:(NSString *)channelID andPID:(NSString *)pid;

/**
 *  启动地址的播放
 *
 *  @param url 播放地址，可以是本地地址
 *  @param live 是否为直播
 *  @param videoID 用于上报和广告，不传vid将不会请求广告
 *  @param startPosition 视频播放的起始时间，点播有效
 *
 */
- (void)openMediaPlayerWithUrl:(NSString*)url live:(BOOL)live videoID:(NSString*)videoID startPosition:(NSTimeInterval)startPosition;

/**
 *  present全屏播放器
 *  将进入TVKMediaPlayerControlMode_Present模式
 *
 *  @param viewController 在此controller上present
 *
 */
- (void)presentMediaPlayerWithViewController:(UIViewController*)viewController;

/**
 *  dismiss全屏播放器
 *  TVKMediaPlayerControlMode_Present模式下有效
 */
- (void)dismissMediaPlayer;

/**
 *  使播放器关联某个UIViewController，并设置播放器小窗模式下的frame
 *  将进入TVKMediaPlayerControlMode_Attach模式
 *
 *  @param viewController 关联的UIViewController
 *  @param smallPlayerFrame 小窗播放器在viewController.view中的位置
 *
 */
- (void)attachMediaPlayerWithViewController:(UIViewController*)viewController smallPlayerFrame:(CGRect)smallPlayerFrame;

/**
 *  使播放器关联某个UIViewController，并设置播放器小窗模式下的frame
 *  将进入TVKMediaPlayerControlMode_Attach模式
 *
 *  @param viewController 关联的UIViewController
 *  @param smallPlayerFrame 小窗播放器在landingView中的位置
 *  @param landingView 小窗播放器所在的landingView
 *
 */
- (void)attachMediaPlayerWithViewController:(UIViewController*)viewController smallPlayerFrame:(CGRect)smallPlayerFrame landingView:(UIView*)landingView;

/**
 *  取消播放器的关联
 *  TVKMediaPlayerControlMode_Attach模式下有效
 */
- (void)detachMediaPlayer;

/**
 *  强制全屏和小窗切换，只有在TVKMediaPlayerControlMode_Attach模式下才有效
 *
 *  @param fullScreen YES:全屏 NO:小窗
 *
 */
- (void)switchFullScreen:(BOOL)fullScreen;

/**
 *  播放器其他清晰度格式
 *
 *  @param mediaFormat 其他清晰度
 */
- (void)playOtherMediaFormat:(TVKMediaFormatType)mediaFormat;

/**
 *  是否旋转，该函数会触发播放器的大小窗切换，请在viewController的shouldAutorotate调用
 *  
 *  @return YES：旋转 NO：不旋转
 */
-(BOOL)shouldAutorotate;

/**
 *  播放器支持的屏幕状态
 */
- (NSUInteger)supportedInterfaceOrientations;

/**
 *  启动播放
 */
- (void)play;

/**
 *  暂停播放
 */
- (void)pause;

/**
 *  暂停播放，同时请求暂停广告
 */
- (void)pauseWithAD;

/**
 *  中止播放
 */
- (void)stop;

/**
 *  设置播放时间点（实现快进快退）
 *
 *  @param playbackTime 播放时间点，单位秒
 */
- (void)seekTo:(NSTimeInterval)playbackTime;

/**
 *  添加用户小窗控制界面，defaultUI将自动设置为NO
 *
 *  @param smallPlayerUI 小窗控制UIView
 */
- (void)addCustomSmallPlayerUI:(UIView*)smallPlayerUI;

/**
 *  添加用户全屏控制界面，defaultUI将自动设置为NO
 *
 *  @param mainPlayerUI 全屏控制UIView
 */
- (void)addCustomMainPlayerUI:(UIView*)mainPlayerUI;

/**
 *  删除用户控制界面
 *
 *  @param smallPlayer YES-小窗播放器界面 NO-主播放器界面
 */
- (void)removeCustomPlayerUI:(BOOL)smallPlayer;

/**
 *  获取用户控制界面
 *
 *  @param smallPlayer YES-小窗播放器界面 NO-主播放器界面
 */
- (UIView*)customPlayerUI:(BOOL)smallPlayer;

/**
 *  启用播放器功能项
 *
 *  @param funcItem 需要启动的功能项
 */
- (void)enablePlayerFuncWithItem:(TVKMediaPlayerFuncItem)funcItem;

/**
 *  禁用播放器功能项
 *
 *  @param funcItem 需要禁用的功能项
 */
- (void)disablePlayerFuncWithItem:(TVKMediaPlayerFuncItem)funcItem;

/**
 *  跳过广告
 */
- (void)skipAdertisement;

/**
 *  添加自定义view
 *
 *  @param customView 自定义UIView
 *  @param layerID 取值在TVKMediaPlayerCustomLayerIDBegin和TVKMediaPlayerCustomLayerIDEnd之间
 *  @param smallPlayer YES-添加在小窗播放器 NO-添加在主播放器
 */
- (BOOL)addCustomView:(UIView*)customView withLayerID:(int)layerID smallOrMainPlayer:(BOOL)smallPlayer;

/**
 *  删除自定义view
 *
 *  @param layerID 取值在TVKMediaPlayerCustomLayerIDBegin和TVKMediaPlayerCustomLayerIDEnd之间
 *  @param smallPlayer YES-小窗播放器 NO-主播放器
 */
- (void)removeCustomViewWithLayerID:(int)layerID smallOrMainPlayer:(BOOL)smallPlayer;

/**
 *  获取自定义view
 *
 *  @param layerID 取值在TVKMediaPlayerCustomLayerIDBegin和TVKMediaPlayerCustomLayerIDEnd之间
 *  @param smallPlayer YES-小窗播放器 NO-主播放器
 *  @return 自定义view
 */
- (UIView*)customViewWithLayerID:(int)layerID smallOrMainPlayer:(BOOL)smallPlayer;

/**
 *  恢复到播放器UI，使广告着陆页、弹幕输入框等消失
 */
- (void)recoverPlayerUI;

/**
 *  设置CGI请求附加参数
 *
 *  @param key   键
 *  @param value 值
 */
- (void)setUrlExParamWithKey:(NSString*)key value:(NSString*)value;

/**
 *  清理请求地址附加参数
 *
 */
- (void)cleanUrlExParams;

/**
 *  设置直播是否跳过继续试看提示 init时调用一次即可
 *
 */
- (void)enablePlayerFuncOfSkipContinueTryWatchTip:(BOOL)skip;

/**
 *  是否应该显示结束推荐面板，默认显示
 *
 *  @param show YES为显示，NO为不显示
 */
- (void)shouldShowRecommendPannel:(BOOL)show;

/**
 *  启用手势操作缩放播放器view的模式，启用后会关闭播放器的手势控制进度，音量等功能
 *
 *  @param minScaleRate   最小缩放比例，需小于1.0，默认为1.0
 *  @param maxScaleRate   最大缩放比例，需大于1.0，默认为1.0
 */
- (void)enablePlayerFuncOfGestureModeWithMinScaleRate:(CGFloat)minScale andMaxScaleRate:(CGFloat)maxScale;

/**
 *  手势操作下拖动的处理函数
 *
 */
- (void)didPan:(UIPanGestureRecognizer*)thePanGesture;

/**
 *  手势操作下缩放的处理函数
 *
 */
- (void)didPinch:(UIPinchGestureRecognizer *)thePinchGesture;

/**
 *  重置播放器的view，手势缩放模式启用后有效
 *
 */
- (void)resetPlayerViewInGestureMode;

/**
 *  停用手势缩放模式
 *
 */
- (void)disablePlayerFuncOfGestureMode;

/**
 *  获取唯一设备标识
 *
 */
- (NSString*)getDeviceID;

/**
 *  获取当前视频截图
 *
 */
- (UIImage *)getCurrentVideoScreenShot;

/**
 *  播放器静音接口,ios7以上hls下无效
 *
 *  @param mute YES为静音，NO为不静音且恢复成系统音量
 */
- (void)setPlayerMuted:(BOOL)mute;

/**
 *  广告播放器静音接口,ios7以上hls下无效
 *
 *  @param mute YES为静音，NO为不静音且恢复成系统音量
 */
- (void)setAdPlayerMuted:(BOOL)mute;


/**
 *  当前播放视频是否有弹幕
 *
 *
 */
- (bool)isBanabaAvailable;

/**
 *  更新弹幕控制状态
 *
 *  @param switchOn:YES 开启弹幕 NO 关闭弹幕 autoplay: YES为请求弹幕后自动播放弹幕，NO为不自动播放，需手动开启播放
 */
- (bool)updateBanabaStatusWithSwitch:(BOOL)switchOn andAutoPlay:(BOOL)autoplay;

/**
 *  设置弹幕状态，用于播放，暂停，关闭弹幕
 *
 *
 */
- (void)setBanabaStatus:(QLBanabaStatus)banabaStatus;

/**
 *  设置弹幕显示行数
 *
 *
 */
- (void)setBanabaChannelCount:(NSUInteger)count;


/**
 *  发表弹幕，最长message length为25
 *
 *
 */
- (bool)commitNewMessage:(NSString*)message;

- (void)didSingleTap:(UITapGestureRecognizer *)theTapGesture;

- (void)didDoubleTap:(UITapGestureRecognizer *)theTapGesture;

- (void)setLoadingImage:(UIImage*)loadingImage;

- (void)setAdMode:(int)adMode;

/**
 *  边下边播部分
 */

/**
 *  初始化下载组件
 *  @param strDataDir 存储目录
 *  其他几个函数指针需要传入
 //日志函数
 void TVHttpProxyLogImpl(const char *logStr){}
 //上报函数
 void TVHttpProxyReportImpl(const char *reportStr){}
 //回调函数：回调下载速度，进度，错误等信息
 void TVHttpProxyCallBackImpl(const char* msg){}
 *  返回: 成功为0
 */
- (int)initModule:(NSString *)strDataDir withLogFunc:(pfnTVHttpProxyLogFunc)logFunc withReportFunc:(pfnTVHttpProxyReportFunc)reportFunc withCallBackFunc:(pfnTVHttpProxyCallBackFunc)callBackFunc;

//析构
- (void)deinitTVHttpProxy;

/**
 *  获取下载组件版本号
 *  返回: 下载组件版本号，形如 "TVHttpproxy.1.0.0.0002"
 */
- (NSString *)TVHttpProxyGetVersion;

/**
 *  启动边下边播视频播放
 *
 *  @param videoID 视频ID
 *  @param mediaType 视频流请求类型
 *  @param startPosition 视频播放的起始时间
 *  @param savedisk 是否存到磁盘
 *  @param fileID 文件标识，不设置的话会设置为VID+"."+清晰度，例如@"w0018wrqjum.hd"
 *  返回: 可在状态变为prepared后获取currentPlayID,失败返回-1
 *
 */
- (int)openTVHttpProxyPlayerWithVideoID:(NSString*)videoID mediaType:(TVKMediaType)mediaType startPosition:(NSTimeInterval)startPosition savedisk:(BOOL)savedisk fileID:(NSString*)fileID;

/**
 *  当前播放的playID （收到prepared回调后才能获取到）
 */
@property(nonatomic,readonly) int currentPlayID;

/*
 * 方法: TVHttpProxySetRemainTime
 * 描述: 设置剩余播放时间, 可选项，用于下载库流量管理
 * 参数:
 playID:TVHttpProxyStartPlay方法返回的playID
 remainTime:剩余播放时间(秒）
 */
-(void)TVHttpProxySetRemainTime:(int)playID withRemainTime:(int)remainTime;


/*
 * 方法: TVHttpProxySetNetWorkState
 * 描述: 设置网络状态
 * 参数:
 state:参看TVHttpProxyStateEnum.h里面的状态定义
 */
-(void)TVHttpProxySetNetWorkState:(int)state;

/*
 * 方法: TVHttpProxySetPlayerState
 * 描述: 设置播放器状态
 * 参数:
 playID:TVHttpProxyStartPlay方法返回的playID
 state:参看TVHttpProxyStateEnum.h里面的状态定义
 */
-(void)TVHttpProxySetPlayerState:(int)playID withPlayerState:(int)state;



/*
 * 方法: TVHttpProxySetCookie
 * 描述: 设置Cookie
 * 参数:
 cookie:字符串
 */
-(void)TVHttpProxySetCookie:(NSString *)cookie;



/*
 * 方法: TVHttpProxyStopPlay
 * 描述: 停止播放
 * 参数:
 playID:TVHttpProxyStartPlay方法返回的playID
 */

-(void)TVHttpProxyStopPlay:(int)playID;


/*
 * 方法: TVHttpProxyHandlerMemoryWarning
 * 描述: 处理内存告警
 * 参数:
 */

-(void)TVHttpProxyHandlerMemoryWarning;

/*
 * 设置最大内存大小
 * @maxSize_Byte:最大内存大小，单位:字节
 * 返回值:
 * 0表示成功，非0表示失败
 */
-(int)TVHttpProxySetMaxMemorySize:(long long)maxSize_Byte;


/*
 * 清理内存
 * 返回值:
 * 0表示成功，非0表示失败
 */
-(int)TVHttpProxyCleanMemory;



/*
 * 设置最大存储大小
 * @maxSize_Byte:最大存储大小，单位:字节
 * 返回值:
 * 0表示成功，非0表示失败
 */
-(int)TVHttpProxySetMaxStorageSize:(long long)maxSize_Byte;



/*
 * 清理存储
 * 返回值:
 * 0表示成功，非0表示失败
 */
-(int)TVHttpProxyCleanStorage;


/*
 * 暂停存储IO，不再进行文件读写
 * 返回值:
 * 0表示成功，非0表示失败
 */
-(int)TVHttpProxyPauseStorageIO;


/*
 * 恢复存储IO
 * 返回值:
 * 0表示成功，非0表示失败
 */
-(int)TVHttpProxyResumeStorageIO;

//注意默认fileID 为@"视频vid"+"."+"清晰度",例如高清的vid:w0018wrqjum清晰度hd，fileID为@"w0018wrqjum.hd"，也可自己在播放时设置

/*
 * 判断分片文件是否在存储中下载完成
 * 返回值:
 * true表示完成，false表示未完成
 */
-(bool)TVHttpProxyIsClipCompleteOnDisk:(NSString*)fileID withClipNo:(int)clipNo;

/*
 * 获取存储在分片文件的大小
 * 返回值:
 * 大于0表示文件大小，小于等于0表示失败
 */
-(long long)TVHttpProxyGetClipFileSizeOnDisk:(NSString*)fileID withClipNo:(int)clipNo;

/*
 * 删除某个分片
 * 返回值:
 * 0表示成功，非0表示失败
 */
-(int)TVHttpProxyDeleteClipFileOnDisk:(NSString*)fileID withClipNo:(int)clipNo;

/*
 * 删除全部分片
 * 返回值:
 * 0表示成功，非0表示失败
 */
-(int)TVHttpProxyDeleteFileOnDisk:(NSString*)fileID;

/*
 * 方法: TVHttpProxySetHttpLowSpeedParams
 * 描述: 设置Http低速状态参数
 * 参数:
 * maxLowSpeedSeconds:低速持续时长，默认值8秒 （合理区间:3 ~ 30)
 * minSpeedFactorBaseBitRate:基于码率的最小速度因子（百分比），默认值20，即0.2倍 (合理区间:1~60)
 * 返回值:
 * 0表示成功，非0表示失败
 */
-(int)TVHttpProxySetHttpLowSpeedParams:(int)maxLowSpeedSeconds withMinSpeedFactorBaseBitRate:(int)minSpeedFactorBaseBitRate;

@end
