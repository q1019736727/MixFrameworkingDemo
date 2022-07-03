//
//  CDVAppDelegate+TMJPush.h
//  Cordova
//
//  Created by ZhouYou on 2018/1/19.
//

#import "CDVAppDelegate.h"
@interface CDVAppDelegate (TMJPush)

@property (nonatomic, strong) NSDictionary *launchUserInfo;

@property (nonatomic, strong) NSString *isLoadComplate;

@property (nonatomic, strong) NSURL *sourceOpenUrl;
@property (nonatomic, strong) NSDictionary *openURLOptions;



- (void)TMJPushApplication:(UIApplication*)application didFinishLaunchingWithOptions:(NSDictionary*)launchOptions;

- (void)TMApplicationWillResignActive:(UIApplication *)application;

- (void)TMApplicationDidEnterBackground:(UIApplication *)application;

- (void)TMApplicationWillEnterForeground:(UIApplication *)application;

- (void)TMApplicationDidBecomeActive:(UIApplication *)application;

- (void)TMApplicationWillTerminate:(UIApplication *)application;

- (void)TMApplication:(UIApplication *)application didRegisterForRemoteNotificationsWithDeviceToken:(NSData *)deviceToken;

- (void)TMApplication:(UIApplication *)application didFailToRegisterForRemoteNotificationsWithError:(NSError *)error;

- (void)TMApplication:(UIApplication *)application didReceiveRemoteNotification:(NSDictionary *)userInfo fetchCompletionHandler:(void (^)(UIBackgroundFetchResult))completionHandler;

- (void)TMApplication:(UIApplication *)app openURL:(NSURL *)url options:(NSDictionary<UIApplicationOpenURLOptionsKey,id> *)options;

- (void)TMApplication:(UIApplication *)application continueUserActivity:(NSUserActivity *)userActivity restorationHandler:(void (^)(NSArray<id<UIUserActivityRestoring>> * _Nullable))restorationHandler;
@end
