cmake_minimum_required(VERSION 3.10)
project(SO101_Kinematics)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Eigen3 REQUIRED)

set(SOPHUS_INCLUDE_DIR "${CMAKE_CURRENT_SOURCE_DIR}/Sophus")

find_library(FMT_LIB fmt)

add_executable(demo src/main.cpp)
target_include_directories(demo PRIVATE ${SOPHUS_INCLUDE_DIR} include)
target_link_libraries(demo PRIVATE Eigen3::Eigen ${FMT_LIB})