//
//  TMBaseScreen.h
//  TMComponentKitSDK
//
//  Created by rxk on 2019/11/26.
//  Copyright © 2019 Tianma. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

#define TMBase_IS_LANDSCAPE (UIInterfaceOrientationIsLandscape([[UIApplication sharedApplication] statusBarOrientation]))

#define TMBase_SCREEN_WIDTH (TMBase_IS_LANDSCAPE ? [[UIScreen mainScreen ] bounds].size.height : [[UIScreen mainScreen ] bounds].size.width)
#define TMBase_SCREEN_HEIGHT (TMBase_IS_LANDSCAPE ? [[UIScreen mainScreen ] bounds].size.width : [[UIScreen mainScreen ] bounds].size.height)

#define TMBase_IS_IPHONE_X_XR_MAX ([TMBaseScreen tmbase_isPhoneX])

#define TMBase_IS_IPHONE_X (TMBase_SCREEN_WIDTH == [TMBaseScreen tmbase_sizeFor58Inch].width && TMBase_SCREEN_HEIGHT == [TMBaseScreen tmbase_sizeFor58Inch].height)
#define TMBase_IS_IPHONE_XR (TMBase_SCREEN_WIDTH == [TMBaseScreen tmbase_sizeFor61Inch].width && TMBase_SCREEN_HEIGHT == [TMBaseScreen tmbase_sizeFor61Inch].height && [UIScreen mainScreen].scale == 2)
#define TMBase_IS_IPHONE_XMAX (TMBase_SCREEN_WIDTH == [TMBaseScreen tmbase_sizeFor65Inch].width && TMBase_SCREEN_HEIGHT == [TMBaseScreen tmbase_sizeFor65Inch].height && [UIScreen mainScreen].scale == 3)

#define TMBase_StatusBar_Height (TMBase_IS_IPHONE_X_XR_MAX ? 44 : 20)

#define TMBaseUI(x) TMBaseUIAdapter(x)
#define TMBaseUIRect(x,y,width,height) TMBaseUIRectAdapter(x,y,width,height)

static inline NSInteger TMBaseUIAdapter (float x){
    //1 - 分机型 特定的比例
    
    //2 - 屏幕宽度按比例适配
    CGFloat scale = 375 / TMBase_SCREEN_WIDTH;
    return (NSInteger)x /scale;
}

static inline CGRect TMBaseUIRectAdapter(x,y,width,height){
    return CGRectMake(TMBaseUIAdapter(x), TMBaseUIAdapter(y), TMBaseUIAdapter(width), TMBaseUIAdapter(height));
}







NS_ASSUME_NONNULL_BEGIN

@interface TMBaseScreen : NSObject
//iphone xs max
+ (CGSize)tmbase_sizeFor65Inch;

//iphone xr
+ (CGSize)tmbase_sizeFor61Inch;

// iphonex
+ (CGSize)tmbase_sizeFor58Inch;

+ (BOOL)tmbase_isPhoneX;
@end

NS_ASSUME_NONNULL_END
