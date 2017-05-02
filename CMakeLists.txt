project(UnscentedKF)

cmake_minimum_required (VERSION 3.5)

if(MSVC)
else(MSVC)
  add_definitions(-std=c++0x)
endif(MSVC)

set(sources
   src/ukf.cpp
   src/main.cpp
   src/tools.cpp)

set(headers 
   src/ground_truth_package.h  
   src/measurement_package.h  
   src/tools.h  
   src/ukf.h)

add_executable(UnscentedKF ${sources} ${headers})
