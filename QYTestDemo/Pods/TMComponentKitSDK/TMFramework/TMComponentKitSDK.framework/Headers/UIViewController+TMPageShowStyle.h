//
//  UIViewController+TMPageShowStyle.h
//  TMComponentKitSDK
//
//  Created by rxk on 2021/7/1.
//  Copyright © 2021 Tianma. All rights reserved.
//

#import <UIKit/UIKit.h>


typedef void(^TMRetryBlock)(void);
typedef void (^TMPageShowViewDismissCompletion)(void);

typedef NS_ENUM(NSUInteger, TMPageShowStyle) {
    TMPageShowStyleNoContent,
    TMPageShowStyleLoadFailure,
    TMPageShowStyleLoading,
};


NS_ASSUME_NONNULL_BEGIN

@interface TMPageShowStyleView : UIControl
@property (nonatomic, strong) UIImageView *imageView;
@property (nonatomic, strong) UILabel *titleLabel;
@property (nonatomic, strong) UILabel *descriptionLabel;

@end

@interface UIViewController (TMPageShowStyle)
- (void)tm_showStyleLoading;
- (void)tm_showStyleNoContentWithShowTitle:(NSString *)showTitle;
- (void)tm_showStyleFailureWithShowTitle:(NSString *)showTitle
                              retryBlock:(TMRetryBlock _Nullable)retryBlock;


- (void)tm_dismissStyle;
- (void)tm_dismissStyleWithCompletion:(nullable TMPageShowViewDismissCompletion)completion;
- (void)tm_dismissStyleWithDelay:(NSTimeInterval)delay;
- (void)tm_dismissStyleWithDelay:(NSTimeInterval)delay completion:(nullable TMPageShowViewDismissCompletion)completion;
@end

NS_ASSUME_NONNULL_END
