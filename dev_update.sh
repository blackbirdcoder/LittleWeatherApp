#!/bin/bash
bear -- clang++ src/*.cpp -std=c++17 -I/usr/local/include -g -o main \
    -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
