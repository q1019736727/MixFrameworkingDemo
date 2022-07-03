//
//  SetI001NewLoginViewController.h
//  SetI001
//
//  Created by rxk on 2019/9/11.
//  Copyright © 2019 Tianma. All rights reserved.
//



NS_ASSUME_NONNULL_BEGIN
typedef void(^TMExitLoginPageComplate)(BOOL isLogin);

@interface SetI001NewLoginViewController : TMViewController
/**
 只有在成功登录会回调
 */
@property (nonatomic, copy) TMExitLoginPageComplate pageComplate;
/**
 成功或失败都会回调
 */
@property (nonatomic, copy) TMExitLoginPageComplate tm_pageComplate;



@end

NS_ASSUME_NONNULL_END
