# ConnectyCube iOS SDK Releases

This repository contains binary distributions of iOS products released by ConnectyCube.

If you have any questions, comments, or issues related to any products distributed via this repository then please raise an issue here on GitHub repository or contact the team by emailing support@connectycube.com.

# ConnectyCube SDK

This repository contains releases of the iOS SDK for interacting with the ConnectyCube communications cloud.

It provides a simple interface to the messaging, video calling (WebRTC), push notifications, users management and cloud files storage capabilities provided by the platform. 

# Installation

The ConnectyCube iOS SDK can be installed directly into your application by adding sdk libraries via CocoaPods.

Make sure that you have [CocoaPods](http://cocoapods.org/) installed.

Open your Podfile and add following line for dynamic framework (iOS 8+):

```
pod 'ConnectyCube'
```

Then add a "Run Script Phase" in build phases of your project. Past the following snippet in the script:

```
bash "${BUILT_PRODUCTS_DIR}/${FRAMEWORKS_FOLDER_PATH}/Connectycube.framework/strip-framework.sh"
```

This fixes a [known Apple bug](http://www.openradar.me/radar?id=6409498411401216), that does not allowing to publish archives to the App store with dynamic frameworks that contains simulator platforms. Script will only work for archiving.

Then open **Terminal** go to your project folder with Podfile and run:

```
pod install
```

Now you can open **.xcworkspace** file and use ConnectyCube Framework in your project. 

# Contact

You can reach the ConnectyCube team at any time by emailing [support@connectycube.com](mailto:support@connectycube.com).

# Licence 

ConnectyCube SDK for iOS is licensed under the ConnectyCube SDK License.
