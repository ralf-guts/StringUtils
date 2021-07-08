cmake_minimum_required(VERSION 3.19)
project(StringUtils C)

set(CMAKE_C_STANDARD 99)

include_directories( ${PROJECT_SOURCE_DIR} )
aux_source_directory( ${PROJECT_SOURCE_DIR} source )

add_executable( StringUtils ${source} )