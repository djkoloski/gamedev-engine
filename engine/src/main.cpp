#include <iostream>
#include <config.h>
#include <glew.h>
#define SDL_MAIN_HANDLED
#include <SDL.h>

#include <geassert.h>
#include <math/vec2.h>

using namespace GE::Math;

int main(int argc, char **argv)
{
	std::cout << "GE version: " << GE_VERSION_MAJOR << "." << 
	GE_VERSION_MINOR << std::endl;

	Vec2 v (1.0f, 4.0f);

	std::cout << v.x << ", " << v.y << std::endl;

	SDL_Init(SDL_INIT_VIDEO);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);

	SDL_Window *window = SDL_CreateWindow("GE", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

	SDL_GLContext context;
	context = SDL_GL_CreateContext(window);
	SDL_GL_MakeCurrent(window, context);

	glViewport(0, 0, 1280, 720);

	SDL_Event e;

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	bool shouldClose = false;
	while (!shouldClose)
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				shouldClose = true;
		}

		glBegin(GL_TRIANGLES);
		glClear(GL_COLOR_BUFFER_BIT);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glEnd();

		SDL_GL_SwapWindow(window);
	}

	SDL_GL_DeleteContext(context);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}
