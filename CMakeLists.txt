cmake_minimum_required(VERSION 3.4)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

option(BUILD_COVERAGE "Build coverage" OFF)

set(
  HUNTER_CACHE_SERVERS
  "https://github.com/bmstu-iu8-cpp-sem-3/hunter-cache"
  CACHE STRING "Default cache server"
)

include("cmake/HunterGate.cmake")

HunterGate(
  URL "https://github.com/cpp-pm/hunter/archive/v0.23.218.tar.gz"
  SHA1 "9a3594a61227967fb92159339ba326701b287b19"
)

project(builder)

hunter_add_package(Boost COMPONENTS program_options filesystem system regex)
hunter_add_package(Async++)
#hunter_add_package(BoostProcess)
find_package(Async++ CONFIG REQUIRED)
#find_package(BoostProcess CONFIG REQUIRED)
find_package(Boost CONFIG REQUIRED program_options filesystem system regex)

add_library(builder STATIC
  ${CMAKE_CURRENT_SOURCE_DIR}/sources/builder.cpp
)
add_library(process INTERFACE
)
add_executable(main
  ${CMAKE_CURRENT_SOURCE_DIR}/sources/main.cpp
)

target_include_directories(process
  INTERFACE ${CMAKE_CURRENT_SOURCE_DIR}/process/include
)
target_include_directories(builder
  PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_link_libraries(builder process Async++::Async++
            Boost::program_options Boost::filesystem Boost::system Boost::regex)

target_link_libraries(main builder)
