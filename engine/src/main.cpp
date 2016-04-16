#include <iostream>
#include <config.h>
#include <Window.h>
#include <math/Vector.hpp>
#include <rendering/Mesh.h>
#include <rendering/Shader.h>

int main(int argc, char **argv)
{
	GE::Window window(1280, 720, "GE");
	window.Clear(0,0,0,0);
	window.SwapBuffers();
	
	SDL_Event e;
	
	GE::Math::Vector3 verts[3] = {GE::Math::Vector3(-0.5f, -0.5f, 0.5f), GE::Math::Vector3(0.5f, -0.5f, 0.5f), GE::Math::Vector3(0.0f, 0.5f, 0.5f)};
	unsigned int inds[3] = {0,1,2};
	
	GE::Mesh mesh(verts, 3, inds, 3);
	GE::Shader shader("./res/uniformTestShader.vs", "./res/uniformTestShader.fs");
	
	shader.AddUniform("inColor");
	GE::Math::Vector4 color(0.0f, 1.0f, 1.0f, 1.0f);
	
	
	
	while (window.IsOpen())
	{
		window.Clear(0,0,0,0);
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				window.Close();
		}

		shader.UpdateUniform("inColor", color);
		shader.Bind();
		mesh.Draw();

		window.SwapBuffers();
	}

	return 0;
}
