﻿cmake_minimum_required(VERSION 3.8)
project(HelloWord-CMake C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED TRUE)

if("${CMAKE_C_COMPILER_ID}" STREQUAL "MSVC")
	add_compile_options(/W4 /D_CRT_SECURE_NO_WARNINGS)
elseif("${CMAKE_C_COMPILER_ID}" STREQUAL "Clang")
	add_compile_options(-Weverything -Werror)
elseif("${CMAKE_C_COMPILER_ID}" STREQUAL "GNU")
	add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# comment
add_subdirectory(libutils)
add_subdirectory(sort-comparison)
add_subdirectory(ds-comparison)
add_subdirectory(list-comparison)

