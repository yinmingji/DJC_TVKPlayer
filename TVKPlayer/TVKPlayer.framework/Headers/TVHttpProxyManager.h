/*
 * Copyright (c) 2015
 * All rights reserved.
 *
 * 文件名称：TVHttpProxyManager.h
 * 摘    要：腾讯视频Http代理管理接口类
 *
 * 当前版本：1.0
 * 作    者：严华梁
 * 完成日期：2015年5月29日
 */

/*
 ServiceType == platform
 手Q：
 Android 940303
 IOS 1520403
 空间：
 Iphone  30403
 Android 30303
 */

#import <Foundation/Foundation.h>

/*上层需提供的函数实现*/
//日志函数
typedef void(*pfnTVHttpProxyLogFunc)(int level, const char *);

//上报函数， const char * 直接是JSON，可以直接MTA上报
typedef void(*pfnTVHttpProxyReportFunc)(const char *);

//其他上报函数，暂时可以传NULL
typedef void(*pfnTVHttpProxyIDKeyReportFunc)(const char *, const char*, const char*);
typedef void(*pfnTVHttpProxyKVReportFunc_New)(int32_t n, ...);

//回调函数：回调下载速度，进度，错误等信息
typedef void(*pfnTVHttpProxyCallBackFunc)(const char *);

//映射函数：关于请求视频URL返回的ContentType的映射转换:有些视频文件会返回Content-Type: application/octet-stream，这种ContentType iOS播放器会直接报错，加上映射函数，由上层负责映射
//对于不需要转换的情况，直接原样返回
typedef const char*(*pfnTVHttpProxyVideoContentTypeMap)(const char *);
/* end of 上层需提供的函数实现 */


@interface TVHttpProxyManager:NSObject

//获取实例，单例
+ (TVHttpProxyManager*)getInstance;

//初始化，需传入上述函数指针(上报以及回调）不能为NULL
/*
 * serviceType: 业务场景，对应腾讯视频分配的平台号
 * strDataDir: 存储根目录，可以为nil
 * reportFunc: 上报实现的函数指针，不能为NULL
 * callBackFunc: 回调的函数指针，不能为NULL
 
*/
- (int)initModule:(int)serviceType withStrDataDir:(NSString *)strDataDir withReportFunc:(pfnTVHttpProxyReportFunc)reportFunc withCallBackFunc:(pfnTVHttpProxyCallBackFunc)callBackFunc;

//析构
- (void)deinitModule:(int)serviceType;

/*
 * 方法: TVHttpProxyInit
 * 描述: 初始化下载组件
 * 参数:
 * serviceType: 业务场景，对应腾讯视频分配的平台号
 * strDataDir: 存储数据的路径
 
 * 返回: 成功返回0,失败返回非0
 */
- (int)TVHttpProxyInit:(int)serviceType :(NSString *)strDataDir;

/*
 * 方法: TVHttpProxyGetLocalServerPort
 * 描述: 获取下载组件本地代理端口
 * 参数:
 
 * 返回: 成功返回本地端口号,失败返回-1
 */
-(int)TVHttpProxyGetLocalServerPort;


/*
 * 方法: TVHttpProxyDeinit
 * 描述: 反初始化下载组件
 * 参数:
 * serviceType: 业务场景，对应腾讯视频分配的平台号
 */
- (void)TVHttpProxyDeinit:(int)serviceType;

/*
 * 方法: TVHttpProxyDeinit
 * 描述: 反初始化下载组件
 * 参数:
 
 * 返回: 下载组件版本号，形如 "TVHttpproxy.1.0.0.0002"
 */
- (NSString *)TVHttpProxyGetVersion;

/*
 * 方法: TVHttpProxyStartPlay
 * 描述: 开始播放
 * 参数: 
 * serviceType: 业务场景，对应腾讯视频分配的平台号
 * cdnUrls:视频文件的cdn url， 多个url直接用分号；隔开
 * fileType: 文件格式， 1:MP4, 2:HLS
 * fileID: 文件标识， vid + '.' +  formatID,  如y0018sf2mtx.100001, y0018sf2mtx.2
 * fileSize: 文件大小，单位:字节
 * fileDuration:文件大小，单位:秒
 
 * 返回: 成功返回大于0的playID,失败返回小于0的值，特别的，返回-8表示本地代理失效
 */
