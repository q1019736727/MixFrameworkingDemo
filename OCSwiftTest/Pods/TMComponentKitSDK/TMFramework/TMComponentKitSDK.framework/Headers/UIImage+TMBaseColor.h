//
//  UIImage+TMBaseColor.h
//  TMOperationalComplexSDK
//
//  Created by rxk on 2019/10/29.
//  Copyright © 2019 Tianma. All rights reserved.
//



#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (TMBaseColor)
/**
 *  @brief  改变图片颜色
 *
 *  @param img 图片
 **
 *  @param color 颜色
 *
 *  @return 被改变颜色后的图片
 */
+ (UIImage *)tmbase_changeImage:(UIImage *)img withColor:(UIColor *)color;

/**
 *  @brief  改变图片颜色
 *
 *  @param imageName 图片名称
 **
 *  @param color 颜色
 *
 *  @return 被改变颜色后的图片
 */
+ (UIImage *)tmbase_changeImageName:(NSString *)imageName withColor:(UIColor *)color;

/**
 *  @brief  根据颜色生成纯色图片
 *
 *  @param color 颜色
 *
 *  @return 纯色图片
 */
+ (UIImage *)tmbase_imageWithColor:(UIColor *)color;
/**
 *  @brief  取图片某一点的颜色
 *
 *  @param point 某一点
 *
 *  @return 颜色
 */
- (UIColor *)tmbase_colorAtPoint:(CGPoint )point;
//more accurate method ,colorAtPixel 1x1 pixel
/**
 *  @brief  取某一像素的颜色
 *
 *  @param point 一像素
 *
 *  @return 颜色
 */
- (UIColor *)tmbase_colorAtPixel:(CGPoint)point;
/**
 *  @brief  返回该图片是否有透明度通道
 *
 *  @return 是否有透明度通道
 */
- (BOOL)tmbase_hasAlphaChannel;

/**
 *  @brief  获得灰度图
 *
 *  @param sourceImage 图片
 *
 *  @return 获得灰度图片
 */
+ (UIImage*)tmbase_covertToGrayImageFromImage:(UIImage*)sourceImage;
@end

NS_ASSUME_NONNULL_END
