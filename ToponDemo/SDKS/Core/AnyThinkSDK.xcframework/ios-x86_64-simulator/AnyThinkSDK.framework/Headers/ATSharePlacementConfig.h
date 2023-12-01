//
//  ATSharePlacementConfig.h
//  AnyThinkSDK
//
//  Created by Topon on 4/24/23.
//  Copyright © 2023 AnyThink. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ATSharePlacementConfig : NSObject

/// for share placement load splash extra
@property (nonatomic, strong) NSDictionary *splashLoadExtra;

/// for share placement load interstitial extra
@property (nonatomic, strong) NSDictionary *interstitialLoadExtra;

/// for share placement load rewardedVideo extra
@property (nonatomic, strong) NSDictionary *rewardedVideoLoadExtra;

/// for share placement load banner extra
@property (nonatomic, strong) NSDictionary *bannerLoadExtra;

/// for share placement load native extra
@property (nonatomic, strong) NSDictionary *nativeLoadExtra;

@end

NS_ASSUME_NONNULL_END
