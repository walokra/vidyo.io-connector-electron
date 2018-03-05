# VidyoConnector-electron

Run VidyoConnector web app on desktop PC or Mac using electron.

Follow these instructions to download corresponding developer package(s) from vidyo.io, install tools for building and running electron with add-on, then run the VidyoConnector-electron app.

## Prerequisites

Create a directory for the electron sample (e.g. electronsample).
Go to https://developer.vidyo.io/documentation/latest/getting-started and download SDK for macOS and/or Windows.  We need the libraries and include files from these packages to build electron add-on.
Extract the content of the package(s) into the new directory.

```
$ ls -l electronsample
total 32
drwxr-xr-x@ 7 ...   238 Jul 27 17:58 VidyoClient-OSXSDK
drwxr-xr-x@ 7 ...   238 Jul 27 17:31 VidyoClient-WindowsSDK
```

## Installing

Download sample electron add-on source code to the same directory.

```
$ ls -l electronsample
total 32
-rw-r--r--  1 ...  1474 Jun 16 13:12 VidyoAddon.cc
drwxr-xr-x@ 7 ...   238 Jul 27 17:58 VidyoClient-OSXSDK
drwxr-xr-x@ 7 ...   238 Jul 27 17:31 VidyoClient-WindowsSDK
-rw-r--r--  1 ...  1822 Aug 11 17:31 binding.gyp
-rw-r--r--  1 ...  1999 Aug 17 16:54 main.js
-rw-r--r--  1 ...   366 Jun 16 13:13 package.json
```

Install electron and node-gyp:
```
npm install electron@1.7.5
npm install -g node-gyp
```

## Build and Run

### Set environment variables

For Mac:
```
export VIDYO_CLIENT_INCL_DIR=$PWD/VidyoClient-OSXSDK/include
export VIDYO_CLIENT_LIB_DIR=$PWD/VidyoClient-OSXSDK/lib/macos
```

For Windows:
```
set VIDYO_CLIENT_INCL_DIR=%cd%\VidyoClient-WindowsSDK\include
set VIDYO_CLIENT_LIB_DIR=%cd%\VidyoClient-WindowsSDK\lib\windows\x64\Release
```

### Build Vidyo Client Electron add-on

For Mac:
```
node-gyp rebuild --target=1.7.5 --arch=x64 --dist-url=https://atom.io/download/electron
```
For Windows:
```
node-gyp rebuild --target=1.7.5 --arch=x64 --dist-url=https://atom.io/download/electron -msvs_version=2017
```

### Run the App
```
npm start
```

### Note
Replace 1.7.5 with desired electron version number as needed.

