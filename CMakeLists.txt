cmake_minimum_required(VERSION 3.10)  # Use a newer CMake version

project(LeaderboardUnitTest)

# Set the output directories for binaries and libraries
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/bin")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY "${PROJECT_BINARY_DIR}/lib")

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)


# Link directories (for libraries)
link_directories(${CMAKE_BINARY_DIR}/lib)

# Add Google Test submodule (if needed)
add_subdirectory(${CMAKE_SOURCE_DIR}/external/googletest)

# Add source and test files
add_executable(leaderboardTest
    src/leaderboard.cpp  # Leaderboard source file
    src/user.cpp  # Leaderboard source file
    test/leaderboardTest.cpp  # Your test file
    src/gameManager.cpp
    src/triviaGame.cpp
)

# Link GoogleTest, GoogleMock
target_link_libraries(leaderboardTest 
    gtest gtest_main 
)

# Enable testing
enable_testing()

# Add test to CTest
add_test(NAME LeaderboardTest COMMAND leaderboardTest)

