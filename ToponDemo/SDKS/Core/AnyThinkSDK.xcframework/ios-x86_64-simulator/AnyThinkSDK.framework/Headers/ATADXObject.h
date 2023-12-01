//
//  ATADXObject.h
//  AnyThinkSDK
//
//  Created by li zhixuan on 2023/10/7.
//  Copyright © 2023 AnyThink. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ATAd.h"

NS_ASSUME_NONNULL_BEGIN

extern NSString *kATADXObjectNetwokName;
extern NSString *kATADXObjectWaterfallInfo;

//for win, usd for price,type string
extern NSString *kATADXObjectSecondLossPrice;
//for loss, usd for price,type string
extern NSString *kATADXObjectWinPrice;
extern NSString *kATADXObjectLossReason;

//for Loss Reason
extern NSString *kATADXObjectLossReasonBidLowPrice;
extern NSString *kATADXObjectLossReasonLowPrice;

@interface ATADXObject : NSObject

- (instancetype)initWithAd:(id<ATAd>)ad;

- (void)sendWinNotificationWithInfo:(NSDictionary *)winInfo;
- (void)sendLossNotificationWithInfo:(NSDictionary *)lossInfo;

- (void)remove;

@end

NS_ASSUME_NONNULL_END
