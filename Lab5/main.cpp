#include "Menu.h"
#include "ReadMenu.h"
#include "paint.h"
#include <Gl\glut.h>
#include <GL\GLU.h>

Menu menu1;

int windW = 1100;
int windH = 600;

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
  glClearColor(1.0, 1.0, 1.0, 1.0);
	glColor3f(1.0, 0.0, 0.0);
	menu1.print();
	DrawColorPalette();
	DrawSizes();
	glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y)
{
	if (key == 27)
		exit(0);
}

void Timer(int)
{
	renderScene();
	glutTimerFunc(40, Timer, 0);
}

int main(int argc, char** argv)
{
	menu1 = CreateMenu("test.txt");
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(windW, windH);
	glutCreateWindow("Paint");

	glutKeyboardFunc(processNormalKeys);

	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutTimerFunc(40, Timer, 0);

	glutMotionFunc(mouseMove);
	glutMouseFunc(mouseClick);

	glutMainLoop();

	return 1;
}

