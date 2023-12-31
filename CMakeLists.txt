cmake_minimum_required(VERSION 3.10)
project(BallPaddleGame)

# Set the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories for header files
include_directories(${PROJECT_SOURCE_DIR}/libs/include)

# Add the source files
file(GLOB SOURCES ./src/*.cpp)

# Create the executable
add_executable(BallPaddleGame ${SOURCES})

# Find SFML libraries
find_package(SFML 2.5 COMPONENTS graphics window system audio network REQUIRED)

target_link_libraries(BallPaddleGame sfml-system sfml-graphics sfml-window sfml-audio sfml-network)

# Link Box2D library
target_link_libraries(BallPaddleGame ${PROJECT_SOURCE_DIR}/libs/libbox2d.a)

# Add compile options for warnings, etc.
target_compile_options(BallPaddleGame PRIVATE -Wall -Wextra)
