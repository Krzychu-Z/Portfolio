#include <iostream>

using namespace std;

//1.
class mojWektor{
private:
	float x_;
	float y_;
public:
	mojWektor(float, float); 

	float getX();

	float getY();

	void setX(float);

	void setY(float);

	void print();

	mojWektor operator+(const mojWektor&);

	mojWektor operator-(const mojWektor&);
	
	mojWektor operator*(const float&);
};

//Basic elements of c++ class
mojWektor::mojWektor(float x = 0.0f, float y = 0.0f){
	x_ = x;
	y_ = y;
}

float mojWektor::getX(){
	return x_;
}

float mojWektor::getY(){
	return y_;
}

void mojWektor::setX(float x){
	x_ = x;
}

void mojWektor::setY(float y){
	y_ = y;
}

void mojWektor::print(){
	cout << "[" << x_ << ", " << y_ << "]" << endl;
}

//2. operator+
mojWektor mojWektor::operator+(const mojWektor &right){
	//By default assigns with [0,0]
	mojWektor result;

	result.setX((this -> getX()) + (right.x_));
	result.setY((this -> getY()) + (right.y_));

	return result;
}

//3. operator-
mojWektor mojWektor::operator-(const mojWektor &right){
	//By default assigns with [0,0]
	mojWektor result;

	result.setX((this -> getX()) - (right.x_));
	result.setY((this -> getY()) - (right.y_));

	return result;
}

//4. operator*
//e.g vector*const ONLY!
mojWektor mojWektor::operator*(const float &right){
	//By default assigns with [0,0]
	mojWektor result;

	result.setX((this -> getX()) * right);
	result.setY((this -> getY()) * right);

	return result;
}

int main(){

	//5. Calculator
	float firstX, firstY, secondX, secondY;
	int input;

	cout << "         2D Vector Calculator          " << endl << endl;
	cout << "         (1). Add two vectors          " << endl;
	cout << "       (2). Subtract two vectors       " << endl;
	cout << "    (3). Multiply vector by constant   " << endl;

	cin >> input;

	//Each cin is secured from typing in e.g char or something that could potentially crash the app.
	if(cin.fail()){
		cout << "Error. Typed in something different than a number" << endl;
	       	return 0;
	}

	if(input == 1){
		cout << "First vector's 'x': ";
		cin >> firstX;
		if(cin.fail()){
			cout << "Error. Typed in something different than a number" << endl;
	       		return 0;
		}

		cout << "First vector's 'y': ";
		cin >> firstY;
		if(cin.fail()){
			cout << "Error. Typed in something different than a number" << endl;
	       		return 0;
		}

		cout << "Second vector's 'x': ";
		cin >> secondX;
		if(cin.fail()){
			cout << "Error. Typed in something different than a number" << endl;
	       		return 0;
		}

		cout << "Second vector's 'y': ";
		cin >> secondY;
		if(cin.fail()){
			cout << "Error. Typed in something different than a number" << endl;
	       		return 0;
		}

		mojWektor u(firstX, firstY);
		mojWektor v(secondX, secondY);

		cout << "\nYour first vector: ";
		u.print();
		cout << "Your second vector: ";
		v.print();

		cout << "\nThe result of adding those two vectors: ";
		(u + v).print();
	} else if(input == 2){
		cout << "NOTE! Calculator here does: first vector - second vector" << endl;
		cout << "First vector's 'x': ";
		cin >> firstX;
		if(cin.fail()){
			cout << "Error. Typed in something different than a number" << endl;
	       		return 0;
		}

		cout << "First vector's 'y': ";
		cin >> firstY;
		if(cin.fail()){
			cout << "Error. Typed in something different than a number" << endl;
	       		return 0;
		}

		cout << "Second vector's 'x': ";
		cin >> secondX;
		if(cin.fail()){
			cout << "Error. Typed in something different than a number" << endl;
	       		return 0;
		}

		cout << "Second vector's 'y': ";
		cin >> secondY;
		if(cin.fail()){
			cout << "Error. Typed in something different than a number" << endl;
	       		return 0;
		}

		mojWektor u(firstX, firstY);
		mojWektor v(secondX, secondY);

		cout << "\nYour first vector: ";
		u.print();
		cout << "Your second vector: ";
		v.print();

		cout << "\nThe result of subtracting from first vector second vector: ";
		(u - v).print();
	} else if(input == 3){
		float real;
		cout << "Vector's 'x': ";
		cin >> firstX;
		if(cin.fail()){
			cout << "Error. Typed in something different than a number" << endl;
	       		return 0;
		}

		cout << "Vector's 'y': ";
		cin >> firstY;
		if(cin.fail()){
			cout << "Error. Typed in something different than a number" << endl;
	       		return 0;
		}

		cout << "Constant that you want to multiply your vector by: ";
		cin >> real;
		if(cin.fail()){
			cout << "Error. Typed in something different than a number" << endl;
	       		return 0;
		}

		mojWektor u(firstX, firstY);

		cout << "\nYour first vector: ";
		u.print();

		cout << "\nThe result of multiplying vector by a constant: ";
		(u*real).print();
	} else {
		cout << "Error. Wrong number passed. Use numbers: 1,2,3 only!" << endl;
	}

return 0;
}
