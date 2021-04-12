cmake_minimum_required(VERSION 3.6)
project(blockchain)

set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(googletest URL https://github.com/google/googletest/archive/609281088cfefc76f9d0ce82e1ff6c30cc3591e5.zip)
FetchContent_MakeAvailable(googletest)

find_package(PkgConfig)
pkg_check_modules(Pistache REQUIRED IMPORTED_TARGET libpistache)

add_executable(${PROJECT_NAME} main.cpp API/Service/RouterService.cpp API/Service/RouterService.h API/RESTController/RestController.cpp API/RESTController/RestController.h API/RESTController/StatusController.cpp API/RESTController/StatusController.h Blockchain/Blockchain.cpp Blockchain/Blockchain.h Blockchain/Block.h Blockchain/Transaction.h)
target_link_libraries(${PROJECT_NAME} PkgConfig::Pistache)


# Testing exec
enable_testing()
add_executable(MainTesting Test/HelloTest.cc Test/BlockchainTest.cpp Blockchain/Blockchain.h Blockchain/Blockchain.cpp Blockchain/Block.h Blockchain/Transaction.h)
target_link_libraries(MainTesting gtest_main)
include(GoogleTest)
gtest_discover_tests(MainTesting)
