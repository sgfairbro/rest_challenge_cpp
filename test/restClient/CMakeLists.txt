PROJECT(restClient_test)

FILE(GLOB EXE_SOURCES "*.cpp")

message( "restClient_test exe sources: ${EXE_SOURCES} ")

#link_directories()

ADD_EXECUTABLE(restClient_test ${EXE_SOURCES})

# Link libraries
TARGET_LINK_LIBRARIES( restClient_test PUBLIC
  restClient
  restServer
  gtest
  gtest_main )

TARGET_INCLUDE_DIRECTORIES( restClient_test PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR} )

add_test( NAME restClient_test
	COMMAND restClient_test --gtest_output=xml:${CMAKE_BINARY_DIR}/googleTestResults/restClient_test.xml 
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} )

