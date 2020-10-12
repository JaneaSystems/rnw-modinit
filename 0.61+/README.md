# MODNAME Windows Implementation

## Module Installation
You can either use autolinking on react-native-windows 0.63 and later or manually link the module on earlier realeases.

### Automatic install with autolinking on RNW >= 0.63
MODNAME supports autolinking. Just call: `npm i [module name here] --save`

### Manual installation on RNW >= 0.62
1. `npm install [module name here] --save`
2. Open your solution in Visual Studio 2019 (eg. `windows\yourapp.sln`)
3. Right-click Solution icon in Solution Explorer > Add > Existing Project...
4. Add `node_modules\[module name here]\windows\MODNAME\MODNAME.vcxproj`
5. Right-click main application project > Add > Reference...
6. Select `MODNAME` in Solution Projects
7. In app `pch.h` add `#include "winrt/MODNAME.h"`
8. In `App.cpp` add `PackageProviders().Append(winrt::MODNAME::ReactPackageProvider());` before `InitializeComponent();`

### Manual installation on RNW 0.61
Do the same steps as for 0.62, but use `node_modules\MODNAME\windows\MODNAME61\MODNAME.vcxproj` in step 4.

## Module development

If you want to contribute to this module Windows implementation, first you must install the [Windows Development Dependencies](https://microsoft.github.io/react-native-windows/docs/rnw-dependencies).

You must temporary install `react-native-windows` package. Versions of `react-native-windows` and `react-native` must match. E.g. if the moudule uses `react-native@0.62`, install `npm i react-native-windows@^0.62 --dev`.

Now, you will be able to open corresponding `MODNAME...sln` file, e.g. `MODNAME62.sln` for `react-native-windows@0.62`.
