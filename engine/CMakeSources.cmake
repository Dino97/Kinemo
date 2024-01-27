set(KINEMO_APP_SRC
    "src/app/Application.cpp"
    "src/app/Window.cpp"
    "src/app/Input.cpp"
)

set(KINEMO_CORE_SRC
    "src/core/Camera.cpp"
    "src/core/OrthographicCameraController.cpp"
)

set(KINEMO_GRAPHICS_SRC
    "src/graphics/Color.cpp"
    "src/graphics/Framebuffer.cpp"
    "src/graphics/Renderer2D.cpp"
    "src/graphics/Shader.cpp"
    "src/graphics/Sprite.cpp"
    "src/graphics/Texture2D.cpp"
    "src/graphics/layers/Layer.cpp"
    "src/graphics/layers/Layer2D.cpp"
    "src/graphics/layers/LayerStack.cpp"
    "src/graphics/TextRenderer.cpp"
    "src/graphics/Font.cpp"
)

set(KINEMO_LUA_SRC
    "src/lua/Lua.cpp"
    "src/lua/LuaInput.cpp"
    "src/lua/LuaPhysics.cpp"
    "src/lua/LuaRenderer2D.cpp"
    "src/lua/LuaTexture2D.cpp"
)

set(KINEMO_MATH_SRC
    "src/math/Mat2.cpp"
    "src/math/Mat4.cpp"
    "src/math/Vec2.cpp"
    "src/math/Vec3.cpp"
)

set(KINEMO_PHYSICS_SRC
    "src/physics/BoundingBox.cpp"
    "src/physics/Physics.cpp"
)

set(KINEMO_SYSTEM_SRC
    "src/system/VirtualFileSystem.cpp"
)

set(KINEMO_UTILITIES_SRC
    "src/utils/Log.cpp"
    "src/utils/Timer.cpp"
)

set(KINEMO_DEPENDENCIES_SRC
    "dependencies/glad/src/glad.c"
)

set(KINEMO_SRC
    ${KINEMO_APP_SRC}
    ${KINEMO_CORE_SRC}
    ${KINEMO_GRAPHICS_SRC}
    ${KINEMO_LUA_SRC}
    ${KINEMO_MATH_SRC}
    ${KINEMO_PHYSICS_SRC}
    ${KINEMO_SYSTEM_SRC}
    ${KINEMO_UTILITIES_SRC}
    ${KINEMO_DEPENDENCIES_SRC}
)
