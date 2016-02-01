#include "MyScene.h"

int main(int argc, char* argv[])
{
	MyScene *scene = NULL;

	scene = new MyScene(argc, argv, "G53GRA", (const int)600, (const int)400);

	scene->Run();

	delete scene;
	return 0;
}