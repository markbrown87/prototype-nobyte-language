cmake_minimum_required(VERSION 3.15)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

project(Lexer
    VERSION 0.0.1 
    DESCRIPTION "Lexer part of the Language."
)

set(SRC 
    src/lexer.cpp
) # Source files

set(INC 
    inc/token_type.hpp
    inc/token_struct.hpp
    inc/lexer.hpp
) # Header files

add_library(${PROJECT_NAME} SHARED ${SRC} ${INC})

target_include_directories(${PROJECT_NAME} PUBLIC 
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/inc>
    $<INSTALL_INTERFACE:inc>
    PRIVATE ${SRC}
)

# Testing configuration begins here
# set(TEST_NAME ${PROJECT_NAME}_tests)
# set(TEST_FILES
#     ${CMAKE_CURRENT_SOURCE_DIR}/tests/unit_tests.cpp
# )

# add_executable(
#     ${TEST_NAME}
#     ${TEST_FILES}
# )
target_link_libraries(${PROJECT_NAME} 
)

# target_link_libraries(${TEST_NAME} PRIVATE gtest::gtest ${PROJECT_NAME})
# target_include_directories(${TEST_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/inc)

# gtest_discover_tests(${TEST_NAME})