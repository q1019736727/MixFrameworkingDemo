//
//  TMPersonalCenterNetworking.h
//  SetI001
//
//  Created by rxk on 2019/12/11.
//  Copyright © 2019 Tianma. All rights reserved.
//

#import <Foundation/Foundation.h>



@class TMBaseNetworking;

NS_ASSUME_NONNULL_BEGIN



/**
 个人中心相关网络请求
 但网络请求失败时，如果错误码为500 ~ 550 表示token有误
 */
@interface TMPersonalCenterNetworking : NSObject

/// 获取当前用户的token，当未登录时，会返回nil
+ (NSString *)tm_token;

/// 退出当前用户，并同步发出 SetI001_Notification_Logout 通知
+ (void)tm_logOut;


/// 手机号或密码登录
/// @param phoneNumber 手机号
/// @param content 验证码/密码（ 如果是验证码登录则传入验证码，如果是密码登录则传入密码）
/// @param state 登录方式
/// @param success 登录成功回调
/// @param failed 登录失败回调
+ (void)tm_loginWithNumber:(NSString *)phoneNumber
               content:(NSString *)content
                  state:(NSInteger)state
                success:(TMHttpSuccess)success
                 failed:(TMHttpFailed)failed;


/// 三方登录
/// @param userID 从三方获取的uid
/// @param openID 从三方获取的openID
/// @param thirdType 三方类型，1：QQ  2：微信  3：微博
/// @param nickName 用户昵称
/// @param icon 用户头像
/// @param birthday 用户生日
/// @param sex 用户性别， 1：男，2：女，0：未知
/// @param address 从三方获取到的用户位置信息
/// @param mobile 手机号
/// @param code 密码
/// @param success 成功回调
/// @param failed 失败回调
+ (TMBaseNetworking *)tm_thirdLoginWithUserID:(NSString *)userID
                                    openID:(nullable NSString *)openID
                                 thirdType:(NSInteger)thirdType
                                  nickName:(NSString *)nickName
                                      icon:(NSString *)icon
                                  birthday:(nullable NSString *)birthday
                                       sex:(NSInteger)sex
                                   address:(nullable NSString *)address
                                    mobile:(nullable NSString *)mobile
                                      code:(nullable NSString *)code
                                   success:(TMHttpSuccess)success
                                    failed:(TMHttpFailed)failed;

/// 绑定三方信息
/// @param userID 从三方获取的uid
/// @param openID 从三方获取的openID
/// @param thirdType 三方类型，1：QQ  2：微信  3：微博
/// @param nickName 用户昵称
/// @param icon 用户头像
/// @param birthday 用户生日
/// @param sex 用户性别， 1：男，2：女，0：未知
/// @param address 从三方获取到的用户位置信息
/// @param success 成功回调
/// @param failed 失败回调
+ (void)tm_thirdBindingWithUserID:(NSString *)userID
                        openID:(nullable NSString *)openID
                     thirdType:(NSInteger)thirdType
                      nickName:(NSString *)nickName
                          icon:(NSString *)icon
                      birthday:(nullable NSString *)birthday
                           sex:(NSInteger)sex
                       address:(nullable NSString *)address
                       success:(TMHttpSuccess)success
                        failed:(TMHttpFailed)failed;

/// 三方登录后如果发现未登录，需要调用该接口绑定登录手机号
/// @param phoneNumber 手机号
/// @param smsCode 验证码
/// @param success 成功回调
/// @param failed 失败回调
+ (void)tm_bindingLoginPhoneNumberWithPhoneNumber:(NSString *)phoneNumber
                                       smsCode:(NSString *)smsCode
                                       success:(TMHttpSuccess)success
                                        failed:(TMHttpFailed)failed;
/**
 取消绑定三方账号

 @param type 类型：1qq 2微信 3微博
 @param success 成功回调
 @param failed 失败回调
 */
+ (void)tm_thirdCancelBindingWithType:(NSInteger)type
                              success:(TMHttpSuccess)success
                               failed:(TMHttpFailed)failed;

/// 获取消息列表
/// @param index 页码索引，从1开始
/// @param pageCount 每页数据大小
/// @param success 成功回调
/// @param failed 失败回调
+ (void)tm_getMessageListWithIndex:(NSInteger )index
                       pageCount:(NSInteger)pageCount
                        success:(TMHttpSuccess)success
                         failed:(TMHttpFailed)failed;


