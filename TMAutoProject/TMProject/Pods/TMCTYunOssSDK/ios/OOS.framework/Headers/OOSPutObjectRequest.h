//
//  OOSPutObjectRequest.h
//  OOS
//
//  Created by rxk on 2021/3/15.
//

#import <Foundation/Foundation.h>

typedef void (^OOSNetworkingUploadProgressBlock) (int64_t bytesSent, int64_t totalBytesSent, int64_t totalBytesExpectedToSend);
typedef NS_ENUM(NSInteger, OOSObjectCannedACL) {
    OOSObjectCannedACLUnknown,
    OOSObjectCannedACLPrivate,
    OOSObjectCannedACLPublicRead,
    OOSObjectCannedACLPublicReadWrite,
    OOSObjectCannedACLAuthenticatedRead,
    OOSObjectCannedACLOOSExecRead,
    OOSObjectCannedACLBucketOwnerRead,
    OOSObjectCannedACLBucketOwnerFullControl,
};
NS_ASSUME_NONNULL_BEGIN

@interface OOSPutObjectRequest : NSObject
@property (nonatomic, assign) OOSObjectCannedACL ACL;

/**
 Object data.
 */
@property (nonatomic, strong) id _Nullable body;

/**
 Name of the bucket to which the PUT operation was initiated.
 */
@property (nonatomic, strong) NSString * _Nullable bucket;
@property (nonatomic, strong) NSString * _Nullable key;
@property (nonatomic, strong) NSNumber * _Nullable contentLength;
@property (nonatomic, strong) NSDate * _Nullable expires;
@property (nonatomic, copy) OOSNetworkingUploadProgressBlock uploadProgress;
@end

NS_ASSUME_NONNULL_END
