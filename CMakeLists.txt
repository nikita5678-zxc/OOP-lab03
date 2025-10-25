cmake_minimum_required(VERSION 3.14)
project(Figures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON) 

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/refs/tags/v1.14.0.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

set(SOURCE_FILES
    src/array.cpp
    src/rectangle.cpp
    src/trapezoid.cpp
    src/rhombus.cpp
)

add_executable(main
    main.cpp
    ${SOURCE_FILES}
)

add_executable(tests
    test/tests.cpp
    ${SOURCE_FILES}
)

target_link_libraries(tests PRIVATE GTest::gtest GTest::gtest_main)

target_include_directories(main PRIVATE include)
target_include_directories(tests PRIVATE include)

