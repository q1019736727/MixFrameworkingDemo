//
//  TMWVKWebViewController.h
//  TMWebViewKitSDK
//
//  Created by rxk on 2020/7/15.
//  Copyright © 2020 Tianma. All rights reserved.
//

#import <TMSDK/TMSDK.h>
#import <WebKit/WebKit.h>



NS_ASSUME_NONNULL_BEGIN
typedef void (^TMWVKJBResponseCallback)(id responseData);
typedef void (^TMWVKJBHandler)(id data, TMWVKJBResponseCallback responseCallback);

@interface TMWVKWebViewController : TMViewController<WKNavigationDelegate>
@property (nonatomic, strong) NSArray *userScriptArray;
@property (nonatomic, strong) WKWebView *tmWebView;
/**网页加载完成后是否自动隐藏加载动画, 默认为自动隐藏*/
@property (nonatomic, assign) BOOL tm_loadComplateAutoAnimated;

/**是否允许使用缓存， 默认不允许*/
@property (nonatomic, assign) BOOL allowUseCache;

@property (nonatomic, copy) TMWVKJBResponseCallback callBackData;

- (void)tmwvk_registerHandler:(NSString*)handlerName handler:(TMWVKJBHandler)handler;
- (void)tmwvk_removeScriptMessageAll;
@end

NS_ASSUME_NONNULL_END
