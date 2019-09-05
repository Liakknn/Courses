cmake_minimum_required(VERSION 3.8)

set(CMAKE WINDOWS_EXPORT_ALL_SYMBOLS ON)
add_library(utils_dynamic SHARED
        include/libutils/sort.h
        src/Sort_Bubble.c
        src/Sort_Selection.c
        src/Sort_Insert.c
        src/Sort_Natural_Merge.c
        src/Sort_Quick.c
        src/Sort_Shaker.c)
add_library(utils_static STATIC
        include/libutils/sort.h
        src/Sort_Bubble.c
        src/Sort_Selection.c
        src/Sort_Insert.c
        src/Sort_Natural_Merge.c
        src/Sort_Quick.c
        src/Sort_Shaker.c)
target_include_directories(utils_static PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
target_include_directories(utils_dynamic PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
