cmake_minimum_required(VERSION 3.14)
project(BarcodeProject CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

if(MSVC)
    add_compile_options(/W4)
else()
    add_compile_options(-Wall -Wextra -Wpedantic)
endif()

set(SOURCES
    src/main.cpp
    src/Code128Encoder.cpp
    src/Code128SymbolTable.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.15.2.zip
)
FetchContent_MakeAvailable(googletest)

add_executable(BarcodeProjectTests
    tests/Code128EncoderTests.cpp
    src/Code128Encoder.cpp
    src/Code128SymbolTable.cpp
)
target_include_directories(BarcodeProjectTests PRIVATE src)
target_link_libraries(BarcodeProjectTests PRIVATE GTest::gtest_main)

include(GoogleTest)
enable_testing()
gtest_discover_tests(BarcodeProjectTests)