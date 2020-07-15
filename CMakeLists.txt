cmake_minimum_required(VERSION 2.8)

PROJECT(LIBRARYMANAGE)

# SET(CMAKE_CXX_FLAGS "-std=c++11")
# SET(CMAKE_CXX_STANDARD 11)
# SET(IPath include)
SET(src src/book.cpp  src/libTime.cpp src/library.cpp src/person.cpp src/trace.cpp)
add_definitions(-std=c++11)
ADD_COMPILE_OPTIONS(-std=c++11)

# include_directories(include)
ADD_LIBRARY(StaLib STATIC ${src})

add_executable(main.exe login/main.cpp)
target_link_libraries(main.exe StaLib)