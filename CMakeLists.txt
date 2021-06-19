cmake_minimum_required(VERSION 3.10)
project(universityDB)

set(SRC
    main.cpp
    Student.cpp
    AllStudents.cpp
)
set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} ${SRC})
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -Werror -pedantic -Wconversion -O3)