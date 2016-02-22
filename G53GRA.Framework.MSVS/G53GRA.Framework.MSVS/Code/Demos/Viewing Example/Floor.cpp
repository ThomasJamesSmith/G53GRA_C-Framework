#include "Floor.h"


Floor::Floor()
{
}


Floor::~Floor()
{
}

void Floor::Display()
{
	// Draws an exciting chequered floor
	glPushMatrix();
	glPushAttrib(GL_ALL_ATTRIB_BITS);

	glBegin(GL_QUADS);
	for (int i = -10; i < 10; i++)
	{
		for (int j = -10; j < 10; j++)
		{
			if (i % 2)
			{
				if (j % 2)
					glColor3f(0.0f, 0.0f, 0.0f);
				else
					glColor3f(1.0f, 1.0f, 1.0f);
			}
			else
			{
				if (j % 2)
					glColor3f(1.0f, 1.0f, 1.0f);
				else
					glColor3f(0.0f, 0.0f, 0.0f);
			}

			glVertex3f(scale[0] * (float)i + scale[0], -100.0f, scale[2] * (float)j + scale[2]);
			glVertex3f(scale[0] * (float)i + scale[0], -100.0f, scale[2] * (float)j);
			glVertex3f(scale[0] * (float)i, -100.0f, scale[2] * (float)j);
			glVertex3f(scale[0] * (float)i, -100.0f, scale[2] * (float)j + scale[2]);
		}
	}
	glEnd();

	glPopAttrib();
	glPopMatrix();
}