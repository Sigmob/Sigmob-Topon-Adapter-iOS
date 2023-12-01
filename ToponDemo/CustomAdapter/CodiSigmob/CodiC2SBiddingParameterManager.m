//
//  CodiC2SBiddingParameterManager.m
//  ToponDemo
//
//  Created by Codi on 2023/11/28.
//

#import "CodiC2SBiddingParameterManager.h"
#import "CodiSafeThreadDictionary.h"

@interface CodiC2SBiddingParameterManager ()
@property(nonatomic, strong) CodiSafeThreadDictionary<NSString *, CodiSigmobBiddingRequest *> *requestDic;

@end

@implementation CodiC2SBiddingParameterManager

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
- (instancetype)init {
    self = [super init];
    if (self) {
        _requestDic = [CodiSafeThreadDictionary dictionary];
    }
    return self;
}
#pragma mark - request CRUD
- (void)saveRequestItem:(CodiSigmobBiddingRequest *)request
             withUnitId:(NSString *)unitID{
    [self.requestDic setValue:request forKey:unitID];
}

- (CodiSigmobBiddingRequest *)getRequestItemWithUnitID:(NSString *)unitID {
    return [self.requestDic objectForKey:unitID];
}

- (void)removeRequestItemWithUnitID:(NSString*)unitID {
    CodiSigmobBiddingRequest *request = [self getRequestItemWithUnitID:unitID];
    if (request) {
        [[ATBidInfoCacheManager sharedManager] invalidateBidInfoForPlacementID:request.placementID unitGroupModel:request.unitGroup];
    }
    [self.requestDic removeObjectForKey:unitID];
}

- (NSDictionary *)getRequests {
    return self.requestDic;
}


@end
