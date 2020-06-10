#pragma once

class Color
{
  private:
    float r_;
    float g_;
    float b_;
  public:
    Color() {r_ = 0.0f; g_ = 0.0f; b_ = 0.0f; }
    Color(float r, float g, float b) { r_ = r; g_ = g; b_ = b; }
    float getR() { return r_; }
    float getG() { return g_; }
    float getB() { return b_; }
};

class Brush
{
  private:
    float size_;
    Color color_; 
  public:
    Brush() {Color color; size_ = 10; color_ = color;}
    Brush(Color color, float size) { size_ = size; color_ = color; }
    Color getColor() { return color_; }
    void draw(float x, float y);
    float getSize() { return size_; }
};