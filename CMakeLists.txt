cmake_minimum_required(VERSION 3.16.3)


# this option turns on testing
# this defaults to off. We can invoke it my passing -Dtest=ON to 
# the make command line
option(test, "Build All Tests" OFF)

# this is our project
project(exchange)

# this is what the output will be
add_executable(${PROJECT_NAME} main.cpp )

# recurse into this directory to build the library. It contains its own
# CMakefiles.txt to build the core library
add_subdirectory(core)

# add the object files from the subdirectory into the project
target_include_directories(${PROJECT_NAME} PUBLIC core )

# and now link in the core files
target_link_directories(${PROJECT_NAME} PRIVATE core)

# link together
target_link_libraries(${PROJECT_NAME} PRIVATE core)

# now if we have defined test, we want to build the tests as well
if (test)

        # add gtest - this should be only for a test build once we get further along
        add_subdirectory(external/googletest)

        # add the tests subdirectory
        add_subdirectory(tests)

        # create the test application
        add_executable(exchange_unit_tests tests/test_main.cpp)

        # add build to include google test stuff.
        # and everything in the tests directory
        target_include_directories(exchange_unit_tests 
                        PUBLIC external/googletest/googletest/include
                        PUBLIC tests
                        PUBLIC core)

        # need to make sure we link google test and the test directory
        target_link_directories(exchange_unit_tests PRIVATE gtest
                                                    PRIVATE tests
                                                    PRIVATE core)

        # now make sure we link the object files in the core library to the main project
        target_link_libraries(exchange_unit_tests core gtest tests)
endif()