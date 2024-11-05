#include "logger.hpp"

int main() {

    Logger* logger1 = Logger::GetInstance("log1.txt", true);
    logger1->log("This is the first log message in file.");
    std::cout << "Logger 1: writing to file: " << logger1->getFilename() << "\n";

    Logger* logger2 = Logger::GetInstance("log2.txt", false);
    logger2->log("This is a log message to console.");
    std::cout << "Logger 2: writing to console\n";

    if (logger1 == logger2) {
        std::cout << "Same instance (singleton reused)\n";
    }
    else {
        std::cout << "Different instances (singleton not reused)\n";
    }

    return 0;
}