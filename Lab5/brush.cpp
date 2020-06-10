#include <iostream>
#include <GL/glut.h>
#include "brush.h"

void Brush::draw(float x, float y)
{
  glPointSize(size_);
  glEnable(GL_POINT_SMOOTH);
  glBegin(GL_POINTS);
  glVertex2f(x, y);
  glEnd();
}
