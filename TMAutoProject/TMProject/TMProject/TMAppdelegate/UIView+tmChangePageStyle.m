//
//  UIView+tmChangePageStyle.m
//  TMProject
//
//  Created by rxk on 2020/10/19.
//  Copyright © 2020 Tianma. All rights reserved.
//

#import "UIView+tmChangePageStyle.h"
#import <objc/runtime.h>
#import "Masonry.h"
#import <TMSDK/TMSDK.h>
@implementation UIView (tmChangePageStyle)
+ (void)load{

    static dispatch_once_t onceToken;

    dispatch_once(&onceToken, ^{
        NSString *bundleID = [[[NSBundle mainBundle] infoDictionary] objectForKey:@"CFBundleIdentifier"];
        
        Class class = NSClassFromString(@"NewsI004DjHeaderView");
        if (bundleID && [bundleID isEqualToString:@"com.tianma.houjiewenhua"] && class) {
            //拿到系统方法
            SEL orignalSel3 = @selector(initWithFrame:);
            Method orignalM3 = class_getInstanceMethod(class, orignalSel3);
            
            SEL swizzledSel3 = @selector(tm_changeStyleInitWithFrame:);
            Method swizzledM3 = class_getInstanceMethod(class, swizzledSel3);
            BOOL didAddMethod3 = class_addMethod(class, orignalSel3, method_getImplementation(swizzledM3), method_getTypeEncoding(swizzledM3));
            if (didAddMethod3) {
                class_replaceMethod(class, swizzledSel3, method_getImplementation(orignalM3), method_getTypeEncoding(orignalM3));
            }else{
                method_exchangeImplementations(orignalM3, swizzledM3);
            }
            
            
            
            SEL orignalSel4 = @selector(setBackgroundColor:);
            Method orignalM4 = class_getInstanceMethod(class, orignalSel4);
            
            SEL swizzledSel4 = @selector(tm_changeStyleWithSetBackgroundColor:);
            Method swizzledM4 = class_getInstanceMethod(class, swizzledSel4);
            BOOL didAddMethod4 = class_addMethod(class, orignalSel4, method_getImplementation(swizzledM4), method_getTypeEncoding(swizzledM4));
            if (didAddMethod4) {
                class_replaceMethod(class, swizzledSel4, method_getImplementation(orignalM4), method_getTypeEncoding(orignalM4));
            }else{
                method_exchangeImplementations(orignalM4, swizzledM4);
            }
            
            
        }
    });
}



- (instancetype)tm_changeStyleInitWithFrame:(CGRect)frame {
    UIView *initView = [self tm_changeStyleInitWithFrame:frame];
    UIView *leftView = [initView valueForKey:@"LeftView"];
    UILabel *titleLabel = [initView valueForKey:@"lab_title"];
    UILabel *moreLabel = [initView valueForKey:@"lab_subTitle"];
    if (leftView && titleLabel && moreLabel) {
        titleLabel.font = [UIFont boldSystemFontOfSize:18];
        [leftView mas_remakeConstraints:^(MASConstraintMaker *make) {
            make.left.mas_equalTo(14);
            make.height.mas_equalTo(20);
            make.width.mas_equalTo(8);
            make.centerY.equalTo(initView);
        }];
        
        [titleLabel mas_remakeConstraints:^(MASConstraintMaker *make) {
            make.left.equalTo(leftView.mas_right).mas_offset(7);
            make.centerY.equalTo(leftView).mas_offset(2);
            make.height.mas_equalTo(24);
        }];
        
        [moreLabel mas_remakeConstraints:^(MASConstraintMaker *make) {
            make.left.equalTo(titleLabel.mas_right).mas_offset(5);
            make.centerY.equalTo(titleLabel);
            make.right.mas_equalTo(-30);
        }];
        
    }
    
    UIView *topLineView = [UIView new];
    topLineView.backgroundColor = [TMEngineConfig instance].themeColor;
    [initView addSubview:topLineView];
    [topLineView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.top.right.mas_equalTo(0);
        make.height.mas_equalTo(1);
    }];
    
    
    return initView;
}

- (void)tm_changeStyleWithSetBackgroundColor:(UIColor *)backgroundColor {
    [self tm_changeStyleWithSetBackgroundColor:TMColorFromRGB(0xefefef)];
}



@end
