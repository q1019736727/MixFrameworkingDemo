//
//  TMLocationManage.h
//  Cordova
//
//  Created by rxk on 2019/8/5.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
@class TMLocationReGeocode;
typedef void(^TMLocationComplate)(TMLocationReGeocode * _Nullable regeocode, NSError *_Nullable error);


NS_ASSUME_NONNULL_BEGIN

@interface TMLocationReGeocode : NSObject

///格式化地址
@property (nonatomic, copy) NSString *formattedAddress;

///国家
@property (nonatomic, copy) NSString *country;

///省/直辖市
@property (nonatomic, copy) NSString *province;

///市
@property (nonatomic, copy) NSString *city;

///区
@property (nonatomic, copy) NSString *district;


///城市编码
@property (nonatomic, copy) NSString *citycode;

///区域编码
@property (nonatomic, copy) NSString *adcode;

///街道名称
@property (nonatomic, copy) NSString *street;

///门牌号
@property (nonatomic, copy) NSString *number;

///兴趣点名称
@property (nonatomic, copy) NSString *POIName;

///所属兴趣点名称
@property (nonatomic, copy) NSString *AOIName;

///纬度
@property (nonatomic, assign) CGFloat latitude;

///经度
@property (nonatomic, assign) CGFloat longitude;

@end




@interface TMLocationManage : NSObject
+ (TMLocationManage *)instance;

- (void)tm_startRealLocationWithComplate:(TMLocationComplate)complate;
@end

NS_ASSUME_NONNULL_END
