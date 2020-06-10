#pragma once
#include "brush.h"

class Pen : public Brush
{
  private:
  public:
  Pen() : Brush() {};
  Pen(float size, Color color) : Brush(color, size) {};
  protected:
};