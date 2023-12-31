//
//  ATNativeADConfiguration.h
//  AnyThinkSDK
//
//  Created by Martin Lau on 20/04/2018.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const kATNativeAdConfigurationContextAdOptionsViewFrameKey;//CGRect wrapped as NSValue, supported by facebook
extern NSString *const kATNativeAdConfigurationContextAdLogoViewFrameKey;//CGRect wrapped as NSValue, supported by gdt&baidu, defaults to top-left corner
extern NSString *const kATNativeAdConfigurationContextNetworkLogoViewFrameKey;//CGRect wrapped as NSValue, support by baidu, defaults to bottom-right corner
@protocol ATNativeADDelegate;
@class ATNativePrepareInfo;

@interface ATNativeADConfiguration : NSObject
/**
 You can store some extra network specific context info in this dictionary.
 */
@property(nonatomic) NSDictionary *context;
@property(nonatomic) Class renderingViewClass;
@property(nonatomic) CGRect ADFrame;
@property(nonatomic) CGRect mediaViewFrame;
@property(nonatomic, weak) UIViewController *rootViewController;
@property(nonatomic, weak) id<ATNativeADDelegate> delegate;
@property(nonatomic) BOOL sizeToFit;
@property(nonatomic) BOOL useCustomPlayer;

@property(nonatomic, strong) ATNativePrepareInfo *nativePrepareInfo;


@end

NS_ASSUME_NONNULL_END
