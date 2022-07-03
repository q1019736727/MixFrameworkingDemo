//
//  UIColor+TMColor.h
//  TMComponentKitSDK
//
//  Created by rxk on 2019/4/11.
//  Copyright © 2019 Tianma. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIColor (TMColor)
+ (UIColor *)tm_colorWithHexString:(NSString *)color;
+ (UIColor *)tm_colorWithHexString:(NSString *)color alpha:(CGFloat)alpha;
@end

NS_ASSUME_NONNULL_END
