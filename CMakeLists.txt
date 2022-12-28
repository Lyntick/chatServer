cmake_minimum_required(VERSION 3.20)
project(chatServer)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

list(APPEND CMAKE_MODULE_PATH "${PROJECT_SOURCE_DIR}/cmake/")#for finding ConanModule

include(ConanModule)


enable_testing()

add_subdirectory(Network)
add_subdirectory(Server)
add_subdirectory(Base)