//
//  CodiCustomIntersititialAdapter.m
//  ToponDemo
//
//  Created by Codi on 2023/11/28.
//

#import "CodiCustomIntersititialAdapter.h"
#import "CodiCustomIntersititialEvent.h"
#import <WindSDK/WindSDK.h>
#import "CodiSigmobBaseManager.h"
#import "CodiSigmobC2SBiddingRequestManager.h"
#import "CodiC2SBiddingParameterManager.h"

@interface CodiCustomIntersititialAdapter()<WindNewIntersititialAdDelegate>
@property(nonatomic, readonly) CodiCustomIntersititialEvent *customEvent;
@property (nonatomic, strong) WindNewIntersititialAd *intersititialAd;
@property (nonatomic, strong) id observer;
@end

@implementation CodiCustomIntersititialAdapter

-(instancetype) initWithNetworkCustomInfo:(NSDictionary*)serverInfo localInfo:(NSDictionary*)localInfo {
    self = [super init];
    if (self != nil) {
        [CodiSigmobBaseManager initWithCustomInfo:serverInfo localInfo:localInfo];
        NSLog(@"[Codi]: %s", __FUNCTION__);
    }
    return self;
}

-(void) loadADWithInfo:(NSDictionary*)serverInfo localInfo:(NSDictionary*)localInfo completion:(void (^)(NSArray<NSDictionary *> *, NSError *))completion {
    NSLog(@"[Codi]: %s", __FUNCTION__);
    NSString *unitId = [serverInfo objectForKey:@"placementId"];
    NSString *bidId = [serverInfo objectForKey:kATAdapterCustomInfoBuyeruIdKey];
    //c2s
    if (bidId) {
        CodiSigmobBiddingRequest *request = [[CodiC2SBiddingParameterManager sharedInstance] getRequestItemWithUnitID:unitId];
        if (request && request.customObject) {
            request.state = 1;
            _customEvent = (CodiCustomIntersititialEvent *)request.customEvent;
            self.customEvent.requestCompletionBlock = completion;
            self.intersititialAd = (WindNewIntersititialAd *)request.customObject;
            if (self.intersititialAd.isAdReady) {
                [self.customEvent trackInterstitialAdLoaded:self.intersititialAd adExtra:nil];
                [[CodiC2SBiddingParameterManager sharedInstance] removeRequestItemWithUnitID:self.intersititialAd.placementId];
            }else {
                //等event中的成功回调触发trackInterstitialAdLoaded
            }
        }
        return;
    }
    
    _customEvent = [[CodiCustomIntersititialEvent alloc] initWithInfo:serverInfo localInfo:localInfo];
    self.customEvent.requestCompletionBlock = completion;

    dispatch_async(dispatch_get_main_queue(), ^{
        WindAdRequest *sigRequest = [WindAdRequest request];
        sigRequest.placementId = unitId;
        self.intersititialAd = [[WindNewIntersititialAd alloc] initWithRequest:sigRequest];
        self.intersititialAd.delegate = self.customEvent;
        [self.intersititialAd loadAdData];
    });
    
}


+ (BOOL)adReadyWithCustomObject:(id)customObject info:(NSDictionary*)info {
    return ((WindNewIntersititialAd *)customObject).isAdReady;
}

+(void) showInterstitial:(ATInterstitial*)interstitial inViewController:(UIViewController*)viewController delegate:(id<ATInterstitialDelegate>)delegate {
    NSLog(@"[Codi]: %s", __FUNCTION__);
    WindNewIntersititialAd *sigInterstitial = interstitial.customObject;
    interstitial.customEvent.delegate = delegate;
    [sigInterstitial showAdFromRootViewController:viewController options:nil];
}


//completion: 当 header bidding 完成后，需要执行此回调，将 bidding 得到的数据或者错误回传给 Topon SDK
+ (void)bidRequestWithPlacementModel:(ATPlacementModel*)placementModel
                     unitGroupModel:(ATUnitGroupModel*)unitGroupModel
                               info:(NSDictionary*)info
                         completion:(void(^)(ATBidInfo *bidInfo, NSError *error))completion {
    NSLog(@"[Codi]: %s", __FUNCTION__);
    [CodiSigmobBaseManager initWithCustomInfo:info localInfo:info];
    NSString *placementId = [unitGroupModel.content objectForKey:@"placementId"];

    CodiCustomIntersititialEvent *customEvent = [[CodiCustomIntersititialEvent alloc] initWithInfo:info localInfo:info];
    customEvent.isC2SBiding = YES;
    customEvent.networkAdvertisingID = placementId;
    
    CodiSigmobBiddingRequest *request = [CodiSigmobBiddingRequest new];
    request.unitGroup = unitGroupModel;
    request.placementID = placementModel.placementID;
    request.customEvent = customEvent;
    request.bidCompletion = completion;
    request.unitID = placementId;
    request.extraInfo = info;
    request.state = 0;
    request.adType = ATAdFormatInterstitial;
    [[CodiSigmobC2SBiddingRequestManager sharedInstance] startWithRequestItem:request];
}

//customObject为当广告对象
+ (void)sendWinnerNotifyWithCustomObject:(id)customObject
                              secondPrice:(NSString*)price
                                 userInfo:(NSDictionary<NSString *, NSString *> *)userInfo {
    NSLog(@"[Codi]: %s", __FUNCTION__);
    if ([customObject isKindOfClass:[WindNewIntersititialAd class]]) {
        WindNewIntersititialAd *interstitial = (WindNewIntersititialAd *)customObject;
        NSString *price =  [interstitial getEcpm];
        [interstitial sendWinNotificationWithInfo:@{
            @"AUCTION_PRICE": @(price.intValue)
        }];
    }
}

//customObject为当广告对象，lossType 为 bid失败原因
+ (void)sendLossNotifyWithCustomObject:(id)customObject
                              lossType:(ATBiddingLossType)lossType
                              winPrice:(nonnull NSString *)price
                              userInfo:(NSDictionary *)userInfo {
    NSLog(@"[Codi]: %s", __FUNCTION__);
    if ([customObject isKindOfClass:[WindNewIntersititialAd class]]) {
        WindNewIntersititialAd *interstitial = (WindNewIntersititialAd *)customObject;
        WindAdBiddingLossReason reason = WindAdBiddingLossReasonOther;
        if (lossType == ATBiddingLossWithLowPriceInNormal || lossType == ATBiddingLossWithLowPriceInHB) {
            reason = WindAdBiddingLossReasonLowPrice;
        }else if (lossType == ATBiddingLossWithBiddingTimeOut) {
            reason = WindAdBiddingLossReasonLoadTimeout;
         }
        [interstitial sendLossNotificationWithInfo:@{
            @"AUCTION_PRICE": @(price.floatValue),
            @"LOSS_REASON": @(reason)
        }];
    }
}

- (void)dealloc {
    NSLog(@"[Codi]: %s -- ", __func__);
}

@end
