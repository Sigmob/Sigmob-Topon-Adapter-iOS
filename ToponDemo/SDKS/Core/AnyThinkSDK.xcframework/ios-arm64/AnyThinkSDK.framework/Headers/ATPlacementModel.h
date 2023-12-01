//
//  ATPlacementModel.h
//  AnyThinkSDK
//
//  Created by Martin Lau on 11/04/2018.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

#import "ATModel.h"
#import "ATUnitGroupModel.h"
#import "ATMyOfferOfferModel.h"
#import "ATMyOfferSetting.h"
#import "ATADXPlacementSetting.h"
#import <UIKit/UIKit.h>

#import "ATStorage.h"
#import "ATModelProtocol.h"

typedef NS_ENUM(NSInteger, ATADShowType) {
    /**
     * priority -> show times -> added time
     */
    ATADShowTypePriority = 0,
    /**
     * show times -> priority -> added time
     */
    ATADShowTypeSerial = 1
};

typedef enum : NSUInteger {
    ATLoadingRequestConcurrentFixedType = 1,
    ATLoadingRequestConcurrentEqualPriceType = 2,
} ATLoadingRequestModelType;

typedef NS_ENUM(NSInteger, ATNativeMixBannerStyleType) {
    ATNativeMixBannerStyleTypeToponOne = 1,
};

typedef enum : NSUInteger {
    ATLoadingApiUnknown,
    ATLoadingApiTypeDefault, // Default load
    ATLoadingApiTypeAuto, // Automatic load, note: It is not shared with the default load, as long as the automatic load is used, the default load cannot be initiated
    ATLoadingApiTypeSuccessRetry, // Retry load after successful callback
    ATLoadingApiTypeFailRetry, // Retry load after failure callback
    ATLoadingApiTypeSerialMultiCachMode // serial + multi-cach mode
} ATLoadingApiType;

typedef NS_ENUM(NSInteger, ATRevenueToPlatform) {
    ATRevenueToPlatformAdjust = 1,
    ATRevenueToPlatformAppsflyer = 2,
    ATRevenueToPlatformTenjin
};


typedef NS_ENUM(NSInteger, ATCallSuccessType) {
    ATCallSuccessShowPriorityType = 1,
    ATCallSuccessPricePriorityType = 2,
};
extern NSString *const kATPlacementModelCacheDateKey;
extern NSString *const kATPlacementModelCustomDataKey;
@interface ATPlacementModelExtra:ATModel
@property(nonatomic, readonly) BOOL cachesPlacementSetting;
@property(nonatomic, readonly) NSTimeInterval defaultAdSourceLoadingDelay;
@property(nonatomic, readonly) NSInteger defaultNetworkFirmID;
@property(nonatomic, readonly) BOOL usesServerSettings;
@property(nonatomic, readonly) NSInteger countdown;
@property(nonatomic, readonly) BOOL allowsSkip;
@property(nonatomic, readonly) BOOL closeAfterCountdownElapsed;
@end

@interface ATPlatfromInfo : NSObject

- (instancetype)initWithDictionary:(NSDictionary *)dictionary;

@property(nonatomic) ATRevenueToPlatform platform;
@property(nonatomic) NSInteger dataType;
@property(nonatomic, copy) NSString *token;

@end

typedef NS_ENUM(NSUInteger, ATPlacementModelUserValueTimingType) {
    ATPlacementModelUserValueTimingTypeNone = 0,
    ATPlacementModelUserValueTimingTypeShow = 1,
};

typedef NS_ENUM(NSUInteger, ATPlacementModelUserValueStrategyIndexType) {
    ATPlacementModelUserValueStrategyIndexTypeLocal = 0,
    ATPlacementModelUserValueStrategyIndexTypeShowPrice = 1,
};

typedef NS_ENUM(NSUInteger, ATPlacementModelWaterfallModeType) {
    ATPlacementModelWaterfallModeTypeSerialMultiCach = 1,
    ATPlacementModelWaterfallModeTypeNormal = 2,
};


typedef NS_ENUM(NSUInteger, ATBannerAutoRefreshType) {
    ATBannerAutoRefreshTypePlacementStrategy = 1,
    ATBannerAutoRefreshTypeAdSourceStrategy = 2,
};

