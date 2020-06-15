#pragma once
#include "shape.h"

class Rectangle : public Shape
{
  private:
    float x2_;
    float y2_;
  public:
    Rectangle() : Shape() { x2_ = 0; y2_ = 0; };
    Rectangle(float x1, float y1, float x2, float y2, float size, Color color) : 
    Shape(x1, y1, color, size) {x2_ = x2; y2_ = y2; };
    virtual void draw() override;
};