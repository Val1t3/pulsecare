cmake_minimum_required(VERSION 3.10)

project(pulsecare-core)

set(CMAKE_CXX_STANDARD 20)

add_executable(pulsecare-core
        main.cpp
        src/ADBManager.cpp
)