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

  if (trace.getTrace().size() > 12)
  {
    trace.getTrace().pop_back();
  }
  trace.draw();
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
    tmp = trace.goUp();
    break;
  case GLUT_KEY_DOWN:
    tmp = trace.goDown();
    break;
  case GLUT_KEY_LEFT:
    tmp = trace.goLeft();
    break;
  case GLUT_KEY_RIGHT:
    tmp = trace.goRight();
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
