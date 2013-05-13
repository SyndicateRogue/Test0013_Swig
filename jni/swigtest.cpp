/* File : example.cpp */

#include "swigtest.h"

namespace swigtest {

#define M_PI 3.14159265358979323846

/* Move the shape to a new location */
void Shape::move(double dx, double dy) {
  x = dx;
  y += dy;
}

int Shape::nshapes = 0;

double Circle::area(void) {
  return M_PI*radius*radius;
}

double Circle::perimeter(void) {
  return 2*M_PI*radius;
}

void Circle::setR(double r) {
	radius = r;
	TestCallback * cb = new TestCallback(cb_);
	cb->onChanged((Shape*)this);
}

double Square::area(void) {
  return width*width;
}

double Square::perimeter(void) {
  return 4*width;
}

void Circle::TestCallback::onChanged(Shape* shape){
	ccb_->onChanged(shape);
}

}
