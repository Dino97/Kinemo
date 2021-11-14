project(kinemo)

include(CMakeSources.cmake)

add_subdirectory(dependencies/spdlog)
add_subdirectory(dependencies/stb_image)

add_library(${PROJECT_NAME} STATIC ${KINEMO_SRC})

target_include_directories(${PROJECT_NAME} 
    PUBLIC 
        src
    PRIVATE
        dependencies/glad/include
        dependencies/FreeType/include
)

###################################
# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(dependencies/glfw)
target_include_directories(${PROJECT_NAME} PRIVATE dependencies/glfw/include)
target_link_libraries(${PROJECT_NAME} PRIVATE glfw)
###################################

# TO-DO: why spdlog must be public?
target_link_libraries(${PROJECT_NAME} PUBLIC spdlog)
target_link_libraries(${PROJECT_NAME} PRIVATE stb_image)
