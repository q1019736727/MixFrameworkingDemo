//
//  TMUserPushManage.h
//  SetI001
//
//  Created by rxk on 2020/6/10.
//  Copyright © 2020 Tianma. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TMUserPushManage : NSObject
+ (void)tmuser_closePush;
+ (void)tm_userAddPushTagWithTag:(NSString *)tag;
+ (void)tm_userRemovePushTagWithTag:(NSString *)tag;
@end

NS_ASSUME_NONNULL_END
