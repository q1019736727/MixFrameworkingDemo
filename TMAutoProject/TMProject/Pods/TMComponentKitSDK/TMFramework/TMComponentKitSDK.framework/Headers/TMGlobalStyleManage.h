//
//  TMGlobalStyleManage.h
//  TMComponentKitSDK
//
//  Created by rxk on 2021/7/1.
//  Copyright © 2021 Tianma. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

@interface TMGlobalStyleManage : NSObject
/**
 是否自动启用风格样式，默认启用
 */
@property (nonatomic, assign) BOOL isAutoEnable;
/**上拉加载图片数组*/
@property (nonatomic, strong) NSArray *upLoadImages;
/**上下拉加载图片数组*/
@property (nonatomic, strong) NSArray *downRefreshImages;

/**页面无内容时的图片,  为NSData或者NSString类型*/
@property (nonatomic, strong) id noContentImage;
@property (nonatomic, assign) CGSize noContentImageSize;

/**页面加载失败时的图片,  为NSData或者NSString类型*/
@property (nonatomic, strong) id failureImage;
@property (nonatomic, assign) CGSize failureImageSize;

/**H5加载图片,  为NSData或者NSString类型*/
@property (nonatomic, strong) id h5LoadingImage;
@property (nonatomic, assign) CGSize h5LoadingImageSize;

/**页面加载中的图片,  为NSData或者NSString类型*/
@property (nonatomic, strong) id loadingImage;
@property (nonatomic, assign) CGSize loadingImageSize;

/**默认加载图*/
@property (nonatomic, strong) UIImage *placeholdImage;
/**默认图背景颜色*/
@property (nonatomic, strong) UIColor *placeholdImageBackgroundColor;

/**默认头像*/
@property (nonatomic, strong) NSString *defaultAvatarUrl;
@property (nonatomic, strong) UIImage *defaultAvatarImage;


+ (TMGlobalStyleManage *)instance;

@end

NS_ASSUME_NONNULL_END
