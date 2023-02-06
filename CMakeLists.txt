cmake_minimum_required(VERSION 3.22)
project(aisdtomczykowskisekulapon8)

set(CMAKE_CXX_STANDARD 14)

include_directories(heapLib)
include_directories(benchmark)
include_directories(heapUnitTest)

add_library(heapLib heapLib/k_heap.h)
set_target_properties(heapLib PROPERTIES LINKER_LANGUAGE CXX)

add_executable(heapApp heapApp/heapApp.cpp)
target_link_libraries(heapApp heapLib)

#testy
include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip
)
if(WIN32)
    # For Windows: Prevent overriding the parent project's compiler/linker settings
    set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
endif(WIN32)
FetchContent_MakeAvailable(googletest)

enable_testing()
add_executable(heapUnitTest heapUnitTest/heapUnitTest.cpp)
target_link_libraries(heapUnitTest PUBLIC gtest_main heapLib)

include(GoogleTest)
gtest_discover_tests(heapUnitTest)




