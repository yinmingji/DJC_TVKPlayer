//
//  TVKSDKManager.h
//  TVKUtility
//
//  Created by chen selwin on 14-7-16.
//  Copyright (c) 2014年 chen selwin. All rights reserved.
//

#import <Foundation/Foundation.h>

/**
 *  认证状态
 */
typedef enum
{
    TVKAUTH_STATUS_UNKNOWN = 0,            //未认证
    TVKAUTH_STATUS_VALID,                  //认证有效
    TVKAUTH_STATUS_INVALID_DECRYPT_EXCEPTION,
    TVKAUTH_STATUS_INVALID_DECRYPT_FAILED,
    TVKAUTH_STATUS_INVALID_MISSING_VER,
	TVKAUTH_STATUS_INVALID_VER_MISMATCH,
	TVKAUTH_STATUS_INVALID_BUNDLE_ID_MISMATCH,
	TVKAUTH_STATUS_INVALID_CERT_MISMATCH,
	TVKAUTH_STATUS_INVALID_PLATFORM_EMPTY,
	TVKAUTH_STATUS_INVALID_SDTFROM_EMPTY,
	TVKAUTH_STATUS_INVALID_CHANNELID_EMPTY,
}
TVKAuthStatus;

/**
 *  SDK管理类，用户获取和设置SDK的一些公共参数
 */
@interface TVKSDKManager : NSObject

/**
 *  获取SDK版本号
 */
@property(nonatomic,readonly) NSString* version;

/**
 *  获取和设置SDK分配的产品平台标识
 */
@property(nonatomic,strong) NSString* productPlatform;

/**
 *  获取和设置SDK分配的用于后台统计的产品平台标识
 */
@property(nonatomic,strong) NSString* productSdtfrom;

/**
 *  获取和设置SDK分配的用于地址校验的私钥
 */
@property(nonatomic,strong) NSString* productPrivateKey;

/**
 *  获取SDK的鉴权渠道号
 */
@property(nonatomic,assign) int productChannelID;

/**
 *  获取产品传入用于SDK的鉴权的AppKey
 */
@property(nonatomic,readonly) NSString* productAppKey;

/**
 *  设置网络请求时的cookie
 */
@property(nonatomic,strong) NSString* cookieForRequest;

/**
 *  设置广告请求时的cookie，包含微信会员，设备会员等信息
 */
@property(nonatomic,strong) NSArray* cookieForAD;

/**
 *  设置CGI请求的UA
 */
@property(nonatomic,strong) NSString* uaForRequest;

/**
 *  设置用户QQ号码
 */
@property(nonatomic,strong) NSString* loginQQ;

/**
 *  QQ登录后的appID
 */
@property(nonatomic,strong) NSString* loginQQAPPID;

/**
 *  QQ登录后的票据SKEY
 */
@property(nonatomic,strong) NSData* loginQQSKEY;

/**
 *  QQ登录后的票据LSKEY
 */
@property(nonatomic,strong) NSData* loginQQLSKEY;

/**
 *  QQ登录后的票据ST
 */
@property(nonatomic,strong) NSData* loginQQST;

/**
 *  是否是VIP用户，vip用户无广告
 */
@property(nonatomic,assign) BOOL isVipUser;

/**
 *  鉴权状态，必须为TVKAUTH_STATUS_VALID SDK才能工作
 */
@property(nonatomic,readonly) TVKAuthStatus authStatus;

/**
 *  guid，cgi请求会带上，若不填写则sdk会使用自己生成的guid
 */
@property(nonatomic,strong) NSString* guid;

/**
 *  获取SDK的拉起渠道id
 */
@property(nonatomic,assign) int sdkConfID;

/**
 *微信openId
 */
@property(nonatomic,strong) NSString* wxOpenId;

/**
 *微信accessToken
 */
@property(nonatomic,strong) NSString* wxAccessToken;

/**
 *微信appID
 */
@property(nonatomic,strong) NSString* wxAppId;

/**
 *  用户名 发弹幕时用到
 */
@property(nonatomic, copy) NSString *nickName;

/**
 *  头像 发弹幕时用到
 */
@property(nonatomic, copy) NSString *headUrl;

/**
 *直播打点上报额外信息
 */
@property(nonatomic,strong) NSString* extraReportInfo;

/**
 *设置弹幕行数
 */
@property(nonatomic,assign) NSUInteger banabaChannelCount;

/**
 *  设置播放器present依据的viewController
 *
 */
@property(nonatomic,weak) UIViewController* presentViewController;

/**
 * 额外上报信息
 */
@property(atomic,copy) NSDictionary* exReportDic;

/**
 * 是否打开艾瑞统计
 */
@property(nonatomic,assign) BOOL enableIRTracker;

/**
 * 是否打开IPV6兼容模式
 */
@property(nonatomic,assign) BOOL enableIPV6Mode;

/**
 *  获得单例
 *
 *  @return 管理类单例
 */
+ (TVKSDKManager*)sharedInstance;

/**
 *  初始化SDK
 *
 *  @param appKey 产品申请单AppKey，用户鉴权，需在其他方法前调用
 *
 *  @return 鉴权成功返回yes，否则为no
 */
- (BOOL)registerWithAppKey:(NSString*)appKey;

@property(nonatomic, copy) NSString* imageCachePath;
//清除图片缓存
- (void)removeAllCache:(BOOL)fromDisk;
//获取图片缓冲文件缓存大小
- (long long)getFileCacheSize;

- (void)setInitProxyForServiceType:(int)serviceType Init:(BOOL)init;

- (BOOL)isInitProxyForServiceType:(int)serviceType;


@end
