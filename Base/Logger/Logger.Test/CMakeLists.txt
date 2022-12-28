set(TARGET Logger.Test)
set(OUTPUT_NAME Logger.Test)

set(SOURCE_FILES TestLoggerToFile.cpp)

set(EXTRA_LIBS Catch2::Catch2)

add_executable(${TARGET} ${SOURCE_FILES})

target_link_libraries(${TARGET} ${EXTRA_LIBS} Logger.Static)

target_include_directories(${TARGET} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_test(NAME ${OUTPUT_NAME} COMMAND ${TARGET})


