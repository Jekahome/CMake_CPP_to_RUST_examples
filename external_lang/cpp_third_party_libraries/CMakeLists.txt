cmake_minimum_required(VERSION 3.5)

project (external_cpp_library)


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#-------------------- Create a library -----------------------------------------
#Generate the shared library from the library sources
#-------------------------------------------------------------------------------

include_directories("${PROJECT_SOURCE_DIR}/include/")

add_library(external_cpp_library_fake_lib 
            STATIC 
              src/main.cpp
            )

