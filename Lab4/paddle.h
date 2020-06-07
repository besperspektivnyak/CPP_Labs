#pragma once
#include "object.h"

class Paddle : public Object
{
private:
	float width_;
	float height_;
public:
  Paddle(): Object() { width_ = 60; height_ = 10; }
	Paddle(Point center, float speed, float width, float height) : Object(center, speed)
	{
		width_ = width;
		height_ = height;
	}
	virtual void draw() override;
	void setWidth(int wid) { width_ += wid; }
	float getWidth() { return width_; }
	float getHeight() { return height_; }

};