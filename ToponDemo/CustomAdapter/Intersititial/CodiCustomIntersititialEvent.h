//
//  CodiCustomIntersititialEvent.h
//  ToponDemo
//
//  Created by Codi on 2023/11/28.
//

#import <Foundation/Foundation.h>
#import <AnyThinkSDK/ATBidInfoCacheManager.h>
#import <AnyThinkInterstitial/AnyThinkInterstitial.h>
#import <WindSDK/WindSDK.h>


NS_ASSUME_NONNULL_BEGIN

@interface CodiCustomIntersititialEvent : ATInterstitialCustomEvent<WindNewIntersititialAdDelegate>

@property(nonatomic, copy) NSString *price;

@property (nonatomic,copy) void (^bidCompletionBlock)(ATBidInfo *bidInfo, NSError *error);

@end

NS_ASSUME_NONNULL_END
