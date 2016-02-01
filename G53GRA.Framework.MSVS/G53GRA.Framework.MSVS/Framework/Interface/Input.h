#pragma once

class Input
{
public:
	Input(void){}
	virtual ~Input(void){}

	virtual void HandleKey(unsigned char key, int state, int x, int y) = 0;
	virtual void HandleSpecialKey(int key, int state, int x, int y)    = 0;
	virtual void HandleMouse(int button, int state, int x, int y)      = 0;
	virtual void HandleMouseDrag(int x, int y)						   = 0;
	virtual void HandleMouseMove(int x, int y)						   = 0;

/*
	void HandleKey(unsigned char key, int state, int x, int y);
	void HandleSpecialKey(int key, int state, int x, int y);
	void HandleMouse(int button, int state, int x, int y);
	void HandleMouseDrag(int x, int y);
	void HandleMouseMove(int x, int y);
*/
};