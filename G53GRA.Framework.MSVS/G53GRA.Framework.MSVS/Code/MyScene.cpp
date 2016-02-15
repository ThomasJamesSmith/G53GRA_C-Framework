#include "MyScene.h"

#include "Triangle.h"
#include "Triforce.h"
#include "Planet.h"
#include "Planet2.h"
#include "Lamp.h"
#include "Floor.h"

MyScene::MyScene(int argc, char** argv, const char *title, const int& windowWidth, const int& windowHeight)
	: Scene(argc, argv, title, windowWidth, windowHeight)
{

}

void MyScene::Initialise()
{
	glClearColor(0.f, 0.f, 0.f, 1.f);

	// DEMO 1
	//Triangle *t = new Triangle();
    // AddObjectToScene(t);

	// DEMO 2 (Demos / Triforce)
    //Triforce *t = new Triforce();
    // AddObjectToScene(t);
    
	// DEMO 3 (Demos/Solar System)
    // create and add a new triangle to the scene
    //Planet *sun = new Planet(30.0f, 0.0f, 12.0f, 0.0f);
    //sun->SetColour(255, 255, 0); //yellow
    //
    //Planet *mars = new Planet(6.0f, 60.0f, 150.0f, 50.0f);
    //mars->SetColour(255, 0, 0); //red
    //
    //Planet2 *earth = new Planet2(15.0f, 135.0f, 100.0f, 20.0f, 6.0f, 30.0, 100.0f, 8.0f );
    //earth->SetColour(0, 0, 255); //earth blue, moon grey
    //
    //AddObjectToScene(sun);
    //AddObjectToScene(mars);
    //AddObjectToScene(earth);

	// DEMO 4 (Demos/Animated Lamp)
	// Create and add a new lamp to the scene
	Lamp *l = new Lamp();
	l->size(6.f);
	AddObjectToScene(l);
	
}

void MyScene::Projection()
{
	gluPerspective(60.0, (GLdouble)windowWidth / (GLdouble)windowHeight, 1.0, 1000.0);
}