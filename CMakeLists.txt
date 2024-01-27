cmake_minimum_required(VERSION 3.27)
set(PROJ_NAME project_euler_solutions)
project(${PROJ_NAME}})

set(CMAKE_CXX_STANDARD 20)

set(SOURCES
    main.cpp
        )

set(HEADERS
        solutions/Problem_1.h
        utils/arithmetic_sequences.h
        all_solutions.h
        solutions/Problem_2.h
        utils/fibonacci.h
        test/fibonacci_test.cpp)

add_subdirectory(${CMAKE_SOURCE_DIR}/third_party/googletest)

enable_testing()

add_executable(${PROJ_NAME} ${SOURCES} ${HEADERS})

target_include_directories(${PROJ_NAME} PRIVATE
        ${CMAKE_SOURCE_DIR}/solutions
        ${CMAKE_SOURCE_DIR}/utils
        ${CMAKE_SOURCE_DIR}/third_party/googletest/googletest/include)

target_link_libraries(${PROJ_NAME} gtest_main)

include(GoogleTest)
gtest_discover_tests(${PROJ_NAME})
add_test(NAME project_euler_test_all COMMAND ${PROJ_NAME})

target_compile_options(${PROJ_NAME} PRIVATE --coverage)
target_link_options(${PROJ_NAME} PRIVATE --coverage)






