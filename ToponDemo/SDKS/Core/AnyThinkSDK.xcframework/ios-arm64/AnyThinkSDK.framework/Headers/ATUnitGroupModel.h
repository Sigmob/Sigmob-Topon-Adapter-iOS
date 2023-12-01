//
//  ATUnitGroupModel.h
//  AnyThinkSDK
//
//  Created by Martin Lau on 11/04/2018.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

#import "ATModel.h"
#import <UIKit/UIKit.h>
#import "ATMyOfferOfferModel.h"
#import "ATBidInfo.h"

#import "ATModelProtocol.h"
#import "ATAdapter.h"
#import "ATStorage.h"

#define ATBaiDuUnitIDKey @"ATBaiDuUnitIDKey"
#define ATBaiDuplacementIdKey @"ATBaiDuplacementIdKey"
#define ATBaiDuUpdateExposureNotificationKey @"ATBaiDuUpdateExposureNotificationKey"

typedef NS_ENUM(NSInteger, ATRequestFiledType) {
    ATRequestFiledAdFodderDataType = 1,
    ATRequestFiledAdMetaDataType = 2,
};


typedef NS_ENUM(NSInteger, ATAdListType) {
    ATAdListTypeNormal = 1,
    ATAdListTypeC2S = 2,
    ATAdListTypeS2S = 3,
    ATAdListTypeAdx = 4,
    ATAdListTypeDsp = 5,
    ATAdListTypeOnLine = 6,
    ATAdListTypeInhouse = 7,
    ATAdListTypeDirect = 8,
    ATAdListTypeDynamicBid = 9,
    ATAdListTypeBottom = 10,
    ATAdListTypeBKS = 11,
};


typedef NS_ENUM(NSInteger, ATAdmobPriceType) {
    ATAdmobPriceSortType = 0,
    ATAdmobPriceEstimateType,
    ATAdmobPriceRealType,
};

typedef NS_ENUM(NSInteger, ATShowAutoLoadType) {
    ATShowAutoOneAdSupportLoadType = 1,
    ATShowAutoOneAdNotSupportLoadType,
    ATShowAutoOneNetWorkNotSupportLoadType,
};
/// ad type：0 Native, 1 Rewarded, 2 Banner, 3 Interstitial, 4 Splash
typedef NS_ENUM(NSInteger, ATUnitGroupJointAdType) {
    ATUnitGroupJointAdOtherType = -1,
    ATUnitGroupJointAdNativeType = 0,
    ATUnitGroupJointAdRewardedType = 1,
    ATUnitGroupJointAdBannerType = 2,
    ATUnitGroupJointAdInterstitialType = 3,
    ATUnitGroupJointAdSplashType = 4,
};

typedef NS_ENUM(NSInteger, ATNetworkCurrencyType) {
    ATNetworkCurrencyCNYType = 0,
    ATNetworkCurrencyUSDType,

};


@interface ATUnitGroupModel : ATModel <ATModelProtocol, ATStorageEntityProtocol>
-(instancetype) initWithDictionary:(NSDictionary *)dictionary;

@property (nonatomic, assign) ATRequestFiledType requestFiledType;
@property (nonatomic, assign) ATAdListType adListType;

@property(nonatomic, strong) NSString *tpBidID;

@property(nonatomic, readonly, weak) Class adapterClass;
@property(nonatomic, readonly) NSString *adapterClassString;
@property(nonatomic, readonly) NSInteger capByDay;
@property(nonatomic, readonly) NSInteger capByHour;
@property(nonatomic, assign) NSTimeInterval networkCacheTime;
@property(nonatomic, readonly) NSInteger networkFirmID;
@property(nonatomic, readonly) NSString *networkName;
@property(nonatomic, readonly) NSInteger networkRequestNum;
@property(nonatomic, readonly) NSTimeInterval networkDataTimeout; //  5.1.0 双回调数据超时
@property(nonatomic, readonly) NSTimeInterval networkTimeout;
@property(nonatomic, readonly) NSTimeInterval skipIntervalAfterLastLoadingFailure;
@property(nonatomic, readonly) NSTimeInterval skipIntervalAfterLastBiddingFailure;
/// 废弃
@property(nonatomic, readonly) NSString *unitGroupID;
@property(nonatomic, readonly) NSString *unitID;
@property(nonatomic, readonly) NSDictionary *content;
@property(nonatomic, readonly) NSTimeInterval showingInterval;//minimum interval between previous request & last impression
@property(nonatomic, readonly) CGSize adSize;
@property(nonatomic, readonly) NSTimeInterval autoRefreshInterval;

@property (nonatomic, assign) CGFloat c2sWinExpandRatio;
@property (nonatomic, assign) CGFloat c2sLossExpandRatio;
@property (nonatomic, assign) CGFloat s2sWinExpandRatio;
@property (nonatomic, assign) CGFloat s2sLossExpandRatio;


