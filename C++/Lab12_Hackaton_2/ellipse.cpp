#include <iostream>
#include <math.h>
#include "figures.hpp"

using namespace std;
/*
class ellipse{
private:
	float a_;i
	float b_;
public:
	ellipse(point, point, point);

	float getAxis_L(){
		return a_;
	}

	float getAxis_S(){
		return b_;
	}

	float approxCircumference();

	float getArea();

	bool checkPoint(point, point);
};
*/

ellipse::ellipse(point o, point a, point b){
	a_ = sqrt(pow(a.get_x() - o.get_x(),2.0) + pow(a.get_y() - o.get_y(),2.0));
	b_ = sqrt(pow(b.get_x() - o.get_x(),2.0) + pow(b.get_y() - o.get_y(),2.0));
}

float ellipse::approxCircumference(){
	return(M_PI*(3*(a_ + b_) - sqrt((3*a_ + b_)*(a_ +3*b_))));
}

float ellipse::getArea(){
	return(M_PI*a_*b_);
}

bool ellipse::checkPoint(point c, point o){
	if((pow(c.get_x() - o.get_x(), 2.0)/pow(a_, 2.0)) + (pow(c.get_y() - o.get_y(), 2.0)/pow(b_, 2.0)) == 1.0){
		return true;
	} 
	return false;
}
