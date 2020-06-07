#pragma once
#include "object.h"

enum class TypeCollision
{
	X,
	Y, 
	XY
};

class Ball : public Object
{
private:
	float radius_;
	int lives_;
	float speedX_;
	float speedY_;
public:
  Ball() : Object() {radius_ = 30; lives_ = 3; speedX_ = 0; speedY_ = 0; }
	Ball(Point center, float speed, float radius, int lives) : Object(center, speed)
	{ radius_ = radius; lives_ = lives; speedX_ = speed; speedY_ = speed; }
	virtual void draw() override;
	virtual void collide(TypeCollision flag);
	int getLives() { return lives_; }
	float getRad() { return radius_; }
	void setLives(int live) { lives_ += live; }
	float getSpeedX() { return speedX_; }
	float getSpeedY() { return speedY_; }
	void setSpeedX(float delta) { speedX_ += delta; }
	void setSpeedY(float delta) { speedY_ += delta; }
};