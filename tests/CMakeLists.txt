# make sure the test files can find the core files and gtest
include_directories(../core ../external/googletest/googletest/include)

# just add the test file here - we don't want the test_main - we must include
# it the top top level
add_library(tests test_orders.cpp)

