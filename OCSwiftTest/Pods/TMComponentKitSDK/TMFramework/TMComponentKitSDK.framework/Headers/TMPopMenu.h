//
//  TMPopMenu.h
//  TMPopMenuDemo
//
//  Created by iDog on 2019/1/28.
//  Copyright © 2019 iDog. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "TMPopMenuView.h"
#import "TMPopMenuItem.h"
NS_ASSUME_NONNULL_BEGIN


@interface TMPopMenu : NSObject

+ (void)showMenuInView:(UIView *)view fromRect:(CGRect)rect menuItems:(NSArray <TMPopMenuItem *> *)menuItems;

+ (void)dismissMenuAnimated:(BOOL)animated;

@end

NS_ASSUME_NONNULL_END
