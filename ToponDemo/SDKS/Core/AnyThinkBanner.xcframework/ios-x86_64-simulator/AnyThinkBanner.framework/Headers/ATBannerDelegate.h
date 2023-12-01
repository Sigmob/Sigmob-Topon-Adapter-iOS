//
//  ATBannerDelegate.h
//  AnyThinkSDK
//
//  Created by Martin Lau on 18/09/2018.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

#ifndef ATBannerDelegate_h
#define ATBannerDelegate_h

#import <AnyThinkSDK/AnyThinkSDK.h>

@class ATBannerView;

NS_ASSUME_NONNULL_BEGIN

extern NSString *const kATBannerDelegateExtraNetworkIDKey; // Network Firm Id of Banner
extern NSString *const kATBannerDelegateExtraAdSourceIDKey; // ad source ID of Banner
extern NSString *const kATBannerDelegateExtraAdSourceIsHeaderBidding; // Whether the ad source is head bidding,1: yes, 2: no
extern NSString *const kATBannerDelegateExtraPrice; // Get Estimate eCPM
extern NSString *const kATBannerDelegateExtraPriority; // the sort of the current Banner ad source in WaterFall


@protocol ATBannerDelegate<ATAdLoadingDelegate>

/// BannerView display results
- (void)bannerView:(ATBannerView *)bannerView didShowAdWithPlacementID:(NSString *)placementID extra:(NSDictionary *)extra;

/// bannerView click
- (void)bannerView:(ATBannerView *)bannerView didClickWithPlacementID:(NSString *)placementID extra:(NSDictionary *)extra;

@optional

/// bannerView auto refresh
- (void)bannerView:(ATBannerView *)bannerView didAutoRefreshWithPlacement:(NSString *)placementID extra:(NSDictionary *)extra;

/// BannerView auto refresh failed
- (void)bannerView:(ATBannerView *)bannerView failedToAutoRefreshWithPlacementID:(NSString *)placementID error:(NSError *)error;

/// bannerView click the close button
- (void)bannerView:(ATBannerView *)bannerView didTapCloseButtonWithPlacementID:(NSString *)placementID extra:(NSDictionary *)extra;

/// Whether the bannerView click jump is in the form of Deeplink
/// currently only returns for TopOn Adx advertisements
- (void)bannerView:(ATBannerView *)bannerView didDeepLinkOrJumpForPlacementID:(NSString *)placementID extra:(NSDictionary *)extra result:(BOOL)success;

@end

#endif /* ATBannerDelegate_h */

NS_ASSUME_NONNULL_END
