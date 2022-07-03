//
//  AppDelegate.m
//  TMProject
//
//  Created by 任旭奎 on 2018/9/18.
//  Copyright © 2018年 车音智能. All rights reserved.
//

#import "AppDelegate.h"
#import <TMNavigation/TMNavigation.h>
#import <Bugly/Bugly.h>
#import <AMapFoundationKit/AMapFoundationKit.h>
#import <AMapLocationKit/AMapLocationKit.h>
#import <IQKeyboardManager/IQKeyboardManager.h>
#import <TMSDK/CDVAppDelegate+TMJPush.h>
#import "TMPrivacyAgreementViewController.h"
#import "BaiduMobStat.h"
#import "TMProject-Swift.h"
@import QYTestSDK;
@interface AppDelegate ()

@end

@implementation AppDelegate


- (BOOL)application:(UIApplication *)application didFinishLaunchingWithOptions:(NSDictionary *)launchOptions {
//    [self redirectStandardOutput];
    
//    BOOL isShow = [[NSUserDefaults standardUserDefaults] boolForKey:@"isShowPrivacyAgreement"];
//    if (!isShow) {
//        TMPrivacyAgreementViewController *vc = [[TMPrivacyAgreementViewController alloc] init];
//        [TMEngineConfig instance].navigationTintColor = [UIColor blackColor];
//        TMWS(weakSelf);
//        vc.agreePrivacyAgreementsBlock = ^{
//            [weakSelf initKey];
//            [weakSelf TMJPushApplication:application didFinishLaunchingWithOptions:launchOptions];
//
//            TMNavigationViewController *tmp = [[TMNavigationViewController alloc] init];
//
//            UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:tmp];
//            nav.navigationBar.translucent = NO;
//            nav.navigationBar.titleTextAttributes = @{NSForegroundColorAttributeName : [UIColor whiteColor]};
//            [nav.navigationBar setTintColor:[UIColor whiteColor]];
//
//            weakSelf.window.rootViewController = nav;
//        };
//
//        UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:vc];
//        nav.navigationBar.translucent = NO;
//        nav.navigationBar.titleTextAttributes = @{NSForegroundColorAttributeName : [UIColor whiteColor]};
//        [nav.navigationBar setTintColor:[UIColor whiteColor]];
//
//
//        self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
//        self.window.backgroundColor = [UIColor whiteColor];
//        self.window.rootViewController = nav;
//        [self.window makeKeyAndVisible];
//        return YES;
//
//    } else {
//        [self TMJPushApplication:application didFinishLaunchingWithOptions:launchOptions];
//
//
//        [self initKey];
//
//
//
//        TMNavigationViewController *tmp = [[TMNavigationViewController alloc] init];
//
//        UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:tmp];
//        nav.navigationBar.translucent = NO;
//        nav.navigationBar.titleTextAttributes = @{NSForegroundColorAttributeName : [UIColor whiteColor]};
//        [nav.navigationBar setTintColor:[UIColor whiteColor]];
//
//
//
//        self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
//        self.window.backgroundColor = [UIColor whiteColor];
//        self.window.rootViewController = nav;
//        [self.window makeKeyAndVisible];
//        return YES;
//    }
    
    Class cls = NSClassFromString(@"_TtC9QYTestSDK19MyTestSDKController");
    QYViewController * vc = [[QYViewController alloc]init];

    UINavigationController *nav = [[UINavigationController alloc] initWithRootViewController:vc];
    
    
    self.window = [[UIWindow alloc] initWithFrame:[UIScreen mainScreen].bounds];
    self.window.backgroundColor = [UIColor whiteColor];
    self.window.rootViewController = nav;
    [self.window makeKeyAndVisible];

    TianmaSwift * tool = [[TianmaSwift alloc]init];
    return YES;

}

