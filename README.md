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
- `CMakeLists.txt`: CMake build configuration

## Contributing

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

# SinesBox Library Documentation

## Overview

SinesBox is a C++ library for creating colorful, customizable text boxes in terminal applications. It provides an easy-to-use interface for drawing text boxes with various styling options, including color selection, bold formatting, and rainbow-styled borders.

## Features

- Customizable text box drawing
- Support for multiple text colors
- Border styling (normal and bold)
- Background color options
- Automatic text wrapping
- Rainbow border mode
- UTF-8 compatible

## Installation

### Prerequisites
- C++ compiler with C++11 support
- Linux or macOS (uses `sys/ioctl.h` for terminal width detection)

### Basic Usage

```cpp
#include "SinesBox.h"
#include "SinesGlobalSettings.h"

int main() {
    // Initialize global settings (UTF-8 support)
    SinesBoxLib::SinesGlobalSettings::initialize();

    // Create a SinesBox instance
    SinesBoxLib::SinesBox box;

    // Set text and styling
    box.setText("Hello, World! This is a sample text box.");
    box.setTextColor("green");
    box.setBorderColor("blue");
    box.setBorderBold(true);

    // Draw the box
    box.draw();

    return 0;
}
```

## API Reference

### `SinesBox` Class Methods

#### Constructors
- `SinesBox()`: Creates a new SinesBox instance with default settings

#### Text Methods
- `void setText(const std::string& text)`: Sets the text to be displayed in the box
  - Automatically wraps text to fit terminal width

#### Color Methods
- `void setBorderColor(const std::string& color)`: Sets the border color
- `void setTextColor(const std::string& color)`: Sets the text color
- `void setBackgroundColor(const std::string& color)`: Sets the background color

#### Style Methods
- `void setBorderBold(bool bold)`: Enables/disables bold border
- `void setTextBold(bool bold)`: Enables/disables bold text

#### Rendering Methods
- `void draw()`: Draws the text box with current settings
- `void drawRainbow()`: Draws the text box with rainbow-colored borders

### Supported Colors

The library supports the following colors:
- Basic colors: black, red, green, yellow, blue, magenta, cyan, white
- Bright colors: brightblack, brightred, brightgreen, brightyellow, brightblue, brightmagenta, brightcyan, brightwhite

## Global Settings

`SinesGlobalSettings::initialize()` sets the locale to UTF-8, ensuring proper character rendering on Linux systems.

## Example Scenarios

### Rainbow Border Box
```cpp
SinesBoxLib::SinesBox rainbowBox;
rainbowBox.setText("Colorful rainbow border with text!");
rainbowBox.drawRainbow();
```

### Styled Informational Box
```cpp
SinesBoxLib::SinesBox infoBox;
infoBox.setText("Important message with green border and yellow text");
infoBox.setBorderColor("green");
infoBox.setTextColor("yellow");
infoBox.setBorderBold(true);
infoBox.draw();
```

## Limitations
- Requires terminal support for ANSI color codes
- Works best on Unix-like systems (Linux, macOS)
- Terminal width detection might not work perfectly on all systems

## Contributing
Contributions are welcome! Please submit pull requests or open issues on the project repository.

# 🚨 **Attention**

The background color is **not perfect yet**, so I highly recommend **waiting for the next update** for an improved design.

Stay tuned for updates!
