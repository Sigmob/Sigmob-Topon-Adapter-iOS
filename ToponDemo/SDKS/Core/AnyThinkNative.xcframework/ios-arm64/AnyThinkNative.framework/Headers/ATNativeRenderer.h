//
//  ATNativeRenderer.h
//  AnyThinkSDK
//
//  Created by Martin Lau on 25/04/2018.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AnyThinkSDK/AnyThinkSDK.h>
#import "ATNativeADRenderer.h"

@class ATNativeADCache;

NS_ASSUME_NONNULL_BEGIN

@protocol ATNativeADRenderer;
@interface ATNativeRenderer : NSObject<ATNativeADRenderer>

-(UIView*)retriveADView;
- (void)recordCustomPlayerStatus:(ATPlayerStatus)status currentTime:(NSTimeInterval)time;
-(instancetype) initWithConfiguraton:(ATNativeADConfiguration*)configuration adView:(ATNativeADView*)adView;
-(__kindof UIView*)createMediaView;
@property(nonatomic, weak) ATNativeADView *ADView;
@property(nonatomic, readonly) ATNativeADConfiguration *configuration;

- (UIView *)getNetWorkMediaView;

- (UIView *)getNetWorkShakeView:(ATNativeADCache *)offer frame:(CGRect)frame;

- (UIView *)getNetworkSlideViewWithOffer:(ATNativeADCache *)offer frame:(CGRect)frame repeat:(int)repeat animationWidth:(CGFloat)animationWidth animationHeight:(CGFloat)animationHeight;

// for override
- (void)closeAct;


@end

NS_ASSUME_NONNULL_END
