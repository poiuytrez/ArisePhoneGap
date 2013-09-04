package io.arise;

import org.apache.cordova.CallbackContext;
import org.apache.cordova.CordovaPlugin;
import org.json.JSONArray;
import org.json.JSONException;

/**
 * Arise Plugin
 * @author Guillaume Charhon - Arise.io
 *
 */
public class ArisePlugin extends CordovaPlugin{

	CallbackContext callbackContext;

	@Override
	/**
	 * Called by each javascript plugin function
	 */
	public boolean execute(String action, JSONArray data, final CallbackContext callbackContext) throws JSONException {
		this.callbackContext = callbackContext;
		// Check if the action has a handler
		Boolean isValidAction = true;

		try {
			// Initialize the framework
			if ("initialize".equals(action)) {
				String authKey = data.getString(0);
				String appName = data.getString(1);

				Arise.initialize(cordova.getActivity().getApplicationContext(), authKey, appName);

				callbackContext.success();

				return true;
				
			} else if ("getVariationWithListener".equals(action)) {
				// Retrieve a variation
				String tagName = data.getString(0);
				String defaultValue = data.getString(1);

				this.cordova.setActivityResultCallback(this);
				// Get and setup the variation
				ABTest.getVariationWithListener(tagName, defaultValue, new VariationListener() {
					@Override
					public void onVariationAvailable(String value) {
						// callback with the variation
						callbackContext.success(value);
					}
				});
				
			} else if ("recordView".equals(action)){
				// Record a view
				String tagName = data.getString(0);
				// record the view
				ABTest.recordView(tagName);
				callbackContext.success();
			} 
			else if ("recordConversion".equals(action)){
				String tagName = data.getString(0);
				// record the conversion
				ABTest.recordConversion(tagName);
				callbackContext.success();
			} else {
				// No handler for the action
				isValidAction = false;
			}
		} catch (IllegalStateException e){
			callbackContext.error(e.getMessage());
		} catch (JSONException e){
			callbackContext.error(e.getMessage());
		}

		// Method not found
		return isValidAction;

	}


}
