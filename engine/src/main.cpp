#include <iostream>
#include "config.h"
#include <SDL.h>

int main(int argc, char* argv[])
{
	std::cout << "GE version: " << GE_VERSION_MAJOR << "." << GE_VERSION_MINOR << std::endl;
	std::cout << "Hello world!" << std::endl;

	if (SDL_Init(SDL_INIT_VIDEO) != 0) {
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return 1;
	}
	SDL_Quit();
	return 0;
}