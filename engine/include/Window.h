#ifndef WINDOW_H
#define WINDOW_H

#include <glew.h>
#define SDL_MAIN_HANDLED
#include <SDL.h>

namespace GE
{
	class Window
	{
	public:
		Window(unsigned int width, unsigned int height, char* title);
		~Window();
		
		void Clear(float r, float g, float b, float a);
		
		void SwapBuffers();
		
		void Close() {m_open = false;}
		
		bool IsOpen(){return m_open;}
		unsigned int GetWidth() const {return m_width;}
		unsigned int GetHeight() const {return m_height;}
		char* getTitle() const {return m_title;}
		SDL_Window *GetWindow() const {return m_window;}
		
	private:
		bool m_open;	
		unsigned int m_width;
		unsigned int m_height;
		char* m_title;
		SDL_Window *m_window;
		SDL_GLContext m_context;
	};
}

#endif //WINDOW_H