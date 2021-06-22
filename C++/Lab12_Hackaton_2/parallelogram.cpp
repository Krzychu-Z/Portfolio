#include <iostream>
#include <math.h>
#include "figures.hpp"
using namespace std;

/*
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

class parallelogram{
private:
	float circumference_, area_;
	float *pointsX_, *pointsY_;
public:

	parallelogram(point, point, point, point);

	float getArea(void);

	float getCircumference(void);
	
	bool checkPoint(point);

	~parallelogram();
};
*/
parallelogram::parallelogram(point A, point B, point C, point D){

	float slopeAB = (A.get_y() - B.get_y())/(A.get_x() - B.get_x());
	float slopeCD = (C.get_y() - D.get_y())/(C.get_x() - D.get_x());
	float slopeAD = (A.get_y() - D.get_y())/(A.get_x() - D.get_x());
	float slopeCB = (C.get_y() - B.get_y())/(C.get_x() - B.get_x());
	if((A.get_x() - B.get_x())==0){
		float lenAB;
		if(A.get_y() > B.get_y()){
			lenAB = abs(A.get_y() - B.get_y());
		}
		else
		{
			lenAB = abs(B.get_y() - A.get_y());
		}
		float lenAD = sqrt(pow((D.get_x() - A.get_x()),2)+pow((D.get_y() - A.get_y()),2));
		float bAD = A.get_y() - (slopeAD * A.get_x());

		float height = (abs(slopeAD * C.get_x() - C.get_y() + bAD))/(sqrt(pow(slopeAD,2)+1));
		area_ = lenAD * height;

		circumference_ = 2*lenAB + 2 *lenAD;
		
	}
	else if((C.get_x() - B.get_x())==0){
		float lenAB = sqrt(pow((B.get_x() - A.get_x()),2)+pow((B.get_y() - A.get_y()),2));
		float lenAD;
		if(C.get_y() > B.get_y()){
			lenAD = abs(C.get_y() - B.get_y());
		}
		else
		{
			lenAD = abs(B.get_y() - C.get_y());
		}
		float bAB = A.get_y() - (slopeAB * A.get_x());

		float height = (abs(slopeAB * C.get_x() - C.get_y() + bAB))/(sqrt(pow(slopeAB,2)+1));
		area_ = lenAB * height;

		circumference_ = 2*lenAB + 2 *lenAD;
	
	}
	else{
		float lenAB = sqrt(pow((B.get_x() - A.get_x()),2)+pow((B.get_y() - A.get_y()),2));
		float lenAD = sqrt(pow((D.get_x() - A.get_x()),2)+pow((D.get_y() - A.get_y()),2));
		float bAB = A.get_y() - (slopeAB * A.get_x());

		float height = (abs(slopeAB * C.get_x() - C.get_y() + bAB))/(sqrt(pow(slopeAB,2)+1));
		area_ = lenAB * height;

		circumference_ = 2*lenAB + 2 *lenAD;
	}	
	
	pointsX_ = new float[4];
	pointsY_ = new float[4];
	
	pointsX_[0] = A.get_x();
	pointsX_[1] = B.get_x();
	pointsX_[2] = C.get_x();
	pointsX_[3] = D.get_x();
	pointsY_[0] = A.get_y();
	pointsY_[1] = B.get_y();
	pointsY_[2] = C.get_y();
	pointsY_[3] = D.get_y();
}
float parallelogram::getArea(){
	return area_;
}

float parallelogram::getCircumference(){
	return circumference_;
}

