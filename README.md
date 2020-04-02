# Raptor
> A multiband waveshaping & distortion audio plugin.

## Installing / Getting started

Raptor is a C++ application, that leverages both juce for powering the API. The build
system has been ported to CMake. Juce's internal AudioPluginHost serves as a testbed
for development.

## Developing

Until constructs are standardized about the build, not for the faint of heart.

### Built With

C++, Juce, love.

### Prerequisites

C++14, Cmake, LLVM/Clang

### Setting up Dev

### Building

The project automatically rebuilds if the source code is altered and saved.

```shell
cmake build .
```
Note that certain hidden and static files require a full restart, really anything
outside the main application folder.

## Tests

Thoughts are welcome.

## Style guide

Our code uses Google's C++ style guide.
Please lint your code.

## Api Reference

## Licensing

This is private software, and cannot be redistributed or copied in any way.
All contents therein are confidential and may be the subject of legal privilege.
