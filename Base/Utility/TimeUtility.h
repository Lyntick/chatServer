#pragma once


namespace Utility::Time { //This's thread safe time methods

    using timestempAlias = std::uint64_t;// it's alias for being more understandable time

    inline std::tm localtimeThreadSafe(std::time_t timer) {// wrapper for using localtime in thread-safe way, and for different OS
        std::tm bt{};
#if defined(__unix__)
        localtime_r(&timer, &bt);
#elif defined(_MSC_VER)
        localtime_s(&bt, &timer);
#else
        static std::mutex mtx;
        std::scoped_lock lock(mtx);
        bt = *std::localtime(&timer);
#endif
        return bt;
    }







}

