#pragma once


class Circle
{
  private:
    float x_;
    float y_;
    float radius_;
  public:
    Circle() {x_ = 0; y_ = 0; radius_ = 0; }
    Circle(float x, float y, float rad) { x_ = x; y_ = y; radius_ = rad; }
    void draw();
};