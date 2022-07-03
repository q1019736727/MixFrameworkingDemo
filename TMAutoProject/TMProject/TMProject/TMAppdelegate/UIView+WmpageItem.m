//
//  UIView+WmpageItem.m
//  TMProject
//
//  Created by rxk on 2021/7/19.
//  Copyright © 2021 Tianma. All rights reserved.
//

#import "UIView+WmpageItem.h"
#import <objc/runtime.h>
#import <WMPageController/WMMenuItem.h>
#import <WMPageController/WMMenuView.h>
#import <WMPageController/WMPageController.h>
#import <TMComponentKitSDK/TMComponentKitSDK.h>
@implementation UIView (WmpageItem)

+ (void)load{

    static dispatch_once_t onceToken;

    dispatch_once(&onceToken, ^{
        NSString *bundleID = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleIdentifier"];

        Class class = NSClassFromString(@"Newsl004MenuView");
        if (bundleID && [bundleID isEqualToString:@"com.chinamcloud.wangjie.tsxgbdst"] && class) {
            //拿到系统方法
            SEL orignalSel3 = NSSelectorFromString(@"addItems");
            SEL swizzledSel3 = @selector(tm_addItems);
            [self exchangeImplementationsWithClass:class orignalSel:orignalSel3 swizzledSel:swizzledSel3];
        }
    });
}

+ (void)exchangeImplementationsWithClass:(Class)class orignalSel:(SEL)orignalSel swizzledSel:(SEL)swizzledSel {
    
    //拿到系统方法
    
    Method orignalM3 = class_getInstanceMethod(class, orignalSel);
    
    Method swizzledM3 = class_getInstanceMethod(class, swizzledSel);
    BOOL didAddMethod3 = class_addMethod(class, orignalSel, method_getImplementation(swizzledM3), method_getTypeEncoding(swizzledM3));
    if (didAddMethod3) {
        class_replaceMethod(class, swizzledSel, method_getImplementation(orignalM3), method_getTypeEncoding(orignalM3));
    }else{
        method_exchangeImplementations(orignalM3, swizzledM3);
    }
    
}

- (void)tm_addItems {
    [self tm_addItems];
    WMMenuView *menuView = (WMMenuView *)self;
    for (UILabel *tempLabel in menuView.scrollView.subviews) {
        if ([tempLabel isKindOfClass:[WMMenuItem class]]) {
            tempLabel.font = [UIFont boldSystemFontOfSize:16];
        }
    }
}

@end
