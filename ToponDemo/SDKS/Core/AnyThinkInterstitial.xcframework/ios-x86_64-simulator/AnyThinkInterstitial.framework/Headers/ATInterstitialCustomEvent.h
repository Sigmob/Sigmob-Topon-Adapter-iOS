//
//  ATInterstitialCustomEvent.h
//  AnyThinkInterstitial
//
//  Created by Martin Lau on 21/09/2018.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

#import "ATInterstitial.h"
#import "ATInterstitialDelegate.h"
#import <AnyThinkSDK/AnyThinkSDK.h>

NS_ASSUME_NONNULL_BEGIN
@interface ATInterstitialCustomEvent : ATAdCustomEvent

/// callback to developer when ad is loaded
/// @param interstitialAd - ad objec
/// @param adExtra - extra data
- (void)trackInterstitialAdLoaded:(id)interstitialAd adExtra:(NSDictionary *_Nullable)adExtra;

/// 广告渲染成功(素材下载成功)
- (void)trackInterstitialAdRenderSuccess:(id)interstitialAd adExtra:(NSDictionary *_Nullable)adExtra;

/// 广告加载成功
- (void)trackInterstitialAdDataLoadSuccess:(id)interstitialAd adExtra:(NSDictionary *_Nullable)adExtra;

/// callback to developer when ad is load failed
/// @param error - error message
- (void)trackInterstitialAdLoadFailed:(NSError *)error;

/// callback to developer when ad is showed
- (void)trackInterstitialAdShow;

/// callback to developer when show failed
/// @param error - show error message
- (void)trackInterstitialAdShowFailed:(NSError *)error;

/// callback to developer when start to play
- (void)trackInterstitialAdVideoStart;

/// callback to developer when end to play
- (void)trackInterstitialAdVideoEnd;

/// callback to developer when play failed
/// @param error - play error message
- (void)trackInterstitialAdDidFailToPlayVideo:(NSError *)error;


- (void)trackInterstitialAdDidFailToPlayVideo:(NSError*)error extra:(NSDictionary *)extraDic;
/// callback to developer when ad is clicked
- (void)trackInterstitialAdClick;

/// callback to developer when ad is clicked
- (void)trackInterstitialAdClickWithClickType:(ATOfferClickAdType)clickType;

/// callback to developer when ad is closed
- (void)trackInterstitialAdClose __attribute__((deprecated("Deprecated, please Use `trackInterstitialAdClose:`")));

- (void)trackInterstitialAdClose:(NSDictionary *)extra;

///  Whether the click jump of ad is in the form of Deeplink
/// @param success - success status
- (void)trackInterstitialAdDeeplinkOrJumpResult:(BOOL)success;


- (NSDictionary *)delegateExtra;
- (ATNativeADSourceType)adSourceType;

- (instancetype)initWithInfo:(NSDictionary *)serverInfo
                   localInfo:(NSDictionary *)localInfo ;

@property (nonatomic,weak) id<ATInterstitialDelegate> delegate;
@property (nonatomic,strong) ATInterstitial *interstitial;
@property (nonatomic,readonly) NSString *unitID;
@property (nonatomic,assign) NSInteger priorityIndex;

@end


NS_ASSUME_NONNULL_END
