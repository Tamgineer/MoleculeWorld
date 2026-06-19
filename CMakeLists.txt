cmake_minimum_required(VERSION 3.11)
project(MoleculeWorld VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_POLICY_DEFAULT_CMP0000 NEW) 
set(CMAKE_POLICY_VERSION_MINIMUM 3.5)

# Standard C++ Settings
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# --- 1. Fetch raylib (Automated Dependency) ---
include(FetchContent)
FetchContent_Declare(
  raylib
  URL https://github.com/raysan5/raylib/archive/refs/tags/5.0.tar.gz
)
set(BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(raylib)

# --- 2. Define Project Files ---
# Since everything is in the root, we just list the filenames.
set(SOURCES
    Bond.cpp
    EatingParticle.cpp
    Main.cpp
    Molecule.cpp
    Particle.cpp
)

add_executable(${PROJECT_NAME} ${SOURCES})

# --- 3. Headers & Linking ---
# '.' tells CMake to look for .h files in the same folder as this script
target_include_directories(${PROJECT_NAME} PUBLIC .)

# OS-Agnostic Linking
if(WIN32)
    target_link_libraries(${PROJECT_NAME} PRIVATE raylib winmm gdi32 opengl32)
elseif(UNIX AND NOT APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE raylib m pthread dl rt X11)
elseif(APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE raylib "-framework CoreVideo" "-framework IOKit" "-framework Cocoa" "-framework OpenGL")
endif()