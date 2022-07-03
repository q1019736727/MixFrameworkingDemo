//
//  UIImage+TMBaseAlpha.h
//  TMOperationalComplexSDK
//
//  Created by rxk on 2019/10/29.
//  Copyright © 2019 Tianma. All rights reserved.
//


#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (TMBaseAlpha)
/**
 *  @brief  是否有alpha通道
 *
 *  @return 是否有alpha通道
 */
- (BOOL)tmbase_hasAlpha;
/**
 *  @brief  如果没有alpha通道 增加alpha通道
 *
 *  @return 如果没有alpha通道 增加alpha通道
 */
- (UIImage *)tmbase_imageWithAlpha;
/**
 *  @brief  增加透明边框
 *
 *  @param borderSize 边框尺寸
 *
 *  @return 增加透明边框后的图片
 */
- (UIImage *)tmbase_transparentBorderImage:(NSUInteger)borderSize;


/**
 *  @brief  裁切含透明图片为最小大小
 *
 *  @return 裁切后的图片
 */
- (UIImage *)tmbase_trimmedBetterSize;
@end

NS_ASSUME_NONNULL_END
