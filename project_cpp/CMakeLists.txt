# https://github.com/cCppProsto/cmake/tree/master/lesson_2

cmake_minimum_required(VERSION 3.5)

# имя проекта. Доступно ${PROJECT_NAME}
project(my_project)
set(MAIN_PROJECT_SRC_LIST main)

# OUTPUT => STATUS,WARNING,DERPECATED,FATAL_ERROR,SEND_ERROR
message(STATUS "PROJECT_SOURCE_DIR=${PROJECT_SOURCE_DIR}")
message(STATUS "CMAKE_SOURCE_DIR=${CMAKE_SOURCE_DIR}")
message(STATUS "MAIN_PROJECT_SRC_LIST=${MAIN_PROJECT_SRC_LIST}")
message(STATUS "PROJECT_NAME=${PROJECT_NAME}")

# установка стандарта версии языка c++ (c++98,c++03,c++11,c++14,c++17)
# set(CMAKE_CXX_STANDART 11)
# или через флаги компиляции установить последнюю версию стандарта `c++1y`
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

# установка стандарта для языка с (c89,c90,c99,c11)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c99")

# передать флаги компиляции
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wno-unused-variable -O2")
# или другим способом передать флаги компилятора
# add_definitions(-Wall -Wno-unused-variable -O2)


# добавить папку для поиска заголовочных файлов,а файлы .cpp реализации должны быть на уровне с main.cpp
include_directories("${PROJECT_SOURCE_DIR}/include/")

# Подключение всех папок библиотек для поиска заголовочных файлов
FILE(GLOB dir_libraries "${PROJECT_SOURCE_DIR}/lib/*")
foreach (_dir ${dir_libraries})
    include_directories("${_dir}/") 
endforeach()


#-------------------- Create a static library -----------------------------------------
#Generate the static library from the library sources
#--------------------------------------------------------------------------------------
#include_directories("${PROJECT_SOURCE_DIR}/lib/my_static_lib/") # include .hpp Уже подключил в foreach
add_library(${PROJECT_NAME}_fake_lib STATIC 
            lib/my_static_lib/mul.cpp
          )

target_include_directories(${PROJECT_NAME}_fake_lib
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/my_static_lib
)

#-------------------- Create a library --------------------------------------------------
#Generate the shared library from the library sources
#----------------------------------------------------------------------------------------
#include_directories("${PROJECT_SOURCE_DIR}/lib/my_shared_dynamic_lib/") # include .hpp Уже подключил в foreach
add_library(${PROJECT_NAME}_fake_dyn_lib SHARED 
            lib/my_shared_dynamic_lib/sLibrary.cpp
          )
          
add_library(${PROJECT_NAME}_fake_dyn_lib::lib_1 ALIAS ${PROJECT_NAME}_fake_dyn_lib)

target_include_directories(${PROJECT_NAME}_fake_dyn_lib
    PUBLIC 
        ${PROJECT_SOURCE_DIR}/my_shared_dynamic_lib
)

#-------------------- Create a external library -----------------------------------------
# Generate static library from external library sources libcmake_example_4_static_fake_lib.a
# Для сборки подпроектов используют add_subdirectory() https://www.youtube.com/watch?v=-RdBrHGTW6Y&ab_channel=cppProsto
#-------------------------------------------------------------------------------
# Кроме этого, файлы заголовков все равно нужно копировать из внешней библиотеки в include/
link_directories(${CMAKE_SOURCE_DIR}/third_lib/)


# ---------------------------------------------------------------------------------------
# Альтернативный вариант сборки external библиотеки с помощью скриптов
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${CMAKE_SOURCE_DIR}/cmake/")
enable_language(Rust)
include(CMakeCargo)
add_subdirectory(test-lib)

#------------------- Create an executable ------------------------------------------------
# подключение others .cpp 
FILE(GLOB include_others_files "${CMAKE_SOURCE_DIR}/others/*.*")
# подключение others .hpp
include_directories("${PROJECT_SOURCE_DIR}/others/")

message(STATUS "INCLUDE_DIRECTORIES=${INCLUDE_DIRECTORIES}")

# собрать в один список все файлы `.cpp` выбранной папки (все файлы должны быть одного стандарта, т.е. .cpp и .с не соберутся)
# GLOB_RECURSE - найдет по шаблону и все инструкции #include рекурсивно подключит
# GLOB - найдет только по шаблону
FILE(GLOB src_files ${CMAKE_SOURCE_DIR}/src/*.*)

# теперь собрать исполняемый файл из списка файлов (add_library создать библиотеку)
add_executable(${PROJECT_NAME} ${include_others_files} ${src_files})

#add_subdirectory("${PROJECT_SOURCE_DIR}/include/my_lib")
#target_link_libraries(${PROJECT_NAME} "my_include_lib")
 
# Линковка библиотек к исполняемому файлу. Выполняется после вызова add_executable ---------
# линковать статиическую библиотеку с целевым файлом
target_link_libraries( ${PROJECT_NAME}
    PRIVATE 
        ${PROJECT_NAME}_fake_lib
)
# линковать динамическую библиотеку с целевым файлом
target_link_libraries( ${PROJECT_NAME}
    PRIVATE 
        ${PROJECT_NAME}_fake_dyn_lib
)
# линковать внешнюю динамическую библиотеку `libexternal_cpp_library_fake_lib.a` с целевым файлом
target_link_libraries( ${PROJECT_NAME}
    PUBLIC
        external_cpp_library_fake_lib
)
# линковать внешнюю динамическую библиотеку `libexternal_rust_library.so` с целевым файлом
target_link_libraries( ${PROJECT_NAME}
    PUBLIC
        external_rust_library
)
# линковать внешнюю динамическую библиотеку `test-lib` с целевым файлом
target_link_libraries(${PROJECT_NAME} PUBLIC test-lib dl pthread)
# -------------------------------------------------------------------------------------------
# запуск сборки из папки с файлом CMakeLists
# $ cmake .

# или запуск сборки из папки build ( .. это путь к CMakeLists)
# $ cd build
# $ cmake ..

# Собрать из получившегося Makefile
# $ make
# $ ./my_project




