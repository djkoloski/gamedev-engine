#include <iostream>
#include <config.h>
#include <Window.h>

int main(int argc, char **argv)
{
	GE::Window window(1280, 720, "GE");
	
	SDL_Event e;

	while (window.IsOpen())
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				window.Close();
		}

		glBegin(GL_TRIANGLES);
		window.Clear(0, 0, 0, 1);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(0.5f, -0.5f);
		glVertex2f(0.0f, 0.5f);
		glEnd();

		window.SwapBuffers();
	}

	return 0;
}
