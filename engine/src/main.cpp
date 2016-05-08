#include <iostream>
#include <config.h>
#include <Window.h>
#include <math/Vector.hpp>
#include <rendering/Mesh.h>
#include <rendering/Shader.h>
#include <rendering/Texture.h>

int main(int argc, char **argv)
{
	GE::Window window(1280, 720, "GE");
	window.Clear(0,0,0,0);
	window.SwapBuffers();
	
	SDL_Event e;
	
	GE::Math::Vector3 verts[3] = {GE::Math::Vector3(-0.5f, -0.5f, 0.5f), GE::Math::Vector3(0.5f, -0.5f, 0.5f), GE::Math::Vector3(0.0f, 0.5f, 0.5f)};
	GE::Math::Vector2 texCoords[3] = {GE::Math::Vector2(0, 0), GE::Math::Vector2(1, 0), GE::Math::Vector2(0.5f, 1)};
	unsigned int inds[3] = {0,1,2};
	
	GE::Mesh mesh(verts, 3, texCoords, 3, inds, 3);
	GE::Shader shader("./res/texTestShader.vs", "./res/texTestShader.fs");
	
	unsigned char image[1024];
	
	for(int i = 0; i < 16; ++i)
	{
		for(int j = 0; j < 16; ++j)
		{
			int pixel = 4 * (16 * i + j);
			image[pixel] = 255 * ((i/2 + j / 2)%2);
			image[pixel + 1] = 255 * ((i/2 + j / 2)%2);
			image[pixel + 2] = 255 * ((i/2 + j / 2)%2);
			image[pixel + 3] = 255;
		}
	}
	
	GE::Texture texture(image, 16, 16, GL_RGBA, GL_NEAREST);
	
	
	while (window.IsOpen())
	{
		window.Clear(0,0,1,1);
		while (SDL_PollEvent(&e))
		{
			if (e.type == SDL_QUIT)
				window.Close();
		}

		shader.UpdateUniform("texMap", 0);
		shader.Bind();
		mesh.Draw();

		window.SwapBuffers();
	}

	return 0;
}
