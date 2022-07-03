//
//  TMCertificateConfig.h
//  SetI001
//
//  Created by rxk on 2018/12/19.
//  Copyright © 2018年 Tianma. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

//与AFSSLPinningMode对应，使用时可以直接使用，也可以强转
typedef NS_ENUM(NSUInteger, TMSSLPinningMode) {
    //与AFSSLPinningModeNone对应
    TMSSLPinningModeNone,
    //与TMSSLPinningModeCertificate对应
    TMSSLPinningModeCertificate,
};

@interface TMCertificateConfig : NSObject

/**
 是否是https请求
 */
@property (nonatomic, assign, readonly) BOOL isHttpsRequest;

/**
 https证书类型,只有AFSSLPinningModeNone和AFSSLPinningModeCertificate两种类型
 */
@property (nonatomic, assign, readonly) TMSSLPinningMode pinningMode;

/**
 https证书数据
 */
@property (nonatomic, strong, readonly) id certificateData;

/**
 https证书密码
 */
@property (nonatomic, strong, readonly) NSString *certificatePassword;

/**
 是否允许无效证书
 */
@property (nonatomic, assign, readonly) BOOL allowInvalidCertificates;

/**
 是否需要验证域名
 */
@property (nonatomic, assign, readonly) BOOL validatesDomainName;

+ (TMCertificateConfig *)instance;
@end

NS_ASSUME_NONNULL_END
