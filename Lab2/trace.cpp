#include "trace.h"

float Trace::getSpeed()
{
	return speed_;
}

std::list<Point>& Trace::getTrace()
{
	return trace_;
}
