//
//  TVKMediaDefine.h
//  TVKUtility
//
//  Created by chen selwin on 14-11-4.
//  Copyright (c) 2014年 chen selwin. All rights reserved.
//

#ifndef TVKUtility_TVKMediaDefine_h
#define TVKUtility_TVKMediaDefine_h

/**
 *  流类型
 *
 *  TVKMediaType_AUTO        自动，wifi默认mp4，3g默认hls
 *  TVKMediaType_MP4         MP4地址
 *  TVKMediaType_P2P         P2P地址（暂不支持）
 *  TVKMediaType_HLS         HLS地址
 */
typedef enum
{
    TVKMediaType_AUTO,
    TVKMediaType_MP4,
    TVKMediaType_P2P,
    TVKMediaType_HLS,
}
TVKMediaType;

/**
 *  视频清晰度
 *
 *  TVKMediaFormatType_AUTO     自动，由后台决定返回的清晰度（分段MP4或HLS）
 *  TVKMediaFormatType_MSD      流畅（分段MP4或HLS）
 *  TVKMediaFormatType_SD       标清（分段MP4或HLS）
 *  TVKMediaFormatType_HD       高清（分段MP4或HLS）
 *  TVKMediaFormatType_SHD      超清（分段MP4或HLS）
 *  TVKMediaFormatType_FHD      全高清（分段MP4或HLS）
 *  TVKMediaFormatType_HDMP4    整段高清MP4
 *
 *  注:后台会根据platform进行限制，限制放开前只返回高清mp4，默认不放开
 */
typedef enum
{
    TVKMediaFormatType_AUTO = 0,
    TVKMediaFormatType_MSD,
    TVKMediaFormatType_SD,
    TVKMediaFormatType_HD,
    TVKMediaFormatType_SHD,
    TVKMediaFormatType_FHD,
    TVKMediaFormatType_HDMP4,
    TVKMediaFormatType_AUDIO,
}
TVKMediaFormatType;

/**
 *  播放器控制方式
 *  TVKMediaPlayerControlMode_Unknown 未知
 *  TVKMediaPlayerControlMode_Present 全屏弹出方式
 *  TVKMediaPlayerControlMode_Attach 附加在UIViewController上，支持小窗全屏切换
 */
typedef enum
{
    TVKMediaPlayerControlMode_Unknown,
    TVKMediaPlayerControlMode_Present,
    TVKMediaPlayerControlMode_Attach,
}
TVKMediaPlayerControlMode;

/**
 *  播放器功能配置
 *
 *  TVKMediaPlayerFunc_Advertisement 广告
 *  TVKMediaPlayerFunc_FlyScreen 飞幕
 *  TVKMediaPlayerFunc_Share 分享
 *  TVKMediaPlayerFunc_Favorite 关注
 *  TVKMediaPlayerFunc_Moment 影视圈
 *  TVKMediaPlayerFunc_Download 下载
 *  TVKMediaPlayerFunc_JumpNext 跳下一集
 *  TVKMediaPlayerFunc_ChooseFormat 选择清晰度
 *  TVKMediaPlayerFunc_Recomment 推荐列表
 *  TVKMediaPlayerFunc_MoreMenu 更多菜单
 *  TVKMediaPlayerFunc_SmallBackBtn 小窗显示回退按钮
 *  TVKMediaPlayerFunc_InteractiveVote 互动投票
 *  TVKMediaPlayerFunc_DLNA DLNA
 *  TVKMediaPlayerFunc_AirPlay airplay
 *  TVKMediaPlayerFunc_MainPlayerGes 全屏播放器支持手势
 *  TVKMediaPlayerFunc_SmallPlayerGes 小窗播放器支持手势
 *  TVKMediaPlayerFunc_Gesture 播放器支持手势
 *  TVKMediaPlayerFunc_ScreenShot 截屏
 *  TVKMediaPlayerFunc_FoldPlayer 显示收起播放窗口按钮
 *  TVKMediaPlayerFunc_LoadingTips 显示加载提示
 *  TVKMediaPlayerFunc_WWANAlertTips 3g观看时显示Alert提示，确认后不显示
 *  TVKMediaPlayerFunc_WWANPropmtTips 3g观看时显示弱提示
 *  TVKMediaPlayerFunc_WWANPropmtTipsWeak 3g观看时显示弱提示的弱模式，每次不暂停，都显示3G弱提示
 */
