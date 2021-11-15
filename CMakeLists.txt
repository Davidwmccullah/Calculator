cmake_minimum_required(VERSION 3.21.3)
project(calculator)

set(CMAKE_C_FLAGS "-Wall -Werror -lm")

include_directories("${PROJECT_SOURCE_DIR}/include")

add_library(calc SHARED src/calculator.c)

add_executable(${PROJECT_NAME} src/calculator.c)
target_compile_definitions(${PROJECT_NAME} PRIVATE)
target_link_libraries(${PROJECT_NAME} calc)