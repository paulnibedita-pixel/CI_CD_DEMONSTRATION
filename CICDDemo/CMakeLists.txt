cmake_minimum_required(VERSION 3.16)
project(CICDDemo LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(cicd_demo main.cpp)

enable_testing()
# Test 1: App Test
add_test(NAME ApplicationTest COMMAND cicd_demo)
# Test 2: Calculator unit test
add_test(
    NAME CalculatorUnitTest
    COMMAND cicd_demo --test
)