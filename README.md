# TOML [![Build Status](https://travis-ci.com/Hun1eR/TOML.svg?branch=master)](https://travis-ci.com/Hun1eR/TOML) [![Download](https://badgen.net/github/release/Hun1eR/TOML)](https://github.com/Hun1eR/TOML/releases/latest) ![Platform](https://badgen.net/badge/platform/linux%20%7C%20windows/gray) [![License](https://img.shields.io/github/license/Hun1eR/TOML)](LICENSE)


AMXX Mod X module that allow to perform [CRUD](https://en.wikipedia.org/wiki/Create,_read,_update_and_delete) operations over [TOML](https://en.wikipedia.org/wiki/TOML) files.  


> **[toml.inc](third_party/scripting/include/toml.inc)**  
**[plugin_example.sma](third_party/scripting/toml_example.sma)**


## Installation
* Install the [AMXX Mod X](https://www.amxmodx.org) version 1.8.2 or later.
* Download archive [toml.zip](https://github.com/Hun1eR/TOML/releases/latest)
* Unpack the `toml_amxx.dll` (for Windows) or `toml_amxx_i386.so` (for Linux) to `<hlds>/cstrike/addons/amxmodx/modules` directory.


## Building
#### Prerequisites:
Compiler with C++17 support ([Visual Studio](https://visualstudio.microsoft.com), [GCC](https://gcc.gnu.org) or [Intel C++ Compiler](https://software.intel.com/c-compilers)).  
[CMake](https://cmake.org) version 3.13.5 or later (for Linux).

#### Building on Windows:
&nbsp;&nbsp;&nbsp;&nbsp;Just open the solution in Visual Studio and compile.

#### Building on Linux:
&nbsp;&nbsp;&nbsp;Open the console and go to the directory with sources (where *CMakeLists.txt* is located).  
&nbsp;&nbsp;&nbsp;For compile with *GCC* run the following command:<br/>
```sh
  rm -rf build && CC=gcc CXX=g++ cmake -B build && cmake --build build
```
&nbsp;&nbsp;&nbsp;For compile with *Intel C++ Compiler* run the following command:<br/>
```sh
  rm -rf build && CC=icc CXX=icpc cmake -B build && cmake --build build
```
&nbsp;&nbsp;&nbsp;For compile with *Clang* run the following command:<br/>
```sh
  rm -rf build && CC=clang CXX=clang++ cmake -B build && cmake --build build
```

## Release History
* 1.1.0
    * Updated SDKs.
    * Updated CMake scripts.
    * Updated toml11 library.
    * Added Clang compiler support.
    * Minor code fixes.
* 1.0.1
    * Code refactoring.
    * Linux version compiled with new version of GCC (10.1).
* 1.0.0
    * First release.


## Credits
Tom Preston-Werner ([TOML file format](https://github.com/toml-lang/toml))  
Toru Niina ([toml11](https://github.com/ToruNiina/toml11))


## License
This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.
