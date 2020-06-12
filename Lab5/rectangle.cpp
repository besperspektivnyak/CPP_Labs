#include "rectangle.h"
#include <GL\glut.h>

void Rectangle::draw()
{
  glColor3f(color_.getR(), color_.getG(), color_.getB());
	glBegin(GL_LINE_LOOP);
	glVertex2f(x1_, y1_);
	glVertex2f(x1_, y2_);
	glVertex2f(x2_, y2_);
	glVertex2f(x2_, y1_);
	glEnd();
}
