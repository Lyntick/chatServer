set(TARGET Utility)

set(SOURCES_FILES FileUtility.h TimeUtility.h)

add_library(${TARGET} INTERFACE)
target_sources(${TARGET} INTERFACE ${SOURCES_FILES})
target_include_directories(${TARGET} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})