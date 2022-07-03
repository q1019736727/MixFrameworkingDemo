//
//  TMMapNavigationManager.h
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import <MapKit/MapKit.h>

/**导航类型*/
typedef NS_ENUM(NSUInteger, TMMapNavigationType) {
    /**未知导航*/
    TMMapNavigationTypeUnknow,
    /**高德导航*/
    TMMapNavigationTypeGaoDe,
    /**百度导航*/
    TMMapNavigationTypeBaidu,
    /**苹果导航*/
    TMMapNavigationTypeApple,
};

/**导航完成状态*/
typedef NS_ENUM(NSUInteger, TMMapNavigationComplateStatus) {
    /**成功*/
    TMMapNavigationComplateStatusSuccess,
    /**没有导航选项*/
    TMMapNavigationComplateStatusUnNavigationItem,
    /**失败*/
    TMMapNavigationComplateStatusFail,
    /**取消*/
    TMMapNavigationComplateStatusCancel,
};

/**导航坐标系*/
typedef NS_ENUM(NSUInteger, TMMapNavigationCoordType) {
    /**百度坐标系*/
    TMMapNavigationCoordTypeBD09,
    /**GCJ02坐标系：苹果自带定位、高德定位*/
    TMMapNavigationCoordTypeGCJ02,
    /**WGS84：GPS定位，国内不允许用*/
    TMMapNavigationCoordTypeWGS84,
};


NS_ASSUME_NONNULL_BEGIN
/*!
 * @brief 导航完成结果回调
 */
typedef void (^TMMapNavigationCompelitionBlock)(TMMapNavigationComplateStatus status, TMMapNavigationType navigationType, NSString *message);

@interface TMMapNavigationManager : NSObject
/**
 *  @brief  导航控制器
 *
 *  @return 返回导航控制器
 */
+ (instancetype)share;

- (void)showNavigationActionWithCoordType:(TMMapNavigationCoordType)coordType
                               originName:(NSString *_Nullable)originName
                         originCoordinate:(CLLocationCoordinate2D)originCoordinate
                          destinationName:(NSString *)destinationName
                    destinationCoordinate:(CLLocationCoordinate2D)destinationCoordinate
                    completion:(TMMapNavigationCompelitionBlock)completion ;
@end
NS_ASSUME_NONNULL_END