-(int)TVHttpProxyStartPlay:(int)serviceType :(NSString *)cdnUrls withFileType:(int)fileType withFileID:(NSString*)fileID withFileSize:(long long)fileSize withFileDuration:(int)fileDuration;

/*
 * 方法: TVHttpProxyPreLoad
 * 描述: 预加载
 * 参数:
 * serviceType: 业务场景，对应腾讯视频分配的平台号
 * playID:TVHttpProxyStartPlay方法返回的playID
 * duration:预加载秒数
 
 * 返回: 成功返回0，失败返回非0
 */
-(int)TVHttpProxyPreLoad:(int)serviceType :(int)playID withDuration:(int)duration;

/*
 * 方法: TVHttpProxyBuildPlayURLMP4
 * 描述: 构建本地代理URL
 * 参数:
 * playID:TVHttpProxyStartPlay方法返回的playID
 
 * 返回: 本地代理URL  形如 http://127.0.0.1:port/playmp4?data_id=xxxxx    
        port为TVHttpProxyGetLocalServerPort返回的端口号， xxxx为playID加密之后的字串
 */
-(NSString *)TVHttpProxyBuildPlayURLMP4:(int)playID;

/*
 * 方法: TVHttpProxySetRemainTime
 * 描述: 设置剩余播放时间
 * 参数:
 * serviceType: 业务场景，对应腾讯视频分配的平台号
 * playID:TVHttpProxyStartPlay方法返回的playID
 * remainTime:剩余播放时间(秒）
 */
-(void)TVHttpProxySetRemainTime:(int)serviceType :(int)playID withRemainTime:(int)remainTime;


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
 * serviceType: 业务场景，对应腾讯视频分配的平台号
 * playID:TVHttpProxyStartPlay方法返回的playID
 * state:参看TVHttpProxyStateEnum.h里面的状态定义
 */
-(void)TVHttpProxySetPlayerState:(int)serviceType :(int)playID withPlayerState:(int)state;



/*
 * 方法: TVHttpProxySetCookie
 * 描述: 设置Cookie
 * 参数:
 * serviceType: 业务场景，对应腾讯视频分配的平台号
 * cookie:字符串
 */
-(void)TVHttpProxySetCookie:(int)serviceType :(NSString *)cookie;



/*
 * 方法: TVHttpProxyStopPlay
 * 描述: 停止播放
 * 参数:
 * serviceType: 业务场景，对应腾讯视频分配的平台号
 * playID:TVHttpProxyStartPlay方法返回的playID
 */

-(void)TVHttpProxyStopPlay:(int)serviceType :(int)playID;


/*
 * 方法: TVHttpProxyHandlerMemoryWarning
 * 描述: 处理内存告警
 * 参数:
 */

-(void)TVHttpProxyHandlerMemoryWarning;


/**
 * 功能: 开始播放一个视频
 * 参数
 * @serviceType: 业务场景，对应腾讯视频分配的平台号
 * @fileType: 视频文件类型，1为MP4，2为hls
 * @fileID:   视频的keyID，如"s0016ql3rz9.10203.1"，从vinfo里可以获取
 * @isSaveDisk: 是否启用存储
 * @playFlag：播放任务属性，保留字段，暂时不启用，统一传0
 *
 * 返回值: 如果任务创建成功，则返回全局唯一的播放任务ID，后续将使用这个ID来通知下载组件视频的播放状态；失败返回小于0的值，特别的，返回-8表示本地代理失效
 */
-(int)TVHttpProxyStartPlay:(int)serviceType :(int)fileType withFileID:(NSString*)fileID  withIsSaveDisk:(bool)isSaveDisk withPlayFlag:(int)playFlag;


/**
 * 功能: 开始预加载一个视频
 * 参数
 * @serviceType: 业务场景，对应腾讯视频分配的平台号
 * @fileType: 视频文件类型，1为MP4，2为hls
 * @fileID:   视频的keyID，如"s0016ql3rz9.10203.1"，从vinfo里可以获取
 * @isSaveDisk: 是否启用存储
 * @preLoadFlag: 预加载的标识，用来区别预加载任务的属性，会影响预加载任务的调度，暂时不启用，统一传0
 *
 * 返回值: 如果任务创建成功，则返回全局唯一的预下载任务ID，后续将使用这个ID来通知下载组件视频的播放状态；否则返回-1，可以调用dmGetLastError获取错误码
 */
