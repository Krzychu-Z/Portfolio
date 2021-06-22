#include <iostream>
#include <math.h>
#include <unistd.h>
#include "grapher.hpp"

using namespace std;

//-------------- Reads factors from array - Reads factors' array size - Free factor - Pointer to chart position - y =|f(x)|
void polynomial_10(float* factorTabPointer, size_t factorTabSize, float freeFactor, int* spacePointer, char isModulus_y, char isModulus_x, int ddx){
	for(int x = -10; x <= 10; x++){
		float* y_value = new float; 

		//This block calculates 'y' value from given 'x'.
		size_t i = 0;
		while(i < factorTabSize){
			if((isModulus_x == 'y' || isModulus_x == 'Y') && x < 0){
				if( i != (factorTabSize - 1)){
					float tmp = (*factorTabPointer)*pow(x*(-1),factorTabSize - i - ddx);
					*y_value += tmp;
					factorTabPointer++;
				} else {
					float tmp = (*factorTabPointer)*pow(x*(-1),factorTabSize - i - ddx);
					*y_value += tmp;
				}
			} else {
				if( i != (factorTabSize - 1)){
					float tmp = (*factorTabPointer)*pow(x,factorTabSize - i - ddx);
					*y_value += tmp;
					factorTabPointer++;
				} else {
					float tmp = (*factorTabPointer)*pow(x,factorTabSize - i - ddx);
					*y_value += tmp;
				}
			}
			i++;
		}

		i = i - factorTabSize + 1;

		*y_value += freeFactor;

		//if y = |f(x)|
		if((isModulus_y == 'y' || isModulus_y == 'Y') && *y_value < 0){
			*y_value = *y_value*(-1);
		}

		factorTabPointer = factorTabPointer - (factorTabSize - 1);

		//Estimates the value to an integer from <-10,10> and puts it onto a chart.
		switch ((int)*y_value){
			case -10:
				spacePointer = spacePointer + 420 + (x + 10);
				*spacePointer = 1;
				spacePointer = spacePointer - 420 - (x + 10);
				break;
			case -9:
				spacePointer = spacePointer + 399 + (x + 10);
				*spacePointer = 1;
				spacePointer = spacePointer - 399 - (x + 10);
				break;
			case -8:
				spacePointer = spacePointer + 378 + (x + 10);
				*spacePointer = 1;
				spacePointer = spacePointer - 378 - (x + 10);
				break;
			case -7:
				spacePointer = spacePointer + 357 + (x + 10);
				*spacePointer = 1;
				spacePointer = spacePointer - 357 - (x + 10);
				break;
			case -6:
				spacePointer = spacePointer + 336 + (x + 10);
				*spacePointer = 1;
				spacePointer = spacePointer - 336 - (x + 10);
				break;
			case -5:
				spacePointer = spacePointer + 315 + (x + 10);
				*spacePointer = 1;
				spacePointer = spacePointer - 315 - (x + 10);
				break;
			case -4:
				spacePointer = spacePointer + 294 + (x + 10);
				*spacePointer = 1;
				spacePointer = spacePointer - 294 - (x + 10);
				break;
			case -3:
				spacePointer = spacePointer + 273 + (x + 10);
				*spacePointer = 1;
				spacePointer = spacePointer - 273 - (x + 10);
				break;
			case -2:
				spacePointer = spacePointer + 252 + (x + 10);
				*spacePointer = 1;
				spacePointer = spacePointer - 252 - (x + 10);
				break;
			case -1:
				spacePointer = spacePointer + 231 + (x + 10);
				*spacePointer = 1;
				spacePointer = spacePointer - 231 - (x + 10);
				break;
			case 0:
				spacePointer = spacePointer + 210 + (x + 10);
				*spacePointer = 1;
				spacePointer = spacePointer - 210 - (x + 10);
				break;
			case 1:
				spacePointer = spacePointer + 189 + (x + 10);
				*spacePointer = 1;
				spacePointer = spacePointer - 189 - (x + 10);
				break;
			case 2:
				spacePointer = spacePointer + 168 + (x + 10);
				*spacePointer = 1;
				spacePointer = spacePointer - 168 - (x + 10);
				break;
			case 3:
				spacePointer = spacePointer + 147 + (x + 10);
				*spacePointer = 1;
				spacePointer = spacePointer - 147 - (x + 10);
				break;
			case 4:
				spacePointer = spacePointer + 126 + (x + 10);
				*spacePointer = 1;
				spacePointer = spacePointer - 126 - (x + 10);
				break;
			case 5:
				spacePointer = spacePointer + 105 + (x + 10);
				*spacePointer = 1;
				spacePointer = spacePointer - 105 - (x + 10);
				break;
			case 6:
				spacePointer = spacePointer + 84 + (x + 10);
				*spacePointer = 1;
				spacePointer = spacePointer - 84 - (x + 10);
				break;
			case 7:
				spacePointer = spacePointer + 63 + (x + 10);
				*spacePointer = 1;
				spacePointer = spacePointer - 63 - (x + 10);
				break;
			case 8:
				spacePointer = spacePointer + 42 + (x + 10);
				*spacePointer = 1;
				spacePointer = spacePointer - 42 - (x + 10);
				break;
			case 9:
				spacePointer = spacePointer + 21 + (x + 10);
				*spacePointer = 1;
				spacePointer = spacePointer - 21 - (x + 10);
				break;
			case 10:
				spacePointer = spacePointer + (x + 10);
				*spacePointer = 1;
				spacePointer = spacePointer - (x + 10);
				break;
		}

		delete y_value;
	}
}

