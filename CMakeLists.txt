cmake_minimum_required(VERSION 3.6)
project(blockchain)

set(CMAKE_CXX_STANDARD 14)

find_package(PkgConfig)
pkg_search_module(OPENSSL REQUIRED openssl)
if( OPENSSL_FOUND )
    include_directories(${OPENSSL_INCLUDE_DIRS})
    message(STATUS "Using OpenSSL ${OPENSSL_VERSION}")
else()
    # Error; with REQUIRED, pkg_search_module() will throw an error by it's own
endif()

## Google Test
include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip)
FetchContent_MakeAvailable(googletest)



## Pistache

pkg_check_modules(Pistache REQUIRED IMPORTED_TARGET libpistache)

find_package(OpenSSL REQUIRED)

add_executable(${PROJECT_NAME} main.cpp Utils/json.hpp API/Service/RouterService.cpp API/Service/RouterService.h API/RESTController/RestController.cpp API/RESTController/RestController.h API/RESTController/StatusController.cpp API/RESTController/StatusController.h Blockchain/Blockchain.cpp Blockchain/Blockchain.h Blockchain/Block.h Blockchain/Transaction.h)
target_link_libraries(${PROJECT_NAME} PkgConfig::Pistache ${OPENSSL_LIBRARIES})


# Testing exec
enable_testing()
add_executable(MainTesting Utils/json.hpp Test/HelloTest.cc Test/BlockchainTest.cc Blockchain/Blockchain.h Blockchain/Blockchain.cpp Blockchain/Block.h Blockchain/Transaction.h)
target_link_libraries(MainTesting gtest_main ${OPENSSL_LIBRARIES})
include(GoogleTest)
gtest_discover_tests(MainTesting)