typedef enum
{
    TVKMediaPlayerFunc_Advertisement    =   0x00000001,
    TVKMediaPlayerFunc_FlyScreen        =   0x00000002,
    TVKMediaPlayerFunc_Share            =   0x00000004,
    TVKMediaPlayerFunc_Favorite         =   0x00000008,
    TVKMediaPlayerFunc_Moment           =   0x00000010,
    TVKMediaPlayerFunc_Download         =   0x00000020,
    TVKMediaPlayerFunc_JumpNext         =   0x00000040,
    TVKMediaPlayerFunc_ChooseFormat     =   0x00000080,
    TVKMediaPlayerFunc_Recomment        =   0x00000100,
    TVKMediaPlayerFunc_MoreMenu         =   0x00000200,
    TVKMediaPlayerFunc_InteractiveVote  =   0x00000400,
    TVKMediaPlayerFunc_DLNA             =   0x00000800,
    TVKMediaPlayerFunc_AirPlay          =   0x00001000,
    TVKMediaPlayerFunc_MainPlayerGes    =   0x00002000,
    TVKMediaPlayerFunc_SmallPlayerGes   =   0x00004000,
    TVKMediaPlayerFunc_Gesture          =   TVKMediaPlayerFunc_MainPlayerGes|TVKMediaPlayerFunc_SmallPlayerGes,
    TVKMediaPlayerFunc_ScreenShot       =   0x00008000,
    TVKMediaPlayerFunc_FoldPlayer       =   0x00010000,
    TVKMediaPlayerFunc_LoadingTips      =   0x00020000,
    TVKMediaPlayerFunc_WWANAlertTips    =   0x00040000,
    TVKMediaPlayerFunc_WWANPropmtTips   =   0x00080000,
    TVKMediaPlayerFunc_WWANTips         =   TVKMediaPlayerFunc_WWANAlertTips|TVKMediaPlayerFunc_WWANPropmtTips,
    TVKMediaPlayerFunc_WWANPropmtTipsWeak = 0x00100000,
}
TVKMediaPlayerFuncItem;

/**
 *  播放器状态
 *
 *  TVKMediaPlayerStateUnknown 初始状态
 *  TVKMediaPlayerStatePreparing 获取信息中
 *  TVKMediaPlayerStatePrepared 获取信息完毕
 *  TVKMediaPlayerStatePlayStarted 开始播放（包含缓冲）
 *  TVKMediaPlayerStateAdPlaying 广告播放中（包含缓冲和暂停等状态）
 *  TVKMediaPlayerStateAdInterrupt 广告播放中断
 *  TVKMediaPlayerStateAdEnd 广告播放完毕
 *  TVKMediaPlayerStatePlaying 正片播放中
 *  TVKMediaPlayerStateCaching 正片播放缓冲中（未播放状态）
 *  TVKMediaPlayerStateUserPaused 正片播放用户行为导致暂停
 *  TVKMediaPlayerStateSeeking 正片播放用户拖动进度
 *  TVKMediaPlayerStateInterrupt 正片播放中断
 *  TVKMediaPlayerStateEnd 正片播放完毕
 *  TVKMediaPlayerStateFailed 播放失败
 *  TVKMediaPlayerStateClosed 播放器关闭
 *  TVKMediaPlayerStateBackAdEnd 后贴片广告播放完毕
 */
