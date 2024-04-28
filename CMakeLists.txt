cmake_minimum_required(VERSION 3.27)
set(PROJ_NAME project_euler_solutions)
project(${PROJ_NAME})

set(CMAKE_CXX_STANDARD 20)

list(APPEND ${CMAKE_CXX_FLAGS_DEBUG} "-g -O0")
list(APPEND ${CMAKE_CXX_FLAGS_RELEASE} "-O3 -NDEBUG")
list(APPEND ${CMAKE_CXX_FLAGS} "-Wall -Wextra -Wpedantic")

option(ENABLE_ASAN "Enable Address Sanitizer" OFF)

if(ENABLE_ASAN)
        list(APPEND ${CMAKE_CXX_FLAGS} "-fsanitize=address")
        message("ASan enabled")
endif()

set(SOURCES
        main.cpp

        test/fibonacci_test.cpp
        test/digits_test.cpp
        test/primes_test.cpp
        test/multiples_test.cpp
        test/matrix_test.cpp
        test/read_matrix_test.cpp
        test/divisors_test.cpp
        test/read_vector_of_vectors_test.cpp
        test/factorial_test.cpp
)

set(HEADERS
        all_solutions.h

        utils/arithmetic_sequences.h
        utils/multiples.h
        utils/fibonacci.h
        utils/primes.h
        utils/digits_test.h
        utils/Matrix.h
        utils/read_matrix.h
        utils/divisors.h
        utils/read_vector_of_vectors.h
        utils/factorials.h

        solutions/Problem_1.h
        solutions/Problem_2.h
        solutions/Problem_3.h
        solutions/Problem_4.h
        solutions/Problem_5.h
        solutions/Problem_6.h
        solutions/Problem_7.h
        solutions/Problem_8.h
        solutions/Problem_9.h
        solutions/Problem_10.h
        solutions/Problem_11.h
        solutions/Problem_12.h
        solutions/Problem_13.h
        solutions/Problem_14.h
        solutions/Problem_15.h
        solutions/Problem_16.h
        solutions/Problem_17.h
        solutions/Problem_18.h
        solutions/Problem_19.h
        solutions/Problem_20.h
        solutions/Problem_21.h
)

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






