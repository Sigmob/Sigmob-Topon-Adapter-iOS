//
//  CodiCustomIntersititialAdapter.h
//  ToponDemo
//
//  Created by Codi on 2023/11/28.
//

#import <Foundation/Foundation.h>


NS_ASSUME_NONNULL_BEGIN

@interface CodiCustomIntersititialAdapter : NSObject

@property (nonatomic,copy) void (^metaDataDidLoadedBlock)(void);

@end

NS_ASSUME_NONNULL_END
