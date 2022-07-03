//
//  TMWImagePickerManager.h
//  TMWebViewKitSDK
//
//  Created by rxk on 2020/5/29.
//  Copyright © 2020 Tianma. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
typedef void(^TMWImagePickerComplateBlock)(NSArray *_Nullable fileUrls, NSArray *_Nullable converImages, NSError *_Nullable error);

typedef NS_ENUM(NSUInteger, TMWImagePickerType) {
    TMWImagePickerTypeImage,
    TMWImagePickerTypeVideo,
};
/**操作类型*/
typedef NS_ENUM(NSUInteger, TMWImagePickerOperationType) {
    /**相册*/
    TMWImagePickerOperationTypePhotoAlbum,
    /**拍照*/
    TMWImagePickerOperationTypeTakePhoto,
};
NS_ASSUME_NONNULL_BEGIN

@interface TMWImagePickerManager : NSObject

+ (TMWImagePickerManager *)instance;

///needCrop：是否需要裁剪，1是，2否，mimeType为0和2或者count大于1不支持裁剪
///needCapture：是否需要录制/拍照，1需要，2不需要，不传默认为1 (需要打开相册)
///onlyCapture：只需要录制/拍照，1是，2否，不传默认2。(不需要打开相册) 优先级高于needCapture
///mimeType：文件类型，0全部，1图片，2视频
///maxCount：选择的数量，最大9，最小1，不填默认1
///customCropScale：自定义裁剪比例，以冒号分割，比例为宽高比。自定义比例的优先级高于固定比例
///cropScale：裁剪比例，0原始，1是2比3，2是3:4，3是16比9，4是1:1，5是3:2，6是4:3，7是9:16，-1是全部比例（不建议这么做）
- (void)tmw_cropImageWithisCrop:(BOOL)isCrop
                    needCapture:(BOOL)needCapture
                    onlyCapture:(BOOL)onlyCapture
                       mimeType:(NSInteger)mimeType
                       maxCount:(NSInteger)maxCount
                customCropScale:(NSString*)customCropScale
                      cropScale:(NSArray*)cropScale
                     controller:(UIViewController*)controller
                       complate:(TMWImagePickerComplateBlock)complate;



+ (void)tmw_getImageWithPickerType:(TMWImagePickerType)pickerType
                          maxCount:(int)maxCount
                      isNeedUpload:(BOOL)isNeedUpload
                          complate:(TMWImagePickerComplateBlock)complate;


+ (void)tmw_getImageWithPickerType:(TMWImagePickerType)pickerType
                          maxCount:(int)maxCount
                      isNeedUpload:(BOOL)isNeedUpload
                          isTailor:(BOOL)isTailor
                       tailorSize:(CGSize)tailorSize 
                          complate:(TMWImagePickerComplateBlock)complate;


+ (void)tmw_getImageWithPickerType:(TMWImagePickerType)pickerType
                          maxCount:(int)maxCount
              videoMaximumDuration:(NSTimeInterval)videoMaximumDuration 
                      isNeedUpload:(BOOL)isNeedUpload
                          isTailor:(BOOL)isTailor
                       tailorSize:(CGSize)tailorSize
                          complate:(TMWImagePickerComplateBlock)complate;



+ (void)tmw_getImageWithPickerType:(TMWImagePickerType)pickerType
                     operationType:(TMWImagePickerOperationType)operationType
                          maxCount:(int)maxCount
              videoMaximumDuration:(NSTimeInterval)videoMaximumDuration
                      isNeedUpload:(BOOL)isNeedUpload
                          isTailor:(BOOL)isTailor
                       tailorSize:(CGSize)tailorSize
                          complate:(TMWImagePickerComplateBlock)complate;

@end

NS_ASSUME_NONNULL_END
