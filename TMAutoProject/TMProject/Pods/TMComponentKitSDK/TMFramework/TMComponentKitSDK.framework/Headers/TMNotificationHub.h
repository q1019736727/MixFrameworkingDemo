//
//  TMNotificationHub.h
//  TMComponentKitSDK
//
//  Created by rxk on 2019/4/11.
//  Copyright © 2019 Tianma. All rights reserved.
//


#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

/**
 *  The default diameter of the notification hub view.
 */
FOUNDATION_EXPORT CGFloat const TMNotificationHubDefaultDiameter;

@interface TMNotificationHub : NSObject

//%%% setup
- (id)initWithView:(UIView *)view;
- (id)initWithBarButtonItem:(UIBarButtonItem *)barButtonItem;

//%%% adjustment methods
- (void)setView:(UIView *)view andCount:(int)startCount;
- (void)setCircleAtFrame:(CGRect)frame;
- (void)setCircleColor:(UIColor*)circleColor labelColor:(UIColor*)labelColor;
- (void)setCircleBorderColor:(UIColor *)color borderWidth:(CGFloat)width;
- (void)moveCircleByX:(CGFloat)x Y:(CGFloat)y;
- (void)scaleCircleSizeBy:(CGFloat)scale;
@property (nonatomic, strong) UIFont *countLabelFont;

//%%% changing the count
- (void)increment;
- (void)incrementBy:(int)amount;
- (void)decrement;
- (void)decrementBy:(int)amount;
@property (nonatomic, assign) int count;
@property (nonatomic, assign) int maxCount;

//%%% hiding / showing the count
- (void)hideCount;
- (void)showCount;

//%%% animations
- (void)pop;
- (void)blink;
- (void)bump;

@property (nonatomic)UIView *hubView;

@end
