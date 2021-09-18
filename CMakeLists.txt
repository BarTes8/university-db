cmake_minimum_required(VERSION 3.10)
project(universityDB)

set(SRC
    main.cpp
    Menu.cpp
    Person.cpp
    Student.cpp
    UniversityDB.cpp
)
set(CMAKE_CXX_STANDARD 20)

add_executable(${PROJECT_NAME} ${SRC})
target_compile_options(${PROJECT_NAME} PRIVATE -Wall -Wextra -pedantic  -O3)

include(FetchContent)
FetchContent_Declare(
  googletest
  # Specify the commit you depend on and update it regularly.
  URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Now simply link against gtest or gtest_main as needed. Eg
enable_testing() 
add_executable(${PROJECT_NAME}-ut test.ut.cpp Menu.cpp Student.cpp UniversityDB.cpp Person.cpp)
target_link_libraries(${PROJECT_NAME}-ut gtest_main)
add_test(NAME s${PROJECT_NAME}_test COMMAND ${PROJECT_NAME}-ut)
