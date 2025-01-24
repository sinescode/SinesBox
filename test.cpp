#include <SinesBox/SinesBox.h>
#include <SinesBox/SinesGlobalSettings.h>
#include <iostream>
#include <thread>
#include <chrono>


void basicExample() {
    std::cout << "\nBasic Example:\n";
    SinesBoxLib::SinesBox box;
    box.setText("Hello, World!");
    box.setBorderColor("cyan");
    box.setTextColor("yellow");
    box.setBorderBold(true);
    box.draw();
}

void multilineExample() {
    std::cout << "\nMultiline Example:\n";
    SinesBoxLib::SinesBox box;
    box.setText("This is a longer text that will automatically wrap to multiple lines based on your terminal width.It demonstrates how the box adjusts to content length while maintaining proper formatting and alignment.This is a longer text that will automatically wrap to multiple lines based on your terminal width.It demonstrates how the box adjusts to content length while maintaining proper formatting and alignment.");
    box.setBorderColor("green");
    box.setTextColor("white");
    box.setBackgroundColor("brightblack");
    box.setBorderBold(true);
    box.draw();
}

void rainbowExample() {
    std::cout << "\nRainbow Example:\n";
    SinesBoxLib::SinesBox box;
    box.setText("Rainbow text with automatic wrapping and colorful borders This example shows how to create eye-catching displays.This is a longer text that will automatically wrap to multiple lines based on your terminal width.It demonstrates how the box adjusts to content length while maintaining proper formatting and alignment.This is a longer text that will automatically wrap to multiple lines based on your terminal width.It demonstrates how the box adjusts to content length while maintaining proper formatting and alignment.");
    box.drawRainbow();
}

void styleExamples() {
    std::cout << "\nStyle Examples:\n";
    
    // Normal style
    SinesBoxLib::SinesBox normal;
    normal.setText("Normal border");
    normal.setBorderColor("white");
    normal.draw();
    
    std::cout << "\n";
    
    // Bold border
    SinesBoxLib::SinesBox bold;
    bold.setText("Bold border");
    bold.setBorderColor("white");
    bold.setBorderBold(true);
    bold.draw();
    
    std::cout << "\n";
    
    // Bold text
    SinesBoxLib::SinesBox boldText;
    boldText.setText("Bold text");
    boldText.setTextBold(true);
    boldText.draw();
}

void colorExamples() {
    std::cout << "\nColor Examples:\n";
    
    const std::vector<std::string> colors = {
        "red", "green", "yellow", "blue", "magenta", "cyan",
        "brightred", "brightgreen", "brightyellow", "brightblue", "brightmagenta", "brightcyan"
    };
    
    for (const auto& color : colors) {
        SinesBoxLib::SinesBox box;
        box.setText("Color: " + color);
        box.setBorderColor(color);
        box.setTextColor(color);
        box.draw();
        std::cout << "\n";
    }
}

void animatedExample() {
    std::cout << "\nAnimated Example (press Ctrl+C to stop):\n";
    SinesBoxLib::SinesBox box;
    box.setText("Animated Box!");
    
    const std::vector<std::string> colors = {
        "red", "yellow", "green", "cyan", "blue", "magenta"
    };
    
    size_t colorIndex = 0;
    while (true) {
        // Clear previous output (move cursor up and clear line)
        std::cout << "\033[3A\033[J";
        
        box.setBorderColor(colors[colorIndex]);
        box.setTextColor(colors[(colorIndex + 2) % colors.size()]);
        box.setBorderBold(colorIndex % 2 == 0);
        box.draw();
        
        colorIndex = (colorIndex + 1) % colors.size();
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
    }
}

int main() {
    // Initialize global settings (important for Windows compatibility)
    SinesBoxLib::SinesGlobalSettings::initialize();
    
    std::cout << "BoxDesign Examples\n";
    std::cout << "=================\n";
    
    basicExample();
    multilineExample();
    rainbowExample();
    styleExamples();
    colorExamples();
    
    try {
        animatedExample();  // This will run until Ctrl+C is pressed
    } catch (...) {
        std::cout << "\nAnimation stopped.\n";
    }
    
    return 0;
}