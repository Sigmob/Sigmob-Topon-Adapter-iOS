//
//  CodiSigmobC2SBiddingRequestProtocol.h
//  ToponDemo
//
//  Created by Codi on 2023/11/28.
//

#import <Foundation/Foundation.h>
#import <AnyThinkSDK/AnyThinkSDK.h>


@protocol CodiC2SBiddingRequestProtocol <NSObject>
+(void)bidRequestWithPlacementModel:(ATPlacementModel*)placementModel
                      unitGroupModel:(ATUnitGroupModel*)unitGroupModel
                                info:(NSDictionary*)info
                          completion:(void(^)(ATBidInfo *bidInfo, NSError *error))completion;

@optional
+ (void)sendWinnerNotifyWithCustomObject:(id)customObject
                              secondPrice:(NSString*)price
                                 userInfo:(NSDictionary<NSString *, NSString *> *)userInfo;

+ (void)sendLossNotifyWithCustomObject:(nonnull id)customObject
                              lossType:(ATBiddingLossType)lossType
                              winPrice:(nonnull NSString *)price
                              userInfo:(NSDictionary *)userInfo;
@end

