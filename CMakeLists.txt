cmake_minimum_required(VERSION 3.10)

set(CMAKE_CXX_STANDARD 17)

project(compressor)

set(HEADER_FILES
    ./src/include/compare.h
    ./src/include/leafNode.h
    ./src/include/node.h
    ./src/include/rootNode.h
)

set(SOURCE_FILES
    ./src/compare.cpp
    ./src/leafNode.cpp
    ./src/node.cpp
    ./src/rootNode.cpp
    ./src/main.cpp
)

add_executable(${PROJECT_NAME} ${HEADER_FILES} ${SOURCE_FILES})