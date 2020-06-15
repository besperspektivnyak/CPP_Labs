#pragma once

#include <Gl\glut.h>
#include <GL\GLU.h>

enum class Mode
{
  NEW,
  OPEN,
  SAVE,
  PEN,
  ERASER,
  LINE, 
  CIRCLE,
  RECTANGLE,
  SIZE, 
  COLOR
};

void mouseClick(int button, int state, int x, int y);
void mouseMove(int x, int y);
void Paint(int button, int state, int x, int y);
void DrawColorPalette();
void DrawSizes();
void ChooseMode(int x);
void ChooseColor(int y, int x);
void ChooseSize(int y);
void Save();
void Open();
