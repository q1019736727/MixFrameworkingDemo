//
//  TMPrivacyAgreementViewController.m
//  TMProject
//
//  Created by rxk on 2021/6/25.
//  Copyright © 2021 Tianma. All rights reserved.
//

#import "TMPrivacyAgreementViewController.h"
#import "YYText.h"
#import "NSAttributedString+YYText.h"
#import <TMComponentKitSDK/TMComponentKitSDK.h>
#import "Masonry.h"
@interface TMPrivacyAgreementViewController ()
@property (nonatomic, strong) YYLabel *alertLabel;
@end

@implementation TMPrivacyAgreementViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    [self initUserInterface];
}
- (void)viewWillAppear:(BOOL)animated {
    [super viewWillAppear:animated];
    [self.navigationController setNavigationBarHidden:YES animated:animated];
}

- (void)viewWillDisappear:(BOOL)animated {
    [super viewWillDisappear:animated];
    [self.navigationController setNavigationBarHidden:NO animated:animated];
}

- (void)initUserInterface {
    
    UIView *backgroundView = [[UIView alloc] initWithFrame:self.view.bounds];
    backgroundView.backgroundColor = TMCOLOR_RGB_ALPHA(0x000000, 0.5);
    
    UIBlurEffect *blur = [UIBlurEffect effectWithStyle:UIBlurEffectStyleLight];
    UIVisualEffectView *effectview = [[UIVisualEffectView alloc] initWithEffect:blur];
    effectview.frame = backgroundView.bounds;
    effectview.alpha = .6;
    [backgroundView addSubview:effectview];
    [self.view addSubview:backgroundView];
    
    CGFloat leftMar = 20.0;
    CGFloat rightMar = -20.0;
    UIView *contentView = [UIView new];
    contentView.backgroundColor = [UIColor whiteColor];
    contentView.layer.cornerRadius = 5;
    contentView.layer.masksToBounds = YES;
    [self.view addSubview:contentView];
    
    UILabel *titleLabel = [UILabel new];
    titleLabel.text = @"个人信息保护引导";
    titleLabel.font = [UIFont systemFontOfSize:16];
    titleLabel.textColor = TMColorFromRGB(0x333333);
    titleLabel.textAlignment = NSTextAlignmentCenter;
    [contentView addSubview:titleLabel];
    
    
    _alertLabel = [[YYLabel alloc] init];
    _alertLabel.numberOfLines = 0;
    _alertLabel.lineBreakMode = NSLineBreakByTruncatingTail;
    
    NSString *alertStr = @"请充分阅读并理解《用户使用协议》和《隐私协议》\n1、为基于您的位置向你推荐内容及服务，我们可能会申请位置权限。\n2、定位、摄像头、麦克风、相册等敏感权限均不会默认开启，只有经过明示授权才会使用该功能，您均可以拒绝且不影响继续使用本应用";
    NSMutableAttributedString *alertAtt = [[NSMutableAttributedString alloc] initWithString:alertStr attributes:@{
        NSFontAttributeName : TMGetFont(11),
        NSForegroundColorAttributeName : TMColorFromRGB(0x777777),
        NSBackgroundColorAttributeName : [UIColor clearColor]
    }];
    [alertAtt setAttributes:@{NSFontAttributeName : [UIFont systemFontOfSize:13], NSForegroundColorAttributeName : [UIColor blueColor]} range:[alertStr rangeOfString:@"《用户使用协议》"]];
    [alertAtt setAttributes:@{NSFontAttributeName : [UIFont systemFontOfSize:13], NSForegroundColorAttributeName : [UIColor blueColor]} range:[alertStr rangeOfString:@"《隐私协议》"]];
    
    TMWS(ws);
    [alertAtt yy_setTextHighlightRange:[alertStr rangeOfString:@"《用户使用协议》"] color:[UIColor blueColor] backgroundColor:[UIColor clearColor] tapAction:^(UIView * _Nonnull containerView, NSAttributedString * _Nonnull text, NSRange range, CGRect rect) {
        [ws handelAlertClickEventWithType:1];
    }];
    
    [alertAtt yy_setTextHighlightRange:[alertStr rangeOfString:@"《隐私协议》"] color:[UIColor blueColor] backgroundColor:[UIColor clearColor] tapAction:^(UIView * _Nonnull containerView, NSAttributedString * _Nonnull text, NSRange range, CGRect rect) {
        [ws handelAlertClickEventWithType:2];
    }];
    _alertLabel.preferredMaxLayoutWidth = TMSCREEN_WITH - 2 * (leftMar + fabs(rightMar));
    _alertLabel.attributedText = alertAtt;
    [contentView addSubview:_alertLabel];
    
    
    
    UIButton *cancelButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [cancelButton setTitle:@"不同意" forState:UIControlStateNormal];
    [cancelButton setTitle:@"不同意" forState:UIControlStateHighlighted];
    cancelButton.backgroundColor = [TMEngineConfig instance].themeColor;
    cancelButton.layer.cornerRadius = 5;
    cancelButton.layer.masksToBounds = YES;
    [cancelButton addTarget:self action:@selector(exitApp) forControlEvents:UIControlEventTouchUpInside];
    [contentView addSubview:cancelButton];
    
    UIButton *sureButton = [UIButton buttonWithType:UIButtonTypeCustom];
    [sureButton setTitle:@"同意" forState:UIControlStateNormal];
    [sureButton setTitle:@"同意" forState:UIControlStateHighlighted];
    sureButton.backgroundColor = [TMEngineConfig instance].themeColor;
    sureButton.layer.cornerRadius = 5;
    sureButton.layer.masksToBounds = YES;
    [sureButton addTarget:self action:@selector(agreementDeal) forControlEvents:UIControlEventTouchUpInside];
    [contentView addSubview:sureButton];

    

    
    [titleLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.mas_equalTo(leftMar);
        make.top.mas_equalTo(10);
        make.right.mas_equalTo(rightMar);
    }];
    
    [_alertLabel mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.mas_equalTo(leftMar);
        make.right.mas_equalTo(rightMar);
        make.top.equalTo(titleLabel.mas_bottom).mas_offset(10);
    }];
    
    
    [cancelButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.mas_equalTo(leftMar);
        make.top.equalTo(ws.alertLabel.mas_bottom).mas_offset(10);
        make.right.equalTo(sureButton.mas_left).mas_offset(-10);
        make.height.mas_equalTo(40);
        make.width.equalTo(sureButton);
    }];
    
    [sureButton mas_makeConstraints:^(MASConstraintMaker *make) {
        make.right.mas_equalTo(rightMar);
        make.top.equalTo(cancelButton);
        make.height.mas_equalTo(cancelButton);
    }];
    
    [contentView mas_makeConstraints:^(MASConstraintMaker *make) {
        make.left.mas_equalTo(leftMar);
        make.right.mas_equalTo(rightMar);
        make.centerY.equalTo(backgroundView);
        make.bottom.equalTo(cancelButton.mas_bottom).mas_offset(5);
    }];
    
    
}



- (void)hidePrivacyAgreementView {
    
}

#pragma mark - TYAttributedLabelDelegate

/// 处理用户协议点击事件, 1:用户协议  2：隐私协议
/// @param type 事件类型
- (void)handelAlertClickEventWithType:(NSInteger)type {
    TMViewController *vc = [[NSClassFromString(@"SetI001AboutViewController") alloc] init];
    [vc setValue:@(type == 1 ? 0 : 1) forKey:@"pageType"];
    [self.navigationController pushViewController:vc animated:YES];
}

- (void)exitApp {
    exit(0);
}
- (void)agreementDeal {
    [[NSUserDefaults standardUserDefaults] setBool:YES forKey:@"isShowPrivacyAgreement"];
    if (_agreePrivacyAgreementsBlock) {
        _agreePrivacyAgreementsBlock();
    }
}

@end
