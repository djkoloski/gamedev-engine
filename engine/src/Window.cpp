#include <Window.h>
#include <config.h>
#include <iostream>
namespace GE
{
	Window::Window(unsigned int width, unsigned int height, char* title)
	{
		m_width = width;
		m_height = height;
		m_title = title;
		std::cout << "GE version: " << GE_VERSION_MAJOR << "." << GE_VERSION_MINOR << std::endl;
		std::cout << "Compiled: " << __DATE__ << " at " << __TIME__ << std::endl;
		
		SDL_Init(SDL_INIT_VIDEO);

		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
		SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 3);

		m_window = SDL_CreateWindow(title , SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

		m_context = SDL_GL_CreateContext(m_window);
		SDL_GL_MakeCurrent(m_window, m_context);

		glViewport(0, 0, width, height);
	}

	Window::~Window()
	{
		SDL_GL_DeleteContext(m_context);
		SDL_DestroyWindow(m_window);
		SDL_Quit();
	}

	void Window::Clear(float r, float g, float b, float a)
	{
		glClearColor(r, g, b, a);
		glClear(GL_COLOR_BUFFER_BIT);
	}

	void Window::SwapBuffers()
	{
		SDL_GL_SwapWindow(m_window);
	}
}