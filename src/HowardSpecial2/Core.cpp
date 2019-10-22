#include "Core.h"
#include<exception>

Core::Core()
{
}

std::shared_ptr<GameObject> Core::AddObject(){
	std::shared_ptr<GameObject> gameObject = std::make_shared<GameObject>();
	gameObjects.push_back(gameObject);
	return gameObject;
}

void Core::Start() {
	window_h = 300;
	window_w = 300;
	window = SDL_CreateWindow("Triangle", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, window_w, window_h, SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	if (!SDL_GL_CreateContext(window)) {
		throw std::exception();
	}
	if (glewInit() != GLEW_OK) {
		throw std::exception();
	}

	glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	SDL_GL_SwapWindow(window);
}

void Core::Stop() {
	SDL_DestroyWindow(window);
	SDL_Quit();
}
