# Sigmob-Topon-Adapter-iOS
基于Topon v6.2.81聚合，实现自定义适配器支持Sigmob新插屏功能

## 目录结构
```objective-c
|---- ToponDemo
|     |---- SDKS  # Topon SDK
|     |---- CustomAdapter  # 基于topon聚合的自定义渠道实现sigmob新插屏的适配器
|           |---- Base
|                |---- CodiSigmobBaseManager   # 处理初始化相关
|                |---- CodiSigmobBiddingRequest   # 存储c2s竞价的BiddingRequest类
|                |---- CodiSigmobC2SBiddingRequestManager   # 用于管理c2s竞价的BiddingRequest
|           |---- CodiSigmob
|                |---- CodiC2SBiddingParameterManager   # 模块代码
|                |---- CodiSafeThreadDictionary   # 线程安全的字典
|           |---- Intersititial
|                |---- CodiCustomIntersititialAdapter   # 新插屏自定义适配器入口
|                |---- CodiCustomIntersititialEvent   # 新插屏对应的ATInterstitialCustomEvent
```



**在基于Topon聚合实现sigmob自定义适配器接入新插屏时，需要确保自定义ADN和topon支持的sigmob ADN的appId保持一致。**



实现自定义ADN，首先需要在Topon平台创建自定义ADN广告源，同时填写对应广告类型的适配器类名，本示例新插屏的适配器类名：**CodiCustomIntersititialAdapter**



本示例接收的自定义参数在topon平台配置如下

{"appId": "xxxx", "placementId": "xxxxx"}

开发者可根据业务自行调整参数。



Top官方自定义广告平台文档：https://docs.toponad.com/#/zh-cn/ios/ios_adv_doc/customnetwork/custom_network_adapter?id=_4-%e6%8f%92%e5%b1%8f%e5%b9%bf%e5%91%8ainterstitial

实现自定义 header bidding：https://docs.toponad.com/#/zh-cn/ios/ios_adv_doc/customnetwork/custom_network_adapter?id=headerbidding



