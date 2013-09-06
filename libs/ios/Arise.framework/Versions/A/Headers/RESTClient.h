//
//  RESTClient.h
//  Arise
//
//  Created by Weeraphat Kaewnang on 10/07/13.
//  Copyright (c) 2013 smartmobilesoftware. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <Arise/AriseAFNetworking.h>

@interface RESTClient : AriseAFHTTPClient

/**
 Creates and initializes shared instance of AriseAPIClient (AFHTTPCLient) object with the specified URL and default header data
 @return The newly-initialized HTTP client. 
 */
+(RESTClient *)sharedRESTClientWithKey:(NSString *)key;

/**
 Method that register the device on the server.
 @param deviceID A unique device ID.
 */
-(void)registerDevice:(NSString *)deviceID
              success:(void(^)(NSHTTPURLResponse *))successBlock_
              failure:(void(^)(NSHTTPURLResponse *, NSError *))failureBlock_;

/**
 Method that get the running experiment from the server.
 @param deviceID A unique device ID.
 @param dataCallbackBlock The block to be executed on the completion of a successful request.This block has no return value and takes one argument: the object constructed from the response data of the request.
 */
-(void)getProjectData:(NSString *)deviceID
                data:(void(^)(id responseData))dataCallbackBlock;


/**
 Method that send event (View or Conversion) logs to the server.
 @param type Type of event
 @param jsonData Event logs
 @param experimentName Name of experiment
 */
-(void)postEvent:(NSString *)type
         withLog:(NSDictionary *)jsonData
         tagName:(NSString *)tagName
         success:(void(^)(NSString *))successBlock
         failure:(void(^)(NSHTTPURLResponse *, NSError *))failureBlock;

@end
