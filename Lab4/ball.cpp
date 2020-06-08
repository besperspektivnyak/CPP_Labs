#include <GL/glut.h>
#include "ball.h"


void Ball::draw()
{
  glColor3f(0.5f, 0.5f, 0.5f);
	glPointSize(radius_);
	glEnable(GL_POINT_SMOOTH);
	glBegin(GL_POINTS);
	glVertex2f(getCenter().getX(), getCenter().getY());
	glEnd();
}

void Ball::collide(TypeCollision flag)
{
  if (flag == TypeCollision::X)
	  speedX_ = -speedX_;
	else if (flag == TypeCollision::Y)
	  speedY_ = -speedY_;
	else if (flag == TypeCollision::XY)
	{
		speedX_ = -speedX_;
		speedY_ = -speedY_;
	}
}

