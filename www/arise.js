/*
 * Copyright (C) 2013 Arise.io
 */

var arise = {
    // Initialize the arise framework
    initialize: function (success, fail, authKey, appName) {
        return cordova.exec( success, fail,
            "ArisePlugin",
            "initialize", [authKey, appName]);
    },
    // Get a variation
    getVariationWithListener: function (success, fail, tagName, defaultValue) {
        return cordova.exec( success, fail,
            "ArisePlugin",
            "getVariationWithListener", [tagName, defaultValue]);
    },
    // Record a view
    recordView: function (success, fail, tagName) {
        return cordova.exec( success, fail,
            "ArisePlugin",
            "recordView", [tagName]);
    },
    // Record a conversion
    recordConversion: function (success, fail, tagName) {
        return cordova.exec( success, fail,
            "ArisePlugin",
            "recordConversion", [tagName]);
    }

}

module.exports = arise;