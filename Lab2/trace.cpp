#include "trace.h"


float Trace::getSpeed()
{
	return speed_;
}

std::list<Point>& Trace::getTrace()
{
	return trace_;
}

void Trace::draw()
{
  Point cur;

  unsigned i = 0;
  while (i < trace_.size())
  {
    cur = trace_.front();
    glColor3f(0.5, 0, 0.5);
    cur.draw(5 + 2 * i);
    if (i == 0)
    {
      glColor3f(1, 1, 1);
      cur.draw(15);
    }
    trace_.pop_front();
    trace_.push_back(cur);
    i++;
  }
}

void Trace::update()
{
  if (trace_.size() > 12)
  {
    trace_.pop_back();
  }
  draw();
}

void Trace::add(Point p)
{
  trace_.push_front(p);
}
