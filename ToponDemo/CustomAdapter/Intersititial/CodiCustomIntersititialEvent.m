//
//  CodiCustomIntersititialEvent.m
//  ToponDemo
//
//  Created by Codi on 2023/11/28.
//

#import "CodiCustomIntersititialEvent.h"
#import "CodiSigmobC2SBiddingRequestManager.h"
#import "CodiC2SBiddingParameterManager.h"

@interface CodiCustomIntersititialEvent ()

@end

@implementation CodiCustomIntersititialEvent

- (NSString *)networkUnitId {
    return self.serverInfo[@"placementId"];
}




#pragma mark - WindNewIntersititialAdDelegate
/// 广告数据返回回调
/// - Parameters:
///   - rewardVideoAd: WindNewIntersititialAd 实例对象
///   - isFillAd: ture: 填充， false: 无广告数据
- (void)intersititialAdServerResponse:(WindNewIntersititialAd *)intersititialAd isFillAd:(BOOL)isFillAd {
    NSLog(@"[Codi]: %s -- placementId = %@", __func__, intersititialAd.placementId);
    
    if (self.isC2SBiding) {
        if (isFillAd) {
            NSString *price = [intersititialAd getEcpm];
            [CodiSigmobC2SBiddingRequestManager disposeLoadSuccessCall:price customObject:intersititialAd unitID:intersititialAd.placementId];
            
        }else {
            NSError *error = [NSError errorWithDomain:@"" code:200000 userInfo:nil];
            [CodiSigmobC2SBiddingRequestManager disposeLoadFailCall:error key:@"no-ad" unitID:intersititialAd.placementId];
        }
        self.isC2SBiding = NO;
    }
    
}
/// 广告加载成功回调
/// - Parameter rewardVideoAd: WindNewIntersititialAd 实例对象
- (void)intersititialAdDidLoad:(WindNewIntersititialAd *)intersititialAd {
    NSLog(@"[Codi]: %s -- placementId = %@", __func__, intersititialAd.placementId);
    CodiSigmobBiddingRequest *request = [[CodiC2SBiddingParameterManager sharedInstance] getRequestItemWithUnitID:intersititialAd.placementId];
    if (request && request.state == 1) {
        //c2s bidding 且瀑布流被加载了，
        [self trackInterstitialAdLoaded:intersititialAd adExtra:nil];
        [[CodiC2SBiddingParameterManager sharedInstance] removeRequestItemWithUnitID:intersititialAd.placementId];
    }else if (request == nil) {
        // 非bidding, 可以直接回调topon ready
        [self trackInterstitialAdLoaded:intersititialAd adExtra:nil];
    }
}

/// 广告加载出错
/// - Parameters:
///   - intersititialAd: WindNewIntersititialAd 实例对象
///   - error: 具体错误信息
- (void)intersititialAdDidLoad:(WindNewIntersititialAd *)intersititialAd didFailWithError:(NSError *)error {
    NSLog(@"[Codi]: %s -- placementId = %@, error = %@", __func__, intersititialAd.placementId, error);
    [self trackInterstitialAdLoadFailed:error];
}

/// 广告将要曝光回调
/// - Parameter rewardVideoAd: WindNewIntersititialAd 实例对象
- (void)intersititialAdWillVisible:(WindNewIntersititialAd *)intersititialAd {
    NSLog(@"[Codi]: %s -- placementId = %@", __func__, intersititialAd.placementId);
}

/// 广告曝光回调
/// - Parameter rewardVideoAd: WindNewIntersititialAd 实例对象
- (void)intersititialAdDidVisible:(WindNewIntersititialAd *)intersititialAd {
    NSLog(@"[Codi]: %s -- placementId = %@", __func__, intersititialAd.placementId);
    [self trackInterstitialAdShow];
}

/// 广告点击回调
/// - Parameter rewardVideoAd: WindNewIntersititialAd 实例对象
- (void)intersititialAdDidClick:(WindNewIntersititialAd *)intersititialAd {
    NSLog(@"[Codi]: %s -- placementId = %@", __func__, intersititialAd.placementId);
    [self trackInterstitialAdClick];
}

/// 广告跳过回调
/// - Parameter rewardVideoAd: WindNewIntersititialAd 实例对象
- (void)intersititialAdDidClickSkip:(WindNewIntersititialAd *)intersititialAd {
    NSLog(@"[Codi]: %s -- placementId = %@", __func__, intersititialAd.placementId);
}

/// 广告关闭回调
/// - Parameter rewardVideoAd: WindNewIntersititialAd 实例对象
- (void)intersititialAdDidClose:(WindNewIntersititialAd *)intersititialAd {
    NSLog(@"[Codi]: %s -- placementId = %@", __func__, intersititialAd.placementId);
    [self trackInterstitialAdClose:@{}];
}

- (void)dealloc {
    NSLog(@"[Codi]: %s -- ", __func__);
}

@end
