
#ifndef CHATSERVER_LOGGER_H
#define CHATSERVER_LOGGER_H

#include <iostream>
#include <string>
#include <queue>

#include <sstream>
#include <fstream>
#include <filesystem>

#include <thread>
#include <mutex>
#include <condition_variable>

#include "ILogger.h"
namespace Base::Logger{

    class Logger : private ILogger{
    public:
        static Logger& getInstance();
        void log (const std::string& msg, LogLevel) override;

    private:
        Logger();
        ~Logger() override;
        void run();
        void stop();
        std::string timestamp();
        std::string threadID();
        std::string logLevelToStr(LogLevel);
        void openFile();
        void closeFile();
    private://fields
        std::thread _logThread;
        std::mutex _mutex;
        std::condition_variable _logCondition;
        bool _stop = false;

        std::queue<std::string> _logQueue;

        std::fstream _file;
        LogOutput _output = LogOutput::EVERYWHERE;


        std::pair<std::string, std::string> wrap = {"[", "]"};
    };

}



#endif //CHATSERVER_LOGGER_H
