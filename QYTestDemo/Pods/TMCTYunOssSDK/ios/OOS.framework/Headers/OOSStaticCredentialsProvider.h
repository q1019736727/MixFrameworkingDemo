//
//  OOSStaticCredentialsProvider.h
//  OOS
//
//  Created by rxk on 2021/3/15.
//

#import <Foundation/Foundation.h>
@class AWSServiceConfiguration;

typedef NS_ENUM(NSInteger, OOSRegionType) {
    /**
     *  Unknown Region
     */
    OOSRegionUnknown NS_SWIFT_NAME(Unknown),
    /**
     *  杭州
     */
    OOSRegionHangZhou NS_SWIFT_NAME(HangZhou),
    /**
     *  江苏
     */
    OOSRegionJiangShu NS_SWIFT_NAME(JiangShu),
    /**
     *  长沙
     */
    OOSRegionChangSha NS_SWIFT_NAME(ChangSha),
    /**
     *  广州
     */
    OOSRegionGuangZhou NS_SWIFT_NAME(GuangZhou),
    /**
     *  西安
     */
    OOSRegionXiAn NS_SWIFT_NAME(XiAn),
    /**
     *  北京2
     */
    OOSRegionBeiJing2 NS_SWIFT_NAME(Beijing2),
    /**
     *  内蒙
     */
    OOSRegionNeiMeng NS_SWIFT_NAME(NeiMeng),
    /**
     *  内蒙2
     */
    OOSRegionNeiMeng2 NS_SWIFT_NAME(NeiMeng2),
    /**
     *  上海高品质
     */
    OOSRegionShangHaiHQ NS_SWIFT_NAME(ShangHaiHQ),
    /**
     *  北京高品质
     */
    OOSRegionBeiJingHQ NS_SWIFT_NAME(BeiJingHQ),
    
    /**
     *  福建
     */
    OOSRegionFuJian NS_SWIFT_NAME(FuJian),
    /**
     *  福建2
     */
    OOSRegionFuJian2 NS_SWIFT_NAME(FuJian2),
    /**
     *  郑州
     */
    OOSRegionZhengZhou NS_SWIFT_NAME(ZhengZhou),
    /**
     *  沈阳
     */
    OOSRegionShenYang NS_SWIFT_NAME(ShenYang),
    /**
     *  石家庄
     */
    OOSRegionShiJiaZhuang NS_SWIFT_NAME(ShiJiaZhuang),
    /**
     *  浙江金华
     */
    OOSRegionJinHua NS_SWIFT_NAME(JinHua),
    /**
     *  成都
     */
    OOSRegionChengDu NS_SWIFT_NAME(ChengDu),
    /**
     *  乌鲁木齐
     */
    OOSRegionWuLuMuQi NS_SWIFT_NAME(WuLuMuQi),
    /**
     *  甘肃兰州
     */
    OOSRegionGanShuLanZhou NS_SWIFT_NAME(GanShuLanZhou),
    /**
     *  山东青岛
     */
    OOSRegionShanDongQingDao NS_SWIFT_NAME(ShanDongQingDao),
    /**
     *  贵州贵阳
     */
    OOSRegionGuiZhouGuiYang NS_SWIFT_NAME(GuiZhouGuiYang),
    /**
     *  湖北武汉
     */
    OOSRegionHuBeiWuHan NS_SWIFT_NAME(HuBeiWuHan),
    /**
     *  西藏拉萨
     */
    OOSRegionXiZangLaSa NS_SWIFT_NAME(XiZangLaSa),
    /**
     *  安徽芜湖
     */
    OOSRegionAnHuiWuHu NS_SWIFT_NAME(AnHuiWuHu),
    
};



NS_ASSUME_NONNULL_BEGIN

@protocol OOSCredentialsProvider <NSObject>

@end


@interface OOSStaticCredentialsProvider : NSObject<OOSCredentialsProvider>
@property (nonatomic, strong) NSString *accessKey;
@property (nonatomic, strong) NSString *secretKey;

- (instancetype)initWithAccessKey:(NSString *)accessKey
                        secretKey:(NSString *)secretKey;
@end



@interface OOSEndpoint : NSObject
@property (nonatomic, strong) NSURL *url;
@property (nonatomic, assign) OOSRegionType regionType;
- (instancetype)initWithRegion:(OOSRegionType)regionType
                           URL:(NSURL *)URL;
@end



@interface OOSServiceConfiguration : NSObject<NSCopying>

@property (nonatomic, assign) uint32_t maxRetryCount;
@property (nonatomic, assign) NSTimeInterval timeoutIntervalForRequest;

@property (nonatomic, strong) AWSServiceConfiguration * awsConfiguration;

- (instancetype)initWithRegion:(NSInteger)regionType
                      endpoint:(OOSEndpoint *)endpoint
           credentialsProvider:(id<OOSCredentialsProvider>)credentialsProvider;
@end

NS_ASSUME_NONNULL_END
