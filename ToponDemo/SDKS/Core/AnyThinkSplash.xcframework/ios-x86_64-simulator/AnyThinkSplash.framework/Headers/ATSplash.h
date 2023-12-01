//
//  ATSplash.h
//  AnyThinkSplash
//
//  Created by Martin Lau on 2018/12/20.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

#import <UIKit/UIKit.h>
#import <AnyThinkSDK/AnyThinkSDK.h>

@class ATSplashCustomEvent;

NS_ASSUME_NONNULL_BEGIN

@interface ATSplash : NSObject<ATAd>
-(instancetype) initWithPriority:(NSInteger) priority placementModel:(ATPlacementModel*)placementModel requestID:(NSString*)requestID assets:(NSDictionary*)assets unitGroup:(ATUnitGroupModel*)unitGroup finalWaterFall:(ATWaterfall *)finalWaterFall;
- (void)releasCustomObject;
@property(nonatomic) NSInteger showTimes;
/**
 Priority is calculate by the index of the unit group in the placement's unit group list; zero is the highest
 */
@property(nonatomic, readonly) NSInteger priority;
@property(nonatomic, readonly) NSInteger priorityLevel;
@property(nonatomic, readonly) ATPlacementModel *placementModel;
@property(nonatomic) NSString *requestID;
@property(nonatomic, readonly) NSString *originalRequestID;
@property(nonatomic, readonly) NSDate *expireDate;
@property(nonatomic, readonly) NSDate *cacheDate;
@property(nonatomic, readonly) ATUnitGroupModel *unitGroup;
@property(nonatomic) NSMutableArray<NSDictionary*> *unitGroupInfos;
@property(nonatomic, readonly) NSString *unitID;
@property(nonatomic, readonly) id customObject;
@property(nonatomic, readonly) ATSplashCustomEvent *customEvent;
@property(nonatomic, readonly) NSString *price;
@property (nonatomic, strong) NSString *sortPriorityLevel;

@property(nonatomic, readonly) NSString *bidId;
@property(nonatomic, readonly) NSString *tpBidId;
@property(nonatomic, readonly, weak) ATWaterfall *finalWaterfall;
@property(nonatomic, readonly) NSInteger autoReqType;
@property(nonatomic) BOOL adReportClicked;
@property(nonatomic) BOOL isNativeSplash;
@property(nonatomic) NSDictionary *assets;
@property(nonatomic) NSObject *delegateObject;

@property(nonatomic, copy) NSString *scene;
@property(nonatomic) BOOL defaultPlayIfRequired;
@property(nonatomic) BOOL defaultAdxOfferCached;

//to do
// for ad which loads without a placement setting
@property(nonatomic) Class adapterClass;

@property (nonatomic, assign) BOOL isSharePlacementOffer;
@property (nonatomic, strong) NSString *placementId;

@end

NS_ASSUME_NONNULL_END
