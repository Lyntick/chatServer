set(TARGET Logger.Static)

add_library(${TARGET} STATIC Logger.h Logger.cpp)

target_link_libraries(${TARGET} Logger.Interface Utility)
target_include_directories(${TARGET} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})