//
//  ATDebuggerConfigDefine.h
//  AnyThinkSDK
//
//  Created by GUO PENG on 2022/8/10.
//  Copyright © 2022 AnyThink. All rights reserved.
//


#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
#pragma mark - NetWorkType
typedef NS_ENUM(NSUInteger, ATAdNetWorkType) {
    ATAdNetWorkMetaType = 1,
    ATAdNetWorkAdmobType = 2,
    ATAdNetWorkInmobiType = 3,
    ATAdNetWorkApplovinType = 5,
    ATAdNetWorkMintegralType = 6,
    ATAdNetWorkGDTType = 8,
    ATAdNetWorkChartboostType = 9,
    ATAdNetWorkTapjoyType = 10,
    ATAdNetWorkIronsourceType = 11,
    ATAdNetWorkUnityAdsType = 12,
    ATAdNetWorkVungleType = 13,
    ATAdNetWorkCSJType = 15,
    ATAdNetWorkBaiduType = 22,
    ATAdNetWorkNendType = 23,
    ATAdNetWorkMaioType = 24,
    ATAdNetWorkStartAppType = 25,
    ATAdNetWorkKuaiShouType = 28,
    ATAdNetWorkSigmobType = 29,
    ATAdNetWorkMyTargetType = 32,
    ATAdNetWorkFyberType = 37,
    ATAdNetWorkPangleType = 50,
    ATAdNetWorkKlevinType = 51,
    ATAdNetWorkPubNativeType = 58,
    ATAdNetWorkBigoType = 59,
    ATAdNetWorkAdxType = 66,
    

};

#pragma mark - Pangle

typedef NS_ENUM(NSUInteger, ATPangleSplashAdType) {
    ATPangleSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATPangleInterstitialAdType) {
    ATPangleInterstitialAdDefaultType =  0,
};

typedef NS_ENUM(NSUInteger, ATPangleRewardVideoAdType) {
    ATPangleRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATPangleBannerAdType) {
    ATPangleBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATPangleNativeAdType) {
    ATPangleNativeAdDefaultType = 0,
};



#pragma mark - CSJ

typedef NS_ENUM(NSUInteger, ATCSJSplashAdType) {
    ATCSJSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATCSJInterstitialAdType) {
    ATCSJInterstitialAdNewType =  3,

};

typedef NS_ENUM(NSUInteger, ATCSJRewardVideoAdType) {
    ATCSJRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATCSJBannerAdType) {
    ATCSJBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATCSJNativeAdType) {
    ATCSJNativeAdDrawTemplateType = 201,
    ATCSJNativeAdDrawSelfRenderType = 202,
    ATCSJNativeAdFeedTemplateType = 101,
    ATCSJNativeAdFeedSelfRenderType = 102,
};


#pragma mark - Meta
typedef NS_ENUM(NSUInteger, ATMetaSplashAdType) {
    ATMetaSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATMetaInterstitialAdType) {
    ATMetaInterstitialAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATMetaRewardVideoAdType) {
    ATMetaRewardVideoAdDefaultType = 0,
    ATMetaRewardVideoAdInterstitialType,
};

typedef NS_ENUM(NSUInteger, ATMetaBannerAdType) {
    ATMetaBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATMetaNativeAdType) {
    ATMetaNativeAdSelfRenderType = 1,
    ATMetaNativeAdNativeBannerTemplateType = 2,
    ATMetaNativeAdTemplateType = 3,
    ATMetaNativeAdNativeBannerSelfRenderType = 4,
};

#pragma mark - Mytarget

typedef NS_ENUM(NSUInteger, ATMytargetSplashAdType) {
    ATMytargetSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATMytargetInterstitialAdType) {
    ATMytargetInterstitialAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATMytargetRewardVideoAdType) {
    ATMytargetRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATMytargetBannerAdType) {
    ATMytargetBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATMytargetNativeAdType) {
    ATMytargetNativeAdDefaultType = 0,
};

#pragma mark - AdMob
typedef NS_ENUM(NSUInteger, ATAdMobSplashAdType) {
    ATAdMobSplashAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATAdMobInterstitialAdType) {
    ATAdMobInterstitialAdPictureType = 1,
    ATAdMobInterstitialAdVideoType = 2,
};

typedef NS_ENUM(NSUInteger, ATAdMobRewardVideoAdType) {
    ATAdMobRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATAdMobBannerAdType) {
    ATAdMobBannerAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATAdMobNativeAdType) {
    ATAdMobNativeAdPictureType = 1,
    ATAdMobNativeAdVideoType = 2,
};

#pragma mark - Applovin
typedef NS_ENUM(NSUInteger, ATApplovinSplashAdType) {
    ATApplovinSplashAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATApplovinInterstitialAdType) {
    ATApplovinInterstitialAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATApplovinRewardVideoAdType) {
    ATApplovinRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATApplovinBannerAdType) {
    ATApplovinBannerAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATApplovinNativeAdType) {
    ATApplovinNativeAdDefaultType = 0,
};

