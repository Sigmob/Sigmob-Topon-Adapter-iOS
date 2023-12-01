//
//  ATTempWaterfallWrapper.h
//  AnyThinkSDK
//
//  Created by GUO PENG on 2022/10/20.
//  Copyright © 2022 AnyThink. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ATAd.h"

NS_ASSUME_NONNULL_BEGIN
@class ATUnitGroupModel;
@class ATPlacementModel;
@class ATWaterFallMode;
@class ATWaterfall;


typedef enum : NSUInteger {
    ATLoadedCallbackTypeAdSourceStatusCached,
    ATLoadedCallbackTypeNormalRequest
} ATLoadedCallbackType;

@interface ATWaterfallWrapper : NSObject

@property(nonatomic, readonly) BOOL waterFallfinished;

@property(nonatomic, readonly) BOOL finished;

@property(nonatomic, readonly) NSDate *startDate;

@property(nonatomic, readonly, getter=isFilled) BOOL filled;

@property(nonatomic, readonly) ATWaterfall *waterfall;
@property(nonatomic, readonly) ATWaterfall *finalWaterfall;
@property(nonatomic, readonly) ATWaterfall *defaultWaterfall;

@property(nonatomic) BOOL headerBiddingFired;
@property(nonatomic) BOOL headerBiddingFailed;
@property(nonatomic) BOOL hasBeenShowInWaterfall;

@property(nonatomic) NSInteger numberOfCachedOffers;

@property(nonatomic, readonly) dispatch_queue_t access_queue;
@property(nonatomic, assign) BOOL isFillTimeout;

@property(nonatomic, strong) id<ATAd> _Nullable adxOfferCached;

@property(nonatomic, assign) ATLoadedCallbackType loadedCallbackType;

@property (nonatomic, assign) NSInteger highestPriorityOfShownAd;

- (void)finish;
- (void)fill;
- (void)hasBeenShow;
- (void)markUnfinished;

- (void)setWaterFallfinished;
- (void)removeAdxOfferCached;

- (ATUnitGroupModel*)filledUnitGroupWithMaximumPrice;
- (void)installWaterfall:(ATWaterfall*)waterfallToInstall;
- (void)installDefaultWaterfall:(ATWaterfall *)defaultWaterfall;

- (ATUnitGroupModel *)filledUnitGroupPriceNextLoadWithExpectedIndex:(NSInteger)expectedIndex isNeedBeyondEmpty:(BOOL)isNeedBeyondEmpty;

- (ATUnitGroupModel *)requestingUnitGroupMaxPriceWithFilteredUnitID:(NSString *)unitID;


+ (instancetype)wrapperWithPlacementID:(NSString*)placementID requestID:(NSString*)requestID;

@end

NS_ASSUME_NONNULL_END
