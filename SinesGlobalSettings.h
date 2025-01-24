#ifndef SINES_GLOBAL_SETTINGS_H
#define SINES_GLOBAL_SETTINGS_H

#include <clocale>

namespace SinesBoxLib {
    class SinesGlobalSettings {
    public:
        static void initialize() {
            // Set locale to UTF-8 for consistent output on Linux systems
            std::setlocale(LC_ALL, "en_US.UTF-8");
        }
    };
}

#endif // SINES_GLOBAL_SETTINGS_H
