//
//  ViewController.m
//  ToponDemo
//
//  Created by Codi on 2023/11/28.
//

#import "ViewController.h"
#import <AnyThinkSDK/AnyThinkSDK.h>
#import <AnyThinkInterstitial/AnyThinkInterstitial.h>        // 引入头文件


@interface ViewController ()<ATAdLoadingDelegate, ATInterstitialDelegate>
@property (nonatomic, strong) NSString *placementId;
@end

@implementation ViewController

- (void)viewDidLoad {
    [super viewDidLoad];
    // Do any additional setup after loading the view.
    // 插屏广告位
    self.placementId = @"b5e04842b6ccb0";
    [self setupUI];
}

- (void)setupUI {
    CGFloat space = 30;
    CGFloat w = UIScreen.mainScreen.bounds.size.width;
    CGSize size  =CGSizeMake((w-space*3)/2, 50);
    
    UIButton *btn1 = [UIButton buttonWithType:UIButtonTypeCustom];
    [btn1 setTitle:@"加载广告" forState:UIControlStateNormal];
    btn1.backgroundColor = UIColor.systemBlueColor;
    btn1.frame = CGRectMake(space, 64, size.width, size.height);
    [btn1 addTarget:self action:@selector(loadAd) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:btn1];
    
    UIButton *btn2 = [UIButton buttonWithType:UIButtonTypeCustom];
    [btn2 setTitle:@"播放广告" forState:UIControlStateNormal];
    btn2.backgroundColor = UIColor.systemBlueColor;
    btn2.frame = CGRectMake(space*2 + size.width, 64, size.width, size.height);
    [btn2 addTarget:self action:@selector(playAd) forControlEvents:UIControlEventTouchUpInside];
    [self.view addSubview:btn2];
}

- (void)loadAd {
    // 设置extra 自定义参数，会在代理的Extra回传，可以用于该广告位的自定义规则匹配
    
    NSDictionary *extra = @{
        kATCustomDataUserIDKey:@"Codi",
    };
    // 加载插屏广告
    [[ATAdManager sharedManager] loadADWithPlacementID:self.placementId extra:extra delegate:self];
}
- (void)playAd {
    // 展示前需判断广告是否有准备好
    if ([[ATAdManager sharedManager] interstitialReadyForPlacementID:self.placementId]) {
        // 广告已经准备好，展示广告
        [[ATAdManager sharedManager] showInterstitialWithPlacementID:self.placementId inViewController:self delegate:self];
    } else {
        // 广告未准备好
        NSLog(@"[Codi]: [Topon]: 广告未准备好");
    }
}

#pragma mark ATAdLoadingDelegate

/// Callback when the successful loading of the ad
- (void)didFinishLoadingADWithPlacementID:(NSString *)placementID {
    NSLog(@"[Codi]: [Topon]: %s -- placementId = %@", __func__, placementID);
}

/// Callback of ad loading failure
- (void)didFailToLoadADWithPlacementID:(NSString*)placementID
                                 error:(NSError*)error {
    NSLog(@"[Codi]: [Topon]: %s -- placementId = %@", __func__, placementID);
    NSLog(@"[Codi]: [Topon]: error = %@", error);
}


/// Ad start load
- (void)didStartLoadingADSourceWithPlacementID:(NSString *)placementID
                                         extra:(NSDictionary*)extra {
    NSLog(@"[Codi]: [Topon]: %s -- placementId = %@", __func__, placementID);
}
/// Ad load success
- (void)didFinishLoadingADSourceWithPlacementID:(NSString *)placementID
                                          extra:(NSDictionary*)extra {
    NSLog(@"[Codi]: [Topon]: %s -- placementId = %@", __func__, placementID);
}
/// Ad load fail
- (void)didFailToLoadADSourceWithPlacementID:(NSString*)placementID
                                       extra:(NSDictionary*)extra
                                       error:(NSError*)error {
    NSLog(@"[Codi]: [Topon]: %s -- placementId = %@", __func__, placementID);
}

/// Ad start bidding
- (void)didStartBiddingADSourceWithPlacementID:(NSString *)placementID
                                         extra:(NSDictionary*)extra {
    NSLog(@"[Codi]: [Topon]: %s -- placementId = %@", __func__, placementID);
}

/// Ad bidding success
- (void)didFinishBiddingADSourceWithPlacementID:(NSString *)placementID
                                          extra:(NSDictionary*)extra {
    NSLog(@"[Codi]: [Topon]: %s -- placementId = %@", __func__, placementID);
}

/// Ad bidding fail
- (void)didFailBiddingADSourceWithPlacementID:(NSString*)placementID
                                        extra:(NSDictionary*)extra
                                        error:(NSError*)error {
    NSLog(@"[Codi]: [Topon]: %s -- placementId = %@", __func__, placementID);
}



#pragma mark - ATInterstitialDelegate

/// Interstitial ad displayed successfully
- (void)interstitialDidShowForPlacementID:(NSString *)placementID
                                    extra:(NSDictionary *)extra {
    NSLog(@"[Codi]: [Topon]: %s -- placementId = %@", __func__, placementID);
}

/// Interstitial ad clicked
- (void)interstitialDidClickForPlacementID:(NSString *)placementID
                                     extra:(NSDictionary *)extra {
    NSLog(@"[Codi]: [Topon]: %s -- placementId = %@", __func__, placementID);
}

/// Interstitial ad closed
- (void)interstitialDidCloseForPlacementID:(NSString *)placementID
                                     extra:(NSDictionary *)extra {
    NSLog(@"[Codi]: [Topon]: %s -- placementId = %@", __func__, placementID);
}



/// Interstitial ad display failed
- (void)interstitialFailedToShowForPlacementID:(NSString *)placementID
                                         error:(NSError*)error
                                         extra:(NSDictionary *)extra {
    NSLog(@"[Codi]: [Topon]: %s -- placementId = %@", __func__, placementID);
}
/// Interstitial video ad playback start
- (void)interstitialDidStartPlayingVideoForPlacementID:(NSString *)placementID
                                                 extra:(NSDictionary *)extra {
    NSLog(@"[Codi]: [Topon]: %s -- placementId = %@", __func__, placementID);
}

/// Interstitial playback end
- (void)interstitialDidEndPlayingVideoForPlacementID:(NSString *)placementID
                                               extra:(NSDictionary *)extra {
    NSLog(@"[Codi]: [Topon]: %s -- placementId = %@", __func__, placementID);
}

/// Interstitial playback fail
- (void)interstitialDidFailToPlayVideoForPlacementID:(NSString *)placementID
                                               error:(NSError*)error
                                               extra:(NSDictionary *)extra {
    NSLog(@"[Codi]: [Topon]: %s -- placementId = %@", __func__, placementID);
}

/// Whether the click jump on the interstitial advertisement is in the form of Deeplink
/// currently only returns for TopOn Adx advertisements
- (void)interstitialDeepLinkOrJumpForPlacementID:(NSString *)placementID
                                           extra:(NSDictionary *)extra
                                          result:(BOOL)success {
    NSLog(@"[Codi]: [Topon]: %s -- placementId = %@", __func__, placementID);
}




@end
