#include "logger.hpp"

Logger* Logger::instance = nullptr;

Logger::Logger(const std::string& filename, bool logToFile) : filename(filename), logToFile(logToFile) {
    if (logToFile) {
        logFile.open(filename, std::ios::app);
        if (!logFile.is_open()) {
            std::cerr << "error opening log file: " << filename << std::endl;
        }
    }
}

Logger* Logger::GetInstance(const std::string& filename, bool logToFile) {
    if (instance == nullptr) {
        instance = new Logger(filename, logToFile);
    }
    return instance;
}

void Logger::log(const std::string& message) {
    if (logToFile) {
        if (logFile.is_open()) {
            logFile << message << std::endl;
        }
    }
    else {
        std::cout << message << std::endl;
    }
}

std::string Logger::getFilename() const {
    return filename;
}

Logger::~Logger() {
    if (logToFile && logFile.is_open()) {
        logFile.close();
    }
}