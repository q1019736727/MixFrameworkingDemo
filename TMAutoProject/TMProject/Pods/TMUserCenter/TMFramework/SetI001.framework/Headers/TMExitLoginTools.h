//
//  TMExitLoginTools.h
//  SetI001
//
//  Created by rxk on 2020/3/2.
//  Copyright © 2020 Tianma. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef void(^TMExitLoginComplate)(BOOL accountIsDelete, BOOL orderIsDelegate, NSString * _Nullable error);

@protocol TMExitLoginDelegate <NSObject>

- (void)tm_exitOperationLoginnWithComplate:(TMExitLoginComplate _Nullable )complate;

@end


@interface TMExitLoginTools : NSObject
@property (nonatomic, weak) id<TMExitLoginDelegate> delegate;
+ (instancetype)sharedManager;

@end

NS_ASSUME_NONNULL_END
