project(kinemo)

include(CMakeSources.cmake)

set(BOX2D_BUILD_UNIT_TESTS OFF CACHE BOOL "" FORCE)
set(BOX2D_BUILD_TESTBED OFF CACHE BOOL "" FORCE)
set(BOX2D_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(BOX2D_USER_SETTINGS OFF CACHE BOOL "" FORCE)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(dependencies/box2d)
add_subdirectory(dependencies/glfw)
add_subdirectory(dependencies/spdlog)
add_subdirectory(dependencies/stb_image)

add_library(${PROJECT_NAME} STATIC ${KINEMO_SRC})

target_include_directories(${PROJECT_NAME}
    PUBLIC
        src
        dependencies/box2d/include
    PRIVATE
        dependencies/freetype/include
        dependencies/glad/include
)

# TO-DO: why spdlog must be public?
target_link_libraries(${PROJECT_NAME}
    PUBLIC
        spdlog
        box2d
    PRIVATE
        glfw
        stb_image
        ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/freetype/libfreetype.so
)
