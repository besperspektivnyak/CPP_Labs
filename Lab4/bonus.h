#pragma once
#include "object.h"

enum class BonusType
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
  Bonus(): Object() { radius_ = 15; type_ = BonusType::NONE;}
	Bonus(Point center, BonusType type): Object(center) { radius_ = 15; type_ = type; }
	Bonus(Point center, float speed, float radius, BonusType type) : Object(center, speed)
	{
		radius_ = radius;
		type_ = type;
	}
	virtual void draw() override;
	BonusType getType() { return type_; }
};
