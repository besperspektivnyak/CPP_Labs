#pragma once
#include <GL/glut.h>
#include "brush.h"

class Line : public Brush
{
  protected:
    float x1_;
    float y1_;
    float x2_;
    float y2_;
  public:
    Line() {x1_ = 0; y1_ = 0; x2_ = 10; y2_ = 10; }
    Line(float x1, float y1, float x2, float y2, float size, Color color) : Brush(color, size)
    { x1_ = x1; y1_ = y1; x2_ = x2; y2_ = y2; }
    void draw();
};