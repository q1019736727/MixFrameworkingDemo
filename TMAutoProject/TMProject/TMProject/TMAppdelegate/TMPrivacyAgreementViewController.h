//
//  TMPrivacyAgreementViewController.h
//  TMProject
//
//  Created by rxk on 2021/6/25.
//  Copyright © 2021 Tianma. All rights reserved.
//

#import <TMSDK/TMSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface TMPrivacyAgreementViewController : TMViewController
@property (nonatomic, copy) void(^agreePrivacyAgreementsBlock)(void);
@end

NS_ASSUME_NONNULL_END
