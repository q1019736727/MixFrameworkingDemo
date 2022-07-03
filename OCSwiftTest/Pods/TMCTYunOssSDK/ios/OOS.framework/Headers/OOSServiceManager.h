//
//  OOSServiceManager.h
//  OOS
//
//  Created by rxk on 2021/3/15.
//

#import <Foundation/Foundation.h>
@class OOSServiceConfiguration;
NS_ASSUME_NONNULL_BEGIN

@interface OOSServiceManager : NSObject
+ (instancetype)defaultServiceManager;
@property (nonatomic, copy) OOSServiceConfiguration *defaultServiceConfiguration;
@end

NS_ASSUME_NONNULL_END
