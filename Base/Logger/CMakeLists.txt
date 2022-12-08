project(Logger LANGUAGES CXX)

add_subdirectory(Logger.Interface)
add_subdirectory(Logger.Static)
add_subdirectory(Logger.Test)

set(TARGET Logger)

add_library(${TARGET} INTERFACE)