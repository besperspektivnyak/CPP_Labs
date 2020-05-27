#include <stdlib.h>
#include <math.h>
#include <Gl\glut.h>
#include <GL\GLU.h>
#include "ReadMenu.h"
#include "Menu.h"

Menu menu1;
std::vector<MenuElem> active;
int index = 0;

void changeSize(int w, int h) 
{
	if (h == 0)
		h = 1;
	float ratio = w * 1.0 / h;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(45.0f, ratio, 0.1f, 100.0f);
	glMatrixMode(GL_MODELVIEW);
}

void renderScene(void) 
{
	for (unsigned i = 0; i < active.size(); i++)
	{
	  if (i == index)
		  glColor3f(1.0, 0.0, 0.0);
		else
			glColor3f(1.0, 0.0, 1.0);
		active[i].print();
	}
	glutSwapBuffers();
}

void processNormalKeys(unsigned char key, int x, int y) 
{
	switch (key)
	{
		case(27):
			exit(0);
		case(13):
			if (active[index].getSubMenu().size() != 0)
			{
				active = active[index].getSubMenu();
				index = 0;
			}
			break;
	}
}

void processSpecialKeys(int key, int x, int y) {
	switch (key) 
	{
	case GLUT_KEY_DOWN:
		if (index + 1 < (int)active.size() )
		{
			index++;
		}
		else
		  index = 0;
		break;
	case GLUT_KEY_UP:
		if (index - 1 >= 0 && index - 1 < (int)active.size())
		{
			index--;
		}
		else
			index = active.size() - 1;
		break;
	}
}


int main(int argc, char** argv) {

	// инициализация GLUT и создание окна
	menu1 = CreateMenu("test.txt");
	glutInit(&argc, argv);
	active = menu1.getElems();
	glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);

	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 480);
	glutCreateWindow("Menu");

	glutKeyboardFunc(processNormalKeys);
	glutSpecialFunc(processSpecialKeys);

	// регистрация
	glutDisplayFunc(renderScene);
	glutReshapeFunc(changeSize);
	glutIdleFunc(renderScene);

	// главный цикл
	glutMainLoop();

	return 1;
}