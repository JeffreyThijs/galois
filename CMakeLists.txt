cmake_minimum_required(VERSION 3.10)
set (CMAKE_CXX_STANDARD 17)
project(rs_coding)

set (CMAKE_CXX_FLAGS "-Wall -pedantic -ansi")

find_package( Boost REQUIRED COMPONENTS unit_test_framework)
include_directories(${Boost_INCLUDE_DIRS}
                    src/
                    galois/)

file(GLOB SOURCES 
     "src/*.cpp")
 
# tests
file(GLOB TEST_SOURCES
    "tests/*.cpp"
)

add_executable (run_tests ${TEST_SOURCES} ${SOURCES})
target_link_libraries (run_tests ${Boost_LIBRARIES})