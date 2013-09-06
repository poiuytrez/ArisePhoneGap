//
//  ArisePlugin.m
//
//  Created by Weeraphat Kaewnang on 06/09/13.
//
//

#import "ArisePlugin.h"
#import <Cordova/CDV.h>
#import <Arise/Arise.h>

@implementation ArisePlugin

- (void)initialize:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;
    // Get the arguments
    NSString* authKey = [command.arguments objectAtIndex:0];
    NSString* appName = [command.arguments objectAtIndex:1];
    
    if (authKey != nil && appName != nil) {
        // Iniatialize the Arise framework
        [Arise initializeWithKey:authKey appName:appName];
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR];
    }
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)getVariationWithListener:(CDVInvokedUrlCommand*)command
{
    __block CDVPluginResult* pluginResult = nil;
    NSString* tagName = [command.arguments objectAtIndex:0];
    NSString* defaultValue = [command.arguments objectAtIndex:1];
    
    if (tagName != nil) {
        // Retrieve a variation
        [ABTest getVariation:tagName defaultValue:defaultValue data:^(NSString *experimentValue) {
            pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK messageAsString:experimentValue];
            [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
        }];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR];
        [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
    }
}

- (void)recordView:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;
    NSString* tagName = [command.arguments objectAtIndex:0];
    if (tagName != nil) {
        // Record the view
        [ABTest recordView:tagName];
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR];
    }
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}

- (void)recordConversion:(CDVInvokedUrlCommand*)command
{
    CDVPluginResult* pluginResult = nil;
    NSString* tagName = [command.arguments objectAtIndex:0];
    if (tagName != nil) {
        // Record the conversion
        [ABTest recordConversion:tagName];
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_OK];
    } else {
        pluginResult = [CDVPluginResult resultWithStatus:CDVCommandStatus_ERROR];
    }
    [self.commandDelegate sendPluginResult:pluginResult callbackId:command.callbackId];
}


@end

