//
//  ATJoinAdProtocol.h
//  AnyThinkSDK
//
//  Created by GUO PENG on 2022/11/16.
//  Copyright © 2022 AnyThink. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <UIKit/UIKit.h>

NS_ASSUME_NONNULL_BEGIN

typedef NS_ENUM(NSUInteger, ATNativeInterAdViewStatus) {
    ATNativeInterAdVideoStatus = 1,
    ATNativeInterAdEndCardStatus = 2,
};


typedef NS_ENUM(NSUInteger,ATMediaPlayerStatus) {
   ATMediaPlayerStatusInitial = 0,         // 初始状态
   ATMediaPlayerStatusLoading = 1,         // 加载中
   ATMediaPlayerStatusStarted = 2,         // 开始播放
   ATMediaPlayerStatusPaused = 3,          // 用户行为导致暂停
   ATMediaPlayerStatusError = 4,           // 播放出错
   ATMediaPlayerStatusStoped = 5,          // 播放停止
   ATMediaPlayerStatusWillStart = 10,      // 即将播放
};

@protocol ATJoinAdProtocol <NSObject>

- (void)closeAdAction;

- (void)pauseVideoAdAction;

- (CGFloat)getNetWorkVideoPlayProgress;

- (void)setNetworkVideoMuted:(BOOL)isVideoMuted;

- (UIView *)getNetworkLogo;

- (UIView*)getMediaViewAndBindEvent:(UIViewController *)controller;

- (UIView*)getNetworkContainerView;


- (void)registerClickEventWithArray:(NSArray<UIView*>*)clickableViewArray extraDic:(NSDictionary *)extraDic;






@end

NS_ASSUME_NONNULL_END
