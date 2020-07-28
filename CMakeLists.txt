cmake_minimum_required(VERSION 2.6)
project(factowiththtreads)

include_directories(${PROJECT_SOURCE_DIR})

set(PROJ_SOURCES
	src/factorial_thread.cpp
	src/factorial_main.cpp
    )
    
set(PROJ_LIBS
	pthread
    )

set (target_name ${PROJECT_NAME})
message("CMAKE_PROJECT_NAME = ${CMAKE_PROJECT_NAME}")
message("PROJECT_NAME = ${PROJECT_NAME}")
message("target_name = ${target_name}")

add_executable(${target_name} ${PROJ_SOURCES})
target_link_libraries(${target_name} ${PROJ_LIBS})
install(TARGETS ${target_name} DESTINATION usr/bin)

################################
# CTest
################################
# enable_testing()
# OR
include(CTest)
set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/tests)
set(CTEST_BINARY_DIRECTORY ${PROJECT_BINARY_DIR}/tests)
add_subdirectory(tests)

#add_library(${target_name} SHARED ${PROJ_SOURCES})
#target_link_libraries(${target_name} ${PROJ_LIBS})
#install(TARGETS ${target_name} DESTINATION usr/lib)