- (void)initKey {
    [IQKeyboardManager sharedManager].toolbarDoneBarButtonItemText = @"完成";
    [IQKeyboardManager sharedManager].toolbarTintColor = TMColorFromRGB(0x333333);
    
    NSDictionary *keyDic = [[TMEngineConfig instance] featureByName:@"gaodekey_for_brokeNew"];
    NSString *key = [keyDic valueForKey:@"gaodekey"];
    [AMapLocationManager updatePrivacyAgree:AMapPrivacyAgreeStatusDidAgree];
    [AMapLocationManager updatePrivacyShow:AMapPrivacyShowStatusDidShow privacyInfo:AMapPrivacyInfoStatusDidContain];
    [AMapServices sharedServices].apiKey = key ? key : @"";
    
    NSString *buglyKey = [[[TMEngineConfig instance] featureByName:@"buglyName"] valueForKey:@"buglyKey"];
    BuglyConfig *buglyConfig = [[BuglyConfig alloc] init];
    buglyConfig.blockMonitorEnable = YES;
    if ([buglyKey isKindOfClass:[NSString class]] && buglyKey.length > 0) {
        [Bugly startWithAppId:buglyKey config:buglyConfig];
    } else {
        [Bugly startWithAppId:@"020fa07018" config:buglyConfig];
    }
    
    
    NSDictionary *mtjKeyDic = [[TMEngineConfig instance] featureByName:@"mtj_appkey"];
    NSString *mtj_appkey = [mtjKeyDic valueForKey:@"appkey"];
    if ([mtj_appkey isKindOfClass:[NSString class]]) {
        [[BaiduMobStat defaultStat] startWithAppId:mtj_appkey];
    }
    NSLog(@"");
    
}



- (void)applicationWillResignActive:(UIApplication *)application {
    // Sent when the application is about to move from active to inactive state. This can occur for certain types of temporary interruptions (such as an incoming phone call or SMS message) or when the user quits the application and it begins the transition to the background state.
    // Use this method to pause ongoing tasks, disable timers, and invalidate graphics rendering callbacks. Games should use this method to pause the game.
}


- (void)applicationDidEnterBackground:(UIApplication *)application {
    // Use this method to release shared resources, save user data, invalidate timers, and store enough application state information to restore your application to its current state in case it is terminated later.
    // If your application supports background execution, this method is called instead of applicationWillTerminate: when the user quits.
}


- (void)applicationWillEnterForeground:(UIApplication *)application {
    // Called as part of the transition from the background to the active state; here you can undo many of the changes made on entering the background.
}


- (void)applicationWillTerminate:(UIApplication *)application {
    // Called when the application is about to terminate. Save data if appropriate. See also applicationDidEnterBackground:.
}
- (void)applicationDidBecomeActive:(UIApplication *)application {
    
    NSString *content = [[UIPasteboard generalPasteboard] string];
    if (content) {
        [UIPasteboard generalPasteboard].string = content;
    }
    
    [super applicationDidBecomeActive:application];
    
}


- (void)redirectStandardOutput{
    //记录标准输出及错误流原始文件描述符
    dup(STDOUT_FILENO);
    dup(STDERR_FILENO);

    stdout->_flags = 10;
    NSPipe *outPipe = [NSPipe pipe];
    NSFileHandle *pipeOutHandle = [outPipe fileHandleForReading];
    dup2([[outPipe fileHandleForWriting] fileDescriptor], STDOUT_FILENO);
    [pipeOutHandle readInBackgroundAndNotify];

    stderr->_flags = 10;
    NSPipe *errPipe = [NSPipe pipe];
    NSFileHandle *pipeErrHandle = [errPipe fileHandleForReading];
    dup2([[errPipe fileHandleForWriting] fileDescriptor], STDERR_FILENO);
    [pipeErrHandle readInBackgroundAndNotify];
    [[NSNotificationCenter defaultCenter] addObserver:self
                                            selector:@selector(redirectOutNotificationHandle:)
                                            name:NSFileHandleReadCompletionNotification
                                            object:pipeOutHandle];

    [[NSNotificationCenter defaultCenter] addObserver:self
                                            selector:@selector(redirectErrNotificationHandle:)
                                            name:NSFileHandleReadCompletionNotification
                                            object:pipeErrHandle];

}


// 重定向之后的NSLog输出
- (void)redirectOutNotificationHandle:(NSNotification *)nf{
    [[nf object] readInBackgroundAndNotify];
}

// 重定向之后的错误输出
- (void)redirectErrNotificationHandle:(NSNotification *)nf{
    [[nf object] readInBackgroundAndNotify];
}


@end
