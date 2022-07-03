//
//  OOSService.h
//  OOS
//
//  Created by rxk on 2021/3/15.
//

#import <Foundation/Foundation.h>

//#import <OOSPutObjectRequest.h>
@class OOSPutObjectRequest;
@class OOSTask;


NS_ASSUME_NONNULL_BEGIN

typedef __nullable id(^OOSContinuationBlock)(OOSTask * task);


@interface OOSTask : NSObject
@property (nonatomic, copy) OOSContinuationBlock continuationBlock;
@property (nonatomic, strong) OOSPutObjectRequest *putObjectRequest;
@property (nonatomic, strong) NSError * error;
- (void)continueWithBlock:(OOSContinuationBlock)block;

@end


@interface OOS : NSObject
+ (instancetype)defaultOOS;

- (OOSTask *)putObject:(OOSPutObjectRequest *)request;
@end

NS_ASSUME_NONNULL_END
