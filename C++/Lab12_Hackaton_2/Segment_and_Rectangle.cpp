#include <iostream>
#include <cmath>
#include "figures.hpp"

using namespace std;

// CLASS SEGMENT

/*class segment{
        private:
                point A;
                point B;

        public:
                segment(point pkt1, point pkt2);
                double lenght();
                void check_point(point other_one);

};*/

segment::segment(point pkt1, point pkt2){
         A = pkt1;
         B = pkt2;
}

double segment::lenght(){
        double lenght_of_segment;
        lenght_of_segment = sqrt((((A.get_x()) - (B.get_x())) * ((A.get_x()) - (B.get_x()))) +
                        (((A.get_y()) - (B.get_y())) * ((A.get_y()) - (B.get_y()))));
        return lenght_of_segment;
}

void segment::check_point(point other_one){
        if(((other_one.get_x()) <= max((A.get_x()), (B.get_x())) &&
                (other_one.get_x()) >= min((A.get_x()), (B.get_x()))) &&
                ((other_one.get_y()) <= max((A.get_y()), (B.get_y())) &&
                 (other_one.get_y()) >= min((A.get_y()), (B.get_y())))) {

                        if((B.get_x()) * (other_one.get_y()) + (A.get_x()) * (B.get_y()) + (other_one.get_x())
                                * (A.get_y()) - (A.get_x()) * (other_one.get_y()) - (B.get_x()) * (A.get_y())
                                - (other_one.get_x()) * (B.get_y()) == 0){

                                        cout << "The point belongs "
                                                << " to the segment" << endl;
                        }else{
                                cout << "The point doesn't belong"
                                       << "to the segment" << endl;

                        }

        }else{
                cout << "The point doesn't belong"
                       << "to the segment" << endl;

        }
}

// CLASS RECTANGLE

/*class rectangle{
        private:
                point A;
                point B;

        public:
                rectangle(point pkt1, point pkt2);
                double circuit();
                double area();
                void check_point(point other_one);
};*/

rectangle::rectangle(point pkt1, point pkt2){
        A = pkt1;
        B = pkt2;
        cout << "The vertices of this rectangle are:"<< endl;
        cout << "(" << A.get_x() << "; " << A.get_y() << "),  ";
        cout << "(" << A.get_x() << "; " << B.get_y() << "),  ";
        cout << "(" << B.get_x() << "; " << B.get_y() << "),  ";
        cout << "(" << B.get_x() << "; " << A.get_y() << ")";
}

double rectangle::circuit(){
        double a;
        double b;
        double circuit;

        a = abs((A.get_x())-(B.get_x()));
        b = abs((A.get_y())-(B.get_y()));
        circuit = 2 * (a + b);

        return circuit;
}

double rectangle::area(){
        double a;
        double b;
        double area;

        a = abs((A.get_x())-(B.get_x()));
        b = abs((A.get_y())-(B.get_y()));
        area = a * b;

        return area;
}

void rectangle::check_point(point other_one){
        if(((other_one.get_x() == (A.get_x())) || (other_one.get_x() == (B.get_x()))) &&
                (other_one.get_y() >= min((A.get_y()),(B.get_y())) &&
                 (other_one.get_y() <= max((A.get_y()),(B.get_y()))))){

                cout << "The point belongs to the rectangle" << endl;
        } else if(((other_one.get_y() == (A.get_y())) || (other_one.get_y() == (B.get_y()))) &&
                (other_one.get_x() >= min((A.get_x()),(B.get_x())) &&
                 (other_one.get_x() <= max((A.get_x()),(B.get_x()))))){

                cout << "The point belongs to the rectangle" << endl;
        } else{
                cout << "The point doesn't belong to the rectangle" << endl;
        }
}

//tester odcinka, prostokata:

/*int main(){
        point pkt1;
        point pkt2;
        pkt1.set_x(1.0f);
        pkt1.set_y(0.0f);
        pkt2.set_x(3.0f);
        pkt2.set_y(1.0f);
        cout << "Give other cords for point 1:" << endl;
        cout << "x = ";
        cin >> pkt1.x;
        cout << endl << "y = ";
        cin >> pkt1.y;
        cout << endl << "Give other cords for point 2:" << endl;
        cout << "x = ";
        cin >> pkt2.x;
        cout << endl << "y = ";
        cin >> pkt2.y;

        rectangle s1(pkt1, pkt2);

        cout << endl << endl << s1.circuit() << endl << endl;

        point other_one;
        other_one.set_x(0);
        other_one.set_y(0);
      cout << "x = ";
        cin >> other_one.x;
        cout << endl << "y = ";
        cin >> other_one.y;
        s1.check_point(other_one);
        
        
        A.set_x(pkt1.get_x());
        A.set_y(pkt1.get_y());
        B.set_x(pkt2.get_x());
        B.set_y(pkt2.get_y());
}
*/
        
