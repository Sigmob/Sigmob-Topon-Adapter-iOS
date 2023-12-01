//
//  ATADXFloorPrice.h
//  AnyThinkSDK
//
//  Created by li zhixuan on 2023/10/19.
//  Copyright © 2023 AnyThink. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

extern NSString *const kATADXFloorPriceLoadFullWaterfall;
extern NSString *const kATADXFloorPriceLoadTopOnWaterfall;
extern NSString *const kATADXFloorPriceLoadTopOnWaterfallLastStopPrice;

typedef NS_ENUM(NSUInteger, ATADXFloorPriceType) {
    ATADXFloorPriceTypeC = 1,
    ATADXFloorPriceTypeG,
};

@interface ATADXFloorPrice : NSObject

@property (nonatomic, assign) ATADXFloorPriceType type;
@property (nonatomic, assign) NSString *value;

@property (nonatomic, strong) NSDictionary *extra;

@end

NS_ASSUME_NONNULL_END
