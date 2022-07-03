//
//  TMNetworkingSecurityKit.m
//  TMProject
//
//  Created by rxk on 2021/8/26.
//  Copyright © 2021 Tianma. All rights reserved.
//

#import "TMNetworkingSecurityKit.h"
#import <TMSDK/TMEngineConfig.h>

#import <Masonry/Masonry.h>
#import <TMSDK/TMCommonDefine.h>
#import <TMSDK/TMMessageDefine.h>



@implementation TMNetworkingSecurityAlertView
- (instancetype)init
{
    self = [super init];
    if (self) {
        self.frame = [UIScreen mainScreen].bounds;
        
        UIView *backgroundView = [[UIView alloc] init];
        backgroundView.backgroundColor = [UIColor colorWithRed:0 green:0 blue:0 alpha:0.4];
        [self addSubview:backgroundView];
        [backgroundView mas_makeConstraints:^(MASConstraintMaker *make) {
            make.edges.mas_equalTo(0);
        }];
        
        
        CGFloat containWidth = [UIScreen mainScreen].bounds.size.width < 370 ? 200 : 300;
        
        UIView *containView = [UIView new];
        containView.backgroundColor = [UIColor whiteColor];
        containView.layer.cornerRadius = 10;
        [self addSubview:containView];
        [containView mas_makeConstraints:^(MASConstraintMaker *make) {
            make.center.equalTo(backgroundView);
            make.width.mas_equalTo(containWidth);
        }];
        
        UILabel *titleLabel = [UILabel new];
        titleLabel.textAlignment = NSTextAlignmentCenter;
        titleLabel.text = @"提示";
        titleLabel.textColor = [UIColor blackColor];
        titleLabel.font = [UIFont boldSystemFontOfSize:15];
        [containView addSubview:titleLabel];
        [titleLabel mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.right.mas_equalTo(0);
            make.top.mas_equalTo(10);
        }];
        
        UILabel *messageLabel = [UILabel new];
        messageLabel.numberOfLines = 0;
        messageLabel.textAlignment = NSTextAlignmentCenter;
        messageLabel.text = @"系统检测您正在通过代理服务器使用APP，请您谨慎操作，谨防个人信息被窃取";
        messageLabel.textColor = [UIColor blackColor];
        messageLabel.font = [UIFont systemFontOfSize:13];
        [containView addSubview:messageLabel];
        [messageLabel mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.mas_equalTo(20);
            make.right.mas_equalTo(-20);
            make.top.equalTo(titleLabel.mas_bottom).mas_offset(15);
        }];
        
        UIButton *statusButton = [UIButton buttonWithType:UIButtonTypeCustom];
        [statusButton setImage:[UIImage imageNamed:@"SetI001.bundle/tmuser_noselect"] forState:UIControlStateNormal];
        [statusButton setImage:[UIImage imageNamed:@"SetI001.bundle/tmuser_noselect"] forState:UIControlStateHighlighted];
        [statusButton setImage:[UIImage imageNamed:@"SetI001.bundle/tmuser_select"] forState:UIControlStateSelected];
        [statusButton addTarget:self action:@selector(tmns_didClickStatusButton:) forControlEvents:UIControlEventTouchUpInside];
        statusButton.titleLabel.font = [UIFont systemFontOfSize:13];
        statusButton.tag = 200;
        [statusButton setTitle:@" 以后不再弹出该提醒" forState:UIControlStateNormal];
        [statusButton setTitleColor:TMColorFromRGB(0x666666) forState:UIControlStateNormal];
        [statusButton setTitle:@" 以后不再弹出该提醒" forState:UIControlStateHighlighted];
        [statusButton setTitleColor:TMColorFromRGB(0x666666) forState:UIControlStateHighlighted];
        [statusButton setTitle:@" 以后不再弹出该提醒" forState:UIControlStateSelected];
        [statusButton setTitleColor:TMColorFromRGB(0x666666) forState:UIControlStateSelected];
        [containView addSubview:statusButton];
        [statusButton mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.mas_equalTo(20);
            make.top.mas_equalTo(messageLabel.mas_bottom).mas_offset(10);
            make.height.mas_equalTo(40);
        }];
        
        UIView *lineView = [UIView new];
        lineView.backgroundColor = TMColorFromRGB(0x999999);
        [containView addSubview:lineView];
        [lineView mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.right.mas_equalTo(0);
            make.top.equalTo(statusButton.mas_bottom).mas_offset(10);
            make.height.mas_equalTo(1);
        }];
        
        UIButton *sureButton = [UIButton buttonWithType:UIButtonTypeSystem];
        [sureButton addTarget:self action:@selector(tmns_didClickSureButton:) forControlEvents:UIControlEventTouchUpInside];
        sureButton.titleLabel.font = [UIFont systemFontOfSize:16];
        [sureButton setTitle:@"确定" forState:UIControlStateNormal];
        [sureButton setTitle:@"确定" forState:UIControlStateHighlighted];
        [containView addSubview:sureButton];
        [sureButton mas_makeConstraints:^(MASConstraintMaker *make) {
            make.left.right.mas_equalTo(0);
            make.top.mas_equalTo(lineView.mas_bottom).mas_offset(10);
            make.bottom.mas_equalTo(-10);
        }];
    }
    return self;
}






