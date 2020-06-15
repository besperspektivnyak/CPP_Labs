#pragma once
#include "brush.h"

static Color white(1.0f, 1.0f, 1.0f);

class Eraser : public Brush
{
  private:
  public:
  Eraser() : Brush() {};
  Eraser(float size) : Brush(white, size) {};
  protected:
};