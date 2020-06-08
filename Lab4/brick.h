#pragma once
#include "object.h"
#include "bonus.h"

enum class Strength
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
	bool del_;
public:
  Brick(): Object() {
	  Bonus bonus;
		width_ = 10;
		height_ = 10;
		strength_ = Strength::WEAK;
		bonus_ = bonus;
		del_ = false;
	}
	Brick(Point center, float speed, float width, float height, Strength strength, Bonus bonus, bool del) : Object(center, speed)
	{
		width_ = width;
		height_ = height;
		strength_ = strength;
		bonus_ = bonus;
		del_ = del;
	}
	virtual void draw() override;
	bool getDel() { return del_; }
	void setDel() { del_ = true; }
	float getWidth() { return width_; }
	float getHeight() { return height_; }
	Strength getStrength() { return strength_; }
	void setStrength(Strength delta) { strength_ = delta; }
	Bonus getBonus() {return bonus_; }
};
