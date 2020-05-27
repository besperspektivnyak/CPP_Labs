#pragma once
#include "object.h"

class Paddle : public Object
{
private:
	float width_;
	float height_;
public:
	Paddle(Point center, float speed, float width, float height) : Object(center, speed)
	{
		width_ = width;
		height_ = height;
	}
	virtual void draw() override;
	virtual void move() override;
	virtual void collide() override;
	void setWidth();
};