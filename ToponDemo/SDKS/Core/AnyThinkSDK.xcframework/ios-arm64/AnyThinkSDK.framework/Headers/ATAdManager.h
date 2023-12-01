//
//  ATAdManager.h
//  AnyThinkSDK
//
//  Created by Martin Lau on 04/05/2018.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>
#import "ATUnitGroupModel.h"
#import "ATADXFloorPrice.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString *const kATAdAssetsNativeCustomEventKey;
extern NSString *const kATAdAssetsCustomEventKey;
extern NSString *const kATAdAssetsCustomObjectKey;
extern NSString *const kATExtraInfoRootViewControllerKey;
extern NSString *const kATAdAssetsDelegateObjKey;
extern NSString *const kATAdAssetsCustomNativeAdKey;

extern NSString *const kATAdLoadingExtraMediaExtraKey;
extern NSString *const kATAdLoadingExtraNetworkPlacementIDKey;
extern NSString *const kATAdLoadingExtraAdmobContentURLStringsKey;

/*
 * Banner's ad size, the value is a NSValue wrapped CGSize; for banner ad loading,
 * we only support (320.0f, 50.0f) now, so the value you pass via this key will be ignored.
 */
extern NSString *const kATExtraInfoAdSizeKey;
extern NSString *const kATAdLoadingExtraGDTEnableDefaultAudioSessionKey;

typedef BOOL(^AdSourceCustomizeFillterBlock)(NSDictionary *extra);

@protocol ATAdLoadingDelegate;

@interface ATAdManager : NSObject

@property (nonatomic,strong) NSDictionary *extra;
@property (nonatomic,strong) NSMutableDictionary *exludeUnitIDDic;
@property (nonatomic,strong) NSMutableDictionary *exludeNetworkFirmIDDic;

@property(nonatomic, copy) AdSourceCustomizeFillterBlock adSourceCustomizeFillter;

/// singleton object
+ (instancetype)sharedManager;

/// Called when load ad
/// @param placementID - TopOn's ad placement id
/// @param extra - Local configuration parameter
/// @param delegate - delegate object
- (void)loadADWithPlacementID:(NSString *)placementID
                        extra:(NSDictionary *)extra
                     delegate:(id<ATAdLoadingDelegate>)delegate;

- (void)loadADWithPlacementID:(NSString *)placementID
                        extra:(NSDictionary *)extra
                      tkExtra:(nullable NSDictionary *)tkExtra
                adxFloorPrice:(nullable ATADXFloorPrice *)adxFloorPrice
                     delegate:(id<ATAdLoadingDelegate>)delegate;

- (void)setExludePlacementid:(NSString *)placementid
                 unitIDArray:(NSArray <NSString *> *)unitIDArray;


/// Set the network that needs to be excluded when loading an placement, will take effect on the next load
/// @param placementid  - TopOn's ad placement id
/// @param networkFirmIDArray - need to be excluded networkFirmIds
- (void)setExludePlacementid:(NSString *)placementid
          networkFirmIDArray:(NSArray <NSNumber *> *)networkFirmIDArray;

- (BOOL)splashReadyWithoutLogForPlacementID:(NSString *)placementID
                                     sendTK:(BOOL)send;

- (NSDictionary *)extraInfoForPlacementID:(NSString*)placementID
                                requestID:(NSString*)requestID;

- (void)setAdSourceCustomizeFillterPlacementIDArray:(NSArray <NSString *> *)placementIDArray;


/// Notify us after custom close ad only
/// @param placementID  - TopOn's ad placement id
- (void)customCloseADEventWithPlacementID:(NSString *)placementID;

@end

NS_ASSUME_NONNULL_END
