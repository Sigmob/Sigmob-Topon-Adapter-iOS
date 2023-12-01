//
//  ATTestSchemaMode.h
//  AnyThinkSDK
//
//  Created by GUO PENG on 2022/8/2.
//  Copyright © 2022 AnyThink. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ATDebuggerConfigDefine.h"



NS_ASSUME_NONNULL_BEGIN


@interface ATDebuggerConfig : NSObject

@property(nonatomic, assign,readonly) BOOL isDebugger;

@property(nonatomic, assign) ATAdNetWorkType netWorkType;

@property(nonatomic, strong) NSString *deviceIdfaStr;

#pragma mark - CSJ
@property(nonatomic, assign) ATCSJSplashAdType csj_splashAdType;

@property(nonatomic, assign) ATCSJInterstitialAdType csj_interstitialAdType;

@property(nonatomic, assign) ATCSJRewardVideoAdType csj_rewardVideoAdType;

@property(nonatomic, assign) ATCSJBannerAdType csj_bannerAdType;

@property(nonatomic, assign) ATCSJNativeAdType csj_nativeAdType;


#pragma mark - Pangle

@property(nonatomic, assign) ATPangleSplashAdType pangle_splashAdType;

@property(nonatomic, assign) ATPangleInterstitialAdType pangle_interstitialAdType;

@property(nonatomic, assign) ATPangleRewardVideoAdType pangle_rewardVideoAdType;

@property(nonatomic, assign) ATPangleBannerAdType pangle_bannerAdType;

@property(nonatomic, assign) ATPangleNativeAdType pangle_nativeAdType;

#pragma mark - Meta

@property(nonatomic, assign) ATMetaInterstitialAdType meta_interstitialAdType;

@property(nonatomic, assign) ATMetaRewardVideoAdType meta_rewardVideoAdType;

@property(nonatomic, assign) ATMetaBannerAdType meta_bannerAdType;

@property(nonatomic, assign) ATMetaNativeAdType meta_nativeAdType;

#pragma mark - Mytarget

@property(nonatomic, assign) ATMytargetInterstitialAdType mytarget_interstitialAdType;

@property(nonatomic, assign) ATMytargetRewardVideoAdType mytarget_rewardVideoAdType;

@property(nonatomic, assign) ATMytargetBannerAdType mytarget_bannerAdType;

@property(nonatomic, assign) ATMytargetNativeAdType mytarget_nativeAdType;

#pragma mark - AdMob

@property(nonatomic, assign) ATAdMobSplashAdType adMob_splashAdType;

@property(nonatomic, assign) ATAdMobInterstitialAdType adMob_interstitialAdType;

@property(nonatomic, assign) ATAdMobRewardVideoAdType adMob_rewardVideoAdType;

@property(nonatomic, assign) ATAdMobBannerAdType adMob_bannerAdType;

@property(nonatomic, assign) ATAdMobNativeAdType adMob_nativeAdType;

#pragma mark - Applovin

@property(nonatomic, assign) ATApplovinInterstitialAdType applovin_interstitialAdType;

@property(nonatomic, assign) ATApplovinRewardVideoAdType applovin_rewardVideoAdType;

@property(nonatomic, assign) ATApplovinBannerAdType applovin_bannerAdType;


#pragma mark - Baidu
@property(nonatomic, assign) ATBaiduSplashAdType baidu_splashAdType;

@property(nonatomic, assign) ATBaiduInterstitialAdType baidu_interstitialAdType;

@property(nonatomic, assign) ATBaiduRewardVideoAdType baidu_rewardVideoAdType;

@property(nonatomic, assign) ATBaiduBannerAdType baidu_bannerAdType;

@property(nonatomic, assign) ATBaiduNativeAdType baidu_nativeAdType;

#pragma mark - Chartboost

@property(nonatomic, assign) ATChartboostInterstitialAdType chartboost_interstitialAdType;

@property(nonatomic, assign) ATChartboostRewardVideoAdType chartboost_rewardVideoAdType;

@property(nonatomic, assign) ATChartboostBannerAdType chartboost_bannerAdType;


#pragma mark - Fyber

@property(nonatomic, assign) ATFyberInterstitialAdType fyber_interstitialAdType;

@property(nonatomic, assign) ATFyberRewardVideoAdType fyber_rewardVideoAdType;

@property(nonatomic, assign) ATFyberBannerAdType fyber_bannerAdType;


#pragma mark - GDT

@property(nonatomic, assign) ATGDTSplashAdType gdt_splashAdType;

@property(nonatomic, assign) ATGDTInterstitialAdType gdt_interstitialAdType;

@property(nonatomic, assign) ATGDTRewardVideoAdType gdt_rewardVideoAdType;

@property(nonatomic, assign) ATGDTBannerAdType gdt_bannerAdType;

@property(nonatomic, assign) ATGDTDebugNativeAdType gdt_nativeAdType;

#pragma mark - Inmobi

@property(nonatomic, assign) ATInmobiInterstitialAdType inmobi_interstitialAdType;

@property(nonatomic, assign) ATInmobiRewardVideoAdType inmobi_rewardVideoAdType;

@property(nonatomic, assign) ATInmobiBannerAdType inmobi_bannerAdType;

@property(nonatomic, assign) ATInmobiNativeAdType inmobi_nativeAdType;


#pragma mark - Ironsource

@property(nonatomic, assign) ATIronsourceInterstitialAdType ironsource_interstitialAdType;

