MACRO( install_macro_set_install_paths )
  set(CMAKE_INSTALL_PREFIX ${RCC_INST_DIR} CACHE INTERNAL "install dir" FORCE)
  
  set(RCC_LIB_INSTALL_DIR_SUFFIX "lib")
  set(RCC_EXE_INSTALL_DIR_SUFFIX "bin")
  set(RCC_TEST_INSTALL_DIR_SUFFIX "test")

  set(INSTALL_LIB_DIR ${RCC_LIB_INSTALL_DIR_SUFFIX} CACHE PATH
      "Installation directory for libraries")
  set(INSTALL_BIN_DIR ${RCC_EXE_INSTALL_DIR_SUFFIX} CACHE PATH
      "Installation directory for executables")
  set(INSTALL_TEST_DIR ${RCC_TEST_INSTALL_DIR_SUFFIX} CACHE PATH
      "Installation directory for tests")
  set(INSTALL_INCLUDE_DIR include CACHE PATH
      "Installation directory for header files")
  if(WIN32 AND NOT CYGWIN)
    set(DEF_INSTALL_CMAKE_DIR CMake)
  else()
    set(DEF_INSTALL_CMAKE_DIR lib/CMake/rcc)
  endif()

  set(INSTALL_CMAKE_DIR ${DEF_INSTALL_CMAKE_DIR} CACH PATH
      "Installation directory for CMake files")

  # Make all paths absolute
  foreach( p LIB BIN INCLUDE CMAKE TEST)
    set(var INSTALL ${p}_DIR)
    if(NOT IS_ABSOLUTE "${${var}}")
      set(${var} "${CMAKE_INSTALL_PREFIX}/${${var}}")
    endif()
  endforeach()
ENDMACRO()
