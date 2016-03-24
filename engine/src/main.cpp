#include <iostream>
#include <config.h>
#include <Window.h>
#include <math/Vector.hpp>
#include <rendering/Mesh.h>
#include <rendering/Shader.h>

int main(int argc, char **argv)
{
	GE::Window window(1280, 720, "GE");
	SDL_Event e;
	
	Vector3 verts[3] = {Vector3(-0.5f, -0.5f, 0.5f), Vector3(0.5f, -0.5f, 0.5f), Vector3(0.0f, 0.5f, 0.5f)};
	unsigned int inds[3] = {0,1,2};
	
	GE::Mesh mesh(verts, 3, inds, 3);
	GE::Shader shader("./res/testShader.vs", "./res/testShader.fs");

	while (window.IsOpen())
	{
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				window.Close();
		}

		shader.Bind();
		mesh.Draw();

		window.SwapBuffers();
	}

	return 0;
}
