#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <GL/gl.h>

int main() {
	
	std::string title = "Engine - Immediate Mode Triangle";
	int width = 800;
	int height = 600;

	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_Window* window = SDL_CreateWindow(title.c_str(), 
										  SDL_WINDOWPOS_UNDEFINED, 
										  SDL_WINDOWPOS_UNDEFINED, 
										  width, 
										  height, 
										  SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);
	if(window == NULL) {
		std::cerr << "Window could not be created" << std::endl;
	}

 	SDL_GLContext gl_context = SDL_GL_CreateContext(window);
 	if(gl_context == NULL) {
 		std::cerr << "GL Context could not be created" << std::endl;
 	}

	glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();

	glBegin(GL_TRIANGLES);
		glColor4f(1.0f, 0.0f, 0.0f, 1.0f); glVertex2f(-0.5f, -0.5f);
		glColor4f(0.0f, 1.0f, 0.0f, 1.0f); glVertex2f(0.0f, 0.5f); 
		glColor4f(0.0f, 0.0f, 1.0f, 1.0f); glVertex2f(0.5f, -0.5f); 
	glEnd();

	SDL_GL_SwapWindow(window);

	SDL_Delay(2000);

	SDL_GL_DeleteContext(gl_context);
	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
} 