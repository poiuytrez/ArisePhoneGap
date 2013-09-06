//
//  Arise.h
//  Arise
//
//  Created by Weeraphat Kaewnang on 10/07/13.
//  Copyright (c) 2013 smartmobilesoftware. All rights reserved.
//

#import <Foundation/Foundation.h>

#import <Arise/RESTClient.h>
#import <Arise/ABTest.h>
#import <Arise/Device.h>
#import <Arise/AriseDB.h>

@interface Arise : NSObject

@property (nonatomic, strong) NSString *deviceID;

/**
 Iniatialize the Arise SDK. Register the device id on server if it hasn't already been registered.
 @param key The USer authentication key generate by API server
 */
+(Arise *)initializeWithKey:(NSString *)key
                    appName:(NSString *)appName;

#pragma mark - Misc

/**
  Check if the framework has been initialized.
 */
+(BOOL)isInitialized;

+(NSString *)getVersion;
+(NSString *)getAuthKey;
+(NSString *)getAppName;
+(AriseDB *)getAriseDB;
+(NSCondition *)getDataAvailableCondition;

@end
