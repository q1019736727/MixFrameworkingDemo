//
//  TMToast.h
//  TMSDK
//
//  Created by lqkj on 16/5/16.
//  Copyright © 2016年 Harvey. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

@interface TMToastManage : NSObject


@end


@interface TMToast : NSObject

#pragma mark - 中间显示
/**
 *  中间显示
 *
 *  @param text 显示内容， 可以是NSString类型，  也可以是NSAttributedString富文本类型
 */
+ (void)tm_ShowCenterWithText:(id)text;

/**
 *  中间显示内容和更多按钮
 *
 *  @param text 显示内容， 可以是NSString类型，  也可以是NSAttributedString富文本类型
 *
 *  @param moreButtonText 更多按钮， 可以是NSString类型，  也可以是NSAttributedString富文本类型
 */
+ (void)tm_ShowCenterWithText:(id)text moreButtonText:(id)moreButtonText moreButtonClickEvent:(void (^)(void))moreButtonClickEvent;


/**
 *  中间显示+自定义停留时间
 *
 *  @param text     内容
 *  @param duration 停留时间
 */
+ (void)tm_ShowCenterWithText:(id)text duration:(CGFloat)duration;
/**
 *  中间显示+自定义停留时间
 *
 *  @param text     内容
 *  @param moreButtonText 更多按钮， 可以是NSString类型，  也可以是NSAttributedString富文本类型
 *  @param duration 停留时间
 */
+ (void)tm_ShowCenterWithText:(id)text moreButtonText:(id)moreButtonText duration:(CGFloat)duration moreButtonClickEvent:(void (^)(void))moreButtonClickEvent;

#pragma mark - 上方显示
/**
 *  上方显示
 *
 *  @param text 显示内容， 可以是NSString类型，  也可以是NSAttributedString富文本类型
 */
+ (void)tm_ShowTopWithText:(id)text;
/**
 *  顶部显示内容和更多按钮
 *
 *  @param text 显示内容， 可以是NSString类型，  也可以是NSAttributedString富文本类型
 *
 *  @param moreButtonText 更多按钮， 可以是NSString类型，  也可以是NSAttributedString富文本类型
 */
+ (void)tm_ShowTopWithText:(id)text moreButtonText:(id)moreButtonText moreButtonClickEvent:(void (^)(void))moreButtonClickEvent;


/**
 *  上方显示+自定义停留时间
 *
 *  @param text     text 显示内容， 可以是NSString类型，  也可以是NSAttributedString富文本类型
 *  @param duration 停留时间
 */
+ (void)tm_ShowTopWithText:(id)text duration:(CGFloat)duration;
/**
 *  顶部显示+自定义停留时间
 *
 *  @param text     内容
 *  @param moreButtonText 更多按钮， 可以是NSString类型，  也可以是NSAttributedString富文本类型
 *  @param duration 停留时间
 */
+ (void)tm_ShowTopWithText:(id)text moreButtonText:(id)moreButtonText duration:(CGFloat)duration moreButtonClickEvent:(void (^)(void))moreButtonClickEvent;

/**
 *  上方显示+自定义距顶端距离
 *
 *  @param text      text 显示内容， 可以是NSString类型，  也可以是NSAttributedString富文本类型
 *  @param topOffset 到顶端距离
 */
+ (void)tm_ShowTopWithText:(id)text topOffset:(CGFloat)topOffset;

/**
 *  上方显示+更多按钮+自定义距顶端距离
 *
 *  @param text      text 显示内容， 可以是NSString类型，  也可以是NSAttributedString富文本类型
 *  @param moreButtonText 更多按钮， 可以是NSString类型，  也可以是NSAttributedString富文本类型
 *  @param topOffset 到顶端距离
 *
 */
+ (void)tm_ShowTopWithText:(id)text moreButtonText:(id)moreButtonText topOffset:(CGFloat)topOffset moreButtonClickEvent:(void (^)(void))moreButtonClickEvent;

/**
 *  上方显示+自定义距顶端距离+自定义停留时间
 *
 *  @param text      text 显示内容， 可以是NSString类型，  也可以是NSAttributedString富文本类型
 *  @param topOffset 到顶端距离
 *  @param duration  停留时间
 */
