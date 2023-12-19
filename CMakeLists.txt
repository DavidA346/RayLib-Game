cmake_minimum_required(VERSION 3.10)
project(MyRaylibGame)

# Set C++ standard
set(CMAKE_CXX_STANDARD 11)

# Add the source files
file(GLOB_RECURSE SOURCES src/*.cpp)

# Include directories
include_directories(include)

# Add the executable
add_executable(gameApp ${SOURCES})

# Link against Raylib
target_link_libraries(gameApp ${CMAKE_SOURCE_DIR}/lib/libraylib.a)

# Set framework dependencies for macOS
if(APPLE)
    target_link_libraries(gameApp "-framework CoreVideo -framework IOKit -framework Cocoa -framework GLUT -framework OpenGL")
endif()
