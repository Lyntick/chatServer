#There is you can add some librarie


if(NOT EXISTS "${CMAKE_BINARY_DIR}/conan.cmake")
    message(STATUS "Downloading conan.cmake from https://github.com/conan-io/cmake-conan")
    file(DOWNLOAD "https://raw.githubusercontent.com/conan-io/cmake-conan/0.18.1/conan.cmake"
            "${CMAKE_BINARY_DIR}/conan.cmake"
            TLS_VERIFY ON)
endif()

include(${CMAKE_BINARY_DIR}/conan.cmake)

conan_cmake_configure(REQUIRES
        asio/1.18.1
        catch2/2.13.8
        nlohmann_json/3.11.2
        jwt-cpp/0.6.0
        GENERATORS cmake_find_package)

conan_cmake_autodetect(settings)

conan_cmake_install(PATH_OR_REFERENCE .
        BUILD missing
        REMOTE conancenter
        INSTALL_FOLDER ${CMAKE_BINARY_DIR}/Conan
        SETTINGS ${settings})


list(APPEND CMAKE_MODULE_PATH ${CMAKE_BINARY_DIR}/Conan)
list(APPEND CMAKE_PREFIX_PATH ${CMAKE_BINARY_DIR})

find_package(asio REQUIRED)
find_package(catch2 REQUIRED)
find_package(nlohmann_json REQUIRED)
find_package(jwt-cpp REQUIRED)
