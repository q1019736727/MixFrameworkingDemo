//
//  SetI001ConfigInstance.h
//  TmCompDemo
//
//  Created by ZhouYou on 2018/1/16.
//  Copyright © 2018年 ZhouYou. All rights reserved.
//

#import <Foundation/Foundation.h>

#define     SetI001_Notification_Apns       @"SetI001_Notification_Apns"
#define     SetI001_Notification_NightModel @"SetI001_Notification_NightModel"
#define     SetI001_Notification_Font       @"SetI001_Notification_Font"
#define     SetI001_Notification_Logout     @"SetI001_Notification_Logout"
#define     SetI001_Notification_Login     @"SetI001_Notification_Login"

#define     SetI001_Notification_WifiLookImage     @"SetI001_Notification_WifiLookImage"
#define     SetI001_Notification_AutoPlayVideo     @"SetI001_Notification_AutoPlayVideo"

#define     SetI001_Notification_ChangeSex     @"SetI001_Notification_ChangeSex"
#define     SetI001_Notification_Birthday     @"SetI001_Notification_Birthday"
#define     SetI001_Notification_BingMobile     @"SetI001_Notification_BingMobile"

#define     SetI001_Notification_ModifyUserInfo     @"SetI001_Notification_ModifyUserInfo"

/**更新用户页面显示*/
#define     SetI001_Notification_UpdateUserHomePageShow @"SetI001_Notification_UpdateUserHomePageShow"

typedef NS_ENUM(NSUInteger, SetI001_Config_Font) {
    SetI001_Config_FontNormal,
    SetI001_Config_FontSmall,
    SetI001_Config_FontLarge,
};

@interface SetI001ConfigInstance : NSObject

@property (nonatomic, strong) NSDictionary *tm_appConfig;

@property (nonatomic, assign) BOOL isgray;
/**
 App Store地址
 */
@property (nonatomic, strong) NSString *tm_appUrl;

/**首页样式配置*/
@property (nonatomic, strong) NSArray *tm_homePageConfig;
/**首页样式背景图片*/
@property (nonatomic, strong) NSString *tm_homePageBackgroundUrl;

/*推送开关
 TMDataCacheKey:@"local_apnsEnable"
 LocalData
 Default:YES
 */
@property (nonatomic, assign) BOOL apnsEnable;

/**
 是否仅在wifi下查看图片
 TMDataCacheKey:@"local_wifiLookImage"
 Default:NO
 */
@property (nonatomic, assign) BOOL wifiLookImage;

/**
 自动播放视频
 TMDataCacheKey:@"local_autoPlayVideo"
 Default:NO
 */
@property (nonatomic, assign) BOOL autoPlayVideo;


/*夜间模式开关
 TMDataCacheKey:@"local_nightModel"
 LocalData
 Default:NO
 */
@property (nonatomic, assign) BOOL nightModel;



/*正文字体大小
 TMDataCacheKey:@"local_font"
 LocalData
 Default:SetI001_Config_FontNormal
 */
@property (nonatomic, assign) SetI001_Config_Font font;


/**
 返回一个单例
 */
+ (SetI001ConfigInstance *)instance;
+ (instancetype)sharedManager;

//只会统计及清除Document/Caches、Tmp、Caches三个路径下的缓存
- (void)cleanCache:(void(^)(BOOL))result;

- (uint64_t)cacheSize:(void(^)(uint64_t))sizeHander;

/*
//根据key，自动判断是否页面模式返回对应颜色
 */
- (unsigned long)corlorByKey:(NSString *)key;

/*
 //添加更多颜色进去，key  color相对应
 */
- (void)addColors:(NSDictionary *)corlors isNight:(BOOL)night;
@end
