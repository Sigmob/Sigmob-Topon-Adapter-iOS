//
//  ATAPI+Internal.h
//  AnyThinkSDK
//
//  Created by Martin Lau on 08/05/2018.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

#ifndef ATAPI_Internal_h
#define ATAPI_Internal_h
#import "ATAPI.h"

extern NSString *const kATNetWorkVideoStatusKey;

extern NSString *const kATNativeADAssetsAdvertiserKey;
extern NSString *const kATNativeADAssetsMainTextKey;
extern NSString *const kATNativeADAssetsMainTitleKey;
extern NSString *const kATNativeADAssetsMainImageKey;
extern NSString *const kATNativeADAssetsIconImageKey;
extern NSString *const kATNativeADAssetsLogoImageKey;
extern NSString *const kATNativeADAssetsCTATextKey;
extern NSString *const kATNativeADAssetsRatingKey;
extern NSString *const kATNativeADAssetsContainsVideoFlag;
extern NSString *const kATNativeADAssetsUnitIDKey;
extern NSString *const kATNativeADAssetsIconURLKey;
extern NSString *const kATNativeADAssetsImageURLKey;
extern NSString *const kATNativeADAssetsLogoURLKey;
extern NSString *const kATNativeADAssetsVideoUrlKey;
extern NSString *const kATAdAssetsCustomObjectKey;
extern NSString *const kATNativeADAssetsMediaViewKey;
extern NSString *const kATNativeADAssetsImageListKey;
extern NSString *const kATNativeADAssetsVideoDurationKey;
extern NSString *const kATNativeADAssetsVideoAspectRatioKey;
extern NSString *const kATNativeADAssetsNativeExpressAdViewWidthKey;
extern NSString *const kATNativeADAssetsNativeExpressAdViewHeightKey;
extern NSString *const kATNativeADAssetsInteractionTypeKey;
extern NSString *const kATNativeADAssetsVideoMutedTypeKey;
extern NSString *const kATNativeADAssetsMainImageWidthKey;
extern NSString *const kATNativeADAssetsMainImageHeightKey;
extern NSString *const kATNativeADAssetsMediaExtKey;
extern NSString *const kATNativeADAssetsSourceKey;
extern NSString *const kATNativeADAssetsCommentNumKey;
extern NSString *const kATNativeADAssetsAppSizeKey;
extern NSString *const kATNativeADAssetsAppPriceKey;
extern NSString *const kATNativeADAssetsDomainKey;
extern NSString *const kATNativeADAssetsWarningKey;
extern NSString *const kATNativeADAssetsIsExpressAdKey;

extern NSString *const kATADLoadingStartLoadNotification;
extern NSString *const kATADLoadingOfferSuccessfullyLoadedNotification;
extern NSString *const kATADLoadingFailedToLoadNotification;
extern NSString *const kATADLoadingNotificationUserInfoRequestIDKey;
extern NSString *const kATADLoadingNotificationUserInfoPlacementIDKey;
extern NSString *const kATADLoadingNotificationUserInfoPlacementKey;//Not used
extern NSString *const kATADLoadingNotificationUserInfoUnitGroupKey;//Not used
extern NSString *const kATADLoadingNotificationUserInfoErrorKey;
extern NSString *const kATADLoadingNotificationUserInfoExtraKey;
extern NSString *const kATADLoadingNotificationUserInfoLoadingTypeKey;


extern NSString *const kATAgentEventKeyCachedKey;
extern NSString *const kATAgentEventKeyCacheTypeKey;
extern NSString *const kATAgentEventKeyCacheMapKey;
extern NSString *const kATAgentEventKeyCacheNewSerialNumberKey;
extern NSString *const kATAgentEventKeyCacheOldSerialNumberKey;

extern NSString *const kATAgentEventKeyDynamicWaterfall;


/**
 Adopters are expected to implement logic for network offers, for which storage mechanisms must be devise.
 */
@protocol ATNativeAdapter<NSObject>
/**
 The class of the renderer used to render the AD view. This method is a class-method because by the time this information is needed the adapter instance will have been released.
 */
+(Class) rendererClass;
/**
 Adopter should implement this method for the initialization of a adapter instance, which will store the passed info for further use.
 
 */
-(instancetype) initWithNetworkCustomInfo:(NSDictionary*)serverInfo localInfo:(NSDictionary*)localInfo;

/**
 Adopter should implement this method to load network offers.
 
 @param completion might need to be stored and invoked after ad's succeffully loaded.
 Parameters passed to the completion block include a dictionary and an error objects. The error object encapsulates the error info if loading request failed somehow; the dictionary contains all publicly accessible assets (such as title and text) for the native ad, which should be stored using the keys predefined by the SDK.
 */
-(void) loadADWithInfo:(NSDictionary*)serverInfo localInfo:(NSDictionary*)localInfo completion:(void(^)(NSArray<NSDictionary*>* assets, NSError *error))completion;

@property (nonatomic,copy) void (^metaDataDidLoadedBlock)(void);
@end

@interface ATAPI(Internal)
+(ATLogType)logType;
+(BOOL)logEnabled;
+(BOOL)adLogoVisible;
+(NSString *)hbTestModeDeviceID;
+(ATSystemPlatformType)systemPlatformType;
-(void) setVersion:(NSString*)version forNetwork:(NSString*)network;
-(NSDictionary*)networkVersions;
-(NSString*)versionForNetworkFirmID:(NSInteger)networkFirmID;
-(BOOL) initFlagForNetwork:(NSString*)networkName;
-(void) setInitFlagForNetwork:(NSString*)networkName;
- (BOOL)cacheFlagForNetwork:(NSString*)networkName;
- (void)setCacheFlagForNetwork:(NSString*)networkName;
-(void) inspectInitFlagForNetwork:(NSString*)networkName usingBlock:(NSInteger(^)(NSInteger currentValue))block;
-(void) setInitFlag:(NSInteger)flag forNetwork:(NSString*)networkName;
-(NSDictionary*)calculateCustomData;
- (BOOL)isNetworkAvailable;
- (void)updateNetworkAvailable:(BOOL)isAvailable;
@property(nonatomic, readonly) NSString *userAgent;

@property (nonatomic, readonly) BOOL isAppActive;
@property (nonatomic, readonly) BOOL isAppForeground;
@property (nonatomic, strong) ATSharePlacementConfig *sharePlacementConfig;
@end

#endif /* ATAPI_Internal_h */
