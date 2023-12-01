//
//  ATADXSettings.h
//  AnyThinkSDK
//
//  Created by li zhixuan on 2023/10/7.
//  Copyright © 2023 AnyThink. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ATADXSettingsMode) {
    ATADXSettingsModeMediation,
    ATADXSettingsModeNetwork,
};

@interface ATADXSettings : NSObject

@property (nonatomic, readonly) NSMutableDictionary *adxNetworkDict;

+ (instancetype)shareInstance;

- (void)setAdxNetworkModeWithPlacementId:(NSString *)placementId;

- (ATADXSettingsMode)adxModeWithPlacementId:(NSString *)placementId;

@end

NS_ASSUME_NONNULL_END
