//
//  ATOfferModel.h
//  AnyThinkSDK
//
//  Created by stephen on 21/8/2020.
//  Copyright © 2020 AnyThink. All rights reserved.
//

#import "ATModel.h"
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const kATOfferBannerSize320_50;
extern NSString *const kATOfferBannerSize320_90;
extern NSString *const kATOfferBannerSize300_250;
extern NSString *const kATOfferBannerSize728_90;

@interface ATVideoPlayingTKItem : NSObject

@property (nonatomic, copy) NSArray<NSString *> *urls;
@property (nonatomic) NSInteger triggerTime;
@property (nonatomic) BOOL sent;

- (instancetype)initWithDict:(NSDictionary *)dict;

@end

#define ATADCTATAG 10000
#define ATADTEXTTAG 10001
#define ATADTITLETAG 10002
#define ATADICONTAG 10003
#define ATADSHAKETAG 10004
#define ATADWEBTAG 10005
#define ATADCTABACKTAG 10006
#define ATADMAINIMAGETAG 10007
#define ATADMEDIAVIEWTAG 10008
#define ATADDOMAINTAG 10009
#define ATADLOGOTAG 100010


// v5.7.24
typedef NS_ENUM(NSInteger, ATOfferInterActableArea) {
    ATOfferInterActableAreaAll,
    ATOfferInterActableAreaVisibleItems,
    ATOfferInterActableAreaCTA
};

@class ATCampaignExp;
@class ATAdWebViewManager;

typedef NS_ENUM(NSUInteger, ATOfferModelResourceType) {
    ATOfferModelResourceTypeVideo,
    ATOfferModelResourceTypeImage,
    ATOfferModelResourceTypeAudio,
};

@interface ATOfferModel : ATModel

/// html 广告宽
@property (nonatomic, assign) NSInteger offerBannerW;
/// html 广告高
@property (nonatomic, assign) NSInteger offerBannerH;

/// offermodel的唯一标识，在初始化时SDK默认生成
@property(nonatomic, strong) NSString *offerIdentifier;
@property(nonatomic, strong) NSString *requestID;

@property(nonatomic) ATOfferInterActableArea interActableArea;
@property(nonatomic, readwrite) NSString *resourceID;
@property(nonatomic, readwrite) NSString *unitID;
@property(nonatomic, readwrite) NSString *offerID;
@property(nonatomic, readwrite) NSString *offerDspID;
@property(nonatomic, readwrite) NSString *pkgName;
@property(nonatomic, readwrite) NSString *title;
@property(nonatomic, readwrite) NSString *text;
@property(nonatomic, readwrite) NSInteger rating;
@property(nonatomic, readwrite) NSString *iconURL;
@property(nonatomic, readwrite) NSString *fullScreenImageURL;
@property(nonatomic, readwrite) ATInterstitialType interstitialType;//check the offer for video or image
@property(nonatomic, readwrite) NSString *logoURL;//adv_u
@property(nonatomic, readwrite) NSString *CTA;
@property(nonatomic, readwrite) NSString *videoURL;
@property(nonatomic, readwrite) NSString *storeURL;
@property(nonatomic, readwrite) ATLinkType linkType;
@property(nonatomic, readwrite) NSString *clickURL;
@property(nonatomic, readwrite) NSString *deeplinkUrl; 
@property(nonatomic, readwrite) NSString *localResourceID;
@property(nonatomic, assign) ATOfferModelType offerModelType;
@property(nonatomic, assign) ATOfferCrtType crtType;

@property(nonatomic, copy) NSString *jumpUrl;
@property(nonatomic) NSInteger offerFirmID;


@property(nonatomic, assign) BOOL offerIMCapSw;
@property(nonatomic, assign) BOOL offerCLCapSw;

@property(nonatomic, assign) BOOL resourceIMCapSw;
@property(nonatomic, assign) BOOL resourceCLCapSw;



