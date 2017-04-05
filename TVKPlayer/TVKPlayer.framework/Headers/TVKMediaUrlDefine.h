//
//  TVKMediaUrlDefine.h
//  TVKMediaUrl
//
//  Created by chen selwin on 14-7-22.
//
//

#ifndef _TVK_MEDIA_URL_DEFINE_
#define _TVK_MEDIA_URL_DEFINE_

/**
 *  地址类型
 *
 *  TVKMediaUrlType_AUTO        自动，由后台决定
 *  TVKMediaUrlType_MP4         MP4地址
 *  TVKMediaUrlType_P2P         P2P地址（暂不支持）
 *  TVKMediaUrlType_HLS         HLS地址
 */
typedef enum
{
    TVKMediaUrlType_AUTO = 0,
    TVKMediaUrlType_MP4,
    TVKMediaUrlType_P2P,
    TVKMediaUrlType_HLS,
}
TVKMediaUrlType;

/**
 *  错误码定义
 *
 *  TVKErrorRequestDataError   数据请求出错（cgi有返回，但返回结果指明该请求出错或不合法）
 *  TVKErrorRequestNetFailed   数据请求发生网络错误
 *  TVKErrorIPLimit            ip限制
 *  TVKErrorTVUrlIsNotValid    TV直播url不合法
 *  TVKErrorVidIsNotValid      videoID错误
 *  TVKErrorUInfoIsNull        视频uinfo不合法
 */
typedef enum
{
    TVKErrorRequestDataError = 1,
    TVKErrorRequestNetFailed = 2,
    TVKErrorIPLimit = 3,
    TVKErrorTVUrlIsNotValid = 4,
    TVKErrorVidIsNotValid = 5,
    TVKErrorUInfoIsNull = 6,
}
TVKMediaUrlErrorCode;

#endif
