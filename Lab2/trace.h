#pragma once

#include <list>
#include "point.h"

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
};

