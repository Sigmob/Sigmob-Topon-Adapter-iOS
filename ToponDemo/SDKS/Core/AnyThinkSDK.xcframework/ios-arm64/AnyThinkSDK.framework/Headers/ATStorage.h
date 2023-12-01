//
//  ATStorage.h
//  ToponSdkDemo
//
//  Created by li zhixuan on 2022/11/19.
//

#import <Foundation/Foundation.h>

@class ATDatabaseStorage;
@class ATMemoryStorage;

NS_ASSUME_NONNULL_BEGIN

@protocol ATStorageEntityProtocol <NSObject>

- (id)identifier;

@end

@protocol ATStorageProtocol <NSObject>

- (void)createEntityClazz:(Class)clazz;
- (BOOL)saveWithEntity:(id<ATStorageEntityProtocol>)entity entityClazz:(Class)clazz;
- (id<ATStorageEntityProtocol>)readEntityWithIdentifier:(id)identifier entityClazz:(Class)clazz;
- (BOOL)removeEntityWithIdentifier:(id)identifier entityClazz:(Class)clazz;

@end

@interface ATStorage : NSObject<ATStorageProtocol>

+ (ATStorage *)shareInstance;

- (void)createEntityClazz:(Class)clazz;

- (BOOL)saveWithEntity:(id<ATStorageEntityProtocol>)entity entityClazz:(Class)clazz;
- (id<ATStorageEntityProtocol>)readEntityWithIdentifier:(id)identifier entityClazz:(Class)clazz;
- (BOOL)removeEntityWithIdentifier:(id)identifier entityClazz:(Class)clazz;

@end

NS_ASSUME_NONNULL_END