#pragma mark - Baidu

typedef NS_ENUM(NSUInteger, ATBaiduSplashAdType) {
    ATBaiduSplashAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATBaiduInterstitialAdType) {
    ATBaiduInterstitialAdFullScreenVideoType = 2,
    ATBaiduInterstitialAdTemplateType = 3,


};

typedef NS_ENUM(NSUInteger, ATBaiduRewardVideoAdType) {
    ATBaiduRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATBaiduBannerAdType) {
    ATBaiduBannerAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATBaiduNativeAdType) {
    ATBaiduNativeAdSelfRenderType = 1,
    ATBaiduNativeAdTemplateType = 4,
};

#pragma mark - Chartboost
typedef NS_ENUM(NSUInteger, ATChartboostSplashAdType) {
    ATChartboostSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATChartboostInterstitialAdType) {
    ATChartboostInterstitialAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATChartboostRewardVideoAdType) {
    ATChartboostRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATChartboostBannerAdType) {
    ATChartboostBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATChartboostNativeAdType) {
    ATChartboostNativeAdDefaultType = 0,
};

#pragma mark - Fyber
typedef NS_ENUM(NSUInteger, ATFyberSplashAdType) {
    ATFyberSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATFyberInterstitialAdType) {
    ATFyberInterstitialAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATFyberRewardVideoAdType) {
    ATFyberRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATFyberBannerAdType) {
    ATFyberBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATFyberNativeAdType) {
    ATFyberNativeAdDefaultType = 0,
};

#pragma mark - GDT
typedef NS_ENUM(NSUInteger, ATGDTSplashAdType) {
    ATGDTSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATGDTInterstitialAdType) {
    ATGDTInterstitialAdPopupVideoType = 1,
    ATGDTInterstitialAdFullScreenVideoType = 2,

};

typedef NS_ENUM(NSUInteger, ATGDTRewardVideoAdType) {
    ATGDTRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATGDTBannerAdType) {
    ATGDTBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATGDTDebugNativeAdType) {
    ATGDTNativeAdTemplateType = 1,
    ATGDTNativeAdSelfRenderType = 2,
    ATGDTNativeAdVideoTemplateType = 3,
    ATGDTNativeAdVideoSelfRenderType = 4,
};

#pragma mark - Inmobi
typedef NS_ENUM(NSUInteger, ATInmobiSplashAdType) {
    ATInmobiSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATInmobiInterstitialAdType) {
    ATInmobiInterstitialAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATInmobiRewardVideoAdType) {
    ATInmobiRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATInmobiBannerAdType) {
    ATInmobiBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATInmobiNativeAdType) {
    ATInmobiNativeAdDefaultType = 0,
};

#pragma mark - Ironsource
typedef NS_ENUM(NSUInteger, ATIronsourceSplashAdType) {
    ATIronsourceSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATIronsourceInterstitialAdType) {
    ATIronsourceInterstitialAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATIronsourceRewardVideoAdType) {
    ATIronsourceRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATIronsourceBannerAdType) {
    ATIronsourceBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATIronsourceNativeAdType) {
    ATIronsourceNativeAdDefaultType = 0,
};

#pragma mark - Klevin
typedef NS_ENUM(NSUInteger, ATKlevinSplashAdType) {
    ATKlevinSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATKlevinInterstitialAdType) {
    ATKlevinInterstitialAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATKlevinRewardVideoAdType) {
    ATKlevinRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATKlevinBannerAdType) {
    ATKlevinBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATKlevinNativeAdType) {
    ATKlevinNativeAdDefaultType = 0,
};

#pragma mark - KuaiShou
typedef NS_ENUM(NSUInteger, ATKuaiShouSplashAdType) {
    ATKuaiShouSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATKuaiShouInterstitialAdType) {
    ATKuaiShouInterstitialAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATKuaiShouRewardVideoAdType) {
    ATKuaiShouRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATKuaiShouBannerAdType) {
    ATKuaiShouBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATKuaiShouNativeAdType) {
    ATKuaiShouNativeAdFeedSelfRenderType = 101,
    ATKuaiShouNativeAdFeedTemplateType = 102,
    ATKuaiShouNativeAdDrawFeedType = 200,
};

#pragma mark - Maio
typedef NS_ENUM(NSUInteger, ATMaioSplashAdType) {
    ATMaioSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATMaioInterstitialAdType) {
    ATMaioInterstitialAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATMaioRewardVideoAdType) {
    ATMaioRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATMaioBannerAdType) {
    ATMaioBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATMaioNativeAdType) {
    ATMaioNativeAdDefaultType = 0,
};

#pragma mark - Mintegral
typedef NS_ENUM(NSUInteger, ATMintegralSplashAdType) {
    ATMintegralSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATMintegralInterstitialAdType) {
    ATMintegralInterstitialAdVideoType = 2,
};