typedef enum
{
    TVKMediaPlayerStateUnknown = 0,
    TVKMediaPlayerStatePreparing,
    TVKMediaPlayerStatePrepared,
    TVKMediaPlayerStatePlayStarted,
    TVKMediaPlayerStateAdPlaying,
    TVKMediaPlayerStateAdInterrupt,
    TVKMediaPlayerStateAdEnd,
    TVKMediaPlayerStatePlaying,
    TVKMediaPlayerStateCaching,
    TVKMediaPlayerStateUserPaused,
    TVKMediaPlayerStateSeeking,
    TVKMediaPlayerStateInterrupt,
    TVKMediaPlayerStateEnd,
    TVKMediaPlayerStateFailed,
    TVKMediaPlayerStateClosed,
    TVKMediaPlayerStateBackAdEnd,
}
TVKMediaPlayerState;

/**
 *  播放器事件
 *
 *  TVKMediaPlayerEventSkipAD 点击跳过广告
 *  TVKMediaPlayerEventChangeVideo 换集
 *  TVKMediaPlayerEventFreeLiveCutOff 试看直播流中断
 *  TVKMediaPlayerEventADLandingWillPresent 广告着陆页将打开
 *  TVKMediaPlayerEventAdLandingDidDismiss 广告着陆页已关闭
 *  TVKMediaPlayerEventPlayButtonClicked 用户点击播放按钮，userinfo key:“play” value:YES-播放 NO-暂停
 *  TVKMediaPlayerEventPlayerUIShow 播放器默认控制界面显示
 *  TVKMediaPlayerEventPlayerUIHide 播放器默认控制界面隐藏
 *  TVKMediaPlayerEventFolderButtonClicked 点击收起播放窗口按钮
 *  TVKMediaPlayerEventDLNAStateChanged DLNA状态变化，userinfo key:“active” value:YES-激活airplay NO-停止airplay
 *  TVKMediaPlayerEventAirPlayStateChanged airplay状态变化，userinfo key:“active” value:YES-激活airplay NO-停止airplay
 *  TVKMediaPlayerEventBanabaClicked 弹幕按钮点击，userinfo key:“open” value:YES-打开 NO-关闭
 *  TVKMediaPlayerEventBanabaCommentClicked 弹幕评论点击
 *  TVKMediaPlayerEventLiveVoteViewShow 直播互动显示
 *  TVKMediaPlayerEventWWANPlayCancelClicked 取消3g观看点击
 *  TVKMediaPlayerEventClickTryWatchEndButton 直播点击试看结束按钮
 *  TVKMediaPlayerEventAdViewFullscreenClicked 点击广告最大化按钮
 *  TVKMediaPlayerEventAdViewBackButtonClicked 全屏时点击广告返回按钮
 *  TVKMediaPlayerEventBackButtonClicked 全屏时点击返回小窗按钮
 *  TVKMediaPlayerEventDownloadButtonClicked 点击缓存按钮
 *  TVKMediaPlayerEventScreenShotButtonClicked 点击截屏按钮
 *  TVKMediaPlayerEventFavoriteButtonClicked 点击关注按钮，userinfo key:“isFavorite” value:YES-已关注 NO-未关注
 *  TVKMediaPlayerEventQQMusicSkipAD QQ音乐绿钻会员不播放广告
 *  TVKMediaPlayerEventRecommendDataLoadFailed 结束推荐信息获取失败
 *  TVKMediaPlayerEventNoPurchaseForPaidMedia 付费视频回调
 *  TVKMediaPlayerEventWillCaching 是否将显示缓冲提示，userinfo key:“show” value:0:隐藏  1：显示
 *  TVKMediaPlayerEventCaching 缓冲中，userinfo key:“speed” value:速度 kb/s
 *  TVKMediaPlayerEventReadyToPlayVideo 真正调用播放器开始播放视频
 *  TVKMediaPlayerEventGetBanabaInfo 获取到弹幕信息，userinfo key:“isBanabaAvailable” value:NSNumber numberWithBool:YES/NO, Key "targetID" 弹幕id
 *  TVKMediaPlayerEventHitBanabaWithoutLogin 弹幕点赞但未登陆
 *  TVKMediaPlayerEventShowRecommendPannel 显示结束推荐
 *  TVKMediaPlayerEventRecommendPannelWillPlayVideo 结束推荐点击将播放的vid key: "willPlayVid" value: vid
 *  TVKMediaPlayerEventGetFailedInfo 获取到视频失败信息 key:"model" 错误类型前缀  key "code" 错误码
 *  TVKMediaPlayerEventClickAdMuteBtn 点击广告静音按钮 key:"on" value:1/0
 */
