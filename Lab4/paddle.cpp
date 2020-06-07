#include <GL/glut.h>
#include "paddle.h"

void Paddle::draw()
{
  glColor3f(1.0f, 0.0f, 1.0f);
  glBegin(GL_POLYGON);
  glVertex2f(getCenter().getX() + width_ / 2, getCenter().getY() + height_ / 2);
  glVertex2f(getCenter().getX() + width_ / 2, getCenter().getY() - height_ / 2);
  glVertex2f(getCenter().getX() - width_ / 2, getCenter().getY() - height_ / 2);
  glVertex2f(getCenter().getX() - width_ / 2, getCenter().getY() + height_ / 2);
  glEnd();
}



