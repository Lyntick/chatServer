set(TARGET Server.Core)

set(SOURCE_FILES ServerCore.cpp ServerCore.h)

if(WIN32)
    list(APPEND EXTRA_LIBS ws2_32 wsock32)
endif()

add_library(${TARGET} STATIC ${SOURCE_FILES})

target_include_directories(${TARGET}
        INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
#target_include_directories(${TARGET} PRIVATE
#        $<TARGET_PROPERTY:DataAccess.Postgre,SOURCE_DIR>/..)


#target_link_libraries(${TARGET} PRIVATE ${EXTRA_LIBS} asio::asio yas::yas DataAccess.Postgre)
#target_link_libraries(${TARGET} PUBLIC Network.Public DataAccess.Public Utility.Public Base.Logger.Static)

