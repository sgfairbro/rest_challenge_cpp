PROJECT(dataProcessor)

FILE(GLOB LIB_SOURCES "*.cpp")

message( "dataProcessor LIB_SOURCES: ${LIB_SOURCES}" )

ADD_LIBRARY(dataProcessor ${LIB_SOURCES})

# Link libraries
TARGET_LINK_LIBRARIES( dataProcessor )

TARGET_INCLUDE_DIRECTORIES( dataProcessor PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR} )
