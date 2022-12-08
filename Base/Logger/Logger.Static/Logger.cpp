
#include "Logger.h"

namespace Base::Logger {

    Logger::Logger() {
        _logThread = std::thread{&Logger::run, this};
    }

    Logger::~Logger() noexcept {
        if (_logThread.joinable()) {
            stop();
            _logThread.join();
        }
    }

    void Logger::stop() {
        std::unique_lock uLock(_mutex);
        _stop = true;
        _logCondition.notify_one();
    }

    Logger &Logger::getInstance() {
        static Logger logger;
        return logger;
    }

    void Logger::openFile() {
        _file.open(getCurrentDirectory() + "/" + )//todo
    }

    void Logger::closeFile() {
        if (_file.is_open()) {
            _file.close();
        }
    }

    void Logger::run() {

        while (true) {
            std::unique_lock uLock(_mutex);
            _logCondition.wait(uLock, [&]() { return _stop || !_logQueue.empty(); });

            if (_stop) {
                break;
            }

            std::string msg = _logQueue.front();
            _logQueue.pop();
            switch (_output) {
                case LogOutput::CONSOLE:
                    std::cout << msg << std::endl;
                    break;
                case LogOutput::FILE:
                    openFile();
                    _file << msg;
                    closeFile();
                    break;
                case LogOutput::EVERYWHERE:
                    std::cout << msg << std::endl;
                    openFile();
                    _file << msg;
                    closeFile();
                    break;
                default:
                    std::cout <<  "UnknownLogOut" << std::endl;
            }
        }

    }

    void Logger::log(const std::string &msg, LogLevel level) {
        auto wrapFun = [&](const std::string &msg) { return std::string(wrap.first + msg + wrap.second); };

        std::string resultMsg = wrapFun(timestamp()) + " " + wrapFun(threadID()) + " " +
                                wrapFun(logLevelToStr(level)) + " " + msg;

        std::unique_lock uLock(_mutex);
        _logQueue.push(resultMsg);
        _logCondition.notify_one();
    }

    std::string Logger::threadID() {
        std::stringstream strStream;
        strStream << std::this_thread::get_id();
        return strStream.str();
    }

    std::string Logger::timestamp() {

        std::stringstream strStream;
        strStream << ;//todo think how to do correct wrap of std::time
        return strStream.str();
    }

    std::string Logger::logLevelToStr(LogLevel level) {
        std::string trueLevel{};
        switch (level) {
            case LogLevel::DEBUG:
                trueLevel = "DEBUG";
                break;
            case LogLevel::ERROR:
                trueLevel = "ERROR";
                break;
            case LogLevel::WARNING:
                trueLevel = "WARNING";
                break;
            case LogLevel::INFO:
                trueLevel = "INFO";
                break;
            default:
                trueLevel = "Unknown";
        }
        return trueLevel;
    }


}
