#!bin/bash

# ccr: C++ Compile & Run

# The first command-line argument is the filename.
filename=$1

# Compile and run the program.
g++ -std=c++14 -Wall $filename -o ./run.exe && {

    echo "[ Compiled Successfully !! Run Now! ]"
    echo "--------------------------------------"
    echo ""

    ./run.exe


    echo ""
    echo "--------------------------------------"
}