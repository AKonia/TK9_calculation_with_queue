cmake_minimum_required(VERSION 2.8)
#project(lists_tasks)

include_directories(../include)

file(GLOB sources "*.cpp")
file(GLOB headers "*.h*") 

if(UNIX) 
	add_executable(../bin/stackexe  "${sources}" "${headers}")
else()
	add_executable(stackexe  "${sources}" "${headers}")
endif()
