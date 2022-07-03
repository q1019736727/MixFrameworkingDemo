//
//  TMWebViewKitPlugin.h
//  TMWebViewKitSDK
//
//  Created by rxk on 2020/5/29.
//  Copyright © 2020 Tianma. All rights reserved.
//

#import <TMSDK/TMSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface TMWebViewKitPlugin : CDVPlugin
- (void)tm_uploadImageOrVideo:(CDVInvokedUrlCommand *)command;
- (void)tm_hideLoadingView:(CDVInvokedUrlCommand *)command;
@end

NS_ASSUME_NONNULL_END
