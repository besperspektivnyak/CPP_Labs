#pragma once
#include "shape.h"

class Circle : public Shape
{
  private:
    float radius_;
  public:
    Circle() : Shape() { radius_ = 0; }
    Circle(float x, float y, float rad, Color color, float size) : Shape(x, y, color, size) {  radius_ = rad; }
    virtual void draw() override;
};