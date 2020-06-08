#include <GL/glut.h>
#include "brick.h"

void Brick::draw()
{
  switch (strength_)
  {
    case(Strength::WEAK):
      glColor3f(0.90f, 0.4f, 0.70f);
      break;
    case(Strength::MIDDLE):
      glColor3f(0.95f, 0.7f, 0.70f);
      break;
    case(Strength::HARD):
      glColor3f(0.9f, 0.5f, 0.9f);
      break;
  }
  if (del_ == true)
    glColor3f(0.0f, 0.0f, 0.0f);

  glBegin(GL_POLYGON);
  glVertex2f(getCenter().getX() + height_ / 2, getCenter().getY() + width_ / 2);
  glVertex2f(getCenter().getX() + height_ / 2, getCenter().getY() - width_ / 2);
  glVertex2f(getCenter().getX() - height_ / 2, getCenter().getY() - width_ / 2);
  glVertex2f(getCenter().getX() - height_ / 2, getCenter().getY() + width_ / 2);
  glEnd();
  glColor3f(0.0, 0.0, 0.0);
  glBegin(GL_LINES);
  glVertex2f(getCenter().getX() + height_ / 2, getCenter().getY() + width_ / 2);
  glVertex2f(getCenter().getX() + height_ / 2, getCenter().getY() - width_ / 2);
  glVertex2f(getCenter().getX() + height_ / 2, getCenter().getY() - width_ / 2);
  glVertex2f(getCenter().getX() - height_ / 2, getCenter().getY() - width_ / 2);
  glEnd();

}