/// 获取收藏列表
/// @param index 页码索引，从1开始
/// @param size 每页数据大小
/// @param type 收藏类型，1：文章，2：视频
/// @param success 成功回调
/// @param failed 失败回调
+ (void)tm_getCollectListWithIndex:(NSInteger )index
                               size:(NSInteger)size
                               type:(NSInteger)type
                            success:(TMHttpSuccess)success
                             failed:(TMHttpFailed)failed;




/// 清空收藏列表
/// @param type 收藏类型，1：文章，2：视频
/// @param success 成功回调
/// @param failed 失败回调
+ (void)tm_clearCollectionWithType:(NSInteger)type
                           success:(TMHttpSuccess)success
                            failed:(TMHttpFailed)failed;




/**
 下面extend字段需要传入下列格式的json字符串：
 {
     "iosInfo": {
         "native": true,// 跳转界面是否为原生界面
         "src": "HViewController",// 跳转以展示的页面，若是h5页面，直接给出链接，若是原生界面，给出继承TMViewController类的控制器类名
         "paramStr": "",// 所需参数，会传入TMViewController的paramStr字段,在使用时，可以通过‘- (NSDictionary *)paramDict;’方法获取到传入的参数
         "wwwFolder": ""// 若为html组件，对应APP本地html路径
     },
     "androidInfo": {
         "native": false,
         "src": "index.html",
         "paramStr": "21e364890c730daff9e413660e04d924",
         "wwwFolder": "pages/comp01/"
     }
 }
 
 */
/// 添加收藏记录
/// @param appID 组件ID
/// @param title 标题
/// @param articleID 文章ID
/// @param intro 文章简介
/// @param type 类型 1 文章 2视频
/// @param pic 简介图
/// @param extend 扩展
/// @param success 成功回调
/// @param failed 失败回调
+ (void)tm_addCollectWithAppID:(NSString *)appID
                         title:(NSString *)title
                     articleID:(NSString *)articleID
                         intro:(NSString *)intro
                          type:(int)type
                           pic:(nullable NSString *)pic
                        extend:(NSString *)extend
                       success:(TMHttpSuccess)success
                        failed:(TMHttpFailed)failed;


/// 取消收藏
/// @param starId 收藏ID
/// @param success 成功回调
/// @param failed 失败回调
+ (void)tm_cancelCollectWithStarId:(NSString *)starId
                        success:(TMHttpSuccess)success
                         failed:(TMHttpFailed)failed;

/// 检测是否收藏
/// @param appID appID
/// @param articleID 文章ID
/// @param success 成功回调，如果收藏成功，会返回收藏ID
/// @param failed 失败回调
+ (void)tm_checkCollectStatusWithAppID:(NSString *)appID
                             articleID:(NSString *)articleID
                               success:(TMHttpSuccess)success
                                failed:(TMHttpFailed)failed;


/// 获取历史记录列表
/// @param index 页码索引，从1开始
/// @param size 每页展示数量
/// @param getTimeList 刷新传1，加载更多传0
/// @param success 成功回调
/// @param failed 失败回调
+ (void)tm_getHistoryListWithIndex:(NSInteger )index
                               size:(NSInteger)size
                        getTimeList:(NSInteger)getTimeList
                                  success:(TMHttpSuccess)success
                                   failed:(TMHttpFailed)failed;

/*添加历史记录
 member_code      string      必填      用户code
 title              string      必填      文章标题
 app_id           string      必填      开发者创建应用时填的唯一id
 article_id       int         必填      文章id
 */
+ (void)tm_addHistoryWithParm:(NSDictionary *)parmDic
                   success:(TMHttpSuccess)success
                    failed:(TMHttpFailed)failed;

/**
 下面extend字段需要传入下列格式的json字符串：
 {
     "iosInfo": {
         "native": true,// 跳转界面是否为原生界面
         "src": "HViewController",// 跳转以展示的页面，若是h5页面，直接给出链接，若是原生界面，给出继承TMViewController类的控制器类名
         "paramStr": "",// 所需参数，会传入TMViewController的paramStr字段,在使用时，可以通过‘- (NSDictionary *)paramDict;’方法获取到传入的参数
         "wwwFolder": ""// 若为html组件，对应APP本地html路径
     },
     "androidInfo": {
         "native": false,
         "src": "index.html",
         "paramStr": "21e364890c730daff9e413660e04d924",
         "wwwFolder": "pages/comp01/"
     }
 }
 
 */
