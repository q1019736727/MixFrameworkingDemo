//
//  TMUser.h
//  TMShare
//
//  Created by rxk on 2018/8/10.
//  Copyright © 2018年 Tianma. All rights reserved.
//

#import <Foundation/Foundation.h>
/**
 *  性别
 */
typedef NS_ENUM(NSUInteger, TMGender)
{
    /**
     *  男
     */
    TMGenderMale      = 1,
    /**
     *  女
     */
    TMGenderFemale    = 2,
    /**
     *  未知
     */
    TMGenderUnknown   = 0,
};
@interface TMUser : NSObject

@property (nonatomic, copy) NSString *authCode;
/**
 *  平台类型()
 */
@property (nonatomic) NSInteger platformType;

/**
 *  openID
 */
@property (nonatomic, copy) NSString *openID;


/**
 *  用户标识
 */
@property (nonatomic, copy) NSString *uid;

/**
 *  昵称
 */
@property (nonatomic, copy) NSString *nickname;

/**
 *  头像
 */
@property (nonatomic, copy) NSString *icon;

/**
 *  性别
 */
@property (nonatomic) TMGender gender;

/**
 *  生日
 */
@property (nonatomic, copy) NSString *birthday;

/**
 *  地区
 */
@property (nonatomic, copy) NSString *address;

/**
 原始数据
 */
@property (nonatomic, copy) NSDictionary *rawData;

- (instancetype)initWithUserInfo:(NSDictionary *)userInfo
                        platform:(NSInteger)platform
                             uid:(NSString *)uid;
@end
