set(KINEMO_APP_SRC
    "src/app/Application.cpp"
)

set(KINEMO_GRAPHICS_SRC
    "src/graphics/Grid.cpp"
    "src/graphics/Shader.cpp"
    "src/graphics/Sprite.cpp"
    "src/graphics/Texture2D.cpp"
    "src/graphics/Renderer2D.cpp"
    
    "src/graphics/gui/Texture.cpp"
    
    "src/graphics/layers/Layer.cpp"
    "src/graphics/layers/Layer2D.cpp"
    "src/graphics/layers/LayerStack.cpp"
)

set(KINEMO_MATH_SRC
    "src/math/Mat2.cpp"
    "src/math/Mat4.cpp"
    "src/math/Vec2.cpp"
    "src/math/Vec3.cpp"
)

set(KINEMO_OPENGL_SRC
    "src/platform/windows/WindowsInput.cpp"
    "src/platform/windows/WindowsWindow.cpp"
)

set(KINEMO_SYSTEM_SRC
    "src/system/VirtualFileSystem.cpp"
)

set(KINEMO_UTILITIES_SRC
    "src/utils/Log.cpp"
    "src/utils/stb_image.cpp"
    "src/utils/Timer.cpp"
)

set(KINEMO_NOFILTER_SRC
    "src/Camera.cpp"
    "src/OrthographicCameraController.cpp"
)

set(KINEMO_DEPENDENCIES_SRC
    "dependencies/glad/src/glad.c"
)

set(KINEMO_SRC
    ${KINEMO_APP_SRC}
    ${KINEMO_GRAPHICS_SRC}
    ${KINEMO_MATH_SRC}
    ${KINEMO_OPENGL_SRC}
    ${KINEMO_SYSTEM_SRC}
    ${KINEMO_UTILITIES_SRC}
    ${KINEMO_NOFILTER_SRC}
    ${KINEMO_DEPENDENCIES_SRC}
)