// ad attributes
@property(nonatomic, readwrite) NSString *adPublisher;
@property(nonatomic, readwrite) NSString *adVersion;
@property(nonatomic, readwrite) NSString *adPrivacy;
@property(nonatomic, readwrite) NSString *adPermission;

//banner(myoffer:5.6.6)
@property(nonatomic, readwrite) NSString *bannerImageUrl;
@property(nonatomic, readwrite) NSString *bannerBigImageUrl;
@property(nonatomic, readwrite) NSString *rectangleImageUrl;
@property(nonatomic, readwrite) NSString *homeImageUrl;

@property(nonatomic, readwrite) NSArray<NSString*>* resourceURLs;
@property(nonatomic, readwrite) NSArray<NSString*>* resourceVideoURLs;
@property(nonatomic, readwrite) NSArray<NSString*>* resourceImageURLs;
@property(nonatomic, readwrite) NSArray<NSString*>* resourceAudioURLs;

@property(nonatomic) NSInteger displayDuration;

@property(nonatomic, readwrite) NSArray<NSString*>* clickTKUrl;
@property(nonatomic, readwrite) NSArray<NSString*>* openSchemeFailedTKUrl;

//to do
@property(nonatomic) NSInteger videoCurrentTime;
@property(nonatomic) NSInteger videoResumeTime;

@property(nonatomic, copy) NSDictionary *tapInfoDict;

// If it is YES, it means that the feedback has been done.
@property(nonatomic) BOOL feedback;

// v5.7.47 +
@property(nonatomic, readwrite) NSArray<NSString*>* deeplinkSuccessUrl;
@property(nonatomic, readwrite) NSDictionary* at_deeplinkSuccessUrl;
@property(nonatomic, readwrite) NSArray<NSString*>* deeplinkStartTKUrl;
@property(nonatomic, readwrite) NSDictionary* at_deeplinkStartTKUrl;

// v5.7.56+
@property(nonatomic, readwrite) ATSplashImageScaleType splashImageScaleType;

// Whether to enable the shake function. 1 means open, 2 means not open
@property(nonatomic) BOOL splashShakeSw;

// The minimum value of the gyroscope that can trigger a shake click. Default is 0.1
@property(nonatomic, assign) CGFloat shakeStrength;

// Shake the time interval that a tap can trigger again. The default is 5s
@property(nonatomic,assign) NSInteger shakeTime;

@property(nonatomic,assign) BOOL canMute;

// ad type：0 Native, 1 Rewarded, 2 Banner, 3 Interstitial, 4 Splash
@property(nonatomic, readwrite) NSInteger format;

// for SKAdNetwork
@property (nonatomic, strong) ATCampaignExp *campaignExp;

//6.1.32https://confluence.magicgame001.com/pages/viewpage.action?pageId=47126246
@property (nonatomic, assign) BOOL storeKitSwitch;

@property (nonatomic, strong) NSDictionary<NSString *, NSString *> *urlJavascriptDic;

@property (nonatomic, readwrite) NSInteger networkFirmID;

- (BOOL)showAdAttributes;

@property (nonatomic, assign) BOOL isGuideClick;

@property (nonatomic, strong) ATAdWebViewManager *adWebManager;

// 标记广告协议 0: 默认，1:Mraid
@property(nonatomic, assign) ATOfferAdpType adpType;

/// 微信小程序ID
@property (nonatomic, copy) NSString *wxUserName;

/// 打开微信小程序的路径
@property (nonatomic, copy, nullable) NSString *wxPath;

/// 素材是否来源于bid
@property (nonatomic, assign) BOOL isFodderSourceBid;

- (NSString *_Nullable)getResourceURLkey:(NSString *_Nullable)urlStr;

#pragma mark - 素材缺少判断
- (BOOL)isLoseAll;

- (BOOL)isShowAllUI;

- (BOOL)isLoseIcon;

- (BOOL)isLoseTitle;

- (BOOL)isLoseDes;

- (BOOL)isLoseVideo;

@end


NS_ASSUME_NONNULL_END
