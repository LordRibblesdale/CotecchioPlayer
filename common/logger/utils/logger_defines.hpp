#ifndef LOGGER_DEFINES
#define LOGGER_DEFINES

#include <string>
#include <iostream>

namespace Path {
    extern std::string LOGGER_OUTPUT_LOCATION;
}

namespace ColorValues {
    extern std::string RED_COLOR;
    extern std::string YELLOW_COLOR;
    extern std::string BLUE_COLOR;
    extern std::string CYAN_COLOR;
    extern std::string GRAY_COLOR;

    extern std::string RESET_COLOR;
}

enum Color {
    RED,
    YELLOW,
    BLUE,
    CYAN,
    GRAY,
    RESET
};

inline std::ostream& operator<<(std::ostream& stream, Color& c) {
    bool isCharacterOut = (&stream == &std::cout);

    if (isCharacterOut) {
        switch (c) {
            case RED:
                return stream << ColorValues::RED_COLOR;
            case YELLOW:    
                return stream << ColorValues::YELLOW_COLOR;
            case BLUE:
                return stream << ColorValues::BLUE_COLOR;
            case CYAN:
                return stream << ColorValues::CYAN_COLOR;
            case GRAY:
                return stream << ColorValues::GRAY_COLOR;
            case RESET:
                return stream << ColorValues::RESET_COLOR;
            default:
                return stream << "|?|";
        }
    } else {
        return stream;
    }
}

#endif