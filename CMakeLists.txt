cmake_minimum_required(VERSION 3.14)

project(ptfl)

find_package(Qt5 REQUIRED COMPONENTS Widgets Core Sql)

add_subdirectory(src)
