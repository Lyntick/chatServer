set(TARGET Server.Lib)

set(SOURCE_FILES Connection.h)


add_library(${TARGET} INTERFACE)


target_sources(${TARGET} INTERFACE ${SOURCE_FILES} )
#target_include_directories(${TARGET} INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(${TARGET} INTERFACE asio::asio)