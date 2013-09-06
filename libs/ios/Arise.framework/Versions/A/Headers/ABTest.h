//
//  ABTest.h
//  Arise
//
//  Created by Weeraphat Kaewnang on 11/07/13.
//  Copyright (c) 2013 smartmobilesoftware. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface ABTest : NSObject 

/**
 Creates and initializes shared instance of ABTest object.
 @return The newly-initialized ABTest client.
 */
+ (ABTest *)sharedABTestClient;

/**
 Retrieve the project data and save it on the device
 */
-(void)updateProjectData;

/**
 Get the experiment data. After initializing the SDK in the app, this method is use to request a variation from the Arise SDK service.
 @param tagName A tag of the experiment
 @param defaultValue A default value in case of no internet connection
 @param dataCallbackBlock A block callback a String data(variation values)
 */
+(void)getVariation:(NSString *)tagName
       defaultValue:(NSString *)defaultValue
               data:(void(^)(NSString *experimentValue))dataCallbackBlock;

/**
 Send View logs to server. This method use to indicates to the A/B Testing service that the customer has entered the test.
 @param experimentName Name of the experiment
 */
+(void)recordView:(NSString *)tagName;

/**
 Send Conversion logs to server. This method use indicates to the A/B Testing service that the customer has completed the desired action (the conversion).
 @param experimentName Name of the experiment
 */
+(void)recordConversion:(NSString *)tagName;

/**
 Store the experiment data in a plist file on the device
 @param jasonData The data to store
 */
-(void)storeJson:(NSDictionary *)jsonData;

/**
 Retrieve the the experiment data from plist file on the device
 */
-(NSDictionary *)retrieveJson;

+(BOOL)hasJSONData;


@end
