#pragma once
#include "object.h"
#include "bonus.h"

enum Strength
{
	WEAK = 1,
	MIDDLE,
	HARD
};

class Brick : public Object
{
private:
	float height_;
	float width_;
	Strength strength_;
	Bonus bonus_;
public:
	Brick(Point center, float speed, float width, float height, Strength strength, Bonus bonus) : Object(center, speed)
	{
		width_ = width;
		height_ = height;
		strength_ = strength;
		bonus_ = bonus;
	}
	virtual void draw() override;
	virtual void collide() override;
};
