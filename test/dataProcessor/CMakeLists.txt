PROJECT(dataProcessor_test)

FILE(GLOB EXE_SOURCES "*.cpp")

message( "controller test exe sources: ${EXE_SOURCES} ")

#link_directories()

ADD_EXECUTABLE(dataProcessor_test ${EXE_SOURCES})

# Link libraries
TARGET_LINK_LIBRARIES( dataProcessor_test PUBLIC
  dataProcessor
  gtest
  gtest_main )

TARGET_INCLUDE_DIRECTORIES( dataProcessor_test PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR} )

add_test( NAME dataProcessor_test
  COMMAND dataProcessor_test --gtest_output=xml:${CMAKE_BINARY_DIR}/googleTestResults/dataProcessor_test.xml 
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} )

