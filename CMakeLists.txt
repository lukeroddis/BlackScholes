cmake_minimum_required(VERSION 3.31.3)
project(BlackScholes)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(SOURCES
    BlackScholes.cpp
    main.cpp
)

set(HEADERS
    BlackScholes.h
)

add_executable(BlackScholes ${SOURCES} ${HEADERS})