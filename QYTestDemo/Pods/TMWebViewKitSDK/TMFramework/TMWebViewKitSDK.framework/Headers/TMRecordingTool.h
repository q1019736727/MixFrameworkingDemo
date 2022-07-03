
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface TMRecordingTool : NSObject

+ (void)startRecordAudio:(float)time callBack:(void(^)(NSDictionary *dic))callBack;
+ (void)stopRecordAudiocallBack:(void(^)(NSDictionary *dic))callBack;
@end

NS_ASSUME_NONNULL_END
