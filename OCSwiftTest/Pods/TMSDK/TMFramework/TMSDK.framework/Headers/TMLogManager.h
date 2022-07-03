//
//  TMLogManager.h
//  FCOperationalPlatform
//
//  Created by rxk on 2020/4/10.
//  Copyright © 2020 Tianma. All rights reserved.
//

#import <Foundation/Foundation.h>
#define TMLog(format,...)  [TMLogManager logWithFunction:__FUNCTION__ lineNumber:__LINE__ formatString:[NSString stringWithFormat:format, ##__VA_ARGS__]]
NS_ASSUME_NONNULL_BEGIN

@interface TMLogManager : NSObject
// Set the log output status.
+ (void)setLogEnable:(BOOL)enable;

// Gets the log output status.
+ (BOOL)getLogEnable;

// Log output method.
+ (void)logWithFunction:(const char *)function lineNumber:(int)lineNumber formatString:(NSString *)formatString;
@end

NS_ASSUME_NONNULL_END
