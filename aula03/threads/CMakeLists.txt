cmake_minimum_required(VERSION 2.8)

#define nome e versão do projeto
project( threads )

#Adiciona o OPENCV
find_package( OpenCV REQUIRED )

#Para programas em C
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -pthread -std=c11")

#Para programas em CPP
# set(CMAKE_Cxx_STANDARD 99)
# set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -pthread" )

include_directories( threads ${OpenCV_INCLUDE_DIRS} )
include_directories(/usr/include/)
link_directories(/usr/include/)

add_executable( threads threads.c )

target_link_libraries( threads ${OpenCV_LIBS} )
target_link_libraries( threads PUBLIC m)
