//
//  ArisePlugin.h
//
//  Created by Weeraphat Kaewnang on 06/09/13.
//
//

#import <Foundation/Foundation.h>
#import <Cordova/CDV.h>

@interface ArisePlugin : CDVPlugin

- (void)initialize:(CDVInvokedUrlCommand*)command;
- (void)getVariationWithListener:(CDVInvokedUrlCommand*)command;
- (void)recordView:(CDVInvokedUrlCommand*)command;
- (void)recordConversion:(CDVInvokedUrlCommand*)command;

@end
