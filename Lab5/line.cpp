#include "line.h"

void Line::draw()
{
  glColor3f(color_.getR(), color_.getG(), color_.getB());
  glLineWidth(getSize());
  glBegin(GL_LINES);
  glVertex2f(x1_, y1_);
  glVertex2f(x2_, y2_);
  glEnd();
}