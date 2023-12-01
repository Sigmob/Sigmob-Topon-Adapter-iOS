//
//  ATAppSettingManager.h
//  AnyThinkSDK
//
//  Created by Martin Lau on 09/04/2018.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ATAPI+Internal.h"
#import "ATModel.h"


NS_ASSUME_NONNULL_BEGIN
//The keyed value stores the flag as to whether or not clients are expected to upload the offer metadata
extern NSString *const kATAppSettingGDPAFlag;
extern NSString *const kATAppSettingGDPRPolicyURLKey;
extern NSString *const kATSDKCustomChannel;

extern NSString *const kATGeoLongitudeKey;
extern NSString *const kATGeoDimensionKey;

@class ATTrackingSetting;
@class ATADXSetting;
@class ATOnlineApiSetting;
@class ATPlacementModel;
@class ATSharePlacementSetting;
@class ATSharePlacementItem;

@interface ATAppSettingManager : NSObject

+(instancetype)sharedManager;

// 切换域名,重新请求APP策略
- (void)requestAppSettingCompletion:(void(^)(NSDictionary *setting, NSError *error))completion;

// 切换域名,要不要重新请求APP策略
- (void)requestAppSettingCompletion:(void(^)(NSDictionary *setting, NSError *error))completion retry:(BOOL)retry;

/**
 * The following setting accessing methods are thread-safe.
 */
- (BOOL)currentSettingExpired;
- (NSTimeInterval)splashTolerateTimeout;
- (BOOL)usesServerDataConsentSet;
- (BOOL)complyWithCOPPA;
- (BOOL)complyWithCCPA;
- (NSTimeInterval)psIDInterval;
- (NSTimeInterval)psIDIntervalForHotLaunch;
- (ATDataConsentSet)serverDataConsentSet;
- (ATDataConsentSet)commonTkDataConsentSet;
- (NSUInteger)myOfferMaxResourceLength;
- (NSArray *)preinitInfoArr;
- (BOOL)limitThirdPartySDKDataCollection:(BOOL*)setThirdPartySDK networkFirmID:(NSInteger)networkFirmID;
- (BOOL)shouldUploadProtectedFields;
/**
 * If the SDK has been init-ed the first time, the data protected area list will be the embeded one(stored in the Info.plist of the SDK bundle under the key Data Protection Area); or it'll be the one that's returned by the server.
 */
- (BOOL)inDataProtectedArea;
- (void)getUserLocationWithCallback:(void(^)(ATUserLocation location))callback;
- (void)getAreaSuccess:(void(^)(NSString *areaCodeStr))success
                failure: (void(^)(NSError *error))failure;
- (void)setLocationLongitude:(double)longitude dimension:(double)dimension;
- (void)setIsInstallWX:(BOOL)isInstallWX;
- (void)preLoadAPPFodderImage;

- (NSDictionary *)userValueDQLWithPlacement:(ATPlacementModel *)placementId;

@property(nonatomic,strong) NSDictionary *locationDic;

@property(nonatomic, strong) NSDictionary *currentSetting;

@property(nonatomic, readonly) NSDictionary *defaultSetting;

@property(nonatomic, readonly) ATTrackingSetting *trackingSetting;

@property(nonatomic, readonly) ATADXSetting *adxSetting;

@property(nonatomic, readonly) ATOnlineApiSetting *onlineApiSetting;

@property(nonatomic, readonly) NSString *ABTestID;

@property(nonatomic, readonly) NSString *s2sAddress;

@property(nonatomic, readonly) NSString *isInstallWXStr;

@property(nonatomic, assign,getter=isAdmobMediationStatus) BOOL admobMediationStatus;

@property (nonatomic, strong) NSDictionary *appListDic;

@property(atomic) ATSharePlacementSetting *sharePlacementSetting_impl;

/*
 *up id
 */
@property(nonatomic, readonly) NSString* ATID;
/**
 * sysid
 */
@property(nonatomic, readonly) NSString* SYSID;
/**
 * bkupid
 */
@property(nonatomic, readonly) NSString* BKUPID;
/// 是否允许adx原生自渲染提供图片宽高获取能力(sdk6.2.77) 1：允许，2：不允许，默认为2
@property (nonatomic, assign) BOOL isPermitAdGetImagWH;

@property(nonatomic, readonly) NSString *clickNotificationName;
@property(nonatomic, readonly) NSString *showNotificationName;
// 6.1.10
@property (nonatomic, strong) NSString *showDelayUrl;
@property (nonatomic, strong) NSString *showDelayText;

@property (nonatomic, readonly) NSDictionary *requestFailIntervalRuleDic;

@property (nonatomic, strong) NSDictionary *appSettingABDic;

@property (nonatomic, strong) NSDictionary *cachedDic;
@property (nonatomic, strong) NSDictionary *updateCachedDic;

@property (nonatomic, strong) NSArray *guidedClickFodderArray;
@property (nonatomic, strong) NSArray *redPacketFodderArray;
@property (nonatomic, strong) NSArray *cardFodderArray;

@property (nonatomic, strong) NSArray <UIImage *>*cardImageFodderArray;

