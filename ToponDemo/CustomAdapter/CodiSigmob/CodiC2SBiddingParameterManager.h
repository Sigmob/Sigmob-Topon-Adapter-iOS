//
//  CodiC2SBiddingParameterManager.h
//  ToponDemo
//
//  Created by Codi on 2023/11/28.
//

#import <Foundation/Foundation.h>
#import "CodiSigmobBiddingRequest.h"

@interface CodiC2SBiddingParameterManager : NSObject

+ (instancetype)sharedInstance;

- (void)saveRequestItem:(CodiSigmobBiddingRequest *)request
             withUnitId:(NSString *)unitID;

- (CodiSigmobBiddingRequest *)getRequestItemWithUnitID:(NSString*)unitID;

- (void)removeRequestItemWithUnitID:(NSString*)unitID;

- (NSDictionary *)getRequests;

- (void)saveBiddingDelegate:(id)delegate withUnitId:(NSString *)unitID;

- (id)getBiddingDelegateWithUnitId:(NSString *)unitID;

- (void)removeBiddingDelegateWithUnitId:(NSString *)unitID;

@end
