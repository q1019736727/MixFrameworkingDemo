//
//  NSString+TMUserCheck.h
//  SetI001
//
//  Created by rxk on 2021/9/28.
//  Copyright © 2021 Tianma. All rights reserved.
//

#import <Foundation/Foundation.h>
#define TMUserISNULLSTR(str) (str == nil || (NSObject *)str == [NSNull null] || str.length == 0)

NS_ASSUME_NONNULL_BEGIN

@interface NSString (TMUserCheck)
//校验邮箱
+(BOOL)tmuser_isEmailVerify:(NSString *)email;

//校验手机号
+(BOOL)tmuser_isValidateMobile:(NSString *)mobile;

//校验验证码
+(BOOL)tmuser_isValidateNumber:(NSString *)code;

//校验密码
+(BOOL)tmuser_isPasswordVerify:(NSString*) password;
@end

NS_ASSUME_NONNULL_END