typedef NS_ENUM(NSUInteger, ATMintegralRewardVideoAdType) {
    ATMintegralRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATMintegralBannerAdType) {
    ATMintegralBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATMintegralNativeAdType) {
    ATMintegralNativeAdSelfRenderType = 1,
    ATMintegralNativeAdTemplateType = 2,
};

#pragma mark - Nend
typedef NS_ENUM(NSUInteger, ATNendSplashAdType) {
    ATNendSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATNendInterstitialAdType) {
    ATNendInterstitialAdDefaultType = 1,
    ATNendInterstitialAdVideoType = 2,
    ATNendInterstitialAdFullScreenType = 3,
};

typedef NS_ENUM(NSUInteger, ATNendRewardVideoAdType) {
    ATNendRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATNendBannerAdType) {
    ATNendBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATNendNativeAdType) {
    ATNendNativeAdDefaultType = 0,
};

#pragma mark - Sigmob
typedef NS_ENUM(NSUInteger, ATSigmobSplashAdType) {
    ATSigmobSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATSigmobInterstitialAdType) {
    ATSigmobInterstitialAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATSigmobRewardVideoAdType) {
    ATSigmobRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATSigmobBannerAdType) {
    ATSigmobBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATSigmobNativeAdType) {
    ATSigmobNativeAdDefaultType = 0,
};

#pragma mark - StartApp
typedef NS_ENUM(NSUInteger, ATStartAppSplashAdType) {
    ATStartAppSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATStartAppInterstitialAdType) {
    ATStartAppInterstitialAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATStartAppRewardVideoAdType) {
    ATStartAppRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATStartAppBannerAdType) {
    ATStartAppBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATStartAppNativeAdType) {
    ATStartAppNativeAdDefaultType = 0,
};

#pragma mark - Tapjoy
typedef NS_ENUM(NSUInteger, ATTapjoySplashAdType) {
    ATTapjoySplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATTapjoyInterstitialAdType) {
    ATTapjoyInterstitialAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATTapjoyRewardVideoAdType) {
    ATTapjoyRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATTapjoyBannerAdType) {
    ATTapjoyBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATTapjoyNativeAdType) {
    ATTapjoyNativeAdDefaultType = 0,
};

#pragma mark - UnityAds
typedef NS_ENUM(NSUInteger, ATUnityAdsSplashAdType) {
    ATUnityAdsSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATUnityAdsInterstitialAdType) {
    ATUnityAdsInterstitialAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATUnityAdsRewardVideoAdType) {
    ATUnityAdsRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATUnityAdsBannerAdType) {
    ATUnityAdsBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATUnityAdsNativeAdType) {
    ATUnityAdsNativeAdDefaultType = 0,
};

#pragma mark - Vungle
typedef NS_ENUM(NSUInteger, ATVungleSplashAdType) {
    ATVungleSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATVungleInterstitialAdType) {
    ATVungleInterstitialAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATVungleRewardVideoAdType) {
    ATVungleRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATVungleBannerAdType) {
    ATVungleBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATVungleNativeAdType) {
    ATVungleNativeAdDefaultType = 0,
};

#pragma mark - ADX
typedef NS_ENUM(NSUInteger, ATADXSplashAdType) {
    ATADXSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATADXInterstitialAdType) {
    ATADXInterstitialAdFullScreenType = 1,
    ATADXInterstitialAdHalfScreenType = 2,
};

typedef NS_ENUM(NSUInteger, ATADXRewardVideoAdType) {
    ATADXRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATADXBannerAdType) {
    ATADXBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATADXNativeAdType) {
    ATADXNativeAdDefaultType = 0,
};

#pragma mark - PubNative
typedef NS_ENUM(NSUInteger, ATPubNativeInterstitialAdType) {
    ATPubNativeInterstitialAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATPubNativeRewardVideoAdType) {
    ATPubNativeRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATPubNativeBannerAdType) {
    ATPubNativeBannerAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATPubNativeNativeAdType) {
    ATPubNativeNativeAdDefaultType = 0,
};


#pragma mark - Bigo
typedef NS_ENUM(NSUInteger, ATBigoSplashAdType) {
    ATBigoSplashAdDefaultType = 0
};

typedef NS_ENUM(NSUInteger, ATBigoInterstitialAdType) {
    ATBigoInterstitialAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATBigoRewardVideoAdType) {
    ATBigoRewardVideoAdDefaultType = 0,
};

typedef NS_ENUM(NSUInteger, ATBigoBannerAdType) {
    ATBigoBannerAdSmallType = 1,// 320x50
    ATBigoBannerAdLargeType = 2,// 300x250
};

typedef NS_ENUM(NSUInteger, ATBigoNativeAdType) {
    ATBigoNativeAdDefaultType = 0,
};


NS_ASSUME_NONNULL_END
