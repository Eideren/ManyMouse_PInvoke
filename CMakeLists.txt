cmake_minimum_required (VERSION 2.8)
project (ManyMouse)


set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/arc)

if(WIN32)
	
else()
	set(CMAKE_C_FLAGS "-Wl,--no-as-needed -ldl")
endif()

file(GLOB helloworld_SRC
    "*.h"
    "*.c"
)

#add_executable(ManyMouse ${helloworld_SRC})
add_library(ManyMouse SHARED ${helloworld_SRC})
set_target_properties(ManyMouse PROPERTIES PUBLIC_HEADER manymouse.h)