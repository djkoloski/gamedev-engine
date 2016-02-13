#include <iostream>
#define SDL_MAIN_HANDLED
#include <SDL2/SDL.h>
#include <GL/glew.h>

#define WIDTH 1280
#define HEIGHT 720

int main()
{
    SDL_Window* window = NULL;

    SDL_Init(SDL_INIT_VIDEO);

    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MAJOR_VERSION, 2 );
    SDL_GL_SetAttribute( SDL_GL_CONTEXT_MINOR_VERSION, 1 );

    window = SDL_CreateWindow("TEST", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);

    SDL_GLContext context;
    context = SDL_GL_CreateContext(window);
    SDL_GL_MakeCurrent(window, context);

    //glewExperimental = GL_TRUE;
	glewInit();
	glViewport(0, 0, WIDTH, HEIGHT);

    SDL_Event e;

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

	bool shouldClose = false;
	while (!shouldClose)
    {
        while(SDL_PollEvent(&e))
        {
            if(e.type == SDL_QUIT)
            {
                shouldClose = true;
            }
        }
        glBegin(GL_TRIANGLES);
        glClear(GL_COLOR_BUFFER_BIT);
        glColor3f(1.0f, 1.0f ,1.0f);
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
