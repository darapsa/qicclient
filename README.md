# Qt Core wrapper for [libicclient](http://darapsa.org/libicclient)

# Building

## Getting

```sh
$ git clone git://darapsa.org/qicclient.git
$ cd qicclient
$ mkdir build && cd build
```

## Configuring for various target hosts (with optional debugging), compiling, linking, and installing

```sh
$ cmake -DCMAKE_TOOLCHAIN_FILE=/opt/android-sdk-update-manager/ndk/21.3.6528147/build/cmake/android.toolchain.cmake -DCMAKE_FIND_ROOT_PATH=/opt/Qt/5.15.2/android -DANDROID_NATIVE_API_LEVEL=21 -DANDROID_ABI=arm64-v8a -DCMAKE_INSTALL_PREFIX=/opt/Qt/5.15.2/android -DCMAKE_BUILD_TYPE=Debug ..
$ make
$ make install
```

or

```sh
$ emcmake cmake -DCMAKE_TOOLCHAIN_FILE=/opt/emsdk/upstream/emscripten/cmake/Modules/Platform/Emscripten.cmake -DQt5Core_DIR=/opt/Qt/5.15.2/wasm_32/lib/cmake/Qt5Core -DCMAKE_INSTALL_PREFIX=/opt/emsdk/upstream/emscripten/system -DCMAKE_BUILD_TYPE=Debug ..
$ emmake make
$ emmake make install
```

or so on.
