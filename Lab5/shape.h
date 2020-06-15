#pragma once
#include "brush.h"

class Shape : public Brush
{
  protected:
    float x1_;
    float y1_;
  public:
    Shape() : Brush() { x1_ = 0; y1_ = 0; }
    Shape(float x1, float y1, Color color, float size) : Brush(color, size) { x1_ = x1; y1_ = y1; }
    virtual void draw();
};