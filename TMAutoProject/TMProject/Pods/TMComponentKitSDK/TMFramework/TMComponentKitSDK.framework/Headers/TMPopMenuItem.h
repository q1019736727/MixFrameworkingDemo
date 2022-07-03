//
//  TMPopMenuItem.h
//  TMPopMenuDemo
//
//  Created by iDog on 2019/1/28.
//  Copyright © 2019 iDog. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN

typedef void(^TMPopMenuItemHandler)(NSInteger index);

@interface TMPopMenuItem : NSObject

@property (readwrite, nonatomic, strong) UIImage *image;
@property (readwrite, nonatomic, strong) NSString *title;
@property (nonatomic, strong) NSString *des;
@property (nonatomic, copy)  TMPopMenuItemHandler handler;

+ (instancetype) menuItem:(NSString *) title
                    image:(UIImage *) image
                      des:( NSString * _Nullable )des
                   handler:(TMPopMenuItemHandler) handler;

@end

NS_ASSUME_NONNULL_END
