set(TARGET Logger.Static)

add_library(${TARGET} STATIC Logger.h Logger.cpp)

target_link_libraries(${TARGET} Logger.Interface)