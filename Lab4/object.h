#pragma once

class Point
{
private:
	float x_;
	float y_;
	//float r_;
public:
	Point() { x_ = 0; y_ = 0;}
	Point(float x, float y, float r) { x_ = x; y_ = y; }
};

class Object
{
	private:
	  Point center_;
		float speed_;
	protected:
	  Object(Point center, float speed) { center_ = center; speed_ = speed; }
		virtual void draw();
		virtual void move();
		virtual void collide();
};