
#ifndef CHATSERVER_ILOGGER_H
#define CHATSERVER_ILOGGER_H

#include <string>

namespace Base::Logger{

    enum class LogLevel{
        DEBUG,
        WARNING,
        ERROR,
        INFO
    };

    enum class LogOutput{
        FILE,
        CONSOLE,
        EVERYWHERE
    };

    class ILogger{
    public:
       virtual void log(const std::string&, LogLevel) = 0;
       virtual ~ILogger() = default;
    };
}



#endif //CHATSERVER_ILOGGER_H
