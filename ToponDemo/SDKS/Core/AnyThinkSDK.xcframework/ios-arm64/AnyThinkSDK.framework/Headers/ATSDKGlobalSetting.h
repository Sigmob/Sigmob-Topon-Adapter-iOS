//
//  ATSDKGlobalSetting.h
//  AnyThinkSDK
//
//  Created by Topon on 8/23/23.
//  Copyright © 2023 AnyThink. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ATSDKGlobalSetting : NSObject

+ (instancetype)sharedManager;

/// Splash Shake Text String, Only for DirectlyAd
@property (nonatomic, strong) NSString *directlySplashAdShakeTextString;

/// Splash CTA Button BackgroundColor, Only for DirectlyAd
@property (nonatomic, strong) UIColor *directlySplashAdCTAButtonBackgroundColor;

/// Whether to pause the countdown after clicking on the  Splash ad to jump, the default is NO, Only for TopOn ADX、DirectlyAd and Cross Promotion
@property (nonatomic, assign) BOOL clickToPauseCountdownSplashAd;

@end

NS_ASSUME_NONNULL_END
