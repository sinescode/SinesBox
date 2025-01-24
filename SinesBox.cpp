// SinesBox.cpp
#include "SinesBox.h"
#include <iostream>
#include <sys/ioctl.h>
#include <unistd.h>
#include <sstream>

namespace SinesBoxLib {
    SinesBox::SinesBox() :
        // Normal border characters
        normal_corner_tl("┌"),
        normal_corner_tr("┐"),
        normal_corner_bl("└"),
        normal_corner_br("┘"),
        normal_horizontal("─"),
        normal_vertical("│"),
        // Bold border characters
        bold_corner_tl("┏"),
        bold_corner_tr("┓"),
        bold_corner_bl("┗"),
        bold_corner_br("┛"),
        bold_horizontal("━"),
        bold_vertical("┃"),
        // Default colors and styles
        border_color("white"),
        text_color("white"),
        background_color(""),
        is_border_bold(false),
        is_text_bold(false) {
        
        updateBorderCharacters();
        terminal_width = getTerminalWidth();
        
        colors = {
            {"black",   {"30", "40"}},
            {"red",     {"31", "41"}},
            {"green",   {"32", "42"}},
            {"yellow",  {"33", "43"}},
            {"blue",    {"34", "44"}},
            {"magenta", {"35", "45"}},
            {"cyan",    {"36", "46"}},
            {"white",   {"37", "47"}},
            {"brightblack",   {"90", "100"}},
            {"brightred",     {"91", "101"}},
            {"brightgreen",   {"92", "102"}},
            {"brightyellow",  {"93", "103"}},
            {"brightblue",    {"94", "104"}},
            {"brightmagenta", {"95", "105"}},
            {"brightcyan",    {"96", "106"}},
            {"brightwhite",   {"97", "107"}}
        };
    }

    void SinesBox::updateBorderCharacters() {
        if (is_border_bold) {
            corner_tl = bold_corner_tl;
            corner_tr = bold_corner_tr;
            corner_bl = bold_corner_bl;
            corner_br = bold_corner_br;
            horizontal = bold_horizontal;
            vertical = bold_vertical;
        } else {
            corner_tl = normal_corner_tl;
            corner_tr = normal_corner_tr;
            corner_bl = normal_corner_bl;
            corner_br = normal_corner_br;
            horizontal = normal_horizontal;
            vertical = normal_vertical;
        }
    }

    int SinesBox::getTerminalWidth() {
        struct winsize w;
        ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
        return w.ws_col;
    }

    std::string SinesBox::colorize(const std::string& text, const std::string& fg_color, 
                                  const std::string& bg_color, bool bold) {
        std::stringstream ss;
        ss << "\033[";
        
        std::vector<std::string> codes;
        
        // Add bold code first if enabled
        if (bold) {
            codes.push_back("1");
        }
        
        // Add foreground color if specified
        if (colors.count(fg_color)) {
            codes.push_back(colors[fg_color].foreground);
        }
        
        // Add background color if specified
        if (!bg_color.empty() && colors.count(bg_color)) {
            codes.push_back(colors[bg_color].background);
        }
        
        // Join all codes with semicolons
        for (size_t i = 0; i < codes.size(); i++) {
            ss << codes[i];
            if (i < codes.size() - 1) {
                ss << ";";
            }
        }
        
        ss << "m" << text << "\033[0m";
        return ss.str();
    }

    std::string SinesBox::repeat(const std::string& str, int count) {
        std::string result;
        for (int i = 0; i < count; i++) {
            result += str;
        }
        return result;
    }

    std::vector<std::string> SinesBox::wrapText(const std::string& text) {
        std::vector<std::string> wrapped_lines;
        std::string current_line;
        int max_width = terminal_width - 4;

        std::istringstream words(text);
        std::string word;
        
        while (words >> word) {
            if (current_line.empty()) {
                current_line = word;
            } else if (current_line.length() + word.length() + 1 <= max_width) {
                current_line += " " + word;
            } else {
                wrapped_lines.push_back(current_line);
                current_line = word;
            }
        }
        
        if (!current_line.empty()) {
            wrapped_lines.push_back(current_line);
        }
        
        return wrapped_lines;
    }

