#pragma once
#include "object.h"

class Ball : public Object
{
private:
	float radius_;
public:
	Ball(Point center, float speed, float radius) : Object(center, speed) { radius_ = radius; }
	virtual void draw() override;
	virtual void move() override;
	virtual void collide() override;
};