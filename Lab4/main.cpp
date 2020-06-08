#include <stdlib.h>
#include <math.h>
#include <Gl\glut.h>
#include <GL\GLU.h>
#include "level.h"
#include "object.h"

int windW = 640;
int windH = 480;
int Score = 1000;
Level level("test.txt");

void changeSize(int w, int h)
{
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, w, 0, h);
	glViewport(0, 0, w, h);
	glMatrixMode(GL_MODELVIEW);
	windW = w;
	windH = h;
}

void renderScene(void)
{
  level.start();
	level.initPaddle();
	level.initBall();
	glutSwapBuffers();
}

void renderScene2(void)
{
	level.start();
	level.initBonus();
	level.initPaddle();
	level.initBall();
	level.moveBall();
	level.collideBallBrick();
	level.collideBallPaddle();
	level.collideBonusPaddle();
	glutSwapBuffers();
}
void processNormalKeys(unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
}

void processSpecialKeys(int key, int x, int y) 
{
	switch (key) 
	{
	case GLUT_KEY_LEFT:
	  level.changePaddlePos(false);
		glClear(GL_COLOR_BUFFER_BIT);
	  break;
	case GLUT_KEY_RIGHT:
		glClear(GL_COLOR_BUFFER_BIT);
	  level.changePaddlePos(true);
    break;
	}
}

void Timer(int)
{
	glClear(GL_COLOR_BUFFER_BIT);
	renderScene2();
	glutTimerFunc(40, Timer, 0);
}

int main(int argc, char** argv) 
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Arkanoid");

	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);

	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutTimerFunc(40, Timer, 0);

	glutMainLoop();

	return 1;
}