    void SinesBox::setText(const std::string& text) {
        text_lines = wrapText(text);
    }

    void SinesBox::setBorderColor(const std::string& color) {
        if (colors.count(color)) {
            border_color = color;
        }
    }

    void SinesBox::setTextColor(const std::string& color) {
        if (colors.count(color)) {
            text_color = color;
        }
    }

    void SinesBox::setBackgroundColor(const std::string& color) {
        if (colors.count(color)) {
            background_color = color;
        }
    }

    void SinesBox::setBorderBold(bool bold) {
        is_border_bold = bold;
        updateBorderCharacters();
    }

    void SinesBox::setTextBold(bool bold) {
        is_text_bold = bold;
    }

    void SinesBox::draw() {
        if (text_lines.empty()) return;

        // Draw top border
        std::cout << colorize(corner_tl, border_color, background_color, is_border_bold);
        std::cout << colorize(repeat(horizontal, terminal_width - 2), border_color, background_color, is_border_bold);
        std::cout << colorize(corner_tr, border_color, background_color, is_border_bold) << "\n";

        // Draw text lines with borders
        for (const auto& line : text_lines) {
            std::cout << colorize(vertical, border_color, background_color, is_border_bold) << " ";
            std::cout << colorize(line, text_color, background_color, is_text_bold);
            
            int padding = terminal_width - line.length() - 4;
            std::cout << colorize(std::string(padding, ' ') + " ", text_color, background_color);
            std::cout << colorize(vertical, border_color, background_color, is_border_bold) << "\n";
        }

        // Draw bottom border
        std::cout << colorize(corner_bl, border_color, background_color, is_border_bold);
        std::cout << colorize(repeat(horizontal, terminal_width - 2), border_color, background_color, is_border_bold);
        std::cout << colorize(corner_br, border_color, background_color, is_border_bold) << "\n";
    }

    void SinesBox::drawRainbow() {
        if (text_lines.empty()) return;

        std::vector<std::string> rainbow_colors = {
            "red", "yellow", "green", "cyan", "blue", "magenta"
        };
        size_t color_idx = 0;

        // Draw top border
        std::cout << colorize(corner_tl, rainbow_colors[0], background_color, true);
        for (int i = 0; i < terminal_width - 2; i++) {
            std::cout << colorize(horizontal, 
                                rainbow_colors[(i / 3) % rainbow_colors.size()], 
                                background_color, true);
        }
        std::cout << colorize(corner_tr, 
                            rainbow_colors[(terminal_width - 2) / 3 % rainbow_colors.size()], 
                            background_color, true) << "\n";

        // Draw text lines
        for (size_t i = 0; i < text_lines.size(); i++) {
            const auto& line = text_lines[i];
            color_idx = i % rainbow_colors.size();
            
            std::cout << colorize(vertical, rainbow_colors[color_idx], background_color, true) << " ";
            std::cout << colorize(line, rainbow_colors[color_idx], background_color, true);
            
            int padding = terminal_width - line.length() - 4;
            std::string padding_str(padding + 1, ' ');
            std::cout << colorize(padding_str, rainbow_colors[color_idx], background_color, true);
            std::cout << colorize(vertical, rainbow_colors[color_idx], background_color, true) << "\n";
        }

        // Draw bottom border
        color_idx = text_lines.size() % rainbow_colors.size();
        std::cout << colorize(corner_bl, rainbow_colors[color_idx], background_color, true);
        for (int i = 0; i < terminal_width - 2; i++) {
            std::cout << colorize(horizontal, 
                                rainbow_colors[(i / 3 + color_idx) % rainbow_colors.size()], 
                                background_color, true);
        }
        std::cout << colorize(corner_br, 
                            rainbow_colors[(terminal_width - 2) / 3 + color_idx % rainbow_colors.size()], 
                            background_color, true) << "\n";
    }
}