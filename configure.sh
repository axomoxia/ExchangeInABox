#! /bin/sh
# script to run cmake and regenerate the universe
cmake -s . -B build -Dtest=ON
