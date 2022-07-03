//
//  Header.h
//  CordovaLib
//
//  Created by ZhouYou on 2017/12/15.
//

#ifndef Header_h
#define Header_h

//用户点击推送通知后
#define TMMessageNotification_ReceivedNotification      @"TMMessageNotification_ReceivedNotification"

//启动加载完成，启动页消失后由导航组件出发
#define TMMessageNotification_DidFinishLoading          @"TMMessageNotification_DidFinishLoading"

#define TMMessageNotification_DidFinishLaunching        @"TMMessageNotification_DidFinishLaunching"

#define TMMessageNotification_WillResignActive          @"TMMessageNotification_WillResignActive"

#define TMMessageNotification_DidEnterBackground        @"TMMessageNotification_DidEnterBackground"

#define TMMessageNotification_WillEnterForeground       @"TMMessageNotification_WillEnterForeground"

#define TMMessageNotification_DidBecomeActive           @"TMMessageNotification_DidBecomeActive"

#define TMMessageNotification_WillTerminate             @"TMMessageNotification_WillTerminate"

//接收到openURL消息
#define kTMAppDelegateHandleOpenURLNotification @"kTMAppDelegateHandleOpenURLNotification"
#define kTMAppDelegateHandleOpenURLAndOpenUrlOptionsNotification @"kTMAppDelegateHandleOpenURLAndOpenUrlOptionsNotification"

#define kTMAppDelegateHandleContinueUserActivityNotification @"kTMAppDelegateHandleContinueUserActivityNotification"

#define TMSDKImage(imageName) [UIImage imageNamed:[NSString stringWithFormat:@"TMSDK.bundle/%@", imageName]]

#endif /* Header_h */
