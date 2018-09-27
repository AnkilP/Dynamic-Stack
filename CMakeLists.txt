cmake_minimum_required(VERSION 3.12)
project(Dynamic_Stack)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(Dynamic_Stack
        Dynamic_stack.h
        Dynamic_stack_driver.cpp
        Dynamic_stack_tester.h
        ece250.h
        Exception.h
        LICENSE
        P2Description.pdf
        test.in
        Tester.h)
