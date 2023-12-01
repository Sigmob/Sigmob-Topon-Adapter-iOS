//
//  CodiSigmobC2SBiddingRequestManager.m
//  ToponDemo
//
//  Created by Codi on 2023/11/28.
//

#import "CodiSigmobC2SBiddingRequestManager.h"
#import <WindSDK/WindSDK.h>
#import "CodiCustomIntersititialEvent.h"
#import "CodiC2SBiddingParameterManager.h"

@implementation CodiSigmobC2SBiddingRequestManager
+ (instancetype)sharedInstance {
    static id _sharedInstance = nil;
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        _sharedInstance = [[super allocWithZone:NULL] init];
    });
    return _sharedInstance;
}

+ (instancetype)allocWithZone:(struct _NSZone *)zone {
    return [self sharedInstance];
}

- (void)startWithRequestItem:(CodiSigmobBiddingRequest *)request {
    [[CodiC2SBiddingParameterManager sharedInstance] saveRequestItem:request withUnitId:request.unitID];
    dispatch_async(dispatch_get_main_queue(), ^{
        if (request.adType == ATAdFormatInterstitial) {
            [self startLoadInterstitialAdWithRequest:request];
        }
    });
}

- (void)startLoadInterstitialAdWithRequest:(CodiSigmobBiddingRequest *)request {
    NSString *placementId = request.unitID;
    WindAdRequest *sigRequest = [WindAdRequest request];
    sigRequest.placementId = placementId;
    WindNewIntersititialAd *intersititialAd = [[WindNewIntersititialAd alloc] initWithRequest:sigRequest];
    intersititialAd.delegate = (CodiCustomIntersititialEvent *)request.customEvent;
    request.customObject = intersititialAd;
    [intersititialAd loadAdData];
}


+ (void)disposeLoadSuccessCall:(NSString *)priceStr
                  customObject:(id)customObject
                        unitID:(NSString *)unitID {
    
    CodiSigmobBiddingRequest *request = [[CodiC2SBiddingParameterManager sharedInstance] getRequestItemWithUnitID:unitID];
    if (!request) return;
    
    BOOL isUS = request.unitGroup.networkCurrencyType == ATNetworkCurrencyUSDType ? YES : NO;
    
    ATBidInfo *bidInfo = [ATBidInfo bidInfoC2SWithPlacementID:request.placementID unitGroupUnitID:request.unitGroup.unitID adapterClassString:request.unitGroup.adapterClassString price:priceStr currencyType:isUS ? ATBiddingCurrencyTypeUS : ATBiddingCurrencyTypeCNY expirationInterval:request.unitGroup.bidTokenTime customObject:customObject];
    bidInfo.networkFirmID = request.unitGroup.networkFirmID;
    
    if (request.bidCompletion) {
        request.bidCompletion(bidInfo, nil);
    }
}

+ (void)disposeLoadFailCall:(NSError *)error
                        key:(NSString *)keyStr
                     unitID:(NSString *)unitID {
    CodiSigmobBiddingRequest *request = [[CodiC2SBiddingParameterManager sharedInstance] getRequestItemWithUnitID:unitID];
    if (!request) return;
    
    if (request.bidCompletion) {
        request.bidCompletion(nil, [NSError errorWithDomain:@"com.codiSigmob.SigmobSDK" code:error.code userInfo:@{
            NSLocalizedDescriptionKey:keyStr,
            NSLocalizedFailureReasonErrorKey:error
        }]);
    }
    [[CodiC2SBiddingParameterManager sharedInstance] removeRequestItemWithUnitID:unitID];
}

@end