typedef NS_ENUM(NSInteger, ATPlacementModelBaiduReportType) {
    ATPlacementModelBaiduReportTypeUnKonw = 0,
    ATPlacementModelBaiduReportTypeNormalWin = 1 << 0,
    ATPlacementModelBaiduReportTypeNormalLoss = 1 << 1,
    ATPlacementModelBaiduReportTypeBiddingWin = 1 << 2,
    ATPlacementModelBaiduReportTypeBiddingLoss = 1 << 3,

};

#pragma mark - ATDynamicWaterfallParams
@interface ATDynamicWaterfallParams : NSObject

//动态瀑布流参数
//最大计算条数
@property (nonatomic, assign) NSInteger dynamicWaterfallMaxNCount;
//最小计算条数
@property (nonatomic, assign) NSInteger dynamicWaterfallMinMCount;
//是否基于流量分组维度
@property (nonatomic, assign) BOOL dynamicWaterfallOnlyGroup;
//查询的时间
@property (nonatomic, assign) NSInteger dynamicWaterfallDateCount;
//上浮层数
@property (nonatomic, assign) NSInteger dynamicWaterfallUpwards;
//层数系数
@property (nonatomic, assign) CGFloat dynamicWaterfallWeight;

//从数据查出来的数据，对比后得出的最高价
@property (nonatomic, strong) NSString *highestPrice;
@property (nonatomic, strong) NSString *highestPriceUnitID;

@property (nonatomic, assign) BOOL isNeedFetchDatabaseHighestPrice;

@end

typedef NS_ENUM(NSUInteger, ATPlacementSettingType) {
    ATPlacementSettingTypeNormal,
    ATPlacementSettingTypePreset,
    ATPlacementSettingTypeCool,
};

#pragma mark - ATPlacementModel
@interface ATPlacementModel : ATModel <ATModelProtocol, ATStorageEntityProtocol>

-(instancetype) initWithDictionary:(NSDictionary *)dictionary associatedCustomData:(NSDictionary*)customData placementID:(NSString*)placementID;
-(instancetype) initWithDictionary:(NSDictionary *)dictionary placementID:(NSString*)placementID;

@property (nonatomic, strong) NSDictionary *originalPlacementDic;
@property (nonatomic, strong) NSDictionary *cachedDic;
@property (nonatomic, strong) NSDictionary *updateCachedDic;

@property (nonatomic, assign) ATCallSuccessType callSuccessType;

@property(nonatomic, readonly) NSDictionary *associatedCustomData;
@property(nonatomic, readonly) BOOL cachesPlacementSetting;
@property(nonatomic, readonly) ATAdFormat format;
@property(nonatomic, readonly) NSString *placementID;
@property(nonatomic, readonly) BOOL adDeliverySwitch;
@property(nonatomic, readonly) NSInteger groupID;
@property(nonatomic, readonly) BOOL refresh;
/**
 Auto refresh is for banner.
 */
@property(nonatomic, readonly) BOOL autoRefresh;
@property(nonatomic, readonly) NSTimeInterval autoRefreshInterval;
@property (nonatomic, assign) ATBannerAutoRefreshType bannerAutoRefreshType;
/**
 * How many unit groups to be loaded concurrently
 */

@property(nonatomic, readonly) ATLoadingRequestModelType loadingRequestModelType;
@property(nonatomic, readonly) NSInteger fixedMaxConcurrentRequestCount;
@property(nonatomic, readonly) NSInteger equalPriceMaxConcurrentRequestCount;

@property(nonatomic, readonly) NSString *psID;
@property(nonatomic, readonly) NSString *sessionID;
@property(nonatomic, readonly) ATADShowType showType;
/**
 Max showing times allowed in a day with -1 meaning no limitation
 */
@property(nonatomic, readonly) NSInteger unitCapsByDay;
/**
 Max showing times allowed in a hour with -1 meaning no limitation
 */
@property(nonatomic, readonly) NSInteger unitCapsByHour;
@property(nonatomic, readonly) NSTimeInterval unitPacing;
@property(nonatomic, readonly) BOOL wifiAutoSwitch;
@property(nonatomic, readonly) BOOL autoloadingEnabled;
@property(nonatomic, readonly) NSArray<ATUnitGroupModel*>* allUnitGroups;
@property(nonatomic, readonly) NSArray<ATUnitGroupModel*>* unitGroups;
@property(nonatomic, readonly) NSArray<ATUnitGroupModel*>* headerBiddingUnitGroups;
@property(nonatomic, readonly) NSArray<ATUnitGroupModel*>* S2SHeaderBiddingUnitGroups;
@property(nonatomic, readonly) NSArray<ATUnitGroupModel*>* olApiUnitGroups;
@property(nonatomic, readonly) NSArray<ATUnitGroupModel*>* inhouseUnitGroups;
@property(nonatomic, readonly) NSArray<ATUnitGroupModel*>* bksUnitGroups;
@property(nonatomic, readonly) NSArray<ATUnitGroupModel*>* bottomListUnitGroups;
@property(nonatomic, readonly) NSArray<ATUnitGroupModel*>* directOfferHeaderBiddingUnitGroups;

