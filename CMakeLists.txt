cmake_minimum_required (VERSION 2.6)

#### Options available ####
option(test "Building unit tests." OFF) # Unit testing option

# Name of the project (same as executable name)
set (PROJECT_NAME mips)

# By default, the client will be built in debug mode
# change Debug to Release if you want to build in release mode
set (PROJECT_BUILD_TYPE Debug)

# Libraries that are being used by the project.
set (PROJECT_EXTERNAL_LIBS )

project (${PROJECT_NAME})
set(CMAKE_BUILD_TYPE ${PROJECT_BUILD_TYPE})

# Configuration for the project
# Set include directory
include_directories(include)

# Get all the source files from the src directory, excluding the main
file (GLOB_RECURSE SOURCES src/mips/*.cpp)
# Create library using the source code
add_library(mips_lib ${SOURCES})

### GTEST UNIT TESTING ###
if (test)
    set (GTEST_DIR libs/gtest)
    file (GLOB_RECURSE TESTS tests/*.cpp)
    # add_executable (${PROJECT_NAME} ${TESTS})
    ADD_SUBDIRECTORY(${GTEST_DIR})
    enable_testing()
    include_directories(${GTEST_DIR}/include ${GTEST_DIR})
    add_executable(${PROJECT_NAME}_test ${TESTS})
    TARGET_LINK_LIBRARIES (${PROJECT_NAME}_test gtest gtest_main mips_lib)
endif()
add_executable (${PROJECT_NAME} src/main.cpp)
# Add libraries to be linked
TARGET_LINK_LIBRARIES (${PROJECT_NAME} ${PROJECT_EXTERNAL_LIBS} mips_lib)

#### Variables defining
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
####
