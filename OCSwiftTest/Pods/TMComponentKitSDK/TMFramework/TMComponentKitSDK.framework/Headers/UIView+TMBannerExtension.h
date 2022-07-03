//
//  UIView+TMBannerExtension.h
//  TMRefreshView
//

#import <UIKit/UIKit.h>

#define TMColorCreater(r, g, b, a) [UIColor colorWithRed:(r / 255.0) green:(g / 255.0) blue:(b / 255.0) alpha:a]


@interface UIView (TMBannerExtension)

@property (nonatomic, assign) CGFloat tm_height;
@property (nonatomic, assign) CGFloat tm_width;

@property (nonatomic, assign) CGFloat tm_y;
@property (nonatomic, assign) CGFloat tm_x;

@end
