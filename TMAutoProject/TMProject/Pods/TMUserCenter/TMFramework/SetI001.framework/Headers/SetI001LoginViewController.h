//
//  SetI001LoginViewController.h
//  TmCompDemo
//
//  Created by ZhouYou on 2018/1/15.
//  Copyright © 2018年 ZhouYou. All rights reserved.
//

#import <TMSDK/TMSDK.h>
typedef void(^TMExitLoginPageComplate)(BOOL isLogin);
@interface SetI001LoginViewController : TMViewController
/**
只有在成功登录会回调
*/
@property (nonatomic, copy) TMExitLoginPageComplate pageComplate;
/**
 成功或失败都会回调
 */
@property (nonatomic, copy) TMExitLoginPageComplate tm_pageComplate;

@end