@property(nonatomic, readonly) NSArray<ATUnitGroupModel*>* dynamicHeaderBiddingUnitGroups;
@property(nonatomic, readonly) NSDictionary *dynamicHBAdUnitIds;

@property(nonatomic, readonly) NSTimeInterval bottomRreqts;     // bottomAd dalay request time

@property(nonatomic, readonly) NSTimeInterval headerBiddingRequestLongTimeout;

@property(nonatomic, readonly) NSTimeInterval headerBiddingRequestShortTimeout;

@property(nonatomic, readonly) NSString *S2SBidRequestAddress;
@property(nonatomic, readonly) NSString *waterFallBidRequestAddress;

@property(nonatomic, readonly) NSTimeInterval loadCapDuration;
@property(nonatomic, readonly) NSInteger loadCap;

@property(nonatomic, readonly) NSInteger expectedNumberOfOffers;


@property(nonatomic, readonly) NSTimeInterval bidWaitTimeout;
@property(nonatomic, readonly) NSTimeInterval reqWaitTimeout;

@property(nonatomic, readonly) NSTimeInterval loadFailureInterval;
@property(nonatomic, readonly) NSTimeInterval offerLoadingTimeout;
@property(nonatomic, readonly) NSTimeInterval statusValidDuration;//Upstatus
@property(nonatomic, readonly) NSString *asid;//generated by server side
@property(nonatomic, readonly) NSString *trafficGroupID;

@property(nonatomic, readonly) ATPlacementModelExtra *extra;

@property(nonatomic, readonly) NSInteger defaultNetworkFirmID;
@property(nonatomic, readonly) NSTimeInterval defaultAdSourceLoadingDelay;

/*
 */
@property(nonatomic, readonly) NSTimeInterval updateTolerateInterval;
@property(nonatomic, readonly) NSTimeInterval cacheValidDuration;
@property(nonatomic, readonly) NSDate *cacheDate;

@property(nonatomic, readonly) NSArray<ATMyOfferOfferModel*>* offers;
@property(nonatomic, readonly) ATMyOfferSetting *myOfferSetting;
@property(nonatomic, readonly) NSInteger usesDefaultMyOffer;
@property(nonatomic, readonly) BOOL preloadMyOffer;
//extra
@property(nonatomic, readonly) NSDictionary *callback;

@property(nonatomic, readonly) NSInteger FBHBTimeOut;

@property(nonatomic, readonly) NSDictionary* adxSettingDict;
@property(nonatomic, readonly) NSArray<ATUnitGroupModel*>* adxUnitGroups;
@property(nonatomic, readonly) NSArray<ATUnitGroupModel*>* adxOpenUnitGroups;

@property(nonatomic, readonly) NSDictionary* olApiSettingDict;

@property(nonatomic, readonly) NSTimeInterval waterfallFillTime;

@property(nonatomic, readonly) NSString *currency;
@property(nonatomic, readonly) NSString *exchangeRate;

@property(nonatomic, readonly) NSArray *bURLNotificationFirms;

// v5.7.10
@property(nonatomic, readonly) NSString *campaign;


@property (nonatomic, assign) BOOL isShowSendMTG;

@property (nonatomic, assign) BOOL isMediationIDSendGDT;

@property (nonatomic, strong) NSDictionary *placementABDic;
@property (nonatomic, assign) BOOL isDisplayPriceSwitch;

@property (nonatomic, assign) NSInteger admobEstimatePriceNum;

@property (nonatomic, readonly) NSInteger bidImprssionExtraNum;

@property (nonatomic, strong) NSString *sharePlacementId;

@property (nonatomic, assign) BOOL hasSharePlacementId;
@property (nonatomic, assign) BOOL isSharePlacement;

@property (nonatomic, strong) NSDictionary *baiduReportDic;


-(Class) adManagerClass;

