//
//  ATCustomNetworkMode.h
//  AnyThinkSDK
//
//  Created by GUO PENG on 2022/9/15.
//  Copyright © 2022 AnyThink. All rights reserved.
//

#import <Foundation/Foundation.h>

NS_ASSUME_NONNULL_BEGIN

@interface ATCustomNetworkMode : NSObject

/// 自定义广告平台 adapterName 类名
@property(nonatomic, strong) NSString *adapterName;

/// 缓存时间 单位: 毫秒
@property (nonatomic, assign) NSTimeInterval networkCacheTime;

/// 实时竞价开关
@property (nonatomic, assign) BOOL bidRealTimeLoadSW;

- (instancetype)initWithAdapterName:(NSString *)adapterName
                   networkCacheTime:(NSUInteger)networkCacheTime
                  bidRealTimeLoadSW:(BOOL)bidRealTimeLoadSW;

@end

NS_ASSUME_NONNULL_END
