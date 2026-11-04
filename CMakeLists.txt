cmake_minimum_required(VERSION 3.16)
project(HelloWorld LANGUAGES CXX)

# Require C++20 Standard
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Disable compiler extensions (forces standard C++ instead of gnu++20)
set(CMAKE_CXX_EXTENSIONS OFF)

# executable file(s)
add_executable(main src/main.cpp)

# enable strict warning levels for GCC/Clang
if(CMAKE_CXX_COMPILER_ID MATCHES "GNU|Clang")
    target_compile_options(main PRIVATE
        -Wall
        -Wextra
        -Wpedantic
        -Wconversion
        -Wsign-conversion
        -Weffc++
        -Werror
    )
endif()