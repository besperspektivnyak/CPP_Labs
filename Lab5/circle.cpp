#include <math.h>
#include <GL/glut.h>
#include "circle.h"

void Circle::draw()
{
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 50; i++)
	{
		float angle = 2.0 * 3.1415926 * float(i) / float(50);
		float dx = radius_ * cosf(angle);
		float dy = radius_ * sinf(angle);
		glVertex2f(x_ + dx, y_ + dy);
	}
	glEnd();

}