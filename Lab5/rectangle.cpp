#include "rectangle.h"

void Rectangle::draw()
{
	glBegin(GL_LINE_LOOP);
	glVertex2f(x1_, y1_);
	glVertex2f(x1_, y2_);
	glVertex2f(x2_, y2_);
	glVertex2f(x2_, y1_);
	glEnd();
}