/// 添加历史记录
/// @param appID 组件ID
/// @param title 标题
/// @param articleID 文章ID
/// @param intro 文章简介
/// @param type 类型 1 文章 2视频
/// @param pic 简介图
/// @param extend 扩展
/// @param success 成功回调
/// @param failed 失败回调
+ (void)tm_addHistoryWithAppID:(NSString *)appID
                         title:(NSString *)title
                     articleID:(NSString *)articleID
                         intro:(NSString *)intro
                          type:(int)type
                           pic:(nullable NSString *)pic
                        extend:(NSString *)extend
                       success:(TMHttpSuccess)success
                        failed:(TMHttpFailed)failed;




/// 历史记录
/// @param footprintId 记录ID，若同时删除多个历史记录，则用英文逗号将ID隔开
/// @param success 成功回调
/// @param failed 失败回调
+ (void)tm_deleteHistoryWithFootprintId:(NSString *)footprintId
                                success:(TMHttpSuccess)success
                                 failed:(TMHttpFailed)failed;

/// 清空历史记录
/// @param success 成功回调
/// @param failed 失败回调
+ (void)tm_clearHistoryWithSuccess:(TMHttpSuccess)success
                         failed:(TMHttpFailed)failed;



/// 发送验证码
/// @param phoneNumber 手机号
/// @param state 验证码类型：1: 登录 2: 密码找回 3: 修改密码 4: 原手机号验证 5: 新手机号验证
/// @param success 成功回调
/// @param failed 失败回调
+ (void)tm_sendSMSCheck:(NSString *)phoneNumber
               state:(int)state
             success:(TMHttpSuccess)success
              failed:(TMHttpFailed)failed;

/**
 获取校验码
 */
+ (void)tm_getCodeWithSuccess:(TMHttpSuccess)success
                       failed:(TMHttpFailed)failed;

/// 修改用户信息
/// @param nickName 用户昵称
/// @param birthday 生日
/// @param sex 性别 1 男 2 女
/// @param password 密码
/// @param mobile 手机号
/// @param channelSources 邀请码
/// @param success 成功回调
/// @param failed 失败回调
+ (void)tm_updateUserInfoWithNickName:(nullable NSString *)nickName
                             birthday:(nullable NSString *)birthday
                                  sex:(int)sex
                             password:(nullable NSString *)password
                               mobile:(nullable NSString *)mobile
                       channelSources:(nullable NSString *)channelSources
                              success:(TMHttpSuccess)success
                               failed:(TMHttpFailed)failed;

/// 修改用户头像
/// @param picBase64 将头像转成base64
/// @param success 成功回调
/// @param failed 失败回调
+ (void)tm_updateUserHeadPic:(NSString *)picBase64
                  success:(TMHttpSuccess)success
                   failed:(TMHttpFailed)failed;


/// 验证短信验证码
/// @param code 验证码
/// @param phoneNumber 手机号
/// @param success 成功回调
/// @param failed 失败回调
+ (void)tm_checkSMSCode:(NSString *)code
              mobile:(NSString *)phoneNumber
             success:(TMHttpSuccess)success
              failed:(TMHttpFailed)failed;


/// 修改密码
/// @param password 新密码
/// @param mobile 手机号
/// @param smsCode 验证码
/// @param success 成功回调
/// @param failed 失败回调
+ (void)tm_updatePassword:(NSString *)password
                mobile:(NSString *)mobile
               smsCode:(NSString *)smsCode
               success:(TMHttpSuccess)success
                failed:(TMHttpFailed)failed;

/// 获取用户信息
/// @param success 成功回调
/// @param failed 失败回调
+ (void)tm_getUserInfoWithSuccess:(TMHttpSuccess _Nullable)success
                        failed:(TMHttpFailed _Nullable)failed;

/// 获取免责声明
/// @param success 成功回调
/// @param failed 失败回调
+ (void)tm_getReliefArticleWithSuccess:(TMHttpSuccess)success
                                failed:(TMHttpFailed)failed;

/// 获取隐私协议
/// @param success 成功回调
/// @param failed 失败回调
+ (void)tm_getPrivacyArticleWithSuccess:(TMHttpSuccess)success
                                 failed:(TMHttpFailed)failed;

