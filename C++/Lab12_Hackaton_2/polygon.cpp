#include <iostream>
#include <math.h>
#include "figures.hpp"

using namespace std;

/*  Testing purpose only
 *  ! marks where in the code following convention has been used. (To be changed if necessary)
class point{
private:
	float x_;
	float y_;
public:
	point(float x, float y){
		x_ = x;
		y_ = y;
	}

	float get_x(){
		return x_;
	}

	float get_y(){
		return y_;
	}
};
*/

/*class polygon{
private:
	size_t sideNum_;
	float radius_, circumference_, area_, innerAngle_;
	float *pointsX_, *pointsY_;
public:
	//------sides--center--vertex
	polygon(size_t, point, point); 			//!

	size_t getSidesNum(void);

	float getRadius(void);

	float getCircumference(void);

	float getArea(void);

	void vertexes(point);				//!

	bool isPoint(point);				//!

	~polygon();
};
*/
polygon::polygon(size_t num, point o, point a){		//!
	sideNum_ = num;
	innerAngle_ = 2*M_PI/sideNum_;
	radius_ = sqrt(pow(o.get_x() - a.get_x(), 2.0) + pow(o.get_y() - a.get_y(), 2.0));	//!!
	circumference_ = sideNum_*radius_*sqrt(2*(1 - cos(innerAngle_)));
	area_ = sideNum_*0.5*pow(radius_,2.0)*sin(innerAngle_);

	//Arrays for vertex points
	pointsX_ = new float[sideNum_];
	pointsY_ = new float[sideNum_];
	pointsX_[0] = a.get_x();					//!
	pointsY_[0] = a.get_y();					//!
}

size_t polygon::getSidesNum(){
	return sideNum_;
}

float polygon::getRadius(){
	return radius_;
}

float polygon::getCircumference(){
	return circumference_;
}

float polygon::getArea(){
	return area_;
}

void polygon::vertexes(point o){					//!
	float beta;

	if((pointsX_[0] - o.get_x()) >= 0.0f && (pointsY_[0] - o.get_y()) >= 0.0f){	//!
		//First quadrant
		//First angle to which next will be added
		beta = asin((pointsY_[0] - o.get_y())/radius_);					//!
	} else if ((pointsX_[0] - o.get_x()) < 0.0f && (pointsY_[0] - o.get_y()) >= 0.0f){	//!
		//Second quadrant
		beta = M_PI - asin((pointsY_[0] - o.get_y())/radius_);				//!
	} else if ((pointsX_[0] - o.get_x()) < 0.0f && (pointsY_[0] - o.get_y()) < 0.0f){	//!
		//Third quadrant
		beta = M_PI + (-1)*asin((pointsY_[0] - o.get_y())/radius_);			//!
	} else {
		//Fourth quadrant
		beta = 2*M_PI + asin((pointsY_[0] - o.get_y())/radius_);			//!
	}

	//Vertex assignment loop
	for(size_t i = 1; i < sideNum_; i++){
		//Pretty much pole coordinates
		pointsX_[i] = round((cos(beta + i*innerAngle_)*radius_ + o.get_x())*10000)/10000;	//!
		pointsY_[i] = round((sin(beta + i*innerAngle_)*radius_ + o.get_y())*10000)/10000;	//!

		//Removes stupid notation -0
		if((pointsX_[i] >= -0.00001f) && (pointsX_[i] <= 0.00001f)){
			pointsX_[i] = abs(pointsX_[i]);
		}
		if((pointsY_[i] >= -0.00001f) && (pointsY_[i] <= 0.00001f)){
			pointsY_[i] = abs(pointsY_[i]);
		}
	}

	for(size_t i = 0; i < sideNum_; i++){
		cout << "Vertex no " << i + 1 << "\t(" << pointsX_[i] << ", " << pointsY_[i] << ")" << endl;
	}
}

bool polygon::isPoint(point s){			//!
	for(size_t i = 0; i < sideNum_; i++){
	 if(i != sideNum_ - 1){
	  //--(y - y_a)*(x_b - x_a) - (y_b - y_a)*(x - x_a) = 0----linear function for two points given   !!!!(below)
	  if(((s.get_y() - pointsY_[i])*(pointsX_[i+1] - pointsX_[i]) - (pointsY_[i+1] - pointsY_[i])*(s.get_x() - pointsX_[i])) == 0){
		return true;
	  }	  
	 } else {
	  if(((s.get_y() - pointsY_[i])*(pointsX_[0] - pointsX_[i]) - (pointsY_[0] - pointsY_[i])*(s.get_x() - pointsX_[i])) == 0){
		return true;
	  } else {
	  	//Last element of the loop. If point doesn't belong to the figure following line will be executed
		return false;
	  }	  
	 }
	}
}

polygon::~polygon(){
	delete [] pointsX_;
	delete [] pointsY_;
}

/* int main(){

	point center(1.0f, 3.0f);
       	point vertex(1.0f, 1.0f);	
	point dowolny(0.1322f, 4.8019f);
	polygon pentagon(7, center, vertex);

	pentagon.vertexes(center);

	if(pentagon.isPoint(dowolny)){
		cout << "Point belongs to the figure" << endl;
	} else {
		cout << "Point doesn't belong to the figure" << endl;
	}

	cout << pentagon.getRadius() << endl;
	cout << pentagon.getCircumference() << endl;
	cout << pentagon.getArea() << endl;

return 0;
}
*/
