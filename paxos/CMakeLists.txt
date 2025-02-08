# This must come first
cmake_minimum_required(VERSION 3.15)

# This must come second
project(paxos VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Enable testing at the top level
enable_testing()

# Find GTest package properly for macOS
find_package(GTest REQUIRED)
find_package(Threads REQUIRED)

# Add source files
add_library(paxos
    src/consensus/acceptor.cpp
    src/consensus/proposer.cpp
    src/consensus/learner.cpp
    src/storage/state_manager.cpp
)

target_include_directories(paxos PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/src
)

# Add tests directory
add_subdirectory(tests)