PROJECT(restExecutable)

FILE(GLOB EXE_SOURCES "*.cpp")

message("restExecutable exe sources: ${EXE_SOURCES}")

#link_directories()

ADD_EXECUTABLE(restExecutable ${EXE_SOURCES})

# Link all libraries
TARGET_LINK_LIBRARIES( restExecutable
  controller )
