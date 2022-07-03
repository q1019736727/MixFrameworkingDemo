//
//  TMBWDateTool.h
//  TMBabyWarehouseSDK
//
//  Created by rxk on 2019/5/16.
//  Copyright © 2019 Tianma. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TMSDKDateModel : NSObject
@property (nonatomic, assign) NSInteger year;
@property (nonatomic, assign) NSInteger month;
@property (nonatomic, assign) NSInteger day;
@property (nonatomic, assign) NSInteger hour;
@property (nonatomic, assign) NSInteger minute;
@property (nonatomic, assign) NSInteger second;
@end


@interface TMSDKDateTool : NSObject

@property (nonatomic, assign) double serverTime;
@property (nonatomic, assign) double lastSyncLocalTime;


+ (TMSDKDateTool *)instance;
+ (double)getCurrentDate;
+ (TMSDKDateModel *)converDateWithTime:(double)time;
@end

NS_ASSUME_NONNULL_END
