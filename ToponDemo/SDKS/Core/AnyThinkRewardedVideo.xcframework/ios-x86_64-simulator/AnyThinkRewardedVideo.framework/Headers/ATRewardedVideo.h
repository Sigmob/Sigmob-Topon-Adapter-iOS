//
//  ATRewardedVideo.h
//  AnyThinkSDK
//
//  Created by Martin Lau on 28/06/2018.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AnyThinkSDK/AnyThinkSDK.h>

NS_ASSUME_NONNULL_BEGIN

@class ATRewardedVideoCustomEvent;
@interface ATRewardedVideo : NSObject<ATAd>
-(instancetype) initWithPriority:(NSInteger) priority placementModel:(ATPlacementModel*)placementModel requestID:(NSString*)requestID assets:(NSDictionary*)assets unitGroup:(ATUnitGroupModel*)unitGroup finalWaterFall:(ATWaterfall *)finalWaterFall;
- (void)releasCustomObject;
@property(nonatomic) NSInteger showTimes;
/**
 Priority is calculate by the index of the unit group in the placement's unit group list; zero is the highest
 */
@property(nonatomic, readonly) NSInteger priority;
@property(nonatomic, readonly) NSInteger priorityLevel;
@property(nonatomic, readonly) ATPlacementModel *placementModel;
@property(nonatomic, readonly) NSString *requestID;
@property(nonatomic, readonly) NSString *originalRequestID;
@property(nonatomic, readonly) NSDate *cacheDate;
@property(nonatomic, readonly) NSDate *expireDate;
@property(nonatomic, readonly) ATUnitGroupModel *unitGroup;
@property(nonatomic) NSMutableArray<NSDictionary*> *unitGroupInfos;
@property(nonatomic, readonly) NSString *unitID;
/**
 * Third-party network native ad object.
 */
@property(nonatomic, readonly) id customObject;

@property(nonatomic) ATRewardedVideoCustomEvent *customEvent;
@property(nonatomic, readonly) NSString *appID;
@property(nonatomic) BOOL defaultPlayIfRequired;
@property(nonatomic) BOOL defaultAdxOfferCached;
@property(nonatomic, copy) NSString *scene;
@property(nonatomic, readonly) NSString *price;
@property (nonatomic, strong) NSString *sortPriorityLevel;

@property(nonatomic, readonly) NSString *bidId;
@property(nonatomic, readonly) NSString *tpBidId;
@property(nonatomic, readonly, weak) ATWaterfall *finalWaterfall;
@property(nonatomic, readonly) NSInteger autoReqType;
@property(nonatomic) BOOL adReportClicked;

@property (nonatomic, assign) BOOL isSharePlacementOffer;
@property (nonatomic, strong) NSString *placementId;

@end

NS_ASSUME_NONNULL_END
