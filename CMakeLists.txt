# CMakeList.txt : CMake project for ConwaysGame, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()


project ("game_of_life")

# Collect all source files in src/
file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS src/*.cpp)

# Create executable
add_executable(game_of_life ${SOURCES} "src/ConsoleRenderer.cpp" "src/ConsoleRenderer.h" "src/Game.cpp" "src/Game.h"    "src/Viewport.h")

# Include src/ for headers like #include "Grid.hpp"
target_include_directories(game_of_life PRIVATE src)

if (CMAKE_VERSION VERSION_GREATER 3.12)
	set_property(TARGET game_of_life PROPERTY CXX_STANDARD 20)
endif()


# TODO: Add tests and install targets if needed.
