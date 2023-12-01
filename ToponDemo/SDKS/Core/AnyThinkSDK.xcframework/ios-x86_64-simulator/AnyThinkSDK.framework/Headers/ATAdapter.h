//
//  ATAdapter.h
//  ToponSdkDemo
//
//  Created by li zhixuan on 2022/11/18.
//

#import <Foundation/Foundation.h>
#import "ATAdAdapter.h"

NS_ASSUME_NONNULL_BEGIN

@protocol ATAdapterDelegate;

#pragma mark - ATAdapterProtocol
@protocol ATAdapterProtocol <NSObject>

@property (nonatomic, weak) id<ATAdapterDelegate> delegate;

- (void)loadWithUserInfo:(NSDictionary<id, id> *)userInfo;
- (void)show;

@end

#pragma mark - ATAdapterDelegate
@protocol ATAdapterDelegate <NSObject>

- (void)adapter:(id<ATAdapterProtocol>)adapter adDidLoadCompletionWithUserInfo:(NSDictionary *)userInfo error:(nullable NSError *)error;

@end

#pragma mark - ATAdapter
@interface ATAdapter : NSObject<ATAdAdapter>

- (instancetype)initWithClass:(Class)clazz;

- (BOOL)adReadyForInfo:(NSDictionary *)info;
- (id<ATAd>)readyFilledAdWithPlacementModel:(ATPlacementModel *)placementModel
                                  requestID:(NSString *)requestID
                                   priority:(NSInteger)priority
                                  unitGroup:(ATUnitGroupModel *)unitGroup
                                  localInfo:(NSDictionary *)localInfo;

@end

NS_ASSUME_NONNULL_END
