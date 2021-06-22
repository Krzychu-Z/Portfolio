#include <iostream>
#include <cmath>
#include <string>
#include "figures.hpp"

using namespace std;

/*
class circle:public point{
private:
    float r;
    float circuit;
    float area;

public:
//    circle(float r_=0.0f, float circuit_=0.0f, float area_=0.0f);

    float get_r()
    {
        return r;
    }
    float get_circuit()
    {
        return circuit;
    }
    float get_area()
    {
        return area;
    }

    float calculate_radius(point p1, point p2);

    float calculate_circuit(point p1,point p2);

    float calculate_area(point p1,point p2);

    float check_point(point p1, point p2, point other_one);

};

circle::circle(float r_, float circuit_, float area_)
{
    r = r_;
    circuit = circuit_;
    area = area_;
}
*/


float circle::calculate_radius(point p1, point p2)
{
    r = sqrt((p1.get_x() - p2.get_x())*((p1.get_x() - p2.get_x())) + (p1.get_y() - p2.get_y())*(p1.get_y() - p2.get_y()));
    return r;
}
float circle::calculate_circuit(point p1,point p2)
{
    r = calculate_radius(p1,p2);
    circuit = 2 * M_PI * r;
    return circuit;
}
float circle::calculate_area(point p1, point p2)
{
    r = calculate_radius(p1,p2);
    area = M_PI * r * r;
    return area;
}
float circle::check_point(point p1, point p2,point other_one)
{

    r = calculate_radius(p1,p2);
    float r2 = sqrt((p1.get_x() - other_one.get_x())*(p1.get_x() - other_one.get_x()) + (p1.get_y() - other_one.get_y())*(p1.get_y() - other_one.get_y()));

    if(r2 > r)
    {
        cout<<"Point doesn't belong to the circle"<<endl;
    }
    else{
        cout<<"Point belongs to the circle"<<endl;
    }
}

/*
int main()
{

    point p1(5,2);
    point p2(2,3);
    point other_one(1.23,123.1);
    circle c1;
    //p1.load_points();
    //p2.load_points();
    //other_one.load_points();
    cout<<c1.calculate_radius(p1,p2)<<endl;
    cout<<c1.calculate_area(p1,p2)<<endl;
    cout<<c1.calculate_circuit(p1,p2)<<endl;
    c1.check_point(p1,p2,other_one);






    return 0;
}
*/
