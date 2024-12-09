cmake_minimum_required(VERSION 3.10)

project(pulsecare-cli)

set(CMAKE_CXX_STANDARD 20)

add_executable(pulsecare-cli
        main.cpp
        src/Cli.cpp
        src/CommandParser.cpp
)