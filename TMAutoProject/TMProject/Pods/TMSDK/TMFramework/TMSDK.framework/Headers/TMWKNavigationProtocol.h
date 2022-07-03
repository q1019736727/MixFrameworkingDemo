//
//  TMWKNavigationProtocol.h
//  Cordova
//
//  Created by rxk on 2019/10/16.
//

#import <Foundation/Foundation.h>
#import <WebKit/WebKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol TMWKNavigationProtocol <NSObject>

@optional

/// 是否允许继续加载
/// @param webView 浏览器
/// @param navigationAction 导航控制器
- (BOOL)tm_webView:(WKWebView *)webView decidePolicyForNavigationAction:(WKNavigationAction *)navigationAction;


/// 当开始加载时调用
/// @param webView 浏览器
/// @param navigation 导航控制器
- (void)tm_webView:(WKWebView *)webView didStartProvisionalNavigation:(null_unspecified WKNavigation *)navigation;

/// 当开始加收网页内容时调用
/// @param webView 浏览器
/// @param navigation 导航控制器
- (void)tm_webView:(WKWebView *)webView didCommitNavigation:(null_unspecified WKNavigation *)navigation;

/// 当加载完成时调用
/// @param webView 浏览器
/// @param navigation 导航控制器
- (void)tm_webView:(WKWebView *)webView didFinishNavigation:(null_unspecified WKNavigation *)navigation;

/// 在导航过程中发生错误时调用，跳转失败时调用
/// @param webView 浏览器
/// @param navigation 导航控制器
/// @param error 错误
- (void)tm_webView:(WKWebView *)webView didFailNavigation:(null_unspecified WKNavigation *)navigation withError:(NSError *)error;


- (void)tm_userContentController:(WKUserContentController*)userContentController didReceiveScriptMessage:(WKScriptMessage*)message;

@end
NS_ASSUME_NONNULL_END
