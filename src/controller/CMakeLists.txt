PROJECT(controller)

FILE(GLOB LIB_SOURCES "*.cpp")

message( "controller LIB_SOURCES: ${LIB_SOURCES}" )

ADD_LIBRARY(controller ${LIB_SOURCES})

# Link libraries
TARGET_LINK_LIBRARIES( controller
  dataProcessor
  restClient )

TARGET_INCLUDE_DIRECTORIES( controller PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR} )
