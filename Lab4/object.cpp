#include <math.h>
#include <GL/glut.h>
#include "object.h"

void Point::draw()
{
  glPointSize(30);
  glBegin(GL_POINTS);
  glVertex2f(x_, y_);
  glEnd();
}

Point Point::fabsP()
{
  x_ = fabs(x_);
  y_ = fabs(y_);
  return (*this);
}

void Object::draw()
{
  center_.draw();
}

void Object::move(float shiftX, float shiftY)
{
  Point shift(shiftX, shiftY);
  center_ += shift;
}

void Object::collide()
{
  speed_ = -speed_;
}

