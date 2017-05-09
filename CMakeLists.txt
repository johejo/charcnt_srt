cmake_minimum_required(VERSION 3.7)
project(charcnt_srt)

set(CMAKE_C_STANDARD 99)

set(SOURCE_FILES main.c defs.h sort.c count.c)
add_executable(charcnt_srt ${SOURCE_FILES} defs.h sort.c count.c)