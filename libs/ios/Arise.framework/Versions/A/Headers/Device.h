//
//  Device.h
//  Arise
//
//  Created by Weeraphat Kaewnang on 30/07/13.
//  Copyright (c) 2013 smartmobilesoftware. All rights reserved.
//

#import <Foundation/Foundation.h>

@interface Device : NSObject

/**
 Create a device id and store to user default database
 */
+(NSString *)requestUUID;

/**
 Set the status os the registration 
 */
+(void)setRegistered:(BOOL)isRegistered;

/**
 Get the status os the registration
 */
+(BOOL)isRegistered;

/**
 Method that generate a device ID and returns the string representation of UUID (universally unique identifier).
 */
+ (NSString *)generateUUID;


@end
