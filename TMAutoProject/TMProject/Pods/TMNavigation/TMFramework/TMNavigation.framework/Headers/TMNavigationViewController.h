//
//  TMNavigationViewController.h
//  TMProject
//
//  Created by ZhouYou on 2018/1/21.
//  Copyright © 2018年 ZhouYou. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <TMSDK/TMSDK.h>
/**启动组件在开始加载组件是会发出通知*/
static NSString * _Nonnull kTMNavigationStartLoadingNotication = @"kTMNavigationStartLoadingNotication";
/**tabbar在切换item时会发出通知，  object：表示即将切换的viewcontroller*/
static NSString * _Nonnull kTMTabBarControllerShouldSelectViewControllerNotification = @"kTMTabBarControllerShouldSelectViewControllerNotification";


@interface TMNavigationViewController : UIViewController

@property (nonatomic, strong) UIColor *_Nonnull navBarTextColor;

- (instancetype _Nonnull)initWithConfigPath:(NSString *_Nullable)configPath;
@end
