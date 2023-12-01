//
//  ATADXAdapterManager.h
//  AnyThinkSDK
//
//  Created by li zhixuan on 2023/10/19.
//  Copyright © 2023 AnyThink. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ATADXAdapterManager : NSObject

@property (nonatomic, readonly) NSDictionary<NSString *, NSDictionary<NSString *, NSString *> *> *waterfallInfoDict;

+ (ATADXAdapterManager *)shareInstance;

- (void)requestWithPlacementId:(NSString *)placementId waterfallInfo:(NSDictionary *)waterfallInfoDict completionBlock:(void (^) (NSDictionary *data,  NSError * _Nullable error))completionBlock;

@end

NS_ASSUME_NONNULL_END
