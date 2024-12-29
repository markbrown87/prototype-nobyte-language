cmake_minimum_required(VERSION 3.15)

project(NoByte VERSION 0.0.2 DESCRIPTION "Compiled Language called NoByte after our little dog that just won't stop biting people's anckles.")

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

set(SRC main.cpp) # Main application source file

#find_package(GTest REQUIRED)
#set(CMAKE_CTEST_ARGUMENTS "--output-on-failure" "--rerun-failed")
# include(GoogleTest)
# enable_testing()

# Modules
add_subdirectory(lexer)
add_subdirectory(ast)
add_subdirectory(symbol_table)
add_subdirectory(parser)
# add_subdirectory(utilities)

add_executable(${PROJECT_NAME} ${SRC})
target_link_libraries(${PROJECT_NAME}
    Lexer
    Parser
)

add_custom_command(
    TARGET ${PROJECT_NAME}
    POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy "${CMAKE_CURRENT_SOURCE_DIR}/examples/step1.nob" "${CMAKE_BINARY_DIR}/testdata/step1.nob"
)