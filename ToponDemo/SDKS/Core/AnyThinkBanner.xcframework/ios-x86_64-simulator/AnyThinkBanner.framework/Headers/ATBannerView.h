//
//  ATBannerView.h
//  AnyThinkBanner
//
//  Created by Martin Lau on 18/09/2018.
//  Copyright © 2018 Martin Lau. All rights reserved.
//

#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

@protocol ATBannerDelegate;
@interface ATBannerView : UIView
//to be move into a internal category
@property(nonatomic, weak) id<ATBannerDelegate> delegate;
@property(nonatomic, weak) UIViewController *presentingViewController;

- (void)sendImpressionTracking;

/// Destroys the ad view from this banner ad. The corresponding asset view will also be destroyed.
- (void)destroyBanner;


@end

NS_ASSUME_NONNULL_END
