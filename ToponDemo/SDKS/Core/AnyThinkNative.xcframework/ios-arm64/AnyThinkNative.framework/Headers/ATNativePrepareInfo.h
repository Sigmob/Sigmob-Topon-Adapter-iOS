//
//  ATNativePrepareInfo.h
//  AnyThinkNative
//
//  Created by GUO PENG on 2022/5/7.
//  Copyright © 2022 AnyThink. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>


NS_ASSUME_NONNULL_BEGIN

@interface ATNativePrepareInfo : NSObject

@property(nonatomic, strong) UILabel *advertiserLabel;
@property(nonatomic, strong) UILabel *textLabel;
@property(nonatomic, strong) UILabel *titleLabel;
@property(nonatomic, strong) UILabel *ctaLabel;
@property(nonatomic, strong) UILabel *ratingLabel;
@property(nonatomic, strong) UIImageView *iconImageView;
@property(nonatomic, strong) UIImageView *mainImageView;
@property(nonatomic, strong) UIImageView *logoImageView;
@property(nonatomic, strong) UIButton *dislikeButton;
@property(nonatomic, strong) UIView *mediaView;

// only for yandex native
@property(nonatomic, strong) UILabel *domainLabel;
@property(nonatomic, strong) UILabel *warningLabel;

@property(nonatomic, strong) UIView *mediaContainerView;

+ (instancetype)loadPrepareInfo: (void(^)(ATNativePrepareInfo *prepareInfo))loadPrepareInfoBlock;
                                            
                                            

@end

NS_ASSUME_NONNULL_END