int main(){

	int cspace[441] = { 0 };
	int* cPointer = &cspace[0];
	int cspaceClose[441] = { 0 };
	int* cPointerClose = &cspaceClose[0];

	int trigSpace[2037] = { 0 };
	int* trigSpacePointer = &trigSpace[0];

	size_t deg;
	float tmpParam;//Parameter input
	char coverY, coverX;
	int choice;

	cout << "======================================================================================================"<< endl;
	cout << " 				     _____             _                                               "<< endl;
        cout << "				    |   __|___ ___ ___| |_ ___ ___                                     "<< endl;
        cout << "	   			    |  |  |  _| .'| . |   | -_|  _|                                    "<< endl;
        cout << "				    |_____|_| |__,|  _|_|_|___|_|                                      "<< endl;
        cout << "				                  |_|                                                  "<< endl;                      cout << quote() << endl;
	cout << "======================================================================================================"<< endl;
	cout << "                              Choose which function type you want to see:                             "<< endl;
 	cout << "                          [polynomials -> 0][trigonometric polynomials -> 1]	                       "<< endl;
	cin >> choice;

	if(choice == 0){
		cout << "Enter a degree of your polynomial: ";
		cin >> deg;

		//Array that holds factors of a polynomial (factorTab) and array that holds data about absolute value operations (modulusTab).
		float* factorTab = (float*)calloc(deg, sizeof(float));

		cout << "Is your polynomial of y = |f(x)| type? (y/n): ";
		cin >> coverY;
		cout << "Is your polynomial of y = f(|x|) type? (y/n): ";
		cin >> coverX;

		for (size_t i = 0; i < deg; i++){
			cout << "Enter parameter that stands by " << deg - i << " th/rd/nd/st power: ";
			cin >> tmpParam;
			factorTab[i] = tmpParam;
		}

		float real;

		cout << "Enter free factor. (real value that is added to a polynomial): ";
		cin >> real;

		polynomial_10(factorTab, deg, real, cPointer, coverY, coverX, 0);
		polynomial_1(factorTab, deg, real, cPointerClose, coverY, coverX, 0);

		char deriveMe;

		cout << "Do you wish to see the derivative of this function? (y/n): ";
		cin >> deriveMe;

		cout << "\n";
		cout <<"Here's your all bright and shiny chart of a polynomial. Horizontal axis represents x-axis, vertical represents y-axis"<< endl;
		cout << "Each # mark is a unit (1 or 0.1) on an axis. Each @ represents estimated value of a polynomial." << endl << endl; 
		cout << "======================================================================================================"<< endl;
		cout << "Function from -10 to 10:" << endl;

		drawChart(cPointer);
		usleep(2000000);

		cout << "\n";
		cout << "======================================================================================================"<< endl;
		cout << "Function from -1 to 1:" << endl;

		drawChart(cPointerClose);
		usleep(2000000);

		for (size_t i = 0; i < 440; i++){
			cspace[i] = 0;
			cspaceClose[i] = 0;
		}

		if(deriveMe == 'y' || deriveMe == 'Y'){
			if((coverY == 'n') && (coverX == 'n')){
				polyDerivative(factorTab, deg);
				polynomial_10(factorTab, deg, 0, cPointer, coverY, coverX, 1);
				polynomial_1(factorTab, deg, 0, cPointerClose, coverY, coverX, 1);
				cout << "\n";
				cout << "======================================================================================================"<< endl;
				cout << "Derivative of this function from -10 to 10:" << endl;

				drawChart(cPointer);
				usleep(2000000);
		
				cout << "\n";
				cout << "======================================================================================================"<< endl;
				cout << "Derivative of this function from -1 to 1:" << endl;

				drawChart(cPointerClose);
				usleep(2000000);
			} else {
				cout << "\n";
				cout << "======================================================================================================"<< endl;
				cout << "There is no single derivative function that can describe this function :/" << endl;
			}
		}

		free(factorTab);
	} else if (choice == 1){
		cout << "Enter a degree of your trigonometric polynomial: ";
		cin >> deg;

		//Array that holds factors of a polynomial (factorTab) and array that holds data about absolute value operations (modulusTab).
		float* factorTab = (float*)calloc(deg, sizeof(float));

		cout << "Is your polynomial of y = |f(x)| type? (y/n): ";
		cin >> coverY;
		cout << "Is your polynomial of y = f(|x|) type? (y/n): ";
		cin >> coverX;

		for (size_t i = 0; i < deg; i++){
			cout << "Enter parameter that stands by " << deg - i << " th/rd/nd/st power: ";
			cin >> tmpParam;
			factorTab[i] = tmpParam;
		}

		float real;
		float multi, division, angle;
		char piNum;

		cout << "Enter free factor. (real value that is added to a polynomial): ";
		cin >> real;

		cout << "Enter angle that is added to every argument of your sin(x) function e.g. pi/2 -> '1 P 2', 2*pi: -> '2 P 1': ";
		cin >> multi >> piNum >> division;

		angle = (multi * M_PI)/division;

		trigonometric(factorTab, deg, real, trigSpacePointer, coverY, coverX, angle);

		cout << "\n";
		cout << "A Python in it's own! Beautiful trigonometric polynomial chart! ";
		cout << "Each # mark is equal to pi/12. 2 is representation of 2pi. " << endl;
	        cout << "Each @ represents estimated value of a polynomial. Horizontal axis represents x-axis, vertical y-axis."<< endl;
		
		drawTrigChart(trigSpacePointer);
	
		free(factorTab);
	} else {
		return 0;
	}

	cout << "\n" << endl;
	cout << "======================================================================================================"<< endl;
	cout << "             											       "<< endl;
	cout << "              			      Thank you! I hope I helped a bit		                       "<< endl;
	cout << "             											       "<< endl;
	cout << "======================================================================================================"<< endl;
return 0;
}
