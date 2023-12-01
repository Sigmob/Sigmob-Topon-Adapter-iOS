//
//  ATMyOfferOfferModel.h
//  AnyThinkMyOffer
//
//  Created by Martin Lau on 2019/9/23.
//  Copyright © 2019 Martin Lau. All rights reserved.
//

#import "ATOfferModel.h"
#import "ATMyOfferSetting.h"

@interface ATMyOfferOfferModel : ATOfferModel
-(instancetype) initWithDictionary:(NSDictionary *)dictionary placeholders:(NSDictionary*)placeholders format:(NSInteger)format setting:(ATMyOfferSetting*)setting;

@property(nonatomic, strong) NSString *requestID;
@property(nonatomic, readwrite) NSString *unitID;
@property(nonatomic, strong) NSDictionary *offerDict;

@property(nonatomic, readwrite) ATScreenOrientation imageOrientation;
@property(nonatomic, readwrite) ATScreenOrientation videoOrientation;
@property(nonatomic, readwrite) NSString *videoStartTKURL;
@property(nonatomic, readwrite) NSString *video25TKURL;
@property(nonatomic, readwrite) NSString *video50TKURL;
@property(nonatomic, readwrite) NSString *video75TKURL;
@property(nonatomic, readwrite) NSString *videoEndTKURL;
@property(nonatomic, readwrite) NSString *endCardShowTKURL;
@property(nonatomic, readwrite) NSString *endCardCloseTKURL;
@property(nonatomic, readwrite) NSString *impURL;
@property(nonatomic, readwrite) NSString *impTKURL;
@property(nonatomic, readwrite) NSString *clickTKURL;
@property(nonatomic, readwrite) NSInteger dailyCap;
@property(nonatomic, readwrite) NSTimeInterval pacing;
@property(nonatomic, readwrite) NSDictionary<NSString*, NSString*> *placeholders;

@property(nonatomic, readwrite) ATClickMode performsAsynchronousRedirection;

// v5.7.47
@property(nonatomic, readwrite) ATAdOfferInterType interType;

@property(nonatomic, readwrite) ATUserAgentType impressionUAType;
@property(nonatomic, readwrite) ATUserAgentType clickUAType;

@property(nonatomic, readwrite) ATMyOfferSetting *myOfferSetting;

/// when check placement myoffers cap mini come into effect, see -[ATPlacement miniCapForMyOffers]
@property (nonatomic, assign) NSInteger currentCap;

+(instancetype) mockOfferModel;

- (void)setOfferModelRequestID:(NSString *)requestID;

@end