-(int)TVHttpProxyStartPreLoad:(int)serviceType :(int)fileType withFileID:(NSString*)fileID  withIsSaveDisk:(bool)isSaveDisk withPreLoadFlag:(int)preLoadFlag;


/**
 * 功能: 设置分片的信息
 * 参数
 * @playDataID: 任务ID，由startPlay或者startPreLoad返回
 * @clipNo:     分片号,对于整段，分片号为1
 * @cdnURLs:  完整的播放地址，多个url以”;“分隔
 * @fileSize: 视频文件的大小，从vinfo里可以获取，如果vinfo里没有文件大小，则传0
 * @duration: 视频的时长，以秒为单位，从vinfo里可以获取，如果vinfo里没有视频时长，则传0
 * 返回值: 0表示成功，非0表示失败
 */
-(int)TVHttpProxySetClipInfo:(int)playDataID withClipNo:(int)clipNo withCDNURLs:(NSString*)cdnURLs withFileSize:(long long)fileSize withFileDuration:(int)fileDuration;

/**
 * 功能: 设置分片的信息
 * @playDataID: 任务ID，由startPlay或者startPreLoad返回
 * @clipNo:     分片号,对于整段，分片号为1
 * @cdnURLs:  完整的播放地址，多个url以”;“分隔
 * @fileSize: 视频文件的大小，从vinfo里可以获取，如果vinfo里没有文件大小，则传0
 * @duration: 视频的时长，以秒为单位，从vinfo里可以获取，如果vinfo里没有视频时长，则传0
 * @savepath: 外部可以设置存储路径（绝对路径），如果设置自定义存储路径，SDK将不再负责存储淘汰和存储空间检查，可以为nil
 * @storagePercent:存储百分比，业务可以自定义存储完整的文件的百分比，如30%，则传30， 如果需要完整缓存文件，需要传递100
 * 返回值: 0表示成功，非0表示失败
 */
-(int)TVHttpProxySetClipInfo:(int)playDataID withClipNo:(int)clipNo withCDNURLs:(NSString*)cdnURLs withFileSize:(long long)fileSize withFileDuration:(int)fileDuration withSavePath:(NSString*)savePath withStoragePercent:(int)storagePercent;


/**
 * 根据playDataID和分片号获取本地代理的播放地址
 *
 * @playDataID: 任务ID，由startPlay返回
 * @clipNo:分片号
 *
 * 返回值:
 * 本地代理URL  形如 http://127.0.0.1:port/playmp4?data_id=xxxxx&clip_id=xxx
 * port为TVHttpProxyGetLocalServerPort返回的端口号， xxxx为playID加密之后的字串, clip_id=xxx 为明文分片号
 */
-(NSString *)TVHttpProxyBuildClipPlayURL:(int)playID withClipNo:(int)clipNo;

/**
 * 根据playDataID和分片号开启对应分片的预下载
 
 * 参数
 * @serviceType: 业务场景，对应腾讯视频分配的平台号
 * @playDataID: 任务ID，由startPlay或者startPreLoad返回
 * @clipNo:分片号
 * @duration：预加载时长，-1表示不限制
 * @isSaveDisk: 是否启用存储
 * @preLoadFlag: 预加载的标识，用来区别预加载任务的属性，会影响预加载任务的调度，保留字段，暂时不启用，统一传0
 * 返回值:
 * 0表示成功，非0表示失败
 */
-(int)TVHttpProxyPreLoadClip:(int)serviceType :(int)playDataID withClipNo:(int)clipNo withDuration:(int)duration withIsSaveDisk:(bool)isSaveDisk withPreLoadFlag:(int)preLoadFlag;


/*
 * 停止预加载
 * @playDataID: startPreLoad返回全局唯一的任务ID
 * 返回值:
 * 0表示成功，非0表示失败
 */
-(int)TVHttpProxyStopPreLoad:(int)playDataID;

/*
 * 暂停所有预下载
 * 返回值:
 * 参数
 * @serviceType: 业务场景，对应腾讯视频分配的平台号
 * 0表示成功，非0表示失败
 */
-(int)TVHttpProxyPauseAllPreLoad : (int)serviceType;

/*
 * 恢复所有预下载
 * 参数
 * @serviceType: 业务场景，对应腾讯视频分配的平台号
 * 返回值:
 * 0表示成功，非0表示失败
 */
-(int)TVHttpProxyResumeAllPreLoad : (int)serviceType;

