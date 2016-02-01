#pragma once

#ifdef _WIN32
	#include <GL/glut.h>
	#include <Windows.h>
#else
	#include <GLUT/glut.h>
#endif

#include "Input.h"

class Camera : public Input
{
public:
	Camera();
	~Camera();

	// These functions can be called to get the position/view direction/camera axis of the camera in world space
	void GetEyePosition(float &x, float &y, float &z) const;
	void GetViewDirection(float &x, float &y, float &z) const;
	void GetForwardVector(float &x, float &y, float &z) const;
	void GetRightVector(float &x, float &y, float &z) const;
	void GetUpVector(float &x, float &y, float &z) const;

	void Update(const double& deltaTime);
	void Reset();

	void SetViewport();

	void HandleKey(unsigned char key, int state, int x, int y);
	void HandleSpecialKey(int key, int state, int x, int y);
	void HandleMouse(int button, int state, int x, int y);
	void HandleMouseDrag(int x, int y);
	void HandleMouseMove(int x, int y);

	void SetupCamera();

private:
	// Member variable to keep track of the position of the camera in world space
	float eyePosition[3];

	// Member variable to keep track of the viewDirection, forward, up and right vectors of the camera
	float vd[3];
	float forward[3];
	float right[3];
	float up[3];

	// Member variable used to track when a key is pressed between frames
	// so that we can do an update in the Update() function rather than HandleKey function to obtain smooth motion
	int wKey, sKey, aKey, dKey;

	int windowWidth, windowHeight;

	// Memeber variable to remember mouse details
	int currentButton;
	GLint mouseX, mouseY;
};