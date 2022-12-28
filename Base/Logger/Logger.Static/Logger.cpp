

#include <sstream>
#include <iomanip>

#include "Logger.h"
#include "FileUtility.h"
#include "TimeUtility.h"


using Utility::File::getCurrentDirectory;
//using Utility::Time::


namespace Base::Logger {

    Logger::Logger() {
        _logThread = std::thread{&Logger::run, this};
    }

    Logger::~Logger()  {
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
        _file.open(getCurrentDirectory() + "/"  );//todo
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
        using std::chrono::duration_cast;
        using std::chrono::milliseconds;
        using std::chrono::system_clock;
        using Utility::Time::localtimeThreadSafe;
        using Utility::Time::timestempAlias;

        timestempAlias secDivider      = 1000;
        timestempAlias logMilliseconds = duration_cast<milliseconds>(system_clock::now().time_since_epoch()).count() % secDivider;
        timestempAlias rawTime         = system_clock::to_time_t(system_clock::now());

        std::tm safeTime = localtimeThreadSafe(rawTime);//todo

        const unsigned sizeBuffer      = 26;
        char           buf[sizeBuffer] = {0};

        /// MinGW will warning if we put this string directly
        std::string_view timeFormat = "%F %T";
        std::strftime(buf, sizeBuffer, timeFormat.data(), &safeTime);

        std::string str = std::string(buf);

        std::stringstream ss;
        ss << str << "." << std::setfill('0') << std::setw(3) << logMilliseconds;

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
