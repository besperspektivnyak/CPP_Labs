#include "line.h"

void Line::draw()
{
  glLineWidth(getSize());
  glBegin(GL_LINES);
  glVertex2f(x1_, y1_);
  glVertex2f(x2_, y2_);
  glEnd();
}