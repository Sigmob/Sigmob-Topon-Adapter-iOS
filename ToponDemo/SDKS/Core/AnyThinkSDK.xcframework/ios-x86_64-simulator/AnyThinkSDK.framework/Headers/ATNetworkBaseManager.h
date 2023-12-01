//
//  ATNetworkBaseManager.h
//  AnyThinkSDK
//
//  Created by Topon on 11/11/20.
//  Copyright © 2020 AnyThink. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ATAPI+Internal.h"
#import "ATUnitGroupModel.h"
#import "ATAdAdapter.h"
//#import "ATAdapterLoaderProtocol.h"



NS_ASSUME_NONNULL_BEGIN
#define ATDefaultVersion @"9999.99999999"
@interface ATNetworkBaseManager : NSObject

+ (void)initWithCustomInfo:(NSDictionary*)serverInfo localInfo:(NSDictionary*)localInfo;

//+ (void)startInitNetworkSDK:(NSDictionary *)serverInfo target:(id<ATAdapterLoaderProtocol>)target targetKey:(NSString *)targetKey;

+ (instancetype)sharedManager;

- (NSString *)versionsString;

- (NSArray *)recommendVersionsArray;

@end

NS_ASSUME_NONNULL_END
