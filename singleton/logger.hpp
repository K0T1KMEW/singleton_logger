#pragma once

#include <iostream>
#include <fstream>

class Logger {
private:
    static Logger* instance;
    std::ofstream logFile;
    std::string filename;
    bool logToFile;

    Logger(const std::string& filename, bool logToFile);

public:
    Logger(Logger& other) = delete;
    void operator=(const Logger&) = delete;

    static Logger* GetInstance(const std::string& filename, bool logToFile);

    void log(const std::string& message);

    std::string getFilename() const;

    ~Logger();
};