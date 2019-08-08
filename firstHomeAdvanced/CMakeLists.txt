cmake_minimum_required(VERSION 3.8)

set(This firstHomeAdvanced)  #name of main folder if another name will be error, I rename main folder to Example and do reconfigure->clean and 
                   #rebuild all Right

project(${This} C CXX)

set(CMAKE_C_STANDARD 99)
set(CMAKE_CXX_STANDARD 11)
#independent code is nice thing to have libraries mix together and link together executables
set(CMAKE_POSITION_INDEPENDENT_CODE ON)

#flag to make unit tests
enable_testing()

#add dependencies
add_subdirectory(googletest)

#describing how we will build our code we define two variables Headers and Sources
set(Headers
    firstHomeAdvanced.hpp
)
set(Sources
    firstHomeAdvanced.cpp
)

#we will split our code in two pieces - code and tests along the code
#code must be tested ago this library, we can use Static or Shared

add_library(${This} STATIC ${Sources} ${Headers})

#we will put our tests to subdirectory called test
#and will call CMakeLists from child dir (test)

add_subdirectory(test)


