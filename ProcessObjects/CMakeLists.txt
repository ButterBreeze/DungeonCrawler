cmake_minimum_required(VERSION 3.13)
project(ProcessObjects)

set(CMAKE_CXX_STANDARD 14)
#set(Sources main.cpp database.cpp processmodel.cpp table.cpp database.cpp xmlparser.cpp)

add_executable(ProcessObjects main.cpp column.cpp column.h database.cpp processmodel.cpp
        table.cpp database.cpp xmlparser.cpp tinyxml2.cpp)