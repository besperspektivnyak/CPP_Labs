#pragma once

class Point
{
private:
	float x_;
	float y_;
public:
	Point() { x_ = 0; y_ = 0;}
	Point(float x, float y) { x_ = x; y_ = y; }
	void draw();
	float getX() { return x_; }
	float getY() { return y_; }
	Point fabsP();
	Point operator=(const Point& right)
	{
		x_ = right.x_;
		y_ = right.y_;
		return *this;
	}
	Point operator+=(const Point& right)
	{
		x_ += right.x_;
		y_ += right.y_;
		return *this;
	}
	Point operator-(const Point& right)
	{
		Point newP;
		newP.x_ = x_ - right.x_;
		newP.y_ = y_ - right.y_;
		return newP;
	}
	bool operator<=(const Point& right)
	{
	  if (x_ <= right.x_ && y_ <= right.y_)
		  return true;
		else 
		  return false;
	}
};

class Object
{
	private:
	  Point center_;
		float speed_;
	protected:
	  Object() { Point tmp; center_ = tmp; speed_ = 20; }
		Object(Point center) {Point tmp = center; center_ = tmp; speed_ = 20; }
	  Object(Point center, float speed) { center_ = center; speed_ = speed; }
	public:
		virtual void draw();
		virtual void move(float shiftX, float shiftY);
		virtual void collide();
		Point getCenter() { return center_; }
		float getSpeed() { return speed_; }

};