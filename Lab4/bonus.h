#pragma once
#include "object.h"

enum BonusType
{
	NONE,
	SPEED_PLUS,
	SPEED_MINUS,
	PADDLE_PLUS,
	PADDLE_MINUS,
	LIFE,
	EXTRA_POINTS
};

class Bonus : public Object
{
private:
	float radius_;
	BonusType type_;
public:
	Bonus(Point center, float speed, float radius, BonusType type) : Object(center, speed) 
	{ radius_ = radius; type_ = type; }
	virtual void draw() override;
	virtual void move() override;
	virtual void collide() override;
	Bonus operator=(const Bonus& right) { radius_ = right.radius_; type_ = right.type_; }
};
