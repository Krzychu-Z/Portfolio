#include <iostream>
#include <string.h>
#include <string>
#include <math.h>

# define M_PIl          3.141592653589793238462643383279502884L /* pi */

using namespace std;

class complexCalc{
private:
	float real_;
	float imag_;

	//Used for trigonometric and exponential notation. For instance if the angle is pi/2 then the fraction is 1/2.
	float radius_;
	float fraction_;
public:
	complexCalc(){
		real_ = 0.0f;
		imag_ = 0.0f;
	}

	float getReal(){
		return real_;
	}

	float getImag(){
		return imag_;
	}
	
	void setComplex(float Re, float Im){
		real_ = Re;
		imag_ = Im;
	}

	bool isReal(){
		if(imag_ == 0.0f){
			return true;
		} else {
			return false;
		}
	}

	bool isImag(){
		if(imag_ != 0.0f){
			return true;
		} else {
			return false;
		}
	}

	bool equals(complexCalc num){
		if((real_ == num.getReal()) && (imag_ == num.getImag())){
			return true;
		} else {
			return false;
		}
	}

	void add(complexCalc num){
		real_ += num.getReal();
	        imag_ += num.getImag();	
	}

	void subtract(complexCalc num){
		real_ -= num.getReal();
		imag_ -= num.getImag();
	}

	void multiply(complexCalc num){
		float Re = real_*num.getReal() - imag_*num.getImag();
	        float Im = real_*num.getImag() + imag_*num.getReal();
		real_ = Re;
		imag_ = Im;	
	}

	void divide(complexCalc num){
		if(num.getReal() == 0.0f && num.getImag() == 0.0f){
			cout << "Can't divide by 0" << endl;
		} else {
			float Re = ((real_*num.getReal())+(imag_*num.getImag()))/(pow(num.getReal(),2.0f)+pow(num.getImag(),2.0f));
			float Im = ((imag_*num.getReal())-(real_*num.getImag()))/(pow(num.getReal(),2.0f)+pow(num.getImag(),2.0f));
			real_ = Re;
			imag_ = Im;
		}
	}

	void print(){
		if(imag_ >= 0.0f){
			cout << real_ << "+" << imag_ << "i" << endl;
		} else {
			cout << real_ << "-" << imag_*(-1) << "i" << endl;
		}
	}

	string toString(){
		string number;
		if(imag_ >= 0.0f){
			number = to_string(real_) + "+" + to_string(imag_) + "i";
			return number;
		} else {
			number = to_string(real_) + to_string(imag_) + "i";
			return number;
		}
	}

	void printTrigonometric(){
		radius_ = sqrt(pow(real_,2.0)+pow(imag_,2.0));

		if(real_ == 0.0f && imag_ == 0.0f){
			cout << "Trigonometric notation of 0 + 0i is impossible" << endl;
		} else {
			float cosine = real_/radius_;
			float sine = imag_/radius_;

			if(cosine >= 0.0f && sine >= 0.0f){
				//First quadrant.
				fraction_ = asin(sine)/M_PI;
			} else if ((cosine < 0.0f && sine >= 0.0f) || (cosine < 0.0f && sine < 0.0f)){
				//Second and third quadrant.
				fraction_ = (M_PI - asin(sine))/M_PI;
			} else if (cosine >= 0.0f && sine < 0.0f){
				//Fourth quadrant.
				fraction_ = (2*M_PI + asin(sine))/M_PI;
			}
			cout << radius_ << "*(cos(" << fraction_ << "*pi) + sin(" << fraction_ << "*pi)*i)" << endl;	
		}	
	}
	
	void printExponential(){
		radius_ = sqrt(pow(real_,2.0)+pow(imag_,2.0));

		if(real_ == 0.0f && imag_ == 0.0f){
			cout << "Exponential notation of 0 + 0i is impossible" << endl;
		} else {
			float cosine = real_/radius_;
			float sine = imag_/radius_;

			if(cosine >= 0.0f && sine >= 0.0f){
				//First quadrant.
				fraction_ = asin(sine)/M_PI;
			} else if ((cosine < 0.0f && sine >=0.0f) || (cosine < 0.0f && sine < 0.0f)){
				//Second and third quadrant.
				fraction_ = (M_PI - asin(sine))/M_PI;
			} else if (cosine >= 0.0f && sine < 0.0f){
				//Fourth quadrant.
				fraction_ = (2*M_PI + asin(sine))/M_PI;
			}
			cout << radius_ << "*e^((" << fraction_ << "*pi)*i)" << endl;	
		}	
	}
};