@property(nonatomic, readonly) BOOL splashZoomOut;
@property(nonatomic, strong) NSString *price;
@property(nonatomic, strong) NSString *ecpmByCurrency;
@property(nonatomic, readonly) NSInteger ecpmLevel;
@property(nonatomic, readonly) NSTimeInterval headerBiddingRequestTimeout;
@property(nonatomic, strong) NSString *bidPrice;
@property(nonatomic, strong) NSString *bidToken;
@property(nonatomic, readonly) BOOL headerBidding;
@property(nonatomic, readonly) ATUnitGroupType unitGroupType;
@property(nonatomic, readonly) NSTimeInterval bidTokenTime;
@property(nonatomic, readonly) NSTimeInterval statusTime;
@property(nonatomic, readonly) NSString *clickTkAddress;
@property(nonatomic, readonly) NSTimeInterval clickTkDelayMin;
@property(nonatomic, readonly) NSTimeInterval clickTkDelayMax;
@property(nonatomic, readonly) BOOL postsNotificationOnShow;
@property(nonatomic, readonly) BOOL postsNotificationOnClick;
@property(nonatomic, strong) NSString *precision;
@property(nonatomic, readonly) BOOL canAutoReady;
@property(nonatomic, readonly) BOOL waterfallTimeOutSW;
@property(nonatomic, readonly) BOOL reportBidPriceSW;
@property(nonatomic, assign) BOOL bidRealTimeLoadSW;
@property(nonatomic, readonly) BOOL returnHBEcpmSW;
@property(nonatomic, strong) ATBidInfo *bidInfo;

@property(nonatomic, readonly, getter=isBidInfoNoPrice) BOOL bidInfoNoPrice;
@property(nonatomic, readonly) BOOL unitGroupS2SSW;

@property(nonatomic) BOOL s2sRewardEnabled;

// v5.7.61+
@property(nonatomic, readonly) NSInteger weight;

@property(nonatomic, copy) NSString *directOfferOid;
// v6.1.10
@property (nonatomic,readonly) NSTimeInterval showDelay;

@property(nonatomic, assign) ATShowAutoLoadType showAutoLoadType;


@property(nonatomic) NSInteger priority; // when ad is filterd

/// ad type：0 Native, 1 Rewarded, 2 Banner, 3 Interstitial, 4 Splash
@property(nonatomic, assign) ATUnitGroupJointAdType jointAdType;

@property(nonatomic, assign) BOOL isHBAdvanceRequest;

@property (nonatomic,strong) NSString *bidFloor;

// 新价格
@property (nonatomic, strong) NSString *sortPriorityLevel;

//reference 6.1.42
@property(nonatomic) NSInteger s2sSendLossPosition;

@property (nonatomic, strong) NSString *bidinfoEcpmStr;

@property (nonatomic, assign) ATNetworkCurrencyType networkCurrencyType;

/// 仅在展示时发送Win
@property (nonatomic, assign) BOOL onlyDisplaySendWin;


@property (nonatomic, assign) BOOL admobEstimatePriceSwitch;

@property (nonatomic, assign) ATAdmobPriceType admobPriceType;

@property (nonatomic, strong) NSString *admobPresentShowEcpmPrice;


@property (nonatomic, strong) NSArray *mixAdClickAreaArray;
@property (nonatomic, strong) NSArray<NSString *> *contentURLStrings;

/// C2S 广告加载成功 时间戳
@property (nonatomic, strong) NSDate *adDataSucceedDate;
/// C2S 渲染成功 时间戳
@property (nonatomic, strong) NSDate *adRenderSucceedDate;
/// 广告 开始请求 时间戳
@property (nonatomic, strong) NSDate *requestStartDate;


#pragma mark - NewDepart

@property (nonatomic, readonly) ATAdapter *adapter;

@property (nonatomic, strong) NSDictionary *dictionary;

/// see -[ATUnitGroup updateSamePriceWeight]
@property (atomic, assign, readonly) CGFloat samePriceWeight;

@property (nonatomic, readonly) NSInteger adsMaxCacheNum;

@property (nonatomic, assign) BOOL isPermitSendWin;

@property (nonatomic, assign) BOOL isPermitSendLoss;

@property (nonatomic, strong) NSString *admobRequestAgent;
@property (nonatomic, assign) BOOL isKuaishouNativeShake;

// v6.2.69
@property(nonatomic, readonly) NSInteger admobBibType;
@property(nonatomic, readonly) BOOL isAdmobHybrid;
@property(nonatomic, readonly) NSInteger networkId;


- (BOOL)validateForCapsWithPlacementId:(NSString *)placementId;
- (BOOL)validateForPacingWithPlacementId:(NSString *)placementId;

/// same price need a order, use samePriceWeight to order, when ad cache return
/// @param newWeight when water fall load, will calculate new weight
- (void)updateSamePriceWeight:(CGFloat)newWeight;

- (BOOL)saveWithUnitGroup:(ATUnitGroupModel *)unitGroup;
- (void)updateWithUnitGroup:(ATUnitGroupModel *)unitGroup;
- (void)removeWithUnitGroup:(ATUnitGroupModel *)unitGroup;
- (ATUnitGroupModel *)readUnitGroupWithIdentifier:(NSString *)identifier;

@end