@property (nonatomic, strong) NSArray *allAnimationFodderArray;

+(NSDictionary*)parameters;

- (nullable NSArray *)cardImageFodder;
@end



@interface ATTrackingSetting:ATModel
+(instancetype) defaultSetting;
@property(nonatomic, readonly) NSString *trackerAddress;
@property(nonatomic, readonly) NSInteger trackerNumberThreadhold;
@property(nonatomic, readonly) NSTimeInterval trackerInterval;
@property(nonatomic, readonly) BOOL sendsDataEveryInterval;
@property(nonatomic, readonly) NSString *agentEventAddress;
@property(nonatomic, readonly) NSInteger agentEventNumberThreadhold;
@property(nonatomic, readonly) NSTimeInterval agentEventInterval;
@property(nonatomic, readonly) NSArray<NSString*>* agentEventDropNetworks;
@property(nonatomic, readonly) NSDictionary<NSString*, NSArray<NSString*>*>* agentEventDropFormats;
@property(nonatomic, readonly) NSDictionary<NSString*, NSArray<NSString*>*>* agentEventRTFormats;

@property(nonatomic, readonly) NSDictionary<NSString*, NSDictionary*>* trackRealTimeFormatDic;
@property(nonatomic, readonly) NSDictionary<NSString*, NSDictionary*>* agentRealTimeFormatDic;



/*
 *for batch upload
 */
@property(nonatomic, readonly) NSInteger agentEventBatNumberThreadhold;
@property(nonatomic, readonly) NSInteger agentEventBatInterval;


//TCP
@property(nonatomic, readonly) NSString *trackerTCPAddress;
@property(nonatomic, readonly) NSInteger trackerTCPPort;
@property(nonatomic, readonly) NSInteger trackerTCPType;
@property(nonatomic, readonly) NSString *trackerTCPRate;

//TC
@property(nonatomic, readonly) NSArray<NSString*>* tcHosts;
@property(nonatomic, readonly) NSDictionary<NSString*, NSArray<NSString*>*>* tcTKSkipFormats;
@property(nonatomic, readonly) NSArray<NSString*>* tcTKSkipNetworks;



@end

@interface ATADXSetting:ATModel
+(instancetype) defaultSetting;
@property(nonatomic, readonly) NSString *reqHttpAddress;
@property(nonatomic, readonly) NSString *reqTCPAdress;

@property(nonatomic, readonly) NSInteger reqTCPPort;
@property(nonatomic, readonly) NSInteger reqNetType;

@property(nonatomic, readonly) NSString *bidHttpAddress;
@property(nonatomic, readonly) NSString *bidTCPAdress;
@property(nonatomic, readonly) NSInteger bidTCPPort;
@property(nonatomic, readonly) NSInteger bidNetType;

@property(nonatomic, readonly) NSString *trackerHttpAdress;
@property(nonatomic, readonly) NSString *trackerTCPAdress;
@property(nonatomic, readonly) NSInteger trackerTCPPort;
@property(nonatomic, readonly) NSInteger trackerNetType;

@end

@interface ATOnlineApiSetting:ATModel
+(instancetype) defaultSetting;
@property(nonatomic, readonly) NSString *reqHttpAddress;

@property(nonatomic, readonly) NSString *reqTCPAdress;
@property(nonatomic, readonly) NSInteger reqTCPPort;
@property(nonatomic, readonly) NSInteger reqNetType;

@property(nonatomic, readonly) NSString *trackerHttpAdress;
@property(nonatomic, readonly) NSString *trackerTCPAdress;
@property(nonatomic, readonly) NSInteger trackerTCPPort;
@property(nonatomic, readonly) NSInteger trackerNetType;

@end

#pragma mark - ATSharePlacementSetting
@interface ATSharePlacementItem : ATModel

@property (nonatomic, strong) NSString *placementId;
@property (nonatomic, assign) ATAdFormat format;
@property (nonatomic, assign) NSTimeInterval timingLoadInterval;
@property (nonatomic, assign) NSInteger cacheNumberThreshold;
@property (nonatomic, strong) NSString *ecpmThreshold;

@end

#pragma mark - ATSharePlacementSetting

typedef NS_ENUM(NSUInteger, ATSharePlacementSettingPreLoadType) {
    ATSharePlacementSettingPreLoadTypeStart = 1,
    ATSharePlacementSettingPreLoadTypeBinding,
};

@interface ATSharePlacementSetting : ATModel
+ (instancetype)defaultSetting;
@property (nonatomic, assign) NSTimeInterval loadInterval;
@property (nonatomic, assign) NSInteger loadNubmer;
@property (nonatomic, assign) NSTimeInterval shortTimeOutInterval;

@property (nonatomic, strong) NSMutableDictionary<NSString *, ATSharePlacementItem *> *itemDict;
@property (nonatomic, strong) NSMutableArray<ATSharePlacementItem *> *sharePlacementList;

@property (nonatomic, assign) ATSharePlacementSettingPreLoadType preLoadType;

@end
NS_ASSUME_NONNULL_END
