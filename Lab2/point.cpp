#include "point.h"
#include <GL\glut.h>


double Point::getX()
{
	return x_;
}

double Point::getY()
{
	return y_;
}

double Point::getR()
{
	return r_;
}

Point Point::goDown(float step)
{
	this->y_ -= step;
	return *this;
}

Point Point::goUp(float step)
{
	this->y_ += step;
	return *this;
}

Point Point::goLeft(float step)
{
	this->x_ -= step;
	return *this;
}

Point Point::goRight(float step)
{
	this->x_ += step;
	return *this;
}

void Point::draw(int size)
{
	glPointSize(size);
	glEnable(GL_POINT_SMOOTH);
	glBegin(GL_POINTS);
	glVertex3f(x_, y_, -5);
	glEnd();
}

