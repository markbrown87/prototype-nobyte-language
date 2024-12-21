cmake_minimum_required(VERSION 3.15)

project(SHL VERSION 0.0.2 DESCRIPTION "Compiled Language called Super Highlevel Language or SHL for short! It's a really crappy test language; sorry!")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

set(SRC main.cpp) # Main application source file

find_package(GTest REQUIRED)
set(CMAKE_CTEST_ARGUMENTS "--output-on-failure" "--rerun-failed")
include(GoogleTest)
enable_testing()

# Modules
add_subdirectory(lexer)
add_subdirectory(parser)
add_subdirectory(utilities)

add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME} 
    Lexer
    Parser
)