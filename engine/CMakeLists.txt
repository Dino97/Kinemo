project(kinemo)

include(CMakeSources.cmake)

set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)

add_subdirectory(dependencies/glfw)
add_subdirectory(dependencies/spdlog)
add_subdirectory(dependencies/stb_image)

add_library(${PROJECT_NAME} STATIC ${KINEMO_SRC})

target_include_directories(${PROJECT_NAME}
    PUBLIC
        src
    PRIVATE
        src/app
        src/core
        src/events
        src/graphics
        src/lua
        src/math
        src/physics
        src/system
        src/utils
    PRIVATE
        dependencies/freetype/include
        dependencies/glad/include
        dependencies/FreeType/include
        dependencies/lua/include
)

# TO-DO: why spdlog must be public?
target_link_libraries(${PROJECT_NAME}
    PUBLIC
        spdlog
        box2d
    PRIVATE
        glfw
        stb_image
        ${PROJECT_SOURCE_DIR}/dependencies/lua/liblua54.a
        ${CMAKE_CURRENT_SOURCE_DIR}/dependencies/freetype/libfreetype.so
)
