#include <iostream>
#include <string.h>
#include "figures.hpp"

using namespace std;

int main(){
    int input;
    cout << "======================" << endl << endl;

    cout << "------ FIGURES -------" << endl << endl;

    cout << "======================" << endl << endl;

    cout << "Enter figure from the list: " << endl << endl;
    cout << "1. segment " << endl;
    cout << "2. rectangle " << endl;
    cout << "3. circle " << endl;
    cout << "4. parallelogram " << endl;
    cout << "5. polygon " << endl;
    cout << "6. triangle" << endl;
    cout << "7. ellipse " << endl;
    cout << "8. trapeze " << endl << endl;

    cin >> input;
    cout << "\n";

    if (input == 1){
        float x1, x2, y1, y2;
        bool safe = true;
        cout << "Enter coordinates of the first point (x):"<<endl;
        cin >> x1;
        cout << "Enter coordinates of the first point (y):"<<endl;
        cin >> y1;
        cout << "Enter coordinates of the second point (x):"<<endl;
        cin >> x2;
        cout << "Enter coordinates of the second point (y):"<<endl;
        cin >> y2;
        cout << "\n";
        
        point p1;
        point p2;

        do{
            if((x1 == x2) && (y1 == y2)){
                cout << "That's a point, not a segment" << endl;
                cout << "Enter coordinates of the first point (x):"<<endl;
                cin >> x1;
                cout << "Enter coordinates of the first point (y):"<<endl;
                cin >> y1;
                cout << "Enter coordinates of the second point (x):"<<endl;
                cin >> x2;
                cout << "Enter coordinates of the second point (y):"<<endl;
                cin >> y2;
                cout << "\n";
                
                if((x1 == x2) && (y1 == y2)){
                    //do nothing.
                }else{
                    p1.set_x(x1);
                    p1.set_y(y1);
                    p2.set_x(x2);
                    p2.set_y(y2);
                    safe = false;
                    break;
                }
            }else{
                p1.set_x(x1);
                p1.set_y(y1);
                p2.set_x(x2);
                p2.set_y(y2);
                safe = false;
                break;
            }
        }while(safe);

        segment s1(p1, p2);
        float x3, y3;
        cout << "Enter point to check if it belongs to the segment " <<endl;
        cout << "Enter coordinates of the point (x):"<<endl;
        cin >> x3;
        cout << "Enter coordinates of the point (y):"<<endl;
        cin >> y3;
        cout << "\n";
        point p3(x3, y3);
        s1.check_point(p3);
        cout << "Lenght of this segment is : ";
        cout << s1.lenght() << endl;

    }
    else if (input == 2){
        cout << "The rectangle is parallel to OX and OY. Points that you input belong to diagonal of this rectangle. "<< endl;
        float x1, x2, y1, y2;
        bool safe = true;
        cout << "Enter coordinates of the first point (x):"<<endl;
        cin >> x1;
        cout << "Enter coordinates of the first point (y):"<<endl;
        cin >> y1;
        cout << "Enter coordinates of the second point (x):"<<endl;
        cin >> x2;
        cout << "Enter coordinates of the second point (y):"<<endl;
        cin >> y2;
        point p1;
        point p2;
        do{
            if((x1 == x2) && (y1 == y2)){
                cout << "That's a point, not a diagonal of rectangle"<< endl;
                cout << "Enter coordinates of the first point (x):"<<endl;
                cin >> x1;
                cout << "Enter coordinates of the first point (y):"<<endl;
                cin >> y1;
                cout << "Enter coordinates of the second point (x):"<<endl;
                cin >> x2;
                cout << "Enter coordinates of the second point (y):"<<endl;
                cin >> y2;
                if((x1 == x2) && (y1 == y2)){
                    //do nothing.

                }else if((x1 == x2) || (y1 == y2)){
                    cout << "You selected infinity of rectangles, "
                         << "change it." << endl;
                }else{
                    p1.set_x(x1);
                    p1.set_y(y1);
                    p2.set_x(x2);
                    p2.set_y(y2);
                    safe = false;
                    break;
                }
            }
            else{
                p1.set_x(x1);
                p1.set_y(y1);
                p2.set_x(x2);
                p2.set_y(y2);
                safe = false;
                break;
            }
        }while(safe);

	cout << "\n";
        rectangle r1(p1, p2);
	cout << "\n";

        float x3, y3;
        cout << "Enter point to check if it belongs to the rectangle " <<endl;
        cout << "Enter coordinates of the point (x):"<<endl;
        cin >> x3;
        cout << "Enter coordinates of the point (y):"<<endl;
        cin >> y3;
        point p3(x3, y3);
	cout << "\n\n";
        cout << "Circuit of this rectangle is : ";
        cout << r1.circuit() <<endl;
        cout << "Area of this rectangle is : ";
        cout << r1.area() <<endl;
        r1.check_point(p3);
    }
    else if (input == 3){
        float x1, y1, x2, y2, x3, y3;
        bool safe = true;

	zuruck:

        cout << "Enter coordinates of the circle's center (x):"<<endl;
        cin >> x1;
        cout << "Enter coordinates of the circle's center (y):"<<endl;
        cin >> y1;
        cout << "Enter coordinates of a random point belonging to the circle (x):"<<endl;
        cin >> x2;
        cout << "Enter coordinates of a random point belonging to the circle (y):"<<endl;
        cin >> y2;
        cout << "Enter coordinates of the point you want to check if it belongs to the circle (x):"<<endl;
        cin >> x3;
        cout << "Enter coordinates of the point you want to check if it belongs to the circle (y):"<<endl;
        cin >> y3;

        point p1(x1, y1);
        point p2(x2, y2);
        while(safe){
                if((x1 == x2) && (y1 == y2)){
                        cout << "Your circle is so small I can't see it (I mean radius = 0 ? c'mon!). Input two points, that are not in the same place" << endl;
			goto zuruck;
                } else {
                        point p1(x1, y1);
                        point p2(x2, y2);
                        safe = false;
                }
        }

        point p3(x3, y3);

        circle c1;
        c1.calculate_radius(p1, p2);
        c1.calculate_circuit(p1, p2);
        c1.calculate_area(p1, p2);

        cout << "\nCircuit of this circle is:\t" << c1.get_circuit() << " units long" << endl;
        cout << "Area of this circle is:     \t" << c1.get_area() << " square units" << endl;
        c1.check_point(p1, p2, p3);
    }
    else if (input == 4){
        float x1, x2, x3, x4, y1, y2, y3, y4;
        bool checkCords = true;
        cout << "Enter coordinates of the first point (x):"<<endl;
        cin >> x1;
        cout << "Enter coordinates of the first point (y):"<<endl;
        cin >> y1;
        cout << "Enter coordinates of the second point (x):"<<endl;
        cin >> x2;
        cout << "Enter coordinates of the second point (y):"<<endl;
        cin >> y2;
        cout << "Enter coordinates of the third point (x):"<<endl;
        cin >> x3;
        cout << "Enter coordinates of the third point (y):"<<endl;
        cin >> y3;
        cout << "Enter coordinates of the fourth point (x):"<<endl;
        cin >> x4;
        cout << "Enter coordinates of the fourth point (y):"<<endl;
        cin >> y4;
        point p1;
        point p2;
        point p3;
        point p4;
        
        while(checkCords)
        {
        	if(x1==x2 && y1==y2) {
			cout<< "Wrong coordinates" << endl;
		}
		else if(x1==x3 && y1==y3) {
			cout<< "Wrong coordinates" << endl;
		}
		else if(x1==x4 && y1==y4) {
			cout<< "Wrong coordinates" << endl;
		}
		else if(x2==x3 && y2==y3) {
			cout<< "Wrong coordinates" << endl;
		}
		else if(x2==x4 && y2==y4) {
			cout<< "Wrong coordinates" << endl;
		}
		else if(x3==x4 && y3==y4) {
			cout<< "Wrong coordinates" << endl;
		}
		else if(((y1 - y2)/(x1 - x2))==((y2 - y3)/(x2 - x3))){
			cout<< "Wrong coordinates"<< endl;
		}
		else if(((y1 - y2)/(x1 - x2))==((y1 - y4)/(x1 - x4))){
			cout<< "Wrong coordinates"<< endl;
		}
		else if(((y3 - y4)/(x3 - x4))==((y2 - y3)/(x2 - x3))){
			cout<< "Wrong coordinates"<< endl;
		}
		else if(((y3 - y4)/(x3 - x4))==((y1 - y4)/(x1 - x4))){
			cout<< "Wrong coordinates"<< endl;
		}
		else{
			if(((y1 - y2)/(x1 - x2))==((y3 - y4)/(x3 - x4)) && ((y2 - y3)/(x2 - x3))==((y1 - y4)/(x1 - x4)))
			{
				cout << "Correct coordinates" << endl;
				p1.set_x(x1);
		            	p1.set_y(y1);
		            	p2.set_x(x2);
		            	p2.set_y(y2);
		            	p3.set_x(x3);
		            	p3.set_y(y3);
		            	p4.set_x(x4);
		            	p4.set_y(y4);
		            	checkCords = false;
		            	break;
			}
			else
			{	
				if(((y1 - y2)/(x1 - x2))==((y3 - y4)/(x3 - x4)) && (x2 - x3)==0 && (x1 - x4))
				{
					cout << "Correct coordinates" << endl;
					p1.set_x(x1);
				    	p1.set_y(y1);
				    	p2.set_x(x2);
				    	p2.set_y(y2);
				    	p3.set_x(x3);
				    	p3.set_y(y3);
				    	p4.set_x(x4);
				    	p4.set_y(y4);
				    	checkCords = false;
				    	break;
				}
				else if(((y2 - y3)/(x2 - x3))==((y1 - y4)/(x1 - x4)) && (x1 - x2)==0 && (x3 - x4)==0)
				{
					cout << "Correct coordinates" << endl;
					p1.set_x(x1);
				    	p1.set_y(y1);
				    	p2.set_x(x2);
				    	p2.set_y(y2);
				    	p3.set_x(x3);
				    	p3.set_y(y3);
				    	p4.set_x(x4);
				    	p4.set_y(y4);
				    	checkCords = false;
				    	break;
				}
				else
				{
					cout << "Wrong coordinates, it's not parallelogram" << endl;
				}	
			}
		}
		cout << "Enter coordinates of the first point (x):"<<endl;
        	cin >> x1;
        	cout << "Enter coordinates of the first point (y):"<<endl;
        	cin >> y1;
        	cout << "Enter coordinates of the second point (x):"<<endl;
        	cin >> x2;
        	cout << "Enter coordinates of the second point (y):"<<endl;
        	cin >> y2;
        	cout << "Enter coordinates of the third point (x):"<<endl;
        	cin >> x3;
        	cout << "Enter coordinates of the third point (y):"<<endl;
        	cin >> y3;
        	cout << "Enter coordinates of the fourth point (x):"<<endl;
        	cin >> x4;
        	cout << "Enter coordinates of the fourth point (y):"<<endl;
        	cin >> y4;
        }
        parallelogram f1(p1, p2, p3, p4);
        float x5, y5;
        cout << "Enter point to check if it belongs to the parallelogram " <<endl;
        cout << "Enter coordinates of the point (x):"<<endl;
        cin >> x5;
        cout << "Enter coordinates of the point (y):"<<endl;
        cin >> y5;
        point p5(x5, y5);
        cout << "\nCircumference of this parallelogram is : ";
        cout << f1.getCircumference() << " units" << endl;
        cout << "Area of this parallelogram is : ";
        cout << f1.getArea() << " square units" << endl;
        if(f1.checkPoint(p5))
        {
        cout << "Chosen point belongs to your parallelogram" << endl;
        }
        else
        {
        cout << "Chosen point doesn't belong to your parallelogram" << endl;
        }
    }
    else if (input == 5){ 
    	size_t sideNumber;
	float x1, x2, x3, y1, y2, y3;

        cout << "Enter how many sides does your convex polygon have: "<< endl;
        cin >> sideNumber;
        cout << "Enter coordinates of the center (x):"<< endl;
        cin >> x1;
        cout << "Enter coordinates of the center (y):"<< endl;
        cin >> y1;
        cout << "Enter coordinates of random vertex of this polygon (x): "<< endl;
        cin >> x2;
        cout << "Enter coordinates of random vertex of this polygon (y): "<< endl;
        cin >> y2;

	point center(x1, y1);
	point vertex(x2, y2);
	polygon convex(sideNumber, center, vertex);

	cout << "Enter coordinates of a point that needs to be checked if it belongs to the polygon (x): " << endl;
	cin >> x3;
	cout << "Enter coordinates of a point that needs to be checked if it belongs to the polygon (y): " << endl;
	cin >> y3;
	cout << "\n";

	point researched(x3, y3);

	cout << "Here is the list of coordinates of your polygon's vertexes: " << endl;
	convex.vertexes(center);
	cout << "\n";
	cout << "Circumference of this polygon is:\t" << convex.getCircumference() << " units" << endl;
	cout << "Area of this polygon is:         \t" << convex.getArea() << " square units" << endl << endl;

	if(convex.isPoint(researched)){
		cout << "Your point belongs to the figure" << endl;
	} else {
		cout << "Your point doesn't belong to the figure" << endl;
	}

    }
    else if (input == 6){
        float x1, x2, x3, y1, y2, y3;
        bool checkCords = true;
        cout << "Enter coordinates of the first point (x):"<<endl;
        cin >> x1;
        cout << "Enter coordinates of the first point (y):"<<endl;
        cin >> y1;
        cout << "Enter coordinates of the second point (x):"<<endl;
        cin >> x2;
        cout << "Enter coordinates of the second point (y):"<<endl;
        cin >> y2;
        cout << "Enter coordinates of the third point (x):"<<endl;
        cin >> x3;
        cout << "Enter coordinates of the third point (y):"<<endl;
        cin >> y3;
        point p1;
        point p2;
        point p3;
        
        while(checkCords)
        {
        	if(x1==x2 && y1==y2) {
			cout<< "Wrong coordinates" << endl;
		}
		else if(x2==x3 && y2==y3) {
			cout<< "Wrong coordinates" << endl;
		}
		else if(x1==x3 && y1==y3) {
			cout<< "Wrong coordinates" << endl;
		}
		else if(((y1 - y2)/(x1 - x2))==((y2 - y3)/(x2 - x3))){
			cout<< "Wrong coordinates"<< endl;
		}
		else if(((y1 - y2)/(x1 - x2))==((y1 - y3)/(x1 - x3))){
			cout<< "Wrong coordinates"<< endl;
		}
		else if(((y1 - y3)/(x1 - x3))==((y2 - y3)/(x2- x3))){
			cout<< "Wrong coordinates"<< endl;
		}
		else{
			cout << "Correct coordinates" << endl;
			p1.set_x(x1);
                    	p1.set_y(y1);
                    	p2.set_x(x2);
                    	p2.set_y(y2);
                    	p3.set_x(x3);
                    	p3.set_y(y3);
                    	checkCords = false;
                    	break;
			
		}
		cout << "Enter coordinates of the first point (x):"<<endl;
        	cin >> x1;
        	cout << "Enter coordinates of the first point (y):"<<endl;
        	cin >> y1;
        	cout << "Enter coordinates of the second point (x):"<<endl;
        	cin >> x2;
        	cout << "Enter coordinates of the second point (y):"<<endl;
        	cin >> y2;
        	cout << "Enter coordinates of the third point (x):"<<endl;
        	cin >> x3;
        	cout << "Enter coordinates of the third point (y):"<<endl;
        	cin >> y3;
        }

        triangle t1(p1, p2, p3);
        float x4, y4;
        cout << "Enter point to check if it belongs to the triangle " <<endl;
        cout << "Enter coordinates of the point (x):"<<endl;
        cin >> x4;
        cout << "Enter coordinates of the point (y):"<<endl;
        cin >> y4;
        point p4(x4, y4);
        cout << "Circumference of this triangle is : ";
        cout << t1.getCircumference() << " units" << endl;
        cout << "Area of this triangle is : ";
        cout << t1.getArea() << "square units" << endl;
        if(t1.checkPoint(p4))
        {
        cout << "Chosen point belongs to your triangle" << endl;
        }
        else
        {
        cout << "Chosen point doesn't belong to your triangle" << endl;
        }
    }
   
    else if (input == 7){
	float x1, y1, x2, y2, x3, y3, x4, y4;

	spaghetti:

	cout << "NOTE! Major and minor axis of ellipse are parallel to axis of graph! Transform your points to meet this standard if needed" << endl << endl;

	cout << "Enter coordinates of the ellipse's center (x):"<<endl;
        cin >> x1;
        cout << "Enter coordinates of the ellipse's center (y):"<<endl;
        cin >> y1;
        cout << "Enter coordinates of a common point for ellipse and major axis (x):"<<endl;
        cin >> x2;
        cout << "Enter coordinates of a common point for ellipse and major axis (y):"<<endl;
        cin >> y2;
        cout << "Enter coordinates of a common point for ellipse and minor axis (x):"<<endl;
        cin >> x3;
        cout << "Enter coordinates of a common point for ellipse and minor axis (y):"<<endl;
        cin >> y3;
        cout << "Enter coordinates of a point that needs to be checked if it belongs to the ellipse (x):"<<endl;
        cin >> x4;
        cout << "Enter coordinates of a point that needs to be checked if it belongs to the ellipse (y):"<<endl;
        cin >> y4;

	point center(x1, x2);
	point a(x2, y2);
	point b(x3, y3);

	ellipse e(center, a, b);

	if(e.getAxis_L() == e.getAxis_S()){
		cout << "That is circle. If you have meant circle special command for that is at the beginning of this programme." << endl;
	} else if(((x1 == x2) && (y1 == y2)) || ((x1 == x3) && (y1 == y3)) || ((x2 == x3) && (y2 == y3))){
		cout << "Some of these point are in the same place. Enter them again" << endl;
		goto spaghetti;
	} else {
		cout << "This is analytic equation of your ellipse: x^(2)/" << e.getAxis_L();
	        cout << "^(2) + y^(2)/" << e.getAxis_S() << "^(2) = 1" << endl << endl;
		cout << "Circumference of your ellipse is " << e.approxCircumference() << " units" << endl;
		cout << "Area of your ellipse is " << e.getArea() << " square units" << endl;

		point c(x4, y4);
		if(e.checkPoint(c, center)){
			cout << "Given point belongs to ellipse" << endl;
		} else {
			cout << "Given point doesn't belong to ellipse" << endl;
		}

	}

    } else {
        cout << "You entered wrong number"<<endl;
    }
}
