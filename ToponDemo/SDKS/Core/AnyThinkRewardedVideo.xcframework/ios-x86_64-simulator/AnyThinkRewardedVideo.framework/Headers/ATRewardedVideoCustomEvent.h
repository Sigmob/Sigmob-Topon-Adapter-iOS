//
//  ATRewardedVideoCustomEvent.h
//  AnyThinkSDK
//
//  Created by Martin Lau on 05/07/2018.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

#import <AnyThinkSDK/AnyThinkSDK.h>
//#import "ATAdCustomEvent.h"
#import "ATRewardedVideoDelegate.h"
#import "ATRewardedVideo.h"

NS_ASSUME_NONNULL_BEGIN

@interface ATRewardedVideoCustomEvent : ATAdCustomEvent

/// callback to developer when play failed
/// @param error - play error message
- (void)trackRewardedVideoAdPlayEventWithError:(NSError *)error;

/// callback to developer when ad is closed
/// @param rewarded - reward or not
- (void)trackRewardedVideoAdCloseRewarded:(BOOL)rewarded __attribute__((deprecated("Deprecated, please Use `trackRewardedVideoAdCloseRewarded:extra:`")));

- (void)trackRewardedVideoAdCloseRewarded:(BOOL)rewarded extra:(NSDictionary *)extra;


/// callback to developer when end to play
- (void)trackRewardedVideoAdVideoEnd;

/// callback to developer when ad is clicked
- (void)trackRewardedVideoAdClick;

/// callback to developer when ad is clicked
- (void)trackRewardedVideoAdClickWithClickType:(ATOfferClickAdType)clickType;

/// callback to developer when start to play
- (void)trackRewardedVideoAdVideoStart;
- (void)trackRewardedVideoAdShow;

/// callback to developer when ad is load failed
/// @param error - error message
- (void)trackRewardedVideoAdLoadFailed:(NSError *)error;

-(void) trackRewardedVideoAdPlayEventWithError:(NSError*)error extra:(NSDictionary *)extraDic;


/// callback to developer when ad is loaded
/// @param adObject - ad object
/// @param adExtra - extra data
- (void)trackRewardedVideoAdLoaded:(id)adObject adExtra:(NSDictionary *_Nullable)adExtra;


/// 广告渲染成功(素材下载成功)
- (void)trackRewardedVideoAdRenderSuccess:(id)adObject adExtra:(NSDictionary *_Nullable)adExtra;

/// 广告加载成功
- (void)trackRewardedVideoAdDataLoadSuccess:(id)adObject adExtra:(NSDictionary *_Nullable)adExtra;

/// callback to developer when rewarded
- (void)trackRewardedVideoAdRewarded;

///  Whether the click jump of ad is in the form of Deeplink
/// @param success - success status
- (void)trackRewardedVideoAdDeeplinkOrJumpResult:(BOOL)success;

- (NSDictionary *)delegateExtra;

- (instancetype)initWithInfo:(NSDictionary *)serverInfo
                   localInfo:(NSDictionary *)localInfo;

@property (nonatomic,weak) id<ATRewardedVideoDelegate> delegate;
@property (nonatomic,strong) ATRewardedVideo *rewardedVideo;
@property (nonatomic,readonly) NSString *unitID;
@property (nonatomic) NSString *userID;
@property (nonatomic,assign) NSInteger priorityIndex;

@end
NS_ASSUME_NONNULL_END
