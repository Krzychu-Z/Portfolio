#include <iostream>
#include <math.h>

using namespace std;

class Vector{
private:
	size_t dimension_;
	double *data_;
public:
	Vector(double);

	Vector(double, double);

	Vector(double, double, double);

	Vector(const Vector &copy);

	double length();

	size_t getDimension();

	void setArray(size_t, double);

//	double getArray(size_t);

	void showVector();

//	Vector operator+(const Vector&);

	//Override vector with result of operation on different vectors(e.g '+')
//	Vector operator=(const Vector&);

	~Vector();
};

Vector::Vector(double x){
	dimension_ = 1;
	data_ = new double[dimension_];

	data_[0] = x;
}

Vector::Vector(double x, double y){
	dimension_ = 2;
	data_ = new double[dimension_];

	data_[0] = x;
	data_[1] = y;
}

Vector::Vector(double x, double y, double z){
	dimension_ = 3;
	data_ = new double[dimension_];

	data_[0] = x;
	data_[1] = y;
	data_[2] = z;
}

double Vector::length(){
	double tmp = 0;
	for(size_t i = 0; i < dimension_; i++){
		tmp += pow(data_[i], 2.0);
	}

	return sqrt(tmp);
}

size_t Vector::getDimension(){
	return dimension_;
}

void Vector::setArray(size_t position, double value){
	data_[position] = value;
}

/*
double Vector::getArray(size_t position){
	return data_[position];
}
*/

void Vector::showVector(){
	cout << "[";
	for(size_t i = 0 ; i < dimension_; i++){
		cout << data_[i] << ", ";
	}
	cout << "]" << endl;
}

/*
Vector Vector::operator+(const Vector &right){
	if((this -> dimension_ == 1) && (right.dimension_ == 1)){
		Vector result(0.0);
		Vector *ptr = &result;

		for(size_t i = 0; i < 1; i++){
			double tmp;
			tmp = (this -> data_[i]) + right.data_[i];
			result.setArray(i, tmp);
		}

		return *ptr;
	} else if((this -> dimension_ == 2) && (right.dimension_ == 2)){
		Vector result(0.0, 0.0);
		Vector *ptr = &result;

		for(size_t i = 0; i < 2; i++){
			double tmp;
			tmp = (this -> data_[i]) + right.data_[i];
			result.setArray(i, tmp);
		}

		return *ptr;
	} else if((this -> dimension_ == 3) && (right.dimension_ == 3)){
		Vector result(0.0, 0.0, 0.0);
		Vector *ptr = &result;

		for(size_t i = 0; i < 3; i++){
			double tmp;
			tmp = (this -> data_[i]) + right.data_[i];
			result.setArray(i, tmp);
		}

		return *ptr;
	} else {
		Vector result(0.0, 0.0, 0.0);
		Vector *ptr = &result;
		cout << "Operation illegal!" << endl;
		return *ptr;
	}
}

Vector Vector::operator=(const Vector &right){
	if((this -> dimension_) == (right.dimension_)){
		for(size_t i = 0; i < dimension_; i++){
			this -> data_[i] = right.data_[i];
		}
	} else {
		cout << "Operation illegal!" << endl;
	}
}

*/

Vector::~Vector(){
	cout << "removed" << endl;
	delete[] data_;
}

int main(){

	Vector e(1.0, 1.0, 1.0);
	Vector a(2.0, 5.0, -7.0);
//	Vector b(1.0, 0.0, 0.0);


	a.showVector();
	e.showVector();
//	(e + a).showVector();
//	b.showVector();

return 0;
}
