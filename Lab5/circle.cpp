#include <math.h>
#include <GL/glut.h>
#include "circle.h"

void Circle::draw()
{
	glColor3f(color_.getR(), color_.getG(), color_.getB());
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < 50; i++)
	{
		float angle = 2.0 * 3.1415926 * float(i) / float(50);
		float dx = radius_ * cosf(angle);
		float dy = radius_ * sinf(angle);
		glVertex2f(x1_ + dx, y1_ + dy);
	}
	glEnd();

}