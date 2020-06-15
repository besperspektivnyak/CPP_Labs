#pragma once
#include <GL/glut.h>
#include "shape.h"

class Line : public Shape
{
  protected:
    float x2_;
    float y2_;
  public:
    Line() {x1_ = 0; y1_ = 0; x2_ = 10; y2_ = 10; }
    Line(float x1, float y1, float x2, float y2, float size, Color color) : Shape(x1, y1, color, size)
    { x2_ = x2; y2_ = y2; }
    virtual void draw() override;
};