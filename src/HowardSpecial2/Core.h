#include<gl/glew.h>
#include<SDL2/SDL.h>
#include<vector>

#include "GameObject.h"
#include "Camera.h"

struct NonCopyable {
protected:
	NonCopyable() {}
	~NonCopyable() {}
private:
	NonCopyable(const NonCopyable &);
	NonCopyable& operator=(const NonCopyable &);

};

struct Core : private NonCopyable {
	Core();
	SDL_Window *window;
	int window_h;
	int window_w;
	std::shared_ptr<GameObject> mainCamera;
	std::vector<std::shared_ptr<GameObject>> gameObjects;
	std::shared_ptr<GameObject> AddObject();
	void Start();
	void Stop();
	void Update();
	void Display();
	std::shared_ptr<Core> Initialize();
private:
	std::weak_ptr<Core> self;
};