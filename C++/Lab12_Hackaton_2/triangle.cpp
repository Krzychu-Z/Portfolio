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


class triangle{
private:
        float circumference_, area_;
	float *pointsX_, *pointsY_;
public:

        triangle(point, point, point);

        float getArea(void);

        float getCircumference(void);
        
        bool checkPoint(point);

	~triangle();
};
*/

triangle::triangle(point A, point B, point C){
	
        float slopeAB = (A.get_y() - B.get_y())/(A.get_x() - B.get_x());
        float slopeAC = (A.get_y() - C.get_y())/(A.get_x() - C.get_x());
        float slopeBC = (B.get_y() - C.get_y())/(B.get_x() - C.get_x());
        
        pointsX_ = new float[3];
	pointsY_ = new float[3];
	
	pointsX_[0] = A.get_x();
	pointsX_[1] = B.get_x();
	pointsX_[2] = C.get_x();
	pointsY_[0] = A.get_y();
	pointsY_[1] = B.get_y();
	pointsY_[2] = C.get_y();
        
        float lenAB = sqrt(pow((B.get_x() - A.get_x()),2)+pow((B.get_y() - A.get_y()),2));
        float lenAC = sqrt(pow((C.get_x() - A.get_x()),2)+pow((C.get_y() - A.get_y()),2));
        float lenBC = sqrt(pow((C.get_x() - B.get_x()),2)+pow((C.get_y() - B.get_y()),2));
	
        circumference_ = lenAB + lenAC + lenBC;
	float p = circumference_/2;
	 area_ = sqrt(p*(p-lenAB)*(p-lenAC)*(p-lenBC));        
}
float triangle::getArea(){
        return area_;
}

float triangle::getCircumference(){
        return circumference_;
}

bool triangle::checkPoint(point p){

	int check = 0;
	
	float slopeAB = (pointsY_[0] - pointsY_[1])/(pointsX_[0] - pointsX_[1]);
        float slopeAC = (pointsY_[0] - pointsY_[2])/(pointsX_[0] - pointsX_[2]);
        float slopeBC = (pointsY_[1] - pointsY_[2])/(pointsX_[1] - pointsX_[2]);

	float bAB = pointsY_[0] - (slopeAB * pointsX_[0]);
        float bAC = pointsY_[0] - (slopeAC * pointsX_[0]);
        float bBC = pointsY_[1] - (slopeBC * pointsX_[1]);
        
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
        else if(p.get_y() == slopeAC * p.get_x() + bAC)
        {
        	if(pointsX_[0] < pointsX_[2])
        	{
        		if(p.get_x() >= pointsX_[0] && p.get_x() <= pointsX_[2]) check++;
        	}
        	else
        	{
        		if(p.get_x() >= pointsX_[2] && p.get_x() <= pointsX_[0]) check++;
        	}
        	if(pointsY_[0] < pointsY_[2])
        	{
        		if(p.get_y() >= pointsY_[0] && p.get_y() <= pointsY_[2]) check++;
        	}
        	else
        	{
        		if(p.get_y() >= pointsY_[2] && p.get_y() <= pointsY_[0]) check++;
        	}
        }
        else if(pointsX_[0] - pointsX_[2] == 0 && p.get_x() == pointsX_[0])
        {
         	if(pointsY_[0] < pointsY_[2])
        	{
        		if(p.get_y() >= pointsY_[0] && p.get_y() <= pointsY_[2]) check=2;
        	}
        	else
        	{
        		if(p.get_y() >= pointsY_[2] && p.get_y() <= pointsY_[0]) check=2;
        	}
        }
        else if(p.get_y() == slopeBC * p.get_x() + bBC){
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
        else if(pointsX_[1] - pointsX_[2] == 0 && p.get_x() == pointsX_[1]){
         	if(pointsY_[1] < pointsY_[2])
        	{
        		if(p.get_y() >= pointsY_[1] && p.get_y() <= pointsY_[2]) check=2;
        	}
        	else
        	{
        		if(p.get_y() >= pointsY_[2] && p.get_y() <= pointsY_[1]) check=2;
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

triangle::~triangle(){
	delete [] pointsX_;
	delete [] pointsY_;
}
/*
//testing main
int main(){
        point A(0.0, 0.0);
        point B(0.0,5.0);
        point C(5.0,0.0);

        triangle shape(A,B,C);

        cout << shape.getArea() <<endl;
        cout << shape.getCircumference() << endl;
        
        point Check(1.0,1.0);
        cout << shape.checkPoint(Check) << endl;
return 0;
}
*/