- (NSDictionary *)revenueToPlatforms;

/**
 In order to solve the problem of inconsistency in legal tender. If the current ecpm currency is USD, this method returns NO.
 */
//- (BOOL)needConvertPrice;

/**
 If the current legal currency of ecpm is not USD, this method will calculate the corresponding price according to the latest exchange rate.
 */
//- (NSString *)convertedPrice:(NSString *)price;

//todo: just for in-house list. It's not a good solution.
@property(nonatomic, copy) NSArray<ATUnitGroupModel*>* allUnitGroupArray;


@property(nonatomic, copy) NSArray *directOfferUnitIDArray;


// v5.7.56+
@property(nonatomic, readonly) NSInteger encryptFlag;
@property(nonatomic, readonly, copy) NSString *encryptPublicKey;
@property(nonatomic, readonly, copy) NSDictionary *encryptApiDynamicInfoDic;

/**
 Maximum waiting time for s2s HB adSource to get buyeruid
 */
@property(nonatomic, readonly) NSInteger getBuyeruIdWaitTime;

@property(nonatomic, readonly, copy) NSString *inhouseUrl;
@property(nonatomic, readonly, copy) NSString *thirdInhouseUrl; // bks url of third plantforms

@property(nonatomic, readonly) NSString *exchRateC2U;
@property (nonatomic,readonly) NSString *bidFloor;

@property (nonatomic,readonly) NSInteger s2sBidMax;

@property(nonatomic, assign) BOOL isExistHBAdSource;
@property(nonatomic, assign) BOOL loadSuccessRetrySwitch;
@property(nonatomic, assign) BOOL loadFailRetrySwitch;
@property (nonatomic,assign) BOOL requestMerge;

@property(nonatomic, readonly) NSDictionary *gspRatesDic;
@property (nonatomic,readonly) NSString *adxExtJson;

@property (nonatomic, readonly) NSArray *loaddingTypeSwitchArray;

@property (nonatomic, readonly) BOOL isSetPangleRequestId;

/// 当使用SDK预置策略（或 开屏内置广告源）请求WF时,在WF结束后TopOn SDK根据广告位策略参数(presetwf_reload_sw)判断本次是否需要在WF结束后使用线上返回的广告位策略再执行一次WF
@property (nonatomic, assign) BOOL shouldLoadMoreWhenPresetLoaded;
@property (nonatomic, assign) BOOL hasCoolPlacementSettings;
@property (nonatomic, assign) ATPlacementSettingType type;

@property (nonatomic, assign) BOOL isUsePlacementSettingsFirst;
@property (nonatomic, assign) BOOL isSaveUserValueData;

@property (nonatomic, readonly) ATPlacementModelUserValueTimingType userValueTimingType;
@property (nonatomic, readonly) ATPlacementModelUserValueStrategyIndexType userValueStrategyIndex;
@property (nonatomic, readonly) NSInteger userValueReportCount;
@property (nonatomic, readonly) NSArray<NSArray<NSNumber *> *> *userValuePriceRanges;

@property (nonatomic, readonly) ATPlacementModelWaterfallModeType waterfallModeType;
@property (nonatomic, readonly) NSInteger serialMultiCachModeMaxConcurrentRequsetCount;
@property (nonatomic, readonly) ATLoadingRequestModelType serialMultiCachModeRequestModelType;
@property (nonatomic, readonly) NSTimeInterval LoadFailedAutoRetryLoadInterval;
@property (nonatomic, readonly) NSInteger statusNum;
@property (nonatomic, readonly) ATPlacementModelBaiduReportType baiduReportType;

@property(nonatomic, readonly) BOOL s2sSwitch;

@property (nonatomic, assign) ATNativeMixBannerStyleType nativeMixBannerStyleType;

@property (nonatomic, strong) NSValue *developerBannerSizeValue;
@property (nonatomic, assign) CGSize developerBannerSize;
@property (nonatomic, strong) NSArray *mixAdClickAreaArray;

//动态瀑布流开关
@property (nonatomic, assign) BOOL dynamicWaterfallSwitch;
@property (nonatomic, strong) ATDynamicWaterfallParams *dynamicWaterfall;

- (CGFloat)getNetworkgspRate:(NSString *)networkFirmID;
- (void)parsingUnitGroupsWithDictionary:(NSDictionary *)dictionary;
#pragma mark -NewDepart

- (ATMyOfferOfferModel *)miniCapForMyOffers;

@end
