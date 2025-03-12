# CMakeList.txt : CMake project for Sygic2, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

# Add source to this project's executable.
add_executable (Sygic "Sygic.cpp" "Sygic.h" "dijkstra.h" "dijkstra.cpp" "test.cpp" "test.h")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET Sygic PROPERTY CXX_STANDARD 20)
endif()

# TODO: Add tests and install targets if needed.
