#include <iostream>

using namespace std;

# define M_PIl          3.141592653589793238462643383279502884L /* pi */

class point
{
private:
    float x_;
    float y_;
public:
    point(float x=0, float y=0) //konstruktor
    {
        x_ = x;
        y_ = y;
    }

//SETTERY
    void set_x(float x)
    {
        x_ = x;
    }
    void set_y(float y)
    {
        y_ = y;
    }

//GETTERY

    float get_x()
    {
        return x_;
    }

    float get_y()
    {
        return y_;
    }
};

class circle:public point{
private:
    float r;
    float circuit;
    float area;
public:

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

class polygon{
private:
        size_t sideNum_;
        float radius_, circumference_, area_, innerAngle_;
        float *pointsX_, *pointsY_;
public:
        //------sides--center--vertex
        polygon(size_t, point, point);                  //!

        size_t getSidesNum(void);

        float getRadius(void);

        float getCircumference(void);

        float getArea(void);

        void vertexes(point);                           //!

        bool isPoint(point);                            //!

        ~polygon();
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

class segment{
        private:
                point A;
                point B;

        public:
                segment(point pkt1, point pkt2);
                double lenght();
                void check_point(point other_one);

};

class rectangle{
        private:
                point A;
                point B;

        public:
                rectangle(point pkt1, point pkt2);
                double circuit();
                double area();
                void check_point(point other_one);
};

class ellipse{
private:
        float a_;
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

