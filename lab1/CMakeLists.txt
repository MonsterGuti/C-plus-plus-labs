cmake_minimum_required(VERSION 3.20)
project(lab1)

set(CMAKE_CXX_STANDARD 20)

# Създаваме отделен target за всеки файл
add_executable(time_task time.cpp)
add_executable(workers_task workers.cpp)
add_executable(line_task Line.cpp)