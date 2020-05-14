#pragma once

#include <list>
#include "point.h"
#include <GL\glut.h>

extern Point tmp;

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
	void update();
	void add(Point p);
	void goUp(Point *p)
	{
		 trace_.front().goUp(speed_, p);
	}

	void goDown(Point *p)
	{
		 trace_.front().goDown(speed_, p);
	}

	void goLeft(Point *p)
	{
		 trace_.front().goLeft(speed_, p);
	}

	void goRight(Point *p)
	{
	   trace_.front().goRight(speed_, p);
	}
};

