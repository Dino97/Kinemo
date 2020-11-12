cmake_minimum_required(VERSION 3.13)

option(KINEMO_BUILD_EXAMPLES OFF)


add_subdirectory(engine)

if(KINEMO_BUILD_EXAMPLES)
	message("-- Building examples")
	add_subdirectory(sandbox)
endif()