typedef enum
{
    TVKMediaPlayerEventUnknown = 0,
    TVKMediaPlayerEventSkipAD,
    TVKMediaPlayerEventChangeVideo,
    TVKMediaPlayerEventFreeLiveCutOff,
    TVKMediaPlayerEventADLandingWillPresent,
    TVKMediaPlayerEventAdLandingDidDismiss,
    TVKMediaPlayerEventPlayButtonClicked,
    TVKMediaPlayerEventPlayerUIShow,
    TVKMediaPlayerEventPlayerUIHide,
    TVKMediaPlayerEventFolderButtonClicked,
    TVKMediaPlayerEventDLNAStateChanged,
    TVKMediaPlayerEventAirPlayStateChanged,
    TVKMediaPlayerEventBanabaClicked,
    TVKMediaPlayerEventBanabaCommentClicked,
    TVKMediaPlayerEventLiveVoteViewShow,
    TVKMediaPlayerEventWWANPlayCancelClicked,
    TVKMediaPlayerEventClickTryWatchEndButton,
    TVKMediaPlayerEventAdViewFullscreenClicked,
    TVKMediaPlayerEventAdViewBackButtonClicked,
    TVKMediaPlayerEventBackButtonClicked,
    TVKMediaPlayerEventDownloadButtonClicked,
    TVKMediaPlayerEventScreenShotButtonClicked,
    TVKMediaPlayerEventFavoriteButtonClicked,
    TVKMediaPlayerEventQQMusicSkipAD,
    TVKMediaPlayerEventRecommendDataLoadFailed,
    TVKMediaPlayerEventNoPurchaseForPaidMedia,
    TVKMediaPlayerEventWillCaching,
    TVKMediaPlayerEventCaching,
    TVKMediaPlayerEventReadyToPlayVideo,
    TVKMediaPlayerEventGetBanabaInfo,
    TVKMediaPlayerEventHitBanabaWithoutLogin,
    TVKMediaPlayerEventShowRecommendPannel,
    TVKMediaPlayerEventRecommendPannelWillPlayVideo,
    TVKMediaPlayerEventGetFailedInfo,
    TVKMediaPlayerEventClickAdMuteBtn,
}
TVKMediaPlayerEvent;

/**
 *  自定义窗口id范围
 *
 *  TVKMediaPlayerCustomLayerIDBegin 开始
 *  TVKMediaPlayerCustomLayerIDEnd  结束
 */
extern int const TVKMediaPlayerCustomLayerIDBegin;
extern int const TVKMediaPlayerCustomLayerIDEnd;

typedef NS_ENUM(NSUInteger, QLBanabaStatus) {
    
    QLBanabaStatus_Unknown,
    /*!
     启动timer，并开启动画，显示弹幕
     */
    QLBanabaStatus_Play,
    /*!
     停止timer，并关闭动画
     */
    QLBanabaStatus_Pause,
    /*!
     停止timer，将弹幕隐藏
     */
    QLBanabaStatus_Close,
    /*!
     尝试打开弹幕
     */
    QLBanabaStatus_TryPlay,
    /*!
     尝试暂停弹幕
     */
    QLBanabaStatus_TryPause,
    /*!
     准备，不做任何动作，但是调用了Preare，下一步需要调用TryOpen或Play
     */
    QLBanabaStatus_Prepare,
};

#endif
