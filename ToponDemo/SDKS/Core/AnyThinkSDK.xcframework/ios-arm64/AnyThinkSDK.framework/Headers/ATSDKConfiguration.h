//
//  ATSDKConfiguration.h
//  AnyThinkSDK
//
//  Created by Ben on 2022/6/20.
//  Copyright © 2022 AnyThink. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <AnyThinkSDK/ATNetwokBaseConfigure.h>

NS_ASSUME_NONNULL_BEGIN

@interface ATSDKConfiguration : NSObject

/// pre initialize SDK by configure array
@property (nonatomic,strong) NSArray <ATNetwokBaseConfigure *> *preInitArray;

@end

NS_ASSUME_NONNULL_END
