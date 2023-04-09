cmake_minimum_required(VERSION 3.16)

project(LazyTools VERSION 0.1 LANGUAGES CXX)
set(CMAKE_AUTOMOC ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(QT_QML_OUTPUT_DIRECTORY  ${CMAKE_BINARY_DIR})

find_package(Qt6 6.2 REQUIRED COMPONENTS Qml Quick QuickTest)

add_subdirectory(lazytools)
add_subdirectory(test)

