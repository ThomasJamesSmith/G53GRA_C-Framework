#include "Animation.h"
#include "Input.h"
#include "Scene.h"
#include "DisplayableObject.h"

Texture Scene::texture = Texture();
Camera Scene::camera = Camera();

Scene::Scene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Engine(argc, argv, title, windowWidth, windowHeight)
{
	camera.Reset();
}


Scene::~Scene()
{
	for(DisplayableObject* obj : objects)
	{
		if(obj != NULL)
			delete obj;
		obj = NULL;
	}
}

int Scene::GetWindowWidth()
{
	return Engine::windowWidth;
}

int Scene::GetWindowHeight()
{
	return Engine::windowHeight;
}

int Scene::GetTexture(std::string filename)
{
	return texture.GetTexture(filename);
}

void Scene::Initialise()
{

}

void Scene::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	Reshape(windowWidth, windowHeight);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	camera.SetupCamera();
	for (DisplayableObject* obj : objects)
		obj->Display();

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	CheckGLError();
}

void Scene::Reshape(int w, int h)
{
	windowWidth = w;
	windowHeight = h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	Projection();
	glMatrixMode(GL_MODELVIEW);

	camera.SetViewport();
}

void Scene::Projection(){
	glOrtho(-windowWidth / 2, windowWidth / 2, -windowHeight / 2, windowHeight / 2, 1.0, 1000.0);
}

void Scene::Update(const double& deltaTime)
{
	Animation* animated_obj;
	camera.Update(deltaTime);
	for (DisplayableObject* obj : objects)
	{
		animated_obj = dynamic_cast<Animation*>(obj);
		if (animated_obj != NULL)
			animated_obj->Update(deltaTime);
	}
}

void Scene::AddObjectToScene(DisplayableObject* obj){
	objects.push_back(obj);
}

void Scene::HandleKey(unsigned char key, int state, int x, int y)
{
	Input* input_obj;
	camera.HandleKey(key, state, x, y);
	for(DisplayableObject* obj : objects)
	{
		input_obj = dynamic_cast<Input*>(obj);
		if(input_obj != NULL)
			input_obj -> HandleKey(key, state, x, y);
	}
}

void Scene::HandleSpecialKey(int key, int state, int x, int y)
{
	Input* input_obj;
	camera.HandleSpecialKey(key, state, x, y);
	for (DisplayableObject* obj : objects)
	{
		input_obj = dynamic_cast<Input*>(obj);
		if (input_obj != NULL)
			input_obj->HandleSpecialKey(key, state, x, y);
	}
}

void Scene::HandleMouse(int button, int state, int x, int y)
{
	Input* input_obj;
	camera.HandleMouse(button, state, x, y);
	for (DisplayableObject* obj : objects)
	{
		input_obj = dynamic_cast<Input*>(obj);
		if (input_obj != NULL)
			input_obj->HandleMouse(button, state, x, y);
	}
}

void Scene::HandleMouseDrag(int x, int y)
{
	Input* input_obj;
	camera.HandleMouseDrag(x, y);
	for (DisplayableObject* obj : objects)
	{
		input_obj = dynamic_cast<Input*>(obj);
		if (input_obj != NULL)
			input_obj->HandleMouseDrag(x, y);
	}
}

void Scene::HandleMouseMove(int x, int y)
{
	Input* input_obj;
	camera.HandleMouseMove(x, y);
	for (DisplayableObject* obj : objects)
	{
		input_obj = dynamic_cast<Input*>(obj);
		if (input_obj != NULL)
			input_obj->HandleMouseMove(x, y);
	}
}