cmake_minimum_required(VERSION 3.0.0)
project(RBTree VERSION 0.1.0)

include(CTest)
enable_testing()
set(CMAKE_C_FLAGS "-std=c11 -Wall")
include_directories(include)
file(GLOB SRC_LIST "src/*.c")
add_executable(RBTree ${SRC_LIST})

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)
