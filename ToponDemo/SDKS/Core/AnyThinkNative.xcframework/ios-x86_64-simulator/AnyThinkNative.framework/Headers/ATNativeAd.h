//
//  ATNativeAd.h
//  AnyThinkSDK
//
//  Created by Martin Lau on 02/05/2018.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN
typedef NS_ENUM (NSInteger, ATNativeAdInteractionType) {
    ATNativeAdInteractionTypeUnknown        = 0,
    ATNativeAdInteractionTypeNone           = 1,  // pure ad display
    ATNativeAdInteractionTypeURL            = 2,  // open the webpage using a browser
    ATNativeAdInteractionTypePage           = 3,  // open the webpage within the app
    ATNativeAdInteractionTypeDownload       = 4,  // download the app
    ATNativeAdInteractionTypePhone          = 5,  // make a call
    ATNativeAdInteractionTypeMessage        = 6,  // send messages
    ATNativeAdInteractionTypeEmail          = 7,  // send email
    ATNativeAdInteractionTypeVideoAdDetail  = 8,  // video ad details page
    ATNativeAdInteractionTypeWechat         = 9,  // open wechat
    ATNativeAdInteractionTypeOthers         = 100 // types returned by other ad sdk
};

@interface ATNativeAd : NSObject

/// Advertiser, advertiser's name or link
@property(nonatomic, readonly, nullable) NSString * advertiser;

/// ad title
@property(nonatomic, readonly, nullable) NSString *title;

/// Ad details
@property(nonatomic, readonly, nullable) NSString *mainText;

/// CTA Button text such as 'download/install'
@property(nonatomic, readonly, nullable) NSString *ctaText;

/// app  icon
@property(nonatomic, readonly, nullable) UIImage *icon;

/// main image
@property(nonatomic, readonly, nullable) UIImage *mainImage;

/// ad logo
@property(nonatomic, readonly, nullable) UIImage *logo;

/// video url
@property(nonatomic, readonly, nullable) NSString *videoUrl;

/// ad logo url
@property(nonatomic, readonly, nullable) NSString *logoUrl;

/// app icon url
@property(nonatomic, readonly, nullable) NSString *iconUrl;

/// main image url
@property(nonatomic, readonly, nullable) NSString *imageUrl;

/// main image width
@property(nonatomic, readonly) CGFloat mainImageWidth;

/// main image height
@property(nonatomic, readonly) CGFloat mainImageHeight;

/// mediaView
@property(nonatomic, readonly, nullable) UIView *mediaView;

/// image url list
@property(nonatomic, readonly, nullable) NSArray<NSString *> *imageList;

/// video duration, in second, if there is no value, return 0
@property(nonatomic, readonly) NSInteger videoDuration;

/// video aspect ratio (width/height), if no value or exception returns 0
@property (nonatomic, assign, readonly) CGFloat videoAspectRatio;

/// Only for template AdView
@property(nonatomic, readonly) CGFloat nativeExpressAdViewWidth;
@property(nonatomic, readonly) CGFloat nativeExpressAdViewHeight;

/// Ad-supported jump types
@property(nonatomic, assign, readonly) ATNativeAdInteractionType interactionType;

/// media extension data
@property(nonatomic, copy, readonly, nullable) NSDictionary *mediaExt;

/// app source, marketplace, such as 'App Store'
@property(nonatomic, copy, readonly, nullable) NSString *source;

/// app rating
@property(nonatomic, readonly, nullable) NSNumber *rating;

/// the number of comments, or -1 if there is no value
@property(nonatomic, assign, readonly) NSInteger commentNum;

/// the size of the ad installation package, in KB, if there is no value, return -1
@property(nonatomic, assign, readonly) NSInteger appSize;

/// app purchase price, such as 'free', nil if none
@property(nonatomic, strong, readonly, nullable) NSString *appPrice;

/// The domain. only for Yandex native
@property(nonatomic, strong, readonly, nullable) NSString *domain;

/// The warning. only for Yandex native
@property(nonatomic, strong, readonly, nullable) NSString *warning;

/// is it template ad
@property(nonatomic, assign, readonly) BOOL isExpressAd;

/**
 * For some ads, this property does not always determines whether the ad is a video ad or not; however, to do this, you can always use the corresponding ad view's isVideoContents method instead.
 */
@property(nonatomic, readonly, getter=isVideoContents) BOOL videoContents;

- (instancetype)initWithAssets:(NSDictionary*)assets;

@end

NS_ASSUME_NONNULL_END
