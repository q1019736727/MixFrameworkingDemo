//
//  TMShareSDKModel.h
//  TMShare
//
//  Created by rxk on 2019/9/29.
//  Copyright © 2019 Tianma. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
NS_ASSUME_NONNULL_BEGIN

//分享类型
typedef NS_ENUM(NSUInteger, TMShareSDKShareType) {
//    纯文本分享
    TMShareSDKShareTypeText,
//    图片类分享
    TMShareSDKShareTypeImage,
//    视频类分享
    TMShareSDKShareTypeVideo,
//    音频类分享
    TMShareSDKShareTypeAudio,
//    新闻类分享
    TMShareSDKShareTypeNews,
//    其他类型
    TMShareSDKShareTypeOther
};

@interface TMShareSDKModel : NSObject

/**
 分享的标题
 */
@property (nonatomic, copy) NSString *share_title;

/**
 分享的内容
 */
@property (nonatomic, copy) NSString *share_content;

/**
 分享的跳转链接
 */
@property (nonatomic, copy) NSString *share_url;

/**
 分享的图片链接
 */
@property (nonatomic, copy) NSString *share_image_url;

/**
 分享的图片对象,注意：分享图片大小不能超过64K，需要处理一下
 */
@property (nonatomic, strong) UIImage * _Nullable share_image;

@property (nonatomic, assign) TMShareSDKShareType shareType;

+ (instancetype)tmshare_setupWithTitle:(NSString *)title content:(NSString *)content url:(NSString *)url image:(id)image;

@end

NS_ASSUME_NONNULL_END