/// 关于我们
/// @param success 成功回调
/// @param failed 失败回调
+ (void)tm_getAboutUSWithSuccess:(TMHttpSuccess)success
                          failed:(TMHttpFailed)failed;



/// 意见反馈
/// @param success 成功回调
/// @param failed 失败回调
+ (void)tm_addOpinionInfoWithOpinionInfo:(NSString *)opinionInfo
                                 success:(TMHttpSuccess)success
                                  failed:(TMHttpFailed)failed;

/// 获取签到数据
/// @param success 成功回调
/// @param failed 失败回调
+ (void)tm_getSigninInfoWithSuccess:(TMHttpSuccess)success
                             failed:(TMHttpFailed)failed;

/// 签到
/// @param success 成功回调
/// @param failed 失败回调
+ (void)tm_signinWithSuccess:(TMHttpSuccess)success
                      failed:(TMHttpFailed)failed;

/// 获取用户收藏和历史记录数量
/// @param success 成功回调
/// @param failed 失败回调
+ (void)tm_getHistoryAndCollectionNumWithSuccess:(TMHttpSuccess)success
                                          failed:(TMHttpFailed)failed;

/// 获取个人中心首页banner数据
/// @param success 成功回调
/// @param failed 失败回调
+ (void)tm_getAdvListWithSuccess:(TMHttpSuccess)success
                          failed:(TMHttpFailed)failed;

/// 获取个人中心首页背景图片
/// @param success 成功回调
/// @param failed 失败回调
+ (void)tm_getMainBackgroundImageWithSuccess:(TMHttpSuccess)success
                                      failed:(TMHttpFailed)failed;


/// 获取积分配置信息
/// @param success 成功回调
/// @param failed 失败回调
+ (void)tm_getPointConfigWithSuccess:(TMHttpSuccess)success
                              failed:(TMHttpFailed)failed;


/// 获取收货人地址
/// @param success 成功回调
/// @param failed 失败回调
+ (void)tm_getAddressListWithSuccess:(TMHttpSuccess)success
                              failed:(TMHttpFailed)failed;


/// 添加或者修改收货地址
/// @param addressID 收货地址ID，传入ID表示修改，不传表示添加
/// @param name 收货人
/// @param mobile 收货人电话
/// @param country 国家
/// @param province 省份
/// @param city 城市
/// @param district 区县

/// @param details 详细地址
/// @param isDefault 是否为默认地址
/// @param success 成功回调
/// @param failed 失败回调
+ (void)tm_addOrModifyAddressWithID:(NSNumber *_Nullable)addressID
                            name:(NSString *)name
                            mobile:(NSString *)mobile
                           country:(NSString *)country
                          province:(NSString *)province
                              city:(NSString *)city
                          district:(NSString *)district
                           details:(NSString *)details
                       isDefault:(BOOL)isDefault
                            success:(TMHttpSuccess)success
                             failed:(TMHttpFailed)failed;

/// 删除收货地址
/// @param addressID 地址ID
/// @param success 成功回调
/// @param failed 失败回调
+ (void)tm_deleteAddressWithAddressID:(NSNumber * )addressID
                              success:(TMHttpSuccess)success
                               failed:(TMHttpFailed)failed;

/// 实名认证
/// @param realName 真实姓名
/// @param idCardNumber 身份证号
/// @param idCardZhengImage 身份证正面图片
/// @param idCardFanImage 身份证反面图片
/// @param success 成功回调
/// @param failed 失败回调
+ (void)tm_submitIdCardWithName:(NSString *)realName
                idCardNumber:(NSString *)idCardNumber
            idCardZhengImage:(UIImage *)idCardZhengImage
              idCardFanImage:(UIImage *)idCardFanImage
                        success:(TMHttpSuccess)success
                         failed:(TMHttpFailed)failed;

/// 上传图片
/// @param image 图片
/// @param progress 进度回调
/// @param successHander 成功回调：上传成功时会把 图片链接地址同步返回
/// @param errorHander 失败回调
+ (void)tm_uploadImage:(UIImage *)image
            uploadProgress:(void (^)(CGFloat))progress
              finishHander:(void(^)(NSString *imagePath))successHander
             failedHandler:(void(^)(NSString *error))errorHander;

@end

NS_ASSUME_NONNULL_END
