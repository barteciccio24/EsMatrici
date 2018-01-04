cmake_minimum_required(VERSION 3.7)
project(EsMatrici)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

add_subdirectory(test)

set(SOURCE_FILES main.cpp Matrix.h SquareMatrix.h MatrixFactory.h SquareMatrix.h TypeMatrixFactory.h MatrixFactory.h RowMatrix.h ColMatrix.h RectangleMatrix.h)
add_executable(EsMatrici main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(EsMatrici core)
