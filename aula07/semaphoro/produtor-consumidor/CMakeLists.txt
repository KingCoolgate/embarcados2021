cmake_minimum_required(VERSION 3.15)
project(semaphore_example C)

set(CMAKE_C_STANDARD 99)

find_package(Threads REQUIRED)

add_executable(semaphore_example semaphore_example.c)

target_link_libraries(semaphore_example Threads::Threads)