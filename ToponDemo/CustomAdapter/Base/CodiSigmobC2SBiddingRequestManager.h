//
//  CodiSigmobC2SBiddingRequestManager.h
//  ToponDemo
//
//  Created by Codi on 2023/11/28.
//

#import <Foundation/Foundation.h>
#import "CodiSigmobBiddingRequest.h"

NS_ASSUME_NONNULL_BEGIN

@interface CodiSigmobC2SBiddingRequestManager : NSObject

+ (instancetype)sharedInstance;

- (void)startWithRequestItem:(CodiSigmobBiddingRequest *)request;

+ (void)disposeLoadSuccessCall:(NSString *)priceStr 
                  customObject:(id)customObject
                        unitID:(NSString *)unitID;

+ (void)disposeLoadFailCall:(NSError *)error 
                        key:(NSString *)keyStr
                     unitID:(NSString *)unitID;



@end

NS_ASSUME_NONNULL_END
