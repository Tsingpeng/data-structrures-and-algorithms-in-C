cmake_minimum_required(VERSION 3.0.0)
project(Proj_tree VERSION 0.1.0)

# include(CTest)
# enable_testing()
set(CMAKE_C_FLAGS "-std=c1x ")
include_directories(include)
file(GLOB SRC_LIST "src/*.c")

add_executable(Proj_tree ${SRC_LIST})

# set(CPACK_PROJECT_NAME ${PROJECT_NAME})
# set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
# include(CPack)
