cmake_minimum_required(VERSION 3.10)

project(pulsecare-core)

set(CMAKE_CXX_STANDARD 20)

add_library(pulsecare-core
        src/ADBManager.cpp
        src/DeviceManager.cpp
        src/Core.cpp
)
target_include_directories(pulsecare-core PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/src)
