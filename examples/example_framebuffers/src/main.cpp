#include "Kinemo.h"

using namespace Kinemo;

constexpr unsigned int SCREEN_WIDTH = 1280;
constexpr unsigned int SCREEN_HEIGHT = 720;

class Game : public Application
{
public:
    Game() : Application("Example - Framebuffers", SCREEN_WIDTH, SCREEN_HEIGHT, false)
    {
        // init shader used for rendering framebuffer
        screenShader = std::make_unique<Shader>("PostProcess_Base.vert", "PostProcess_Negative.frag");
        screenShader->Bind();
        screenShader->SetUniform("screenTexture", 1);   // 0 is reserved for renderer2d

        // init framebuffer
        fb = std::make_unique<Framebuffer>(SCREEN_WIDTH, SCREEN_HEIGHT);
        fb->Bind();
        fb->CreateColorBuffer();
        fb->SetClearColor({0.1f, 0.1f, 0.1f, 1});
        fb->Unbind();
    }

    virtual void OnUpdate(float dt) override
    {
        fb->Bind();
        fb->Clear();
        Renderer2D::Begin();
        Renderer2D::DrawQuad({-0.5f, -0.5f, 0.0f}, {1, 1}, {0,1,1,1});
        Renderer2D::End();
        Renderer2D::Flush();
        fb->Unbind();

        // render screen to quad
        screenShader->Bind();
        Renderer2D::Begin();
        Renderer2D::DrawQuad({-1, -1, 0}, {2, 2}, *fb->GetColorBuffer());
        Renderer2D::End();
        Renderer2D::Flush();
        screenShader->Unbind();
    }

private:
    std::unique_ptr<Framebuffer> fb;
    std::unique_ptr<Shader> screenShader;
};

int main()
{
    Game game;
    game.GetWindow().SetVSync(true);
    game.Start();

    return 0;
}