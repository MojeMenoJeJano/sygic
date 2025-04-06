# CMakeList.txt : Top-level CMake project file, do global configuration
# and include sub-projects here.
#
cmake_minimum_required (VERSION 3.8)

project ("Sygic")

# Include sub-projects.
add_subdirectory ("Sygic")

option(WITH_TESTS "include tests in build" OFF)
if(WITH_TESTS)
	
	set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

	include(FetchContent)

	FetchContent_Declare(
	  googletest
	  URL https://github.com/google/googletest/archive/release-1.12.1.zip
	)

	FetchContent_MakeAvailable(googletest)

	enable_testing()

	add_executable(my_tests tests/test_graph_helpers.cpp tests/test_dijkstra.cpp Sygic/graph_helpers.cpp Sygic/dijkstra.cpp)
	target_link_libraries(my_tests gtest gtest_main)

	add_subdirectory(tests)
endif()