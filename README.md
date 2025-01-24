# SinesBox Library

## Overview

SinesBox is a C++ library designed for [brief description of library purpose]. It provides [key features or functionality].

## Requirements

- C++ 17 or later
- CMake 3.10+
- Compatible compiler (GCC, Clang, MSVC)

## Installation

### Building from Source

1. Clone the repository:
```bash
git clone https://github.com/yourusername/SinesBox.git
cd SinesBox
```

2. Create a build directory:
```bash
mkdir build
cd build
```

3. Configure and build the project:
```bash
cmake ..
make
sudo make install
```

### Using CMake in Your Project

Add the following to your project's `CMakeLists.txt`:

```cmake
find_package(SinesBox REQUIRED)
target_link_libraries(YourProject SinesBox)
```

## Compilation

After installing the SinesBox library, compile your project using:

```bash
g++ -o test test.cpp -L/usr/local/lib -lSinesBox -I/usr/local/include -std=c++17
```

Breakdown of compilation flags:
- `-o test`: Output executable name
- `test.cpp`: Your source file
- `-L/usr/local/lib`: Specify library search path
- `-lSinesBox`: Link against SinesBox library
- `-I/usr/local/include`: Specify include directory
- `-std=c++17`: Use C++17 standard

## Usage

### Including the Library

In your C++ source files, include the necessary headers:

```cpp
#include <SinesBox/SinesBox.h>
#include <SinesBox/SinesGlobalSettings.h>
```

### Basic Example

```cpp
#include <SinesBox/SinesBox.h>
#include <SinesBox/SinesGlobalSettings.h>

int main() {
    // Initialize SinesBox library
    SinesBoxLib::SinesGlobalSettings::initialize();

    // Your application logic here

    return 0;
}
```

## Building Options

You can customize the build with the following CMake options:

- `-DCMAKE_INSTALL_PREFIX=/path/to/install`: Specify a custom installation directory
- `-DBUILD_TESTS=ON`: Build library tests (if applicable)

## Project Structure

- `src/`: Source files
- `include/`: Header files
- `tests/`: Unit tests
- `CMakeLists.txt`: CMake build configuration

## Contributing

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request
