cmake_minimum_required(VERSION 3.13)

option(KINEMO_BUILD_EXAMPLES "Build Kinemo examples" FALSE)

add_subdirectory(engine)

if(KINEMO_BUILD_EXAMPLES)
	message("-- Generating Kinemo examples")
	add_subdirectory(examples)
endif()
