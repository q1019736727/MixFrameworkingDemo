//
//  TMBaseTimerService.h
//  TMBabyWarehouseSDK
//
//  Created by rxk on 2019/5/17.
//  Copyright © 2019 Tianma. All rights reserved.
//

#import <Foundation/Foundation.h>
@class TMBaseTimerService;
NS_ASSUME_NONNULL_BEGIN
@protocol TMBaseTimerListener <NSObject>
@required
- (void)didOnTimer:(TMBaseTimerService * _Nullable )timer;
@end

@interface TMBaseTimerService : NSObject
+ (instancetype)sharedInstance;
- (void)addListener:(id<TMBaseTimerListener>)listener;
- (void)removeListener:(id<TMBaseTimerListener>)listener;
@end

NS_ASSUME_NONNULL_END
