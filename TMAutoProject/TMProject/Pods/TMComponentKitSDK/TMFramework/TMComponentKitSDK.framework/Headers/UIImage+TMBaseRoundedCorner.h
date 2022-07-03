//
//  UIImage+TMBaseRoundedCorner.h
//  TMOperationalComplexSDK
//
//  Created by rxk on 2019/10/29.
//  Copyright © 2019 Tianma. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@interface UIImage (TMBaseRoundedCorner)
- (UIImage *)tmbase_roundedCornerImage:(NSInteger)cornerSize borderSize:(NSInteger)borderSize;

@end

NS_ASSUME_NONNULL_END
