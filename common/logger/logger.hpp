#ifndef LOGGER
#define LOGGER

#include <string>
#include <iostream>
#include "utils/logger_defines.hpp"

enum LogType {
    INFO,
    WARNING,
    ERROR,
    RENDERING,
    COMPUTATION,
    DEBUG
};


// TODO check here (if only beginning or whole line)
inline std::ostream& operator<<(std::ostream& stream, LogType& logType) {
    switch (logType) {
        case INFO:
            return stream << "[INFO]\t";
        case WARNING:
            return stream << Color::YELLOW << "[WARNING]\t" << Color::RESET;
        case ERROR:
            return stream << Color::RED << "[ERROR]\t" << Color::RESET;
        case RENDERING:
            return stream << Color::GRAY << "[RENDERING]\t" << Color::RESET;
        case COMPUTATION:
            return stream << Color::CYAN << "[COMPUTATION]\t" << Color::RESET;
        case DEBUG:
            return stream << Color::BLUE << "[DEBUG]\t" << Color::RESET;
        default:
            break;
    }
}

class Logger {
public:
    inline static void beginLog(std::ostream& stream, LogType logType, const std::string& message) {
        stream << logType << message << std::endl;
    }

    inline static bool isPrintingOnFile() {
        return printOnFileCondition;
    }

    inline static bool isDebuggingModeEnabled() {
        return printDebug;
    }

    inline static void setPrintOnFile(bool condition) {
        printOnFileCondition = condition;
    }

    inline static void enableDebuggingMode(bool condition) {
        printDebug = condition;
    }
protected:
    static bool printOnFileCondition;
    static bool printDebug;
};

#endif