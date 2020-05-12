#include "point.h"
#include <GL\glut.h>

Point Point::goDown(float step)
{
  Point tmp;
	this->y_ -= step;
	tmp = (*this);
	return tmp;
}

Point Point::goUp(float step)
{
	Point tmp;
	this->y_ += step;
	tmp = (*this);
	return tmp;
}

Point Point::goLeft(float step)
{
	Point tmp;
	this->x_ -= step;
	tmp = (*this);
	return tmp;
}

Point Point::goRight(float step)
{
	Point tmp;
	this->x_ += step;
	tmp = (*this);
	return tmp;
}

void Point::draw(int size)
{
	glPointSize(size);
	glEnable(GL_POINT_SMOOTH);
	glBegin(GL_POINTS);
	glVertex3f(x_, y_, -5);
	glEnd();
}

