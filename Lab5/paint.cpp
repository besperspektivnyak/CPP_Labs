#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <math.h>
#include "paint.h"
#include "pen.h"
#include "eraser.h"
#include "line.h"
#include "circle.h"
#include "rectangle.h"
#include <Gl\glut.h>
#include <GL\GLU.h>


extern Color white;
Color black(0.0f, 0.0f, 0.0f);
Color red(1.0f, 0.0f, 0.0f);
Color green(0.0f, 1.0f, 0.0f);
Color blue(0.0f, 0.0f, 1.0f);
Color yellow(0.0f, 1.0f, 1.0f);
Color purple(1.0f, 0.0f, 1.0f);
Color lightBlue(0.0f, 1.0f, 1.0f);

bool mouseClicked = 0;
bool statement = false;
Color actualColor = black;
float actualSize = 10;

Mode mode;

float windh = 600, windw = 1100;
float X1, Y1, X2, Y2;

void mouseClick(int button, int state, int x, int y)
{
	if (600 - y > 560)
	{
		if (button == GLUT_LEFT_BUTTON && state == GLUT_UP )
		{
			ChooseMode(x);
		}
	}
	else if(600 - y < 560 && 600 - y > 430)
	  mode = Mode::COLOR;
	else if( 600 - y < 400 && 600 - y > 300)
	  mode = Mode::SIZE;
	else
	{ 
	  glColor3f(0, 0, 0);
	  Paint(button, state, x, y);
	}
}

void ChooseMode(int x)
{
	if (x > 55 && x < 115)
	  mode = Mode::NEW;
	else if (x > 130 && x < 200)
		mode = Mode::OPEN;
	else if (x > 220 && x < 290)
		mode = Mode::SAVE;
	else if (x > 315 && x < 385)
		mode = Mode::PEN;
	else if (x > 425 && x < 510)
		mode = Mode::ERASER;
	else if (x > 530 && x < 590)
		mode = Mode::LINE;
	else if (x > 620 && x < 705)
		mode = Mode::CIRCLE;
	else if (x > 730 && x < 830)
		mode = Mode::RECTANGLE;
	else if (x > 835 && x < 885)
		mode = Mode::SIZE;
	else if (x > 925 && x < 1010)
		mode = Mode::COLOR;
}

void Paint(int button, int state, int x, int y)
{ 
	switch (mode)
	{
		case Mode::NEW:
			if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
				glClear(GL_COLOR_BUFFER_BIT);
		  break;
		case Mode::OPEN:
			if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
			  Open();
		  break;
		case Mode::SAVE:
			if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
			  Save();
			break;
		case Mode::SIZE:
			if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
				ChooseSize(y);
			break;
		case Mode::COLOR:
			if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
				ChooseColor(y, x);
			break;
	}
	  if (mode == Mode::LINE || mode == Mode::CIRCLE || mode == Mode::RECTANGLE)
		{

			if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && statement == false)
			{
				mouseClicked = true;
				statement = true;
				X1 = x;
				Y1 = (float)y;
			}
			else if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN && statement == true)
			{
				mouseClicked = true;
				statement = false;
				X2 = x;
				Y2 = y;
			}
		  if (mode == Mode::LINE)
			{
				Line line(X1, windh - Y1, X2, windh - Y2, actualSize, actualColor);
				if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && mouseClicked == true)
				{
					line.draw();
				}
			}
			else if (mode == Mode::RECTANGLE)
			{
				Circle circle(X1, windh - Y1, fabs(X1 - X2), actualColor, actualSize);
				if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && mouseClicked == true)
				{ 
					circle.draw();
				}
			}
			else if (mode == Mode::RECTANGLE)
			{
			  Rectangle rect(X1, windh - Y1, X2, windh - Y2, actualSize, actualColor);
				if (button == GLUT_LEFT_BUTTON && state == GLUT_UP && mouseClicked == true)
				{
					rect.draw();
				}
		  }
		}
}

void mouseMove(int x, int y)
{
	if (mouseClicked == 1)
	{
		if (mode == Mode::PEN)
		{
			Pen pen(actualSize, actualColor);
			glColor3f(actualColor.getR(), actualColor.getG(), actualColor.getB());
			pen.draw(x, windh - y);
		}
		if (mode == Mode::ERASER)
		{ 
		  Eraser eraser(actualSize);
			glColor3f(1.0f, 1.0f, 1.0f);
			eraser.draw(x, y);
		}
	}
}

