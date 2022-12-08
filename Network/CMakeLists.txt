project(Network)

set(TARGET Network)


add_subdirectory(Network.Libs)

add_library(${TARGET} INTERFACE)