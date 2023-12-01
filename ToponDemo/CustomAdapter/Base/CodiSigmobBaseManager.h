//
//  CodiSigmobBaseManager.h
//  ToponDemo
//
//  Created by Codi on 2023/11/28.
//

#import <Foundation/Foundation.h>
#import <AnyThinkSDK/AnyThinkSDK.h>
#import <WindSDK/WindSDK.h>


@protocol CodiSigmobBiddingRequest <NSObject>
@property (nonatomic, strong) id customObject;
@property (nonatomic, strong) ATUnitGroupModel *unitGroup;
@property (nonatomic, strong) ATAdCustomEvent *customEvent;
@property (nonatomic, copy) NSString *unitID;
@property (nonatomic, copy) NSString *placementID;
@property (nonatomic, copy) NSDictionary *extraInfo;
@property (nonatomic, copy) void(^bidCompletion)(ATBidInfo * _Nullable bidInfo, NSError * _Nullable error);
@property (nonatomic, assign) ATAdFormat adType;
@end



@interface CodiSigmobBaseManager : NSObject
+ (instancetype)sharedInstance;

+ (void)initWithCustomInfo:(NSDictionary *)serverInfo localInfo:(NSDictionary *)localInfo;

@end
