//
//  ServerProfile.h
//  V2RayX
//
//  Copyright © 2016年 Cenmrev. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "AppDelegate.h"
#import "utilities.h"

typedef enum ProtocolType : NSUInteger {
    vless,
    vmess
} ProtocolType;

typedef enum SecurityType : NSUInteger {
    auto_,
    aes_128_gcm,
    chacha20_poly130,
    none
} SecurityType;

typedef enum EncryptionType : NSUInteger {
    encryptionNone,
    encryptionNull
} EncryptionType;

typedef enum NetWorkType : NSUInteger {
    tcp,
    kcp,
    ws,
    http,
    quic
} NetWorkType;

NS_ASSUME_NONNULL_BEGIN

@interface ServerProfile : NSObject
- (NSMutableDictionary*)outboundProfile;
+ (ServerProfile* _Nullable )readFromAnOutboundDic:(NSDictionary*)outDict;
+ (NSArray*)profilesFromJson:(NSDictionary*)outboundJson;
-(ServerProfile*)deepCopy;

@property (nonatomic) NSString* protocol;
@property (nonatomic) NSString* address;
@property (nonatomic) NSUInteger port;
@property (nonatomic) NSString* userId;
@property (nonatomic) NSUInteger alterId; // VMESS
@property (nonatomic) NSUInteger level;
@property (nonatomic) NSString* encryption; // VLESS
@property (nonatomic) NSString* outboundTag;
@property (nonatomic) SecurityType security;
@property (nonatomic) NetWorkType network;
@property (nonatomic) NSString* sendThrough;
@property (nonatomic) NSDictionary* streamSettings; // except network type.
@property (nonatomic) NSDictionary* muxSettings;
@end

NS_ASSUME_NONNULL_END
