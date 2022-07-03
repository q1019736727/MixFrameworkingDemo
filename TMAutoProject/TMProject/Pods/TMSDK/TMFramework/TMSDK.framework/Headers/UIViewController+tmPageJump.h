//
//  UIViewController+tmPageJump.h
//  Cordova
//
//  Created by rxk on 2020/10/14.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIViewController (tmPageJump)

+ (void)tmsdk_jumpH5PageWithUrl:(NSString *)url
                         params:(id _Nullable)params
                          title:(NSString *_Nullable)title;

+ (void)tmsdk_jumpNativePageWithClassName:(NSString *)className
                                   params:(id _Nullable)params
                                    title:(NSString *_Nullable)title;
@end

NS_ASSUME_NONNULL_END
