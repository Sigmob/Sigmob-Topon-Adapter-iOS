//
//  CodiSigmobBiddingRequest.h
//  ToponDemo
//
//  Created by Codi on 2023/11/28.
//

#import <Foundation/Foundation.h>
#import <AnyThinkSDK/AnyThinkSDK.h>

NS_ASSUME_NONNULL_BEGIN

@interface CodiSigmobBiddingRequest : NSObject
@property (nonatomic, strong) id customObject;
@property (nonatomic, strong) ATUnitGroupModel *unitGroup;
@property (nonatomic, strong) ATAdCustomEvent *customEvent;
@property (nonatomic, copy) NSString *unitID;//三方广告位ID
@property (nonatomic, copy) NSString *placementID;// topon广告位ID
@property (nonatomic, copy) NSDictionary *extraInfo;
@property (nonatomic, copy) void(^bidCompletion)(ATBidInfo * _Nullable bidInfo, NSError * _Nullable error);
@property (nonatomic, assign) ATAdFormat adType;


/// 0: 获取价格的状态；1: 在瀑布流中被直接load状态；
@property (nonatomic, assign) NSUInteger state;
@end

NS_ASSUME_NONNULL_END
