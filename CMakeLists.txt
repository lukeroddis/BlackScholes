cmake_minimum_required(VERSION 3.31.3)
project(BlackScholes)

set(CMAKE_CXX_STANDARD 23)

set(SOURCES
    BlackScholes.cpp
    main.cpp
)

set(HEADERS
    BlackScholes.h
)

add_executable(BlackScholes ${SOURCES} ${HEADERS})