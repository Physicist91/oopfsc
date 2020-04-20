cmake_minimum_required(VERSION 3.10)
project(TestQuadratureRule)

set(SOURCES
        ../../sheet07/exercise1/trapezoidal_rule.cc 
        ../../sheet07/exercise1/simpson_rule.cc 
        ../../sheet07/exercise1/composite_quadrature_rule.cc 
        ../../sheet07/exercise1/polynomial.cc
        ../../sheet07/exercise1/composite_sine.cc
        ../../sheet07/exercise2/adaptative_composite_quadrature_rule.cc
        static/polynomial.cc
        static/composite_sine.cc
        test_static_static.cc
        test_static_dynamic.cc
        test_dynamic_dynamic.cc
        main.cc)

set(CMAKE_CXX_STANDARD 17)
SET(CMAKE_C_COMPILER c++)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")
add_executable(TestQuadratures_GNU_g ${SOURCES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O0")
add_executable(TestQuadratures_GNU_O0 ${SOURCES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O1")
add_executable(TestQuadratures_GNU_O1 ${SOURCES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2")
add_executable(TestQuadratures_GNU_O2 ${SOURCES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O3")
add_executable(TestQuadratures_GNU_O3 ${SOURCES})

SET(CMAKE_C_COMPILER clang++)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g")
add_executable(TestQuadratures_CLANG_g ${SOURCES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O0")
add_executable(TestQuadratures_CLANG_O0 ${SOURCES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O1")
add_executable(TestQuadratures_CLANG_O1 ${SOURCES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2")
add_executable(TestQuadratures_CLANG_O2 ${SOURCES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O3")
add_executable(TestQuadratures_CLANG_O3 ${SOURCES})

SET(CMAKE_C_COMPILER c++-7)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -march=native")
add_executable(TestQuadratures_GNU_g_native ${SOURCES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O0 -march=native")
add_executable(TestQuadratures_GNU_O0_native ${SOURCES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O1 -march=native")
add_executable(TestQuadratures_GNU_O1_native ${SOURCES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2 -march=native")
add_executable(TestQuadratures_GNU_O2_native ${SOURCES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O3 -march=native")
add_executable(TestQuadratures_GNU_O3_native ${SOURCES})

SET(CMAKE_C_COMPILER clang++)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -g -march=native")
add_executable(TestQuadratures_CLANG_g_native ${SOURCES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O0 -march=native")
add_executable(TestQuadratures_CLANG_O0_native ${SOURCES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O1 -march=native")
add_executable(TestQuadratures_CLANG_O1_native ${SOURCES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O2 -march=native")
add_executable(TestQuadratures_CLANG_O2_native ${SOURCES})

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -O3 -march=native")
add_executable(TestQuadratures_CLANG_O3_native ${SOURCES})


file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/run.sh
     DESTINATION ${CMAKE_CURRENT_BINARY_DIR})

execute_process(
       COMMAND chmod 777 ${CMAKE_CURRENT_BINARY_DIR}/run.sh
       )