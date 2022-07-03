//
//  TMWVKQrCodeScanController.h
//  TMWebViewKitDemo
//
//  Created by rxk on 2020/7/15.
//  Copyright © 2020 Tianma. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN


@interface TMWVKQrCodeScanController : UIViewController
@property (nonatomic, copy) void(^tm_scranComplate)(NSString *result);
@end

NS_ASSUME_NONNULL_END