+ (void)tm_ShowTopWithText:(id)text topOffset:(CGFloat)topOffset duration:(CGFloat)duration;

/**
 *  上方显示+更多按钮+自定义距顶端距离+自定义停留时间
 *
 *  @param text      text 显示内容， 可以是NSString类型，  也可以是NSAttributedString富文本类型
 *  @param moreButtonText 更多按钮， 可以是NSString类型，  也可以是NSAttributedString富文本类型
 *  @param topOffset 到顶端距离
 *  @param duration  停留时间
 */
+ (void)tm_ShowTopWithText:(id)text moreButtonText:(id)moreButtonText topOffset:(CGFloat)topOffset duration:(CGFloat)duration moreButtonClickEvent:(void (^)(void))moreButtonClickEvent;


#pragma mark - 下方显示
/**
 *  下方显示
 *
 *  @param text text 显示内容， 可以是NSString类型，  也可以是NSAttributedString富文本类型
 */
+ (void)tm_ShowBottomWithText:(id)text;
/**
 *  下方显示 + 更多按钮
 *
 *  @param text text 显示内容， 可以是NSString类型，  也可以是NSAttributedString富文本类型
 *  @param moreButtonText 更多按钮， 可以是NSString类型，  也可以是NSAttributedString富文本类型
 */
+ (void)tm_ShowBottomWithText:(id)text moreButtonText:(id)moreButtonText moreButtonClickEvent:(void (^)(void))moreButtonClickEvent;
/**
 *  下方显示+自定义停留时间
 *
 *  @param text     text 显示内容， 可以是NSString类型，  也可以是NSAttributedString富文本类型
 *  @param duration 停留时间
 */
+ (void)tm_ShowBottomWithText:(id)text duration:(CGFloat)duration;
/**
 *  下方显示+自定义停留时间
 *
 *  @param text     text 显示内容， 可以是NSString类型，  也可以是NSAttributedString富文本类型
 *  @param moreButtonText 更多按钮， 可以是NSString类型，  也可以是NSAttributedString富文本类型
 *  @param duration 停留时间
 */
+ (void)tm_ShowBottomWithText:(id)text moreButtonText:(id)moreButtonText duration:(CGFloat)duration moreButtonClickEvent:(void (^)(void))moreButtonClickEvent;
/**
 *  下方显示+自定义距底端距离
 *
 *  @param text         text 显示内容， 可以是NSString类型，  也可以是NSAttributedString富文本类型
 *  @param bottomOffset 距底端距离
 */
+ (void)tm_ShowBottomWithText:(id)text bottomOffset:(CGFloat)bottomOffset;
/**
 *  下方显示+自定义距底端距离
 *
 *  @param text         text 显示内容， 可以是NSString类型，  也可以是NSAttributedString富文本类型
 *  @param moreButtonText 更多按钮， 可以是NSString类型，  也可以是NSAttributedString富文本类型
 *  @param bottomOffset 距底端距离
 */
+ (void)tm_ShowBottomWithText:(id)text moreButtonText:(id)moreButtonText bottomOffset:(CGFloat)bottomOffset moreButtonClickEvent:(void (^)(void))moreButtonClickEvent;
/**
 *  下方显示+自定义距底端距离+自定义停留时间
 *
 *  @param text        text 显示内容， 可以是NSString类型，  也可以是NSAttributedString富文本类型
 *  @param bottomOffset 距底端距离
 *  @param duration     停留时间
 */
+ (void)tm_ShowBottomWithText:(id)text bottomOffset:(CGFloat)bottomOffset duration:(CGFloat)duration;
/**
 *  下方显示+自定义距底端距离+自定义停留时间
 *
 *  @param text        text 显示内容， 可以是NSString类型，  也可以是NSAttributedString富文本类型
 *  @param moreButtonText 更多按钮， 可以是NSString类型，  也可以是NSAttributedString富文本类型
 *  @param bottomOffset 距底端距离
 *  @param duration     停留时间
 */
+ (void)tm_ShowBottomWithText:(id)text moreButtonText:(id)moreButtonText bottomOffset:(CGFloat)bottomOffset duration:(CGFloat)duration moreButtonClickEvent:(void (^)(void))moreButtonClickEvent;


@end
