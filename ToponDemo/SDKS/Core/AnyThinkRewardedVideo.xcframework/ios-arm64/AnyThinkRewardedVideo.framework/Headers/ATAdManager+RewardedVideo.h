//
//  ATAdManager+RewardedVideo.h
//  AnyThinkSDK
//
//  Created by Martin Lau on 05/07/2018.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

#import <AnyThinkSDK/AnyThinkSDK.h>
#import "ATRewardedVideoDelegate.h"

NS_ASSUME_NONNULL_BEGIN

/*
 * Third-party extra data
 */
extern NSString *const kATAdLoadingExtraKeywordKey;
extern NSString *const kATAdLoadingExtraUserDataKeywordKey;
extern NSString *const kATAdLoadingExtraUserIDKey;
extern NSString *const kATAdLoadingExtraLocationKey;
extern NSString *const kATAdLoadingExtraRewardNameKey;
extern NSString *const kATAdLoadingExtraRewardAmountKey;

extern NSString *const kATRewardedVideoCallbackExtraAdsourceIDKey; // ad source ID of RewardedVideo
extern NSString *const kATRewardedVideoCallbackExtraNetworkIDKey; // Network Firm Id of RewardedVideo

// Klevin SDK
extern NSString *const kATRewardedVideoKlevinRewardTimeKey;
extern NSString *const kATRewardedVideoKlevinRewardTriggerKey;


@interface ATAdManager (RewardedVideo)

/// Display this ad slot rewarded video ad
/// @param placementID - TopOn's ad placement id
/// @param viewController  - display ad window
/// @param delegate - delegate object
- (void)showRewardedVideoWithPlacementID:(NSString *)placementID
                        inViewController:(UIViewController *)viewController
                                delegate:(id<ATRewardedVideoDelegate>)delegate;

/// Display this ad slot rewarded video ad
/// @param placementID - TopOn's ad placement id
/// @param scene - the scene id
/// @param viewController  - display ad window
/// @param delegate - delegate object
- (void)showRewardedVideoWithPlacementID:(NSString *)placementID
                                   scene:(NSString *)scene
                        inViewController:(UIViewController*)viewController
                                delegate:(id<ATRewardedVideoDelegate>)delegate;

/// check whether the rewardedVideo ad is ready
/// v5.7.06+
- (BOOL)rewardedVideoReadyForPlacementID:(NSString *)placementID;

/// Get the status object of the current ad slot ATCheckLoadModel
- (ATCheckLoadModel *)checkRewardedVideoLoadStatusForPlacementID:(NSString *)placementID DEPRECATED_MSG_ATTRIBUTE("use rewardedVideoReadyForPlacementID instead ");

/// Query all cached information of the ad slot
- (NSArray<NSDictionary *> *)getRewardedVideoValidAdsForPlacementID:(NSString *)placementID;

/// Enter the current ad slot cache status statistics in the business scenario.
/// @param scene - ad Scenario
/// v5.7.91+
- (void)entryRewardedVideoScenarioWithPlacementID:(NSString *)placementID
                                            scene:(NSString *)scene;


@end

NS_ASSUME_NONNULL_END
