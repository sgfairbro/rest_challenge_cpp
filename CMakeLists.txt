cmake_minimum_required (VERSION 2.8)
PROJECT(RestChallengeCpp)

# Enable testing
include( CTest )
ENABLE_TESTING()
set( ROOT_DIR ${RestChallengeCpp_SOURCE_DIR} )

# Set install paths
set( RCC_INST_DIR ${CMAKE_CURRENT_SOURCE_DIR}/install )
include ( cmake/install_macros.cmake )
install_macro_set_install_paths()

# Load google test
# add_subdirectory(${ROOT_DIR}/vendor/pistache/third-party/googletest googletest )
add_subdirectory(${ROOT_DIR}/vendor/pistache/third-party/googletest )
set_target_properties( gtest PROPERTIES
  INTERFACE_INCLUDE_DIRECTORIES ${ROOT_DIR}/vendor/pistache/third-party/googletest/include )

# Load boost
# add_library( boost INTERFACE )
# target_include_directories(boost INTERFACE 
#   ${ROOT_DIR}/vendor/boost_1_72_0)

SET( CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17" )

# Add src directories
add_subdirectory(src)

# Add test directories
add_subdirectory(test)
