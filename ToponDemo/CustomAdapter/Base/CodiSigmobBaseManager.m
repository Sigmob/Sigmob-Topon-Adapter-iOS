//
//  CodiSigmobBaseManager.m
//  ToponDemo
//
//  Created by Codi on 2023/11/28.
//

#import "CodiSigmobBaseManager.h"
#import <AnyThinkSDK/AnyThinkSDK.h>
#import <WindSDK/WindSDK.h>

@implementation CodiSigmobBaseManager
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

+ (void)initWithCustomInfo:(NSDictionary *)serverInfo 
                 localInfo:(NSDictionary *)localInfo {
    static dispatch_once_t onceToken;
    dispatch_once(&onceToken, ^{
        [[ATAPI sharedInstance] setVersion:[WindAds sdkVersion] forNetwork:kATNetworkNameSigmob];
        if (![[ATAPI sharedInstance] initFlagForNetwork:kATNetworkNameSigmob]) {
            WindPersonalizedAdvertisingState state = [[ATAPI sharedInstance] getPersonalizedAdState] == ATNonpersonalizedAdStateType ? WindPersonalizedAdvertisingOff : WindPersonalizedAdvertisingOn;
            [WindAds setPersonalizedAdvertising:state];
        
            NSString *appId = [serverInfo objectForKey:@"appId"];
            NSString *appKey = [serverInfo objectForKey:@"appKey"];
            WindAdOptions *options = [[WindAdOptions alloc] initWithAppId:appId appKey:appKey];
            [WindAds startWithOptions:options];
            [[ATAPI sharedInstance] setInitFlag:2 forNetwork:kATNetworkNameSigmob];
            [[ATAPI sharedInstance] setInitFlagForNetwork:kATNetworkNameSigmob];
        }
        
    });
}

@end
