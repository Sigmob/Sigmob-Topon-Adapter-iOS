//
//  ATAdManager+Native.h
//  AnyThinkNative
//
//  Created by Martin Lau on 07/07/2018.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

#import <AnyThinkSDK/AnyThinkSDK.h>

NS_ASSUME_NONNULL_BEGIN

//Currently only GDT supports these two keys.
extern NSString *const kATExtraInfoNativeAdSizeKey;//the value has to be an NSValue wrapped CGSize object.
extern NSString *const kATExtraInfoNativeAdTypeKey;//The value is requried for GDT native ad and has to be an NSNumber warpped ATGDTNativeAdType(NSInteger); Pass @(ATGDTNativeAdTypeTemplate)(@1) for template ads and @(ATGDTNativeAdTypeSelfRendering)(@2) for self rendering ads.
//Following keys are supported by nend only
extern NSString *const kATExtraInfoNativeAdUserIDKey;
extern NSString *const kATExtraInfoNativeAdMediationNameKey;
extern NSString *const kATExtraInfoNaitveAdUserFeatureKey;
extern NSString *const kATExtraInfoNativeAdLocationEnabledFlagKey;

extern NSString *const kATNativeAdSizeToFitKey;
typedef NS_ENUM(NSInteger, ATGDTNativeAdType) {
    ATGDTNativeAdTypeTemplate = 1,
    ATGDTNativeAdTypeSelfRendering = 2
};
@class ATNativeADView;
@class ATNativeADConfiguration;
@class ATNativeAdOffer;

@protocol ATBaiduTemplateRenderingAttributeDelegate <NSObject>

@optional
//logo配置
@property (nonatomic, strong) NSString *iconWidth;
@property (nonatomic, strong) NSString *iconHeight;
@property (nonatomic, strong) NSString *iconLeft;
@property (nonatomic, strong) NSString *iconTop;
@property (nonatomic, strong) NSString *iconRight;
@property (nonatomic, strong) NSString *iconBottom;

//标题配置
@property (nonatomic, strong) NSString *titleLeft;
@property (nonatomic, strong) NSString *titleTop;
@property (nonatomic, strong) NSString *titleWidth;
@property (nonatomic, strong) NSString *titleHeight;
@property (nonatomic, strong) NSString *titleRight;
@property (nonatomic, strong) NSString *titleBottom;
@property (nonatomic, strong) NSString *titleFontSize;//系统默认字体
@property (nonatomic, strong) UIFont *titleFont;
@property (nonatomic, strong) UIColor *titleColor;

//主素材：大图、视频、三图首图
@property (nonatomic, strong) NSString *mainMaterialLeft;
@property (nonatomic, strong) NSString *mainMaterialTop;
@property (nonatomic, strong) NSString *mainMaterialWidth;
@property (nonatomic, strong) NSString *mainMaterialHeight;
@property (nonatomic, strong) NSString *mainMaterialRight;
@property (nonatomic, strong) NSString *mainMaterialBottom;

//三图的中图
@property (nonatomic, strong) NSString *centerPicLeft;
@property (nonatomic, strong) NSString *centerPicTop;
@property (nonatomic, strong) NSString *centerPicWidth;
@property (nonatomic, strong) NSString *centerPicHeight;
@property (nonatomic, strong) NSString *centerPicRight;
@property (nonatomic, strong) NSString *centerPicBottom;

//三图的右图
@property (nonatomic, strong) NSString *lastPicLeft;
@property (nonatomic, strong) NSString *lastPicTop;
@property (nonatomic, strong) NSString *lastPicWidth;
@property (nonatomic, strong) NSString *lastPicHeight;
@property (nonatomic, strong) NSString *lastPicRight;
@property (nonatomic, strong) NSString *lastPicBottom;

//底部行为按钮
@property (nonatomic, strong) NSString *buttonLeft;
@property (nonatomic, strong) NSString *buttonRight;
@property (nonatomic, strong) NSString *buttonTop;
@property (nonatomic, strong) NSString *buttonBottom;
@property (nonatomic, strong) NSString *buttonWidth;
@property (nonatomic, strong) NSString *buttonHeight;
@property (nonatomic, strong) UIFont *buttonFont;
@property (nonatomic, strong) NSString *buttonCornerRadius;
@property (nonatomic, strong) UIColor *buttonTitleColor;
@property (nonatomic, strong) UIColor *buttonBackgroundColor;

//底部负反馈按钮
@property (nonatomic, strong) NSString *dislikeBtnLeft;
@property (nonatomic, strong) NSString *dislikeBtnRight;
@property (nonatomic, strong) NSString *dislikeBtnTop;
@property (nonatomic, strong) NSString *dislikeBtnBottom;
@property (nonatomic, strong) NSString *dislikeBtnHeigth;
@property (nonatomic, strong) NSString *dislikeBtnWidth;
@property (nonatomic, strong) UIImage *dislikeBtnImage;

//底部品牌字样,建议不更改
@property (nonatomic, strong) NSString *brandLeft;
@property (nonatomic, strong) NSString *brandWidth;
@property (nonatomic, strong) NSString *brandHeight;
@property (nonatomic, strong) NSString *brandBottom;
@property (nonatomic, strong) NSString *brandFontSize;
@property (nonatomic, strong) UIFont *brandFont;
@property (nonatomic, strong) UIColor *brandColor;
@end

@interface ATAdManager (Native)

/// Get Native creative
- (ATNativeAdOffer *)getNativeAdOfferWithPlacementID:(NSString *)placementID;

/// Get Native creative
/// @param placementID - TopOn's ad placement id
/// @param scene - scene id
- (ATNativeAdOffer *)getNativeAdOfferWithPlacementID:(NSString *)placementID
                                               scene:(NSString *)scene;

/// check whether the native ad is ready
- (BOOL)nativeAdReadyForPlacementID:(NSString *)placementID;

/// Get the status object of the current ad slot ATCheckLoadModel
/// v5.7.06+
- (ATCheckLoadModel *)checkNativeLoadStatusForPlacementID:(NSString *)placementID DEPRECATED_MSG_ATTRIBUTE("use nativeAdReadyForPlacementID instead ");

/// Query all cached information of the ad slot
/// v5.7.53+
- (NSArray<NSDictionary *> *)getNativeValidAdsForPlacementID:(NSString *)placementID;


- (void)setBaiduTemplateRenderingAttribute:(id<ATBaiduTemplateRenderingAttributeDelegate>)baiduTemplateRenderingAttribute;


///  Enter the current ad slot cache status statistics in the business scenario.
/// @param scene - ad Scenario
/// v5.7.91+
- (void)entryNativeScenarioWithPlacementID:(NSString *)placementID
                                     scene:(NSString *)scene;

@end

NS_ASSUME_NONNULL_END
