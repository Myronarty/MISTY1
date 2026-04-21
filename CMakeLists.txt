cmake_minimum_required(VERSION 3.14)
project(MISTY1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Тимчасово вимикаємо GTest для локальної збірки
find_package(GTest REQUIRED)
include(GoogleTest)

add_library(misty
    MISTY1/Cipher_funcs.cpp
    MISTY1/Fx_functions.cpp
    MISTY1/Key.cpp
    MISTY1/S_boxes.cpp
)
target_include_directories(misty PUBLIC MISTY1)

add_executable(main_app MISTY1/main.cpp)
target_link_libraries(main_app misty)

# Тимчасово вимикаємо виконуваний файл тестів
add_executable(unit_tests tests/test.cpp)
target_link_libraries(unit_tests PRIVATE misty GTest::gtest_main)
enable_testing()
gtest_discover_tests(unit_tests)