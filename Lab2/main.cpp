#include <stdlib.h>
#include <GL\glut.h>
#include <math.h>
#include "point.h"
#include "trace.h"

Trace trace;
Point tmp;

void changeSize(int w, int h) 
{
  if (h == 0)
    h = 1;
  float ratio = 1.0 * w / h;

  glMatrixMode(GL_PROJECTION);

  glLoadIdentity();

  glViewport(0, 0, w, h);

  gluPerspective(45.0f, ratio, 0.1f, 100.0f);

  glMatrixMode(GL_MODELVIEW);
}

void renderScene(void)
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  Point cur;

  unsigned i = 0;

  if (trace.getTrace().size() > 12)
  {
    trace.getTrace().pop_back();
  }

  while (i < trace.getTrace().size())
  {
    cur = trace.getTrace().front();
    glColor3f(0.5, 0, 0.5);
    cur.draw(5 + 2* i);
    if (i == 0)
    {
      glColor3f(1, 1, 1);
      cur.draw(15);
    }
    trace.getTrace().pop_front();
    trace.getTrace().push_back(cur);
    i++;
  }
  glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y) {

  if (key == 27)
    exit(0);
}

void processSpecialKeys(int key, int x, int y) 
{
  switch (key) 
  {
  case GLUT_KEY_UP:
    tmp = trace.getTrace().front().goUp(trace.getSpeed());
    break;
  case GLUT_KEY_DOWN:
    tmp = trace.getTrace().front().goDown(trace.getSpeed());
    break;
  case GLUT_KEY_LEFT:
    tmp = trace.getTrace().front().goLeft(trace.getSpeed());
    break;
  case GLUT_KEY_RIGHT:
    tmp = trace.getTrace().front().goRight(trace.getSpeed());
    break;
  }
}

void Timer(int)
{
  int i = 0;
  renderScene();
  trace.getTrace().push_front(tmp);
  glutTimerFunc(40, Timer, 0);
}

int main(int argc, char** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
  glutInitWindowPosition(100, 100);
  glutInitWindowSize(640, 480);
  glutCreateWindow("Point");


  glutDisplayFunc(renderScene);
  glutReshapeFunc(changeSize);
  glutTimerFunc(40, Timer, 0);

  glutKeyboardFunc(processNormalKeys);
  glutSpecialFunc(processSpecialKeys);

  glutMainLoop();

  return 1;
}
