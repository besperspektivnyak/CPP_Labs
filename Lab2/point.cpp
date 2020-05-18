#include "point.h"
#include <GL\glut.h>

void Point::goDown(float step, Point *p)
{
	this->y_ -= step;
	*p = (*this);
}

void Point::goUp(float step, Point *p)
{
	this->y_ += step;
	*p = (*this);
}

void Point::goLeft(float step, Point *p)
{
	this->x_ -= step;
	*p = (*this);
}

void Point::goRight(float step, Point *p)
{
	this->x_ += step;
	*p = (*this);
}

void Point::draw(int size)
{
	glPointSize(size);
	glEnable(GL_POINT_SMOOTH);
	glBegin(GL_POINTS);
	glVertex3f(x_, y_, -5);
	glEnd();
}

