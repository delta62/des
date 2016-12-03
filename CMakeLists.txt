cmake_minimum_required (VERSION 3.0.2)
project (DES VERSION 0.0.1 LANGUAGES C)

configure_file ("include/des.h.in" "include/des.h")

include_directories (include)
add_subdirectory (src bin)
