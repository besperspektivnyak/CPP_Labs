#pragma once
#include "line.h"

class Rectangle : public Line
{
  private:
  public:
    Rectangle() : Line() {};
    Rectangle(float x1, float y1, float x2, float y2, float size, Color color) : 
    Line(x1, y1,  x2,  y2,  size, color) {};
    void draw();
};