// SinesBox.h
#ifndef SINESBOX_H
#define SINESBOX_H

#include <string>
#include <vector>
#include <map>

namespace SinesBoxLib {
    struct ColorCodes {
        std::string foreground;
        std::string background;
    };

    class SinesBox {
    public:
        SinesBox();
        
        void setText(const std::string& text);
        void setBorderColor(const std::string& color);
        void setTextColor(const std::string& color);
        void setBackgroundColor(const std::string& color);
        void setBorderBold(bool bold);
        void setTextBold(bool bold);
        void draw();
        void drawRainbow();

    private:
        // Terminal properties
        int terminal_width;
        
        // Content
        std::vector<std::string> text_lines;
        
        // Colors
        std::map<std::string, ColorCodes> colors;
        std::string border_color;
        std::string text_color;
        std::string background_color;
        
        // Style flags
        bool is_border_bold;
        bool is_text_bold;
        
        // Normal border characters
        const std::string normal_corner_tl;
        const std::string normal_corner_tr;
        const std::string normal_corner_bl;
        const std::string normal_corner_br;
        const std::string normal_horizontal;
        const std::string normal_vertical;
        
        // Bold border characters
        const std::string bold_corner_tl;
        const std::string bold_corner_tr;
        const std::string bold_corner_bl;
        const std::string bold_corner_br;
        const std::string bold_horizontal;
        const std::string bold_vertical;
        
        // Current border characters
        std::string corner_tl;
        std::string corner_tr;
        std::string corner_bl;
        std::string corner_br;
        std::string horizontal;
        std::string vertical;
        
        // Private methods
        int getTerminalWidth();
        void updateBorderCharacters();
        std::string colorize(const std::string& text, const std::string& fg_color, 
                           const std::string& bg_color, bool bold = false);
        std::string repeat(const std::string& str, int count);
        std::vector<std::string> wrapText(const std::string& text);
    };
}

#endif // SINESBOX_H