/* TESTER WARUNKOW DLA PROSTOKATA

bool safe = true;
        float a, b, c, d;
        do{
                if((pkt1.get_x() == pkt2.get_x()) && (pkt1.get_y() == pkt2.get_y())){
                        cout << "That's a point, not a diagonal of rectangle"
                                << endl;
                        cout << "Give other cords for point 1:" << endl;
                        cout << "x = ";
                        cin >> a;
                        pkt1.set_x(a);
                        cout << endl << "y = ";
                        cin >> b;
                        pkt1.set_y(b);
                        cout << endl << "Give other cords for point 2:" << endl;
                        cout << "x = ";
                        cin >> c;
                        pkt2.set_x(c);
                        cout << endl << "y = ";
                        cin >> d;
                        pkt2.set_y(d);
                        if((pkt1.get_x() == pkt2.get_x()) && (pkt1.get_y() == pkt2.get_y())){
                            cout << "That's a point, not a diagonal of rectangle"
                                << endl;
                            safe = true;
                        }else if((pkt1.get_x() == pkt2.get_x()) || (pkt1.get_y() == pkt2.get_y())){
                            cout << "You selected infinity of rectangles, "
                               << "chaneg it." << endl;
                               safe = true;
                        }else{
                            A.set_x(pkt1.get_x());
                            A.set_y(pkt1.get_y());
                            B.set_x(pkt2.get_x());
                            B.set_y(pkt2.get_y());
                            break;
                        }
                }else if((pkt1.get_x() == pkt2.get_x()) || (pkt1.get_y() == pkt2.get_y())){
                        cout << "You selected infinity of rectangles, "
                               << "chaneg it." << endl;
                        cout << "Give other cords for point 1:" << endl;
                        cout << "x = ";
                        cin >> a;
                        pkt1.set_x(a);
                        cout << endl << "y = ";
                        cin >> b;
                        pkt1.set_y(b);
                        cout << endl << "Give other cords for point 2:" << endl;
                        cout << "x = ";
                        cin >> c;
                        pkt2.set_x(c);
                        cout << endl << "y = ";
                        cin >> d;
                        pkt2.set_y(d);
                          if((pkt1.get_x() == pkt2.get_x()) && (pkt1.get_y() == pkt2.get_y())){
                            cout << "That's a point, not a diagonal of rectangle"
                                << endl;
                            safe = true;
                        }else if((pkt1.get_x() == pkt2.get_x()) || (pkt1.get_y() == pkt2.get_y())){
                            cout << "You selected infinity of rectangles, "
                               << "chaneg it." << endl;
                               safe = true;
                        }else{
                            A.set_x(pkt1.get_x());
                            A.set_y(pkt1.get_y());
                            B.set_x(pkt2.get_x());
                            B.set_y(pkt2.get_y());
                            break;
                        }

                }else{
                        A.set_x(pkt1.get_x());
                        A.set_y(pkt1.get_y());
                        B.set_x(pkt2.get_x());
                        B.set_y(pkt2.get_y());
                        safe = true;
                      break;
                }
        }while(safe == true);
*/

/*TESTER WARUNKOW DLA ODCINKA

bool safe = true;
        float a, b, c, d;
        do{
                if((pkt1.get_x() == pkt2.get_x()) && (pkt1.get_y() == pkt2.get_y())){
                        cout << "That's a point, not a segment" << endl;
                        cout << "Give other cords for point 1:" << endl;
                        cout << "x = ";
                        cin >> a;
                        pkt1.set_x(a);
                        cout << endl << "y = ";
                        cin >> b;
                        pkt1.set_y(b);
                        cout << endl << "Give other cords for point 2:" << endl;
                        cout << "x = ";
                        cin >> c;
                        pkt2.set_x(c);
                        cout << endl << "y = ";
                        cin >> d;
                        pkt2.set_y(d);
                        if((pkt1.get_x() == pkt2.get_x()) && (pkt1.get_y() == pkt2.get_y())){
                            cout << "That's a point, not a segment" << endl;
                            safe = false;
                        }else{
                            A = pkt1;
                            B = pkt2;
                            break;
                        }
                }else{
                        A = pkt1;
                        B = pkt2;
                        break;
                }
        }while(safe == true);
*/

/*ZAPASOWA KLASA PUNKTU
class point{
private:
        float x_;
        float y_;
public:
        //point(float x, float y);


        void set_x( float x){
                x_ = x;
        };
        void set_y( float y){
                y_ = y;
        };
        float get_x(){
                return x_;
        };
        float get_y(){
                return y_;
        };

};
point::point(float x, float y){
          x_ = x;
          y_ = y;
}*/
