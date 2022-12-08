set(TARGET Server.ConsoleApp)


if(WIN32)
    set(EXTRA_LIBS ws2_32 wsock32)
endif()

set(SOURCE_FILES ServerConsole.cpp)

add_executable(${TARGET} ${SOURCE_FILES} )


target_link_libraries(${TARGET} ${EXTRA_LIBS} asio::asio)

install(TARGETS ${TARGET}
        CONFIGURATIONS Debug
        RUNTIME DESTINATION ${CMAKE_BINARY_DIR}/bin/)
install(TARGETS ${TARGET}
        CONFIGURATIONS Release
        RUNTIME DESTINATION ${CMAKE_BINARY_DIR}/bin/)