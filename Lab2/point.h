#pragma once
#include <stdlib.h>
class Point
{
private:
	float x_;
	float y_;
	float r_;
public:
	Point()
	{
		x_ = 0;
		y_ = 0;
		r_ = 0;
	}
	Point(float x, float y, float r)
	{
		x_ = x;
		y_ = y;
		r_ = r;
	}

	Point operator+(Point& right)
	{
		Point tmp;
		tmp.x_ = this->x_ + right.x_;
		tmp.y_ = this->y_ + right.y_;
		tmp.r_ = this->r_ + right.r_;
		return tmp;
	}

	Point operator-(Point& right)
	{
		Point tmp;
		tmp.x_ = this->x_ - right.x_;
		tmp.y_ = this->y_ - right.y_;
		tmp.r_ = this->r_ - right.r_;
		return tmp;
	}

	void goDown(float step, Point *p);
	void goUp(float step, Point *p);
	void goLeft(float step, Point *p);
	void goRight(float step, Point *p);
	void draw(int size);
};