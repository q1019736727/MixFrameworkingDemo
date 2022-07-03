//
//  TMCustomFontManage.h
//  TmCompDemo
//
//  Created by rxk on 2019/9/9.
//  Copyright © 2019 Tianma. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#define TMGetFont(fontSize) [UIFont systemFontOfSize:(fontSize)]
#define TMGetBoldFont(fontSize) [UIFont boldSystemFontOfSize:(fontSize)]
#define TMGetMediummFont(fontSize) [TMCustomFontManage tm_getMediummFontWithFontSize:(fontSize)]

NS_ASSUME_NONNULL_BEGIN

@interface TMCustomFontManage : NSObject

/**
 全局系统字体名称，如果值为nil则表示使用系统自带字体
 */
@property (nonatomic, copy, readonly) NSString *tmFontName;

/**
  全局系统粗字体名称，如果值为nil则表示使用系统自带粗体
 */
@property (nonatomic, copy, readonly) NSString *tmBoldFontName;

@property (nonatomic, copy, readonly) NSString *tmMediummFontName;

/**
 全局字体放大大小，默认为0
 */
@property (nonatomic, assign, readonly) CGFloat labelSize;

+ (TMCustomFontManage *)instance;


+ (UIFont *)tm_getMediummFontWithFontSize:(CGFloat)fontSize;

@end

NS_ASSUME_NONNULL_END
