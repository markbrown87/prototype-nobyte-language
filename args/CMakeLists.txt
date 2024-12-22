cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

project(ArgumentParser
    VERSION 0.0.1 
    DESCRIPTION "Parses Arguments passed into the application."
)

set(SRC 
    src/arg_parser.cpp
    src/arg_config.cpp
) # Source files

set(INC 
    inc/arg_parser.hpp
    inc/arg_config.hpp
) # Header files

add_library(${PROJECT_NAME} SHARED ${SRC} ${INC})

target_include_directories(${PROJECT_NAME} PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
    $<INSTALL_INTERFACE:inc>
    PRIVATE ${SRC}
)

# Testing configuration begins here
set(TEST_NAME ${PROJECT_NAME}_tests)
set(TEST_FILES
    ${CMAKE_CURRENT_SOURCE_DIR}/tests/unit_tests.cpp
)

add_executable(
    ${TEST_NAME}
    ${TEST_FILES}
)
target_link_libraries(${PROJECT_NAME} 
)


target_link_libraries(${TEST_NAME} PRIVATE gtest::gtest ${PROJECT_NAME})
target_include_directories(${TEST_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)

gtest_discover_tests(${TEST_NAME})