@property(nonatomic, assign) ATIronsourceRewardVideoAdType ironsource_rewardVideoAdType;

#pragma mark - Klevin
@property(nonatomic, assign) ATKlevinSplashAdType klevin_splashAdType;

@property(nonatomic, assign) ATKlevinInterstitialAdType klevin_interstitialAdType;

@property(nonatomic, assign) ATKlevinRewardVideoAdType klevin_rewardVideoAdType;


@property(nonatomic, assign) ATKlevinNativeAdType klevin_nativeAdType;

#pragma mark - KuaiShou
@property(nonatomic, assign) ATKuaiShouSplashAdType kuaiShou_splashAdType;

@property(nonatomic, assign) ATKuaiShouInterstitialAdType kuaiShou_interstitialAdType;

@property(nonatomic, assign) ATKuaiShouRewardVideoAdType kuaiShou_rewardVideoAdType;

@property(nonatomic, assign) ATKuaiShouBannerAdType kuaiShou_bannerAdType;

@property(nonatomic, assign) ATKuaiShouNativeAdType kuaiShou_nativeAdType;
#pragma mark - Maio

@property(nonatomic, assign) ATMaioInterstitialAdType maio_interstitialAdType;

@property(nonatomic, assign) ATMaioRewardVideoAdType maio_rewardVideoAdType;

#pragma mark - Mintegral
@property(nonatomic, assign) ATMintegralSplashAdType mintegral_splashAdType;

@property(nonatomic, assign) ATMintegralInterstitialAdType mintegral_interstitialAdType;

@property(nonatomic, assign) ATMintegralRewardVideoAdType mintegral_rewardVideoAdType;

@property(nonatomic, assign) ATMintegralBannerAdType mintegral_bannerAdType;

@property(nonatomic, assign) ATMintegralNativeAdType mintegral_nativeAdType;

#pragma mark - Nend
@property(nonatomic, assign) ATNendInterstitialAdType nend_interstitialAdType;

@property(nonatomic, assign) ATNendRewardVideoAdType nend_rewardVideoAdType;

@property(nonatomic, assign) ATNendBannerAdType nend_bannerAdType;


@property(nonatomic, assign) ATNendNativeAdType nend_nativeAdType;

#pragma mark - Sigmob
@property(nonatomic, assign) ATSigmobSplashAdType sigmob_splashAdType;

@property(nonatomic, assign) ATSigmobInterstitialAdType sigmob_interstitialAdType;

@property(nonatomic, assign) ATSigmobRewardVideoAdType sigmob_rewardVideoAdType;

@property(nonatomic, assign) ATSigmobNativeAdType sigmob_nativeAdType;

#pragma mark - StartApp


@property(nonatomic, assign) ATStartAppInterstitialAdType startApp_interstitialAdType;

@property(nonatomic, assign) ATStartAppRewardVideoAdType startApp_rewardVideoAdType;

@property(nonatomic, assign) ATStartAppBannerAdType startApp_bannerAdType;


#pragma mark - Tapjoy

@property(nonatomic, assign) ATTapjoyInterstitialAdType tapjoy_interstitialAdType;

@property(nonatomic, assign) ATTapjoyRewardVideoAdType tapjoy_rewardVideoAdType;


#pragma mark - UnityAds

@property(nonatomic, assign) ATUnityAdsInterstitialAdType unityAds_interstitialAdType;

@property(nonatomic, assign) ATUnityAdsRewardVideoAdType unityAds_rewardVideoAdType;

@property(nonatomic, assign) ATUnityAdsBannerAdType unityAds_bannerAdType;


#pragma mark - Vungle

@property(nonatomic, assign) ATVungleInterstitialAdType vungle_interstitialAdType;

@property(nonatomic, assign) ATVungleRewardVideoAdType vungle_rewardVideoAdType;

@property(nonatomic, assign) ATVungleBannerAdType vungle_bannerAdType;

@property(nonatomic, assign) ATVungleNativeAdType vungle_nativeAdType;

#pragma mark - ADX

@property(nonatomic, assign) ATADXSplashAdType adx_splashAdType;

@property(nonatomic, assign) ATADXInterstitialAdType adx_interstitialAdType;

@property(nonatomic, assign) ATADXRewardVideoAdType adx_rewardVideoAdType;

@property(nonatomic, assign) ATADXBannerAdType adx_bannerAdType;

@property(nonatomic, assign) ATADXNativeAdType adx_nativeAdType;

#pragma mark - Pubnative
@property(nonatomic, assign) ATPubNativeInterstitialAdType pubnative_interstitialAdType;

@property(nonatomic, assign) ATPubNativeRewardVideoAdType pubnative_rewardVideoAdType;

@property(nonatomic, assign) ATPubNativeBannerAdType pubnative_bannerAdType;

@property(nonatomic, assign) ATPubNativeNativeAdType pubnative_nativeAdType;


#pragma mark - Bigo
@property(nonatomic, assign) ATBigoSplashAdType bigo_splashAdType;

@property(nonatomic, assign) ATBigoInterstitialAdType bigo_interstitialAdType;

@property(nonatomic, assign) ATBigoRewardVideoAdType bigo_rewardVideoAdType;

@property(nonatomic, assign) ATBigoBannerAdType bigo_bannerAdType;

@property(nonatomic, assign) ATBigoNativeAdType bigo_nativeAdType;


#pragma mark - api
- (NSDictionary *)getCurrentNetWorkConfig;




@end

NS_ASSUME_NONNULL_END
