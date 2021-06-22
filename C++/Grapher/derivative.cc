#include <iostream>
#include <math.h>
#include "grapher.hpp"

using namespace std;


void polyDerivative(float* factorTabPointer, size_t factorTabSize){
		for(size_t i = 0; i < factorTabSize; i++){
			*factorTabPointer = (*factorTabPointer)*(factorTabSize - i);
			factorTabPointer++;
		}

        	factorTabPointer = factorTabPointer - (factorTabSize - 1);
}
