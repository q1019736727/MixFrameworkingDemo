//
//  TMSDKTypeDefine.h
//  TMShare
//
//  Created by rxk on 2019/9/27.
//  Copyright © 2019 Tianma. All rights reserved.
//

#ifndef TMSDKTypeDefine_h
#define TMSDKTypeDefine_h
#import "TMUser.h"
#import "TMShareSDKModel.h"

/**
 *  平台类型
 */
typedef NS_ENUM(NSUInteger, TMPlatformType)
{
    /**
     * QQ
     */
    TMPlatformTypeQQ      = 1,
    /**
     *  微信
     */
    TMPlatformTypeWechat    = 2,
    
    /**
     *  微博
     */
    TMPlatformTypeSina   = 3,
    /**
     *  QQ好友
     */
    TMPlatformSubTypeQQFriend         = 10,
    /**
     *  QQ空间
     */
    TMPlatformSubTypeQZone            = 11,
    /**
     *  微信好友
     */
    TMPlatformSubTypeWechatSession    = 20,
    /**
     *  微信朋友圈
     */
    TMPlatformSubTypeWechatTimeline   = 21,
    /**
     *  微信收藏
     */
    TMPlatformSubTypeWechatFav        = 22,
    /**
     *  复制
     */
    TMPlatformSubTypeCopy             = 30,
    /**
     *  投诉/举报
     */
    TMPlatformSubTypeReport             = 31,
    /**
     保存到相册
     */
    TMPlatformSubTypeSavePhoto             = 32,
    /**
     海报
     */
    TMPlatformSubTypePoster             = 33,
    /**
     *  任意
     */
    TMPlatformTypeNoKnow = 999
    
};

/**
 *  分享结果
 */
typedef NS_ENUM(NSUInteger, TMResultState){
    
    /**
     *  未知
     */
    TMResultStateNoKnow     = 0,
    
    /**
     *  成功
     */
    TMResultStateSuccess    = 1,
    
    /**
     *  失败
     */
    TMResultStateFail       = 2,
    
    /**
     *  取消
     */
    TMResultStateCancel     = 3,
};

/**
 *  授权状态变化回调处理器
 *
 *  @param state      状态
 *  @param user       授权用户信息，当且仅当state为TMResultStateSuccess时返回
 *  @param error      错误信息，当且仅当state为TMResultStateFail时返回
 */
typedef void(^TMShareSDKAuthorizeStateChangedHandler) (TMResultState state, TMUser *user, NSError *error);

/**
 *  分享内容状态变更回调处理器
 *
 *  @param state            状态
 *  @param shareModel    分享内容实体,当且仅当state为TMResultStateSuccess时返回
 *  @param error            错误信息,当且仅当state为TMResultStateFail时返回
 */
typedef void(^TMShareSDKShareStateChangedHandler) (TMResultState state, TMPlatformType platformType, TMShareSDKModel *shareModel,  NSError *error);

#endif /* TMSDKTypeDefine_h */
