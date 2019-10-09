project(sandbox)
 
add_executable(${PROJECT_NAME} src/Game.cpp src/Sandbox2D.cpp)

target_link_libraries(${PROJECT_NAME} PRIVATE kinemo)
