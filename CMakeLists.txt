cmake_minimum_required(VERSION 3.10)
project(HighPerformanceTCPServer)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(server main.cpp ${SOURCES})

# Link Winsock2 on Windows
if(WIN32)
    target_link_libraries(server ws2_32)
endif()