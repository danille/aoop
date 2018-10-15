cmake_minimum_required(VERSION 3.12)
project(lab1)

set(CMAKE_CXX_STANDARD 98)

add_executable(lab1 main.cpp CTable.h CTable.cpp CTableManager.cpp CTableManager.h)