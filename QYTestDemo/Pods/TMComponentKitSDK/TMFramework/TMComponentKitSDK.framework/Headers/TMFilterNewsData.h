//
//  TMFilterNewsData.h
//  TMBaseSDK
//
//  Created by rxk on 2019/4/9.
//  Copyright © 2019 Tianma. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TMFilterNewsData : NSObject
+ (void)tm_addFilterDataWithClassName:(NSString *)className newsID:(NSString *)newsID;

+ (void)tm_addFilterDataWithClassName:(NSString *)className userID:(NSString *)userID;


+ (NSArray *)tm_filterDataWithClassName:(NSString *)className newsData:(NSArray *)newsData key:(NSString *)key;

+ (NSArray *)tm_filterDataWithClassName:(NSString *)className newsData:(NSArray *)newsData key:(NSString *)key userKey:(NSString *)userKey;

@end

NS_ASSUME_NONNULL_END
