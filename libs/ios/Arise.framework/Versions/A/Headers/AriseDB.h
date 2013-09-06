//
//  AriseDB.h
//  Arise
//
//  Created by Weeraphat Kaewnang on 17/07/13.
//  Copyright (c) 2013 smartmobilesoftware. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <sqlite3.h>

@interface AriseDB : NSObject

@property (nonatomic) sqlite3 *database;
@property (nonatomic, strong) NSString *databasePath;

/**
 * Creates and initializes shared instance of AriseAPIClient (AFHTTPCLient) object
 */
+ (AriseDB *)sharedAriseDBClient;

/**
 * Creates The database
 */
- (void)ensureDatabaseCreated;

/** 
 * Method that add the Event logs to database
 @param experimentName A Name of the experiment
 @param type Type of events
 @param eventData Logs data
 */
- (void)addEvent:(NSString *)type
         tagName:(NSString *)tagName
       timestamp:(NSNumber *)timestamp;

/**
 Get Eventlogs by experiment name and type
 @param 
 @param
 
 @return A array of dictionnary(Logs data)
 */
- (NSArray *)getEventLogs:(NSString *)type
       withTagName:(NSString *)tagName;

/**
 Get All Logs in database
 @return A array of dictionnary(Logs data)
 */
- (NSArray *)getAllEventLogs;

/**
 Delete log with id
 @param _id A unique id 
 */
- (void)deleteEventWithId:(NSUInteger)_id;

+(BOOL)hasCreateDatabase;

@end
