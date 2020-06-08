#include <GL/glut.h>
#include "bonus.h"

void Bonus::draw()
{
	switch (type_)
	{
		case(BonusType::NONE):
		  return;
		case(BonusType::SPEED_PLUS):
			glColor3f(0.678f, 0.847f, 0.902f);
			break;
		case(BonusType::SPEED_MINUS):
			glColor3f(0.530f, 0.808f, 0.980f);
			break;
		case(BonusType::PADDLE_PLUS):
			glColor3f(0.553f, 0.714f, 0.804f);
			break;
		case(BonusType::PADDLE_MINUS):
			glColor3f(0.530f, 0.808f, 1);
			break;
		case(BonusType::LIFE):
			glColor3f(0.388f, 0.722f, 1);
			break;
		case(BonusType::EXTRA_POINTS):
			glColor3f(0.0f, 0.773f, 0.804f);
			break;
	}
	glPointSize(radius_);
	glEnable(GL_POINT_SMOOTH);
	glBegin(GL_POINTS);
	glVertex2f(getCenter().getX(), getCenter().getY());
	glEnd();
}