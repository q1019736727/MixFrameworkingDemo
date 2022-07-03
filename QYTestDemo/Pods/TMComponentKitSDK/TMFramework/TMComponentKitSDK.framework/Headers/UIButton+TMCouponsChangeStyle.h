//
//  UIButton+TMCouponsChangeStyle.h
//  TMCouponsSDK
//
//  Created by rxk on 2019/3/4.
//  Copyright © 2019 Tianma. All rights reserved.
//

#import <UIKit/UIKit.h>
///图片文字显示位置
typedef NS_ENUM(NSInteger, imageStyleStyle) {
    
    ///图片左 文字右
    imageStyleStyleLeft    = 0,
    ///图片右 文字左
    imageStyleStyleRight   = 1,
    ///图片上 文字下
    imageStyleStyleTop     = 2,
    ///图片下 文字上
    imageStyleStyleBottom  = 3
};

NS_ASSUME_NONNULL_BEGIN

@interface UIButton (TMCouponsChangeStyle)
- (void)changePosition:(imageStyleStyle)style space:(CGFloat)space;
@end

NS_ASSUME_NONNULL_END
