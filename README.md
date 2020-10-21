# rnw-modinit

Generate native modules project files (`.vcxproj` and `.sln`) for [react-native-windows](https://github.com/microsoft/react-native-windows). Generated files contain project files suitable for autolinking and some base C++ code that helps you get started. 

Module files are based on [react-native-camera Windows module files](https://github.com/react-native-camera/react-native-camera/tree/master/windows).

## Usage
```console
node app.js ModuleName template
```
* `ModuleName` will be used as the base for the filenames, the C++ namespace and the native module name. C++ identifiers rules apply.
* `template` is the template used to generate the project files. Currently:
  * `0.61+` for RNW 0.61 and later
  * `0.62+` for RNW 0.62 and later

To generate a native module that will support RNW versions 0.61 and up:
```console
node app.js RNModuleName 0.61+
```

To generate one that supports 0.62 and up:
```console
node app.js RNModuleName 0.62+
```

The app will generate the project files in `windows` folder.

## How it works
The tool will take all the files in the `template` folder, and change all occurrences of `MODNAME` in both the filenames and file content to the given `ModuleName`. It will also generate a GUID and replace all occurrences of `MODGUID` in the files with the generated one.
