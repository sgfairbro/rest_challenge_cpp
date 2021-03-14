PROJECT(restServer)

FILE(GLOB LIB_SOURCES "*.cpp")

message( "restServer LIB_SOURCES: ${LIB_SOURCES}" )

ADD_LIBRARY(restServer ${LIB_SOURCES})

# Link libraries
TARGET_LINK_LIBRARIES( restServer
    pistache_shared )

TARGET_INCLUDE_DIRECTORIES( restServer PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR} )
