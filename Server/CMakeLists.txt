project(Server)

set(TARGET Server)

add_subdirectory(Server.Core)
add_subdirectory(Server.ConsoleApp)
add_subdirectory(Server.Test)

add_library(${TARGET} INTERFACE)