void DrawColorPalette()
{
	glColor3f(1.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2f(10, 560);
	glVertex2f(40, 560);
	glVertex2f(40, 530);
	glVertex2f(10, 530);
	glEnd();
	glColor3f(0.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(40, 560);
	glVertex2f(70, 560);
	glVertex2f(70, 530);
	glVertex2f(40, 530);
	glEnd();
	glColor3f(1.0f, 0.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(10, 530);
	glVertex2f(40, 530);
	glVertex2f(40, 500);
	glVertex2f(10, 500);
	glEnd();
	glColor3f(0.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(40, 530);
	glVertex2f(70, 530);
	glVertex2f(70, 500);
	glVertex2f(40, 500);
	glEnd();
	glColor3f(0.0f, 0.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2f(10, 500);
	glVertex2f(40, 500);
	glVertex2f(40, 470);
	glVertex2f(10, 470);
	glEnd();
	glColor3f(1.0f, 1.0f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(40, 500);
	glVertex2f(70, 500);
	glVertex2f(70, 470);
	glVertex2f(40, 470);
	glEnd();
	glColor3f(1.0f, 0.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2f(10, 470);
	glVertex2f(40, 470);
	glVertex2f(40, 440);
	glVertex2f(10, 440);
	glEnd();
	glColor3f(0.0f, 1.0f, 1.0f);
	glBegin(GL_POLYGON);
	glVertex2f(40, 470);
	glVertex2f(70, 470);
	glVertex2f(70, 440);
	glVertex2f(40, 440);
	glEnd();
}

void DrawSizes()
{
	glColor3f(0.0f, 0.0f, 0.0f);
	glRasterPos2f(10, 400);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0');

	glColor3f(0.0f, 0.0f, 0.0f);
	glRasterPos2f(10, 300);
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '1');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0');
	glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, '0');

	glBegin(GL_LINES);
	glVertex2f(20, 320);
	glVertex2f(20, 400);
	glEnd();
}

void ChooseSize(int y)
{
  actualSize = 600 - y - 320;
}

void ChooseColor(int y, int x)
{  
  if(y < 560 && y > 530 && x >10 && x < 40)
	  actualColor = white;
	else if (y < 560 && y > 530 && x > 40 && x < 70)
		actualColor = black;
	else if (y < 530 && y > 500 && x > 10 && x < 40)
		actualColor = red;
	else if (y < 530 && y > 500 && x > 40 && x < 70)
		actualColor = green;
	else if (y < 500 && y > 470 && x > 10 && x < 40)
		actualColor = blue;
	else if (y < 500 && y > 470 && x > 40 && x < 70)
		actualColor = yellow;
	else if (y < 470 && y > 440 && x > 10 && x < 40)
		actualColor = purple;
	else if (y < 470 && y > 440 && x > 40 && x < 70)
		actualColor = lightBlue;

}

void Save()
{
	char name[20];
	std::cout << "Enter the name of file u want to save ;-\n";
	std::cin >> name;
	std::ofstream outfile(name);
	unsigned char pixel[3];
	for (int i = 0; i < windw; i++)
	{
		for (int j = 0; j < windh - 40; j++)
		{
			std::string r, g, b;
			std::string lines;
			glReadPixels(i, j, 1, 1, GL_RGB, GL_UNSIGNED_BYTE, pixel);
			std::ostringstream convert;
			convert << (int)pixel[0];
			r = convert.str();
			std::ostringstream convert2;
			convert2 << (int)pixel[1];
			g = convert2.str();
			std::ostringstream convert3;
			convert3 << (int)pixel[2];
			b = convert3.str();
			lines = r + " " + g + " " + b + "\n";
			outfile << lines;

		}
	}
	outfile.close();
	std::cout << "\nsaving done\n";
}
void Open()
{
	std::string fname, line;
	std::cout << "Enter the name of the file u want to open:-\n";
	std::getline(std::cin, fname);
	std::ifstream myfile(fname);

	int xc = 0, yc = 0;
	std::string r, g, b;
	while (getline(myfile, line))
	{
		int i = 0, start = 0;
		while (line[i] != ' ' && line[i] != '\n')
			i++;
		r = line.substr(0, i);
		start = i + 1;
		i = 0;
		while (line[i] != ' ' && line[i] != '\n')
			i++;
		g = line.substr(start, i);
		start = start + i + 1;
		i = 0;
		while (line[i] != ' ' && line[i] != '\n')
			i++;
		b = line.substr(start, i);
		float red, green, blue;
		red = (stof(r)) / 255;
		green = (stof(g)) / 255;
		blue = (stof(b)) / 255;
		glColor3f(red, green, blue);
		glBegin(GL_POINTS);
		glVertex2f(xc, yc);
		glEnd();
		glFlush();
		yc++;
		if (yc == 560)
		{
			xc++;
			yc = 0;
		}
	}
	std::cout << "completed";
	myfile.close();
}