project(Base LANGUAGES CXX)

set(TARGET Base)

add_subdirectory(Models)
add_subdirectory(Logger)
add_subdirectory(Utility)


add_library(${TARGET} INTERFACE)

