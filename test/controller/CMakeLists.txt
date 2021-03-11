PROJECT(controller_test)

FILE(GLOB EXE_SOURCES "*.cpp")

message( "controller test exe sources: ${EXE_SOURCES} ")

#link_directories()

ADD_EXECUTABLE(controller_test ${EXE_SOURCES})

# Link libraries
TARGET_LINK_LIBRARIES( controller_test PUBLIC
  controller
  gtest
  gtest_main )

TARGET_INCLUDE_DIRECTORIES( controller_test PUBLIC
  ${CMAKE_CURRENT_SOURCE_DIR} )

add_test( NAME controller_test
  COMMAND controller_test --gtest_output=xml:${CMAKE_BINARY_DIR}/googleTestResults/controller_test.xml 
  WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR} )

