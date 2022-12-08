cmake_minimum_required(VERSION 3.20)
project(chatServer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(ENABLE_CCACHE        "Enable the usage of Ccache."           ON)
option(ENABLE_WARNINGS      "Enable to add warnings to a target."   ON)


list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")#for finding ConanModule

include(CmakeConfig)
include(ConanModule)


if(ENABLE_CCACHE)
    include(Ccache)
endif()

if(ENABLE_WARNINGS)
    include(Warnings)
    set_warnings()
endif()

enable_testing()

add_subdirectory(Network)
add_subdirectory(Server)
add_subdirectory(Base)