bool parallelogram::checkPoint(point p){

	int check = 0;
	
	float slopeAB = (pointsY_[0] - pointsY_[1])/(pointsX_[0] - pointsX_[1]);
        float slopeBC = (pointsY_[1] - pointsY_[2])/(pointsX_[1] - pointsX_[2]);
        float slopeCD = (pointsY_[2] - pointsY_[3])/(pointsX_[2] - pointsX_[3]);
        float slopeDA = (pointsY_[3] - pointsY_[0])/(pointsX_[3] - pointsX_[0]);

	float bAB = pointsY_[0] - (slopeAB * pointsX_[0]);
        float bBC = pointsY_[1] - (slopeBC * pointsX_[1]);
        float bCD = pointsY_[2] - (slopeCD * pointsX_[2]);
        float bDA = pointsY_[3] - (slopeDA * pointsX_[3]);
        
        //cout << bAB << " " << slopeAB << " " << p.get_y() << " " << p.get_x() << endl; 
        //cout << bAC << " " << slopeAC << " " << p.get_y() << " " << p.get_x() << endl; 
	//cout << bBC << " " << slopeBC << " " << p.get_y() << " " << p.get_x() << endl; 
        
        if(p.get_y() == slopeAB * p.get_x() + bAB){
        	if(pointsX_[0] < pointsX_[1])
        	{
        		if(p.get_x() >= pointsX_[0] && p.get_x() <= pointsX_[1]) check++;
        	}
        	else
        	{
        		if(p.get_x() >= pointsX_[1] && p.get_x() <= pointsX_[0]) check++;
        	}
        	if(pointsY_[0] < pointsY_[1])
        	{
        		if(p.get_y() >= pointsY_[0] && p.get_y() <= pointsY_[1]) check++;
        	}
        	else
        	{
        		if(p.get_y() >= pointsY_[1] && p.get_y() <= pointsY_[0]) check++;
        	}
        }
        else if(pointsX_[0] - pointsX_[1] == 0 && p.get_x() == pointsX_[0])
        {
         	if(pointsY_[0] < pointsY_[1])
        	{
        		if(p.get_y() >= pointsY_[0] && p.get_y() <= pointsY_[1]) check=2;
        	}
        	else
        	{
        		if(p.get_y() >= pointsY_[1] && p.get_y() <= pointsY_[0]) check=2;
        	}
        }
        else if(p.get_y() == slopeBC * p.get_x() + bBC)
        {
        	if(pointsX_[1] < pointsX_[2])
        	{
        		if(p.get_x() >= pointsX_[1] && p.get_x() <= pointsX_[2]) check++;
        	}
        	else
        	{
        		if(p.get_x() >= pointsX_[2] && p.get_x() <= pointsX_[1]) check++;
        	}
        	if(pointsY_[1] < pointsY_[2])
        	{
        		if(p.get_y() >= pointsY_[1] && p.get_y() <= pointsY_[2]) check++;
        	}
        	else
        	{
        		if(p.get_y() >= pointsY_[2] && p.get_y() <= pointsY_[1]) check++;
        	}
        }
        else if(pointsX_[1] - pointsX_[2] == 0 && p.get_x() == pointsX_[1])
        {
         	if(pointsY_[1] < pointsY_[2])
        	{
        		if(p.get_y() >= pointsY_[1] && p.get_y() <= pointsY_[2]) check=2;
        	}
        	else
        	{
        		if(p.get_y() >= pointsY_[2] && p.get_y() <= pointsY_[1]) check=2;
        	}
        }
        else if(p.get_y() == slopeCD * p.get_x() + bCD){
        	if(pointsX_[2] < pointsX_[3])
        	{
        		if(p.get_x() >= pointsX_[2] && p.get_x() <= pointsX_[3]) check++;
        	}
        	else
        	{
        		if(p.get_x() >= pointsX_[3] && p.get_x() <= pointsX_[2]) check++;
        	}
        	if(pointsY_[2] < pointsY_[3])
        	{
        		if(p.get_y() >= pointsY_[2] && p.get_y() <= pointsY_[3]) check++;
        	}
        	else
        	{
        		if(p.get_y() >= pointsY_[3] && p.get_y() <= pointsY_[2]) check++;
        	}
        }
        else if(pointsX_[2] - pointsX_[3] == 0 && p.get_x() == pointsX_[2]){
         	if(pointsY_[2] < pointsY_[3])
        	{
        		if(p.get_y() >= pointsY_[2] && p.get_y() <= pointsY_[3]) check=2;
        	}
        	else
        	{
        		if(p.get_y() >= pointsY_[3] && p.get_y() <= pointsY_[2]) check=2;
        	}
        }
        else if(p.get_y() == slopeDA * p.get_x() + bDA){
        	if(pointsX_[3] < pointsX_[0])
        	{
        		if(p.get_x() >= pointsX_[3] && p.get_x() <= pointsX_[0]) check++;
        	}
        	else
        	{
        		if(p.get_x() >= pointsX_[0] && p.get_x() <= pointsX_[3]) check++;
        	}
        	if(pointsY_[3] < pointsY_[0])
        	{
        		if(p.get_y() >= pointsY_[3] && p.get_y() <= pointsY_[0]) check++;
        	}
        	else
        	{
        		if(p.get_y() >= pointsY_[0] && p.get_y() <= pointsY_[3]) check++;
        	}
        }
        else if(pointsX_[3] - pointsX_[0] == 0 && p.get_x() == pointsX_[3]){
         	if(pointsY_[3] < pointsY_[0])
        	{
        		if(p.get_y() >= pointsY_[3] && p.get_y() <= pointsY_[0]) check=2;
        	}
        	else
        	{
        		if(p.get_y() >= pointsY_[0] && p.get_y() <= pointsY_[3]) check=2;
        	}
        }
        else
        {
        return false;
        }
        
        if(check >= 2) {
        return true;
        }
        else {
        return false;
        }
             
}

parallelogram::~parallelogram(){
	delete [] pointsX_;
	delete [] pointsY_;
}
/*
//testing main
int main(){
	point A(0.0, 0.0);
	point B(4.0,0.0);
	point C(6.0,4.0);
	point D(2.0,4.0);

	parallelogram shape(A,B,C,D);
	
	cout << shape.getArea() <<endl;
	cout << shape.getCircumference() << endl;
	
	point Check(2.0,0.0);
        cout << shape.checkPoint(Check) << endl;
        point Check1(4.0,4.0);
        cout << shape.checkPoint(Check1) << endl;
        point Check2(5.0,2.0);
        cout << shape.checkPoint(Check2) << endl;
        point Check3(1.0,2.0);
        cout << shape.checkPoint(Check3) << endl;
        point Check4(7.0,6.0);
        cout << shape.checkPoint(Check4) << endl;
return 0;
}
*/

