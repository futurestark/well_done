cmake_minimum_required(VERSION 3.8)

# nice help to understand structure of module names in cmake build
# https://stackoverflow.com/questions/27853188/build-errors-while-following-the-instructions-given-on-a-website

set(This ExampleTests)

set(Sources 
    ExampleTests.cpp
)

add_executable(${This} ${Sources})

#things that we are depend on 
#gtest_main provided by google test
#and we need thing to testing its our Example

target_link_libraries(${This} PUBLIC
    gtest_main
    firstHomeAdvanced
)

#write unit tests name and command to run them
add_test(
    NAME ${This}
    COMMAND ${This}
)

#target_link_libraries(ExampleTests pthread)
#target_link_libraries(ExampleTests gmock)
#target_link_libraries(ExampleTests gtest)

#after all describes and creating tree, need go to View-> Command Pallete and write >reload
#to update project structure