cmake_minimum_required (VERSION 3.1)
PROJECT(RestChallengeCpp)

# Enable testing
include( CTest )
ENABLE_TESTING()
set( ROOT_DIR ${RestChallengeCpp_SOURCE_DIR} )

# Set install paths
set( RCC_INST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/install )
include ( cmake/install_macros.cmake )
install_macro_set_install_paths()

# Set rapidjson directory
set( RAPIDJSON_DIR ${ROOT_DIR}/vendor/pistache/third-party/rapidjson )

# Load google test
add_subdirectory(${ROOT_DIR}/vendor/pistache/third-party/googletest )
set_target_properties( gtest PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES ${ROOT_DIR}/vendor/pistache/third-party/googletest/include )

# Load Microsoft C++ REST ADK
find_package(cpprestsdk REQUIRED)

# Load pistache
list( APPEND CMAKE_PREFIX_PATH ${ROOT_DIR}/vendor/pistache/prefix/lib/cmake/pistache )
find_package(Pistache 0.0.2 REQUIRED)

SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17" )

# Add src directories
add_subdirectory(src)

# Add test directories
add_subdirectory(test)
