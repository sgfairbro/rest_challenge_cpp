PROJECT(restClient)

FILE(GLOB LIB_SOURCES "*.cpp")

message( "restClient LIB_SOURCES: ${LIB_SOURCES}" )

ADD_LIBRARY(restClient ${LIB_SOURCES})

# Link libraries
TARGET_LINK_LIBRARIES( restClient
    pistache_shared )

TARGET_INCLUDE_DIRECTORIES( restClient PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR} )
