// this is the main file for the "exchange in a box" 
// its main purpose is to kick off the listeners for market participants.

#include "order.hpp"
#include "gtest/gtest.h"

int main(int argc, char ** argv)    
{
    ::testing::InitGoogleTest(&argc,argv);
    return RUN_ALL_TESTS();
}