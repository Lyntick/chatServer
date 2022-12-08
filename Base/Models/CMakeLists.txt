project(Models LANGUAGES CXX)

set(TARGET Models)

set(SOURCE_FILES)#write files here

add_library(${TARGET} INTERFACE)

target_sources(${TARGET} INTERFACE ${SOURCE_FILES})

target_include_directories(${TARGET}
        INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
