#include <iostream>
#include <math.h>
#include "grapher.hpp"

using namespace std;

void polynomial_1(float* factorTabPointer, size_t factorTabSize, float freeFactor, int* spacePointer, char isModulus_y, char isModulus_x, int ddx){
        for(int x = -10; x <= 10; x++){
                float* y_value = new float;

                //This block calculates 'y' value from given 'x'.
                size_t i = 0;
                while(i < factorTabSize){
			 if((isModulus_x == 'y' || isModulus_x == 'Y') && x < 0){
                       	 	if( i != (factorTabSize - 1)){
                               		float tmp = (*factorTabPointer)*pow(((float)x/-10),factorTabSize - i - ddx);
                                	*y_value += tmp;
                                	factorTabPointer++;
                        	} else {
                                	float tmp = (*factorTabPointer)*pow(((float)x/-10),factorTabSize - i - ddx);
                                	*y_value += tmp;
                         	}
			} else {
                       	 	if( i != (factorTabSize - 1)){
                               		float tmp = (*factorTabPointer)*pow(((float)x/10),factorTabSize - i - ddx);
                                	*y_value += tmp;
                                	factorTabPointer++;
                        	} else {
                                	float tmp = (*factorTabPointer)*pow(((float)x/10),factorTabSize - i - ddx);
                                	*y_value += tmp;
                         	}
			} 
                        i++;
                }

                i = i - factorTabSize + 1;

                *y_value += freeFactor;

		if((isModulus_y =='y' || isModulus_y == 'Y') && *y_value < 0){
			*y_value = *y_value*(-1);
		}

                factorTabPointer = factorTabPointer - (factorTabSize - 1);

                //Estimates the value to an integer from <-1,1> and puts it onto a chart.
                if((*y_value >= -1.0f) && (*y_value < -0.9f)){

                        spacePointer = spacePointer + 420 + (x + 10);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 420 - (x + 10);

		} else if ((*y_value >= -0.9f) && (*y_value < -0.8f)) {

                        spacePointer = spacePointer + 399 + (x + 10);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 399 - (x + 10);

		} else if ((*y_value >= -0.8f) && (*y_value < -0.7f)) {

                        spacePointer = spacePointer + 378 + (x + 10);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 378 - (x + 10);

		} else if ((*y_value >= -0.7f) && (*y_value < -0.6f)) {

                        spacePointer = spacePointer + 357 + (x + 10);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 357 - (x + 10);
             
		} else if ((*y_value >= -0.6f) && (*y_value < -0.5f)) {

                        spacePointer = spacePointer + 336 + (x + 10);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 336 - (x + 10);
                  
		} else if ((*y_value >= -0.5f) && (*y_value < -0.4f)) {
               
                        spacePointer = spacePointer + 315 + (x + 10);
			*spacePointer = 1;
                        spacePointer = spacePointer - 315 - (x + 10);
              
		} else if ((*y_value >= -0.4f) && (*y_value < -0.3f)) {

                        spacePointer = spacePointer + 294 + (x + 10);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 294 - (x + 10);
                  
		} else if ((*y_value >= -0.3f) && (*y_value < -0.2f)) {

                        spacePointer = spacePointer + 273 + (x + 10);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 273 - (x + 10);

		} else if ((*y_value >= -0.2f) && (*y_value < -0.1f)) {

                        spacePointer = spacePointer + 252 + (x + 10);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 252 - (x + 10);
         
		} else if ((*y_value >= -0.1f) && (*y_value < -0.0001f)) {

                        spacePointer = spacePointer + 231 + (x + 10);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 231 - (x + 10);
                             
		} else if ((*y_value >= -0.0001f) && (*y_value < 0.0001f)) {

                        spacePointer = spacePointer + 210 + (x + 10);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 210 - (x + 10);
                              
		} else if ((*y_value > 0.0001f) && (*y_value <= 0.1f)) {
                 
                        spacePointer = spacePointer + 189 + (x + 10);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 189 - (x + 10);
                        
		} else if ((*y_value > 0.1f) && (*y_value <= 0.2f)) {

                        spacePointer = spacePointer + 168 + (x + 10);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 168 - (x + 10);
                       
		} else if ((*y_value > 0.2f) && (*y_value <= 0.3f)) {
                       
                        spacePointer = spacePointer + 147 + (x + 10);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 147 - (x + 10);
                            
		} else if ((*y_value > 0.3f) && (*y_value <= 0.4f)) {
                    
                        spacePointer = spacePointer + 126 + (x + 10);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 126 - (x + 10);
                               
		} else if ((*y_value > 0.4f) && (*y_value <= 0.5f)) {
                     
                        spacePointer = spacePointer + 105 + (x + 10);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 105 - (x + 10);
                            
		} else if ((*y_value > 0.5f) && (*y_value <= 0.6f)) {
                     
                        spacePointer = spacePointer + 84 + (x + 10);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 84 - (x + 10);
                              
		} else if ((*y_value > 0.6f) && (*y_value <= 0.7f)) {
                     
                        spacePointer = spacePointer + 63 + (x + 10);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 63 - (x + 10);
                            
		} else if ((*y_value > 0.7000f) && (*y_value <= 0.8000f)) {
                        
                        spacePointer = spacePointer + 42 + (x + 10);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 42 - (x + 10);
                              
		} else if ((*y_value > 0.8f) && (*y_value <= 0.9f)) {
                       
                        spacePointer = spacePointer + 21 + (x + 10);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 21 - (x + 10);
                              
		} else if ((*y_value > 0.9f) && (*y_value <= 1.0f)) {
                      
                        spacePointer = spacePointer + (x + 10);
                        *spacePointer = 1;
                        spacePointer = spacePointer - (x + 10);
                               
                }

                delete y_value;
        }
}



