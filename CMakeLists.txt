cmake_minimum_required(VERSION 3.13 FATAL_ERROR)

set(proj ms_clone)
project(${proj} CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_executable(${proj} 
	src/main.cpp
    src/pch.h
    src/Graphics/d3dx12.h
    src/Utility.h
    src/Utility.cpp
)

get_cmake_property(_varNames VARIABLES)
list (REMOVE_DUPLICATES _varNames)
list (SORT _varNames)
foreach (_varName ${_varNames})
    if (_varName MATCHES "_INIT$")
        message(STATUS "${_varName}=${${_varName}}")
    endif()
endforeach()

include_directories(src/)

add_definitions(-D_CRT_SECURE_NO_WARNINGS)
add_definitions(-D_DEBUG)
add_definitions(-D_UNICODE)
add_definitions(-DDEBUG)

if(NOT CMAKE_C_EXTENSIONS)
    set(CMAKE_C_EXTENSIONS OFF)
endif()

target_compile_definitions(${proj} PRIVATE "UNICODE" "_UNICODE")
target_link_libraries(${proj} PRIVATE "d3d12.lib" "d3dcompiler.lib" "dxgi.lib")