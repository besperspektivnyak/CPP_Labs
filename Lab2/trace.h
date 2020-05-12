#pragma once

#include <list>
#include "point.h"
#include <GL\glut.h>

class Trace
{
private:
	float speed_;
	std::list<Point> trace_;
public:
	Trace()
	{
		Point p;
		trace_.push_back(p);
		speed_ = 0.05f;
	}
	Trace(Point p)
	{
		trace_.push_back(p);
		speed_ = 0.05f;
	}
	float getSpeed();
	std::list<Point>& getTrace();
	void draw();
	Point goUp()
	{
		return trace_.front().goUp(speed_);
	}

	Point goDown()
	{
		return trace_.front().goDown(speed_);
	}

	Point goLeft()
	{
		return trace_.front().goLeft(speed_);
	}

	Point goRight()
	{
		return trace_.front().goRight(speed_);
	}
};