- (void)tmns_didClickStatusButton:(UIButton *)sender {
    sender.selected = !sender.selected;
}
- (void)tmns_didClickSureButton:(UIButton *)sender {
    UIButton *statusButton = [sender.superview viewWithTag:200];
    if ([statusButton isKindOfClass:[UIButton class]] && statusButton.selected) {
        [[NSUserDefaults standardUserDefaults] setValue:@(NO) forKey:@"TMNetworkingSecurityKit_proxySwitch"];
        [[NSUserDefaults standardUserDefaults] synchronize];
    }
    [self removeFromSuperview];
}


+ (void)tmns_showSecurityAlertView {
    NSNumber *proxySwitch = [[NSUserDefaults standardUserDefaults] objectForKey:@"TMNetworkingSecurityKit_proxySwitch"];
    if (proxySwitch && (![proxySwitch boolValue])) {
        return;
    }
    
    for (UIView *tempView in [UIApplication sharedApplication].keyWindow.subviews) {
        if ([tempView isKindOfClass:[TMNetworkingSecurityAlertView class]]) {
            [tempView removeFromSuperview];
        }
    }
    
    [[UIApplication sharedApplication].keyWindow addSubview:[[TMNetworkingSecurityAlertView alloc] init]];
    
}
@end




@implementation TMNetworkingSecurityKit

+ (void)load {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(tmns_tabbarControllerSelectNotication) name:@"kTMTabBarControllerShouldSelectViewControllerNotification" object:nil];
        [[NSNotificationCenter defaultCenter] addObserver:self selector:@selector(tmns_checkAppNetworkingProxySetting) name:TMMessageNotification_DidFinishLoading object:nil];
    });
}



+ (BOOL)tmns_getProxyStatus {
    NSDictionary *proxySettings = (__bridge NSDictionary *)(CFNetworkCopySystemProxySettings());
    NSArray *proxies = (__bridge NSArray *)(CFNetworkCopyProxiesForURL((__bridge CFURLRef _Nonnull)([NSURL URLWithString:[TMEngineConfig instance].domain]), (__bridge CFDictionaryRef _Nonnull)(proxySettings)));
    NSDictionary *settings = [proxies firstObject];
    
    if (![[settings objectForKey:(NSString *)kCFProxyTypeKey] isEqualToString:@"kCFProxyTypeNone"]){
        return YES;
    }else {
        return NO;
    }
}

+ (void)tmns_tabbarControllerSelectNotication {
    static int tabIndex = 0;
    if (tabIndex == 0) {
        tabIndex ++;
        return;
    }
    [self tmns_checkAppNetworkingProxySetting];
    tabIndex ++;
}

+ (void)tmns_checkAppNetworkingProxySetting {
    
    if ([self tmns_getProxyStatus]) {
        static int alertShowIndex = 0;
        if (alertShowIndex >= 5) {
            return;
        }
        alertShowIndex ++;
        [TMNetworkingSecurityAlertView tmns_showSecurityAlertView];
    }
}




@end
