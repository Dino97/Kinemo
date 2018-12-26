#pragma once

#include "Core.h"
#include "Window.h"
#include "utils/Timer.h"
#include "entity/Scene.h"

class KINEMO_API Application
{
private:
	Window* m_Window;
	Timer m_Timer;
	unsigned int m_FPS;
	unsigned int m_Width, m_Height;
	//Scene m_CurrentScene;
	
public:
	Application(const char* title, unsigned int width, unsigned int height, bool fullscreen);
	~Application();

	virtual void OnInit();
	virtual void OnUpdate();
	void OnRender();

	inline unsigned int GetFPS() { return m_FPS; }

	void Start();

public:
	//void LoadScene(Scene scene);
	//Scene& GetLoadedScene() { return m_CurrentScene; }
};