/*
 * 停止所有预下载
 * 参数
 * @serviceType: 业务场景，对应腾讯视频分配的平台号
 * 返回值:
 * 0表示成功，非0表示失败
 */
-(int)TVHttpProxyStopAllPreLoad : (int)serviceType;


/*
 * 设置最大内存大小
 * 参数
 * @serviceType: 业务场景，对应腾讯视频分配的平台号
 * @maxSize_Byte:最大内存大小，单位:字节
 * 返回值:
 * 0表示成功，非0表示失败
 */
-(int)TVHttpProxySetMaxMemorySize : (int)serviceType :(long long)maxSize_Byte;


/*
 * 清理内存
 * 参数
 * @serviceType: 业务场景，对应腾讯视频分配的平台号
 * 返回值:
 * 0表示成功，非0表示失败  
 */
-(int)TVHttpProxyCleanMemory : (int)serviceType;



/*
 * 设置最大存储大小
 * 参数
 * @serviceType: 业务场景，对应腾讯视频分配的平台号
 * @maxSize_Byte:最大存储大小，单位:字节
 * 返回值:
 * 0表示成功，非0表示失败
 */
-(int)TVHttpProxySetMaxStorageSize : (int)serviceType :(long long)maxSize_Byte;



/*
 * 清理存储
 * 参数
 * @serviceType: 业务场景，对应腾讯视频分配的平台号
 * 返回值:
 * 0表示成功，非0表示失败
 */
-(int)TVHttpProxyCleanStorage : (int)serviceType;


/*
 * 暂停存储IO，不再进行文件读写
 * 参数
 * @serviceType: 业务场景，对应腾讯视频分配的平台号
 * 返回值:
 * 0表示成功，非0表示失败
 */
-(int)TVHttpProxyPauseStorageIO : (int)serviceType;


/*
 * 恢复存储IO
 * 参数
 * @serviceType: 业务场景，对应腾讯视频分配的平台号
 * 返回值:
 * 0表示成功，非0表示失败
 */
-(int)TVHttpProxyResumeStorageIO : (int)serviceType;

/*
 * 判断分片文件是否在存储中下载完成
 * 参数
 * @serviceType: 业务场景，对应腾讯视频分配的平台号
 * @fileID: 视频的FileID
 * @clipNo: 分片号
 * 返回值:
 * true表示完成，false表示未完成
 */
-(bool)TVHttpProxyIsClipCompleteOnDisk : (int)serviceType :(NSString*)fileID withClipNo:(int)clipNo;

/*
 * 获取存储在分片文件的大小
 * 参数
 * @serviceType: 业务场景，对应腾讯视频分配的平台号
 * @fileID: 视频的FileID
 * @clipNo: 分片号
 * 返回值:
 * 大于0表示文件大小，小于等于0表示失败
 */
-(long long)TVHttpProxyGetClipFileSizeOnDisk : (int)serviceType :(NSString*)fileID withClipNo:(int)clipNo;


/*
 * 方法: TVHttpProxyGetClipFilePathOnDisk
 * 描述: 获取存储中分片文件的完整路径
 * 参数
 * @serviceType: 业务场景，对应腾讯视频分配的平台号
 * @fileID: 视频的FileID
 * @clipNo: 分片号
 * 返回值:
 * 完整路径，如果失败返回nil
 */
-(NSString *)TVHttpProxyGetClipFilePathOnDisk:(int)serviceType :(NSString*)fileID withClipNo:(int)clipNo;


/*
 * 删除某个分片
 * 参数
 * @serviceType: 业务场景，对应腾讯视频分配的平台号
 * @fileID: 视频的FileID
 * @clipNo: 分片号
 * 返回值:
 * 0表示成功，非0表示失败
 */
-(int)TVHttpProxyDeleteClipFileOnDisk : (int)serviceType :(NSString*)fileID withClipNo:(int)clipNo;

/*
 * 删除全部分片
 * 参数:
 * @serviceType: 业务场景，对应腾讯视频分配的平台号
 * @fileID: 视频的FileID
 * 返回值:
 * 0表示成功，非0表示失败
 */
-(int)TVHttpProxyDeleteFileOnDisk : (int)serviceType :(NSString*)fileID;


