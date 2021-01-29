cmake_minimum_required(VERSION 3.16.3)

# this is our project
project(exchange)

# this is what the output will be
add_executable(${PROJECT_NAME} main.cpp )

# recurse into this directory to build the library. It contains its own
# CMakefiles.txt to build the core library
add_subdirectory(core)

# the target needs to link the code project both for include files
# and also for the linker file 
target_include_directories(${PROJECT_NAME} PUBLIC core)
target_link_directories(${PROJECT_NAME} PRIVATE core)

# now make sure we link the object files in the core library to the main project
target_link_libraries(${PROJECT_NAME} core)