int main(){
	char input = 0;
	complexCalc c1, c2;
	float re1, im1, re2, im2;

[&]{//Lambda to avoid using goto.(Use C++ 11 and later!).
	while((input != 'E') && (input != 'e')){
			cout << "+++++++++++++++++++++++++++++++++++++++++++++++\n\n\n";
			cout << "             The Complex Calc v 1.0            \n\n\n";
			cout << "+++++++++++++++++++++++++++++++++++++++++++++++\n\n";
			cout << "[          (A)dd two complex numbers          ]\n";
			cout << "[       (S)ubtract two complex numbers        ]\n";
			cout << "[       (M)ultiply two complex numbers        ]\n";
			cout << "[        (D)ivide two complex numbers         ]\n";
			cout << "[  (C)heck if two complex numbers are equal   ]\n";
			cout << "[                   (E)xit                    ]\n\n";

			cin >> input;

		if((input != 'E') && (input != 'e')){
			cout << "Insert real part of the first number:" << endl;
			cin >> re1;
			if( cin.fail() ){
            			cout << "Looks like you didn't input a number. This was like avada kedavra to this app, so we had to";
			        cout << " terminate it before muggles get too suspicious." << endl;
				cout << "With regards - Ministry of Magic" << endl << endl;
            			cin.clear();
           		        cin.sync();
				return;
        		}
			cout << "Insert imaginary part of the first number:" << endl;
			cin >> im1;
			if( cin.fail() ){
            			cout << "Looks like you didn't input a number. This was like avada kedavra to this app, so we had to";
			        cout << " terminate it before muggles get too suspicious." << endl;
				cout << "With regards - Ministry of Magic" << endl << endl;
            			cin.clear();
           		        cin.sync();
				return;
        		}
			cout << "Insert real part of the second number:" << endl;
			cin >> re2;
			if( cin.fail() ){
            			cout << "Looks like you didn't input a number. This was like avada kedavra to this app, so we had to";
			        cout << " terminate it before muggles get too suspicious." << endl;
				cout << "With regards - Ministry of Magic" << endl << endl;
            			cin.clear();
           		        cin.sync();
				return;
        		}
			cout << "Insert imaginary part of the second number:" << endl;
			cin >> im2;
			if( cin.fail() ){
            			cout << "Looks like you didn't input a number. This was like avada kedavra to this app, so we had to";
			        cout << " terminate it before muggles get too suspicious." << endl;
				cout << "With regards - Ministry of Magic" << endl << endl;
           			cin.clear();
           		        cin.sync();
				return;
        		}

			c1.setComplex(re1, im1);
			c2.setComplex(re2, im2);
			cout << "\nFirst number: "; 
			c1.print();
	       		cout << "Second number: "; 
			c2.print(); 
			cout << endl;

			bool c1Test = c1.isImag();
			bool c2Test = c2.isImag();
			if(c1Test){
				cout << "First number is a complex number." << endl;
			} else {
				cout << "First number is a real number." << endl;
			}
			if(c2Test){
				cout << "Second number is a complex number." << endl;
			} else {
				cout << "Second number is a real number." << endl;
			}
		}

		if((input == 'A') || (input == 'a')){
			c1.add(c2);
			cout << "\nSum of two complex numbers\nAlgebraic notation: ";
		       	c1.print(); 
			cout << endl;
			cout << "Trigonometric notation: ";
		       	c1.printTrigonometric(); 
			cout << endl;
			cout << "Exponential notation: ";
		       	c1.printExponential();
			cout << endl;
//			cout << "Test string: "<< c1.toString() << endl;	
		} else if ((input == 'S') || (input == 's')){
			c1.subtract(c2);
			cout << "\nSubtraction of two complex numbers\nAlgebraic notation: "; 
			c1.print();
			cout << endl;
			cout << "Trigonometric notation: ";
		       	c1.printTrigonometric();
		       	cout << endl;
			cout << "Exponential notation: ";
		       	c1.printExponential(); 
			cout << endl;
		} else if ((input == 'M') || (input == 'm')){
			c1.multiply(c2);
			cout << "\nMultiplication of two complex numbers\nAlgebraic notation: ";
		       	c1.print();
		       	cout << endl;
			cout << "Trigonometric notation: ";
			c1.printTrigonometric();
		       	cout << endl;
			cout << "Exponential notation: ";
		       	c1.printExponential();
		       	cout << endl;
		} else if ((input == 'D') || (input == 'd')){
			c1.divide(c2);
			cout << "\nDivision of two complex numbers\nAlgebraic notation: ";
		       	c1.print(); 
			cout << endl;
			cout << "Trigonometric notation: ";
		       	c1.printTrigonometric();
		       	cout << endl;
			cout << "Exponential notation: ";
		       	c1.printExponential(); 
			cout << endl;
		} else if ((input == 'C') || (input == 'c')){
			bool test = c1.equals(c2);
			if(test){
				cout << "Both numbers are equal." << endl;
			} else {
				cout << "Both numbers are not equal." << endl; 
			}
		} else if ((input == 'E') || (input == 'e')){
			//do nothing.
		} else {
			cout << "Command unknown. Please try again." << endl;
		}
	}
}();//end of lambda

return 0;
}
