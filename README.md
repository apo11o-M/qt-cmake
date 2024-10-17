# Qt CMake Example

This is a minimal example of a Qt application built with CMake.

I'm using Windows 10 with MSVC 2022 and Qt 6.8.0.

## Getting Started

1. Make sure to have Qt and CMake installed on your system.
2. Edit the `CMakeLists.txt` so the `CMAKE_PREFIX_PATH` points to your Qt installation.
3. Run the following commands:

```bash
mkdir build
cd build
cmake ..
cmake --build .
```

4. Do keep in mind if you don't have the Qt bin directory in your PATH, you will need to copy the required DLLs to the executable directory. Some of them includes:

- Qt6Widgets.dll
- Qt6Core.dll
- Qt6Gui.dll
