#!/bin/bash

trap terminate SIGINT
terminate(){
    pkill test-cpp
    exit
}

echo === RUN ===

./bin/test-cpp
