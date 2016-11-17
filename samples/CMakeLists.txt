cmake_minimum_required(VERSION 2.8)

include_directories(../include)

file(GLOB sources "*.cpp")
file(GLOB headers "*.h*") 

if(UNIX) 
	add_executable(../bin/sampleapp  "${sources}" "${headers}")
else()
	add_executable(sampleapp  "${sources}" "${headers}")
endif()
