#include "shape.h"
#include <GL/glut.h>

void Shape::draw()
{
  glColor3f(color_.getR(), color_.getR(), color_.getR());
  glPointSize(size_);
  glEnable(GL_POINT_SMOOTH);
  glBegin(GL_POINTS);
  glVertex2f(x1_, y1_);
  glEnd();
}
