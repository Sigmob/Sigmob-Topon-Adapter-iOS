//
//  ATTempWaterfall.h
//  AnyThinkSDK
//
//  Created by GUO PENG on 2022/10/20.
//  Copyright © 2022 AnyThink. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ATPlacementModel.h"
#import "ATUnitGroupModel.h"
@class ATWaterFallMode;


typedef NS_ENUM(NSInteger, ATWaterfallType) {
    ATWaterfallTypeWaterfall = 0,
    ATWaterfallTypeFinal = 2
};

typedef NS_ENUM(NSInteger, ATUnitGroupFinishType) {
    ATUnitGroupFinishTypeFinished = 0,
    ATUnitGroupFinishTypeTimeout = 1,
    ATUnitGroupFinishTypeFailed = 2
};

NS_ASSUME_NONNULL_BEGIN

@interface ATWaterfall : NSObject
@property(nonatomic, strong) NSString *placementID;
@property(nonatomic, strong) NSString *requestID;
@property(nonatomic, strong) NSMutableArray<ATUnitGroupModel*>* requestSentUnitGroups;

@property(nonatomic, strong) NSMutableArray<ATUnitGroupModel*>* unitGroups;
@property(nonatomic, strong) NSMutableArray <ATUnitGroupModel*>*advanceSendUGArray;
@property(nonatomic, strong) NSMutableArray <ATUnitGroupModel*>*dynamicSendUGArray;
@property(nonatomic, readonly) NSUInteger numberOfTimeoutRequests;
@property(nonatomic, readonly) ATWaterfallType type;
@property(nonatomic, readonly, getter=isLoading) BOOL loading;

@property(nonatomic, assign) ATLoadingApiType loadingApiType;

@property (nonatomic, weak) ATPlacementModel *placement;

// init
- (instancetype)initWithUnitGroups:(nullable NSArray<ATUnitGroupModel*>*)unitGroups placementID:(NSString*)placementID requestID:(NSString*)requestID;

- (instancetype)initWithPlacementID:(NSString*)placementID requestID:(NSString*)requestID;

// ALL UG
- (void)addRankedAndShuffledUnitGroups:(NSArray<ATUnitGroupModel *> *)unitGroups;
- (void)requestUnitGroup:(ATUnitGroupModel*)unitGroup;
- (void)finishUnitGroup:(ATUnitGroupModel*)unitGroup withType:(ATUnitGroupFinishType)type;
- (void)addUnitGroup:(ATUnitGroupModel*)unitGroup;
- (void)insertUnitGroup:(ATUnitGroupModel*)unitGroup;
- (void)insertUnitGroupArray:(NSArray<ATUnitGroupModel*>*)unitGrous;
- (void)removeFinishedRequestObject:(ATUnitGroupModel *)unitGroup;
- (void)removeUnitGroupWithUnitID:(NSString*)unitID;
- (NSArray *)getRequestFilledUnitGroups;


- (ATUnitGroupModel*)unitGroupWithUnitID:(NSString*)unitID;
- (ATUnitGroupModel*)unitGroupWithMaximumPrice;
- (ATUnitGroupModel*)unitGroupWithMinimumPrice;

- (NSMutableArray<ATUnitGroupModel *> *)getWaterfallAllUnitGroups;
- (NSMutableArray<ATUnitGroupModel *> *)getWaterfallAllNotRequestUnitGroups;
/// 获取ug在final waterfall中的优先级
- (NSInteger)getPriorityInFinalWaterfallWithUnitGroup:(ATUnitGroupModel *)unitGroup;

// Advance
- (NSInteger)getAdvanceSendCount;
- (ATUnitGroupModel*)advanceUnitGroupWithMaximumPrice;
- (void)insertAdvanceUnitGroup:(ATUnitGroupModel*)unitGroup;
- (void)markAdvanceRequestSendUnitGroup:(ATUnitGroupModel*)unitGroup;
- (void)markAdvanceRequestFillUnitGroup:(ATUnitGroupModel*)unitGroup;
- (NSArray *)getAdvanceRequestFillUnitGroups;

// dynamic
- (NSInteger)getDynamicSendCount;
- (NSArray *)getDynamicRequestFillUnitGroups;
- (ATUnitGroupModel*)dynamicUnitGroupWithMaximumPrice;
- (void)markDynamicRequestSendUnitGroup:(ATUnitGroupModel*)unitGroup;
- (void)insertDynamicUnitGroup:(ATUnitGroupModel*)unitGroup;
- (void)markDynamicRequestFillUnitGroup:(ATUnitGroupModel*)unitGroup;

// default
- (ATUnitGroupModel*)firstPendingNonHBUnitGroupWithNetworkFirmID:(NSInteger)nwFirmID;

// other
- (NSString *)getNextPrice:(NSString *)price array:(NSArray *)priceArray;

- (NSInteger)getEqualPriceRequestsQueuedWithSpacing:(NSInteger)divisionSpacing;

- (BOOL)canContinueLoading:(BOOL)waitForSentRequests;

- (void)enumerateTimeoutUnitGroupWithBlock:(void(^)(ATUnitGroupModel*unitGroup))block;

@end

NS_ASSUME_NONNULL_END