/*
 * 方法: TVHttpProxyStartPlayWithSavePath
 * 描述: 开始播放(指定存储路径)
 * 参数:
 * @serviceType: 业务场景，对应腾讯视频分配的平台号
 * cdnUrls:视频文件的cdn url， 多个url直接用分号；隔开
 * fileID: 文件标识,业务层需要保证唯一并且可重用
 * fileSize: 文件大小，单位:字节
 * fileDuration:文件大小，单位:秒
 * savePath:存储路径，绝对路径
 * downloadControlFlag:下载控制(流控)标识，方便后续扩展，默认传0表示不启用流控
 * 返回: 成功返回大于0的Play ID, 后续停止使用该ID调用StopPlay,失败返回-1
 */
-(int)TVHttpProxyStartPlayWithSavePath : (int)serviceType :(NSString *)cdnUrls withFileID:(NSString*)fileID withFileSize:(long long)fileSize withFileDuration:(int)fileDuration withSavePath:(NSString*)savePath withDownloadContorlFlag:(int)downloadControlFlag;



/*
 * 方法: TVHttpProxyStartPreLoadWithSavePath
 * 描述: 开始预下载(指定存储路径)
 * 参数:
 * @serviceType: 业务场景，对应腾讯视频分配的平台号
 * cdnUrls:视频文件的cdn url， 多个url直接用分号；隔开
 * fileID: 文件标识,业务层需要保证唯一并且可重用
 * fileSize: 文件大小，单位:字节
 * fileDuration:文件大小，单位:秒
 * savePath:存储路径，绝对路径
 * downloadControlFlag:下载控制(流控)标识，方便后续扩展，默认传0表示不启用流控
 * 返回: 成功返回大于0的PreLoad ID, 后续停止使用该ID调用StopPreLoad,失败返回-1
 */
-(int)TVHttpProxyStartPreLoadWithSavePath : (int)serviceType :(NSString *)cdnUrls withFileID:(NSString*)fileID withFileSize:(long long)fileSize withFileDuration:(int)fileDuration withSavePath:(NSString*)savePath withDownloadContorlFlag:(int)downloadControlFlag;


/*
 * 方法: TVHttpProxyStartPreLoadWithSavePathAndDurtaion
 * 描述: 开始预下载(指定存储路径)
 * 参数:
 * @serviceType: 业务场景，对应腾讯视频分配的平台号
 * cdnUrls:视频文件的cdn url， 多个url直接用分号；隔开
 * fileID: 文件标识,业务层需要保证唯一并且可重用
 * fileSize: 文件大小，单位:字节
 * fileDuration:文件大小，单位:秒
 * savePath:存储路径，绝对路径
 * downloadControlFlag:下载控制(流控)标识，方便后续扩展，默认传0表示不启用流控
 * preLoadDuration:预下载秒数
 * 返回: 成功返回大于0的PreLoad ID, 后续停止使用该ID调用StopPreLoad,失败返回-1
 */
-(int)TVHttpProxyStartPreLoadWithSavePathAndDurtaion : (int)serviceType :(NSString *)cdnUrls withFileID:(NSString*)fileID withFileSize:(long long)fileSize withFileDuration:(int)fileDuration withSavePath:(NSString*)savePath withDownloadContorlFlag:(int)downloadControlFlag withPreLoadDuration:(int)preLoadDuration;

/*
 * 方法: TVHttpProxySetHttpLowSpeedParams
 * 描述: 设置Http低速状态参数
 * 参数:
 * @serviceType: 业务场景，对应腾讯视频分配的平台号
 * maxLowSpeedSeconds:低速持续时长，默认值8秒 （合理区间:3 ~ 30)
 * minSpeedFactorBaseBitRate:基于码率的最小速度因子（百分比），默认值20，即0.2倍 (合理区间:1~60)
 * 返回值:
 * 0表示成功，非0表示失败
 */
-(int)TVHttpProxySetHttpLowSpeedParams : (int)serviceType :(int)maxLowSpeedSeconds withMinSpeedFactorBaseBitRate:(int)minSpeedFactorBaseBitRate;

/* 
 * 设置日志输出回调接口
 */
- (void)TVHttpProxySetLogFunc : (pfnTVHttpProxyLogFunc)logFunc;

/*
 * 设置ContentType映射函数
 */
- (void)TVHttpProxySetContentTypeMapFunc : (pfnTVHttpProxyVideoContentTypeMap)contentTypeMapFunc;


/*
 * 挂起下载组件
 */
- (int)TVHttpProxySuspend;

/*
 * 恢复下载组件
 */
- (int)TVHttpProxyResume;

/*
 * 重启下载组件
 */
- (int)TVHttpProxyRestart;

@end
