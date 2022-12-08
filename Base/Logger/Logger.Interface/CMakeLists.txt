set(TARGET Logger.Interface)

set(SOURCE_FILES ILogger.h)

add_library(${TARGET} INTERFACE)

target_sources(${TARGET} INTERFACE ${SOURCE_FILES})

target_include_directories(${TARGET} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})