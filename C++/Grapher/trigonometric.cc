#include <iostream>
#include <math.h>
#include "grapher.hpp"

using namespace std;

# define M_PIl          3.141592653589793238462643383279502884L /* pi */

void trigonometric(float* factorTabPointer, size_t factorTabSize, float freeFactor, int* spacePointer, char isModulus_y, char isModulus_x, float plusAngle){
	for(int x = -48; x <= 48; x++){
	        float* y_value = new float;

                //This block calculates 'y' value from given 'x'.
                size_t i = 0;
                while(i < factorTabSize){
                        if((isModulus_x == 'y' || isModulus_x == 'Y') && x < 0){
                                if( i != (factorTabSize - 1)){
                                        float tmp = (*factorTabPointer)*pow(sin(((x*M_PI)/-12) + plusAngle),factorTabSize - i);
                                        *y_value += tmp;
                                        factorTabPointer++;
                                } else {
                                        float tmp = (*factorTabPointer)*pow(sin(((x*M_PI)/-12) + plusAngle),factorTabSize - i);
                                        *y_value += tmp;
                                }
                        } else {
                                if( i != (factorTabSize - 1)){
                                        float tmp = (*factorTabPointer)*pow(sin(((x*M_PI)/12) + plusAngle),factorTabSize - i);
                                        *y_value += tmp;
                                        factorTabPointer++;
                                } else {
                                        float tmp = (*factorTabPointer)*pow(sin(((x*M_PI)/12) + plusAngle),factorTabSize - i);
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

		//Estimates the value and puts it on a chart.
		if(*y_value >= -2.0f && *y_value < -1.8f){         
              		spacePointer = spacePointer + 1940 + (x + 48);
                        *spacePointer = 1;
                	spacePointer = spacePointer - 1940 - (x + 48);
		} else if (*y_value >= -1.8f && *y_value < -1.6f){        
 			spacePointer = spacePointer + 1843 + (x + 48);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 1843 - (x + 48);
		} else if (*y_value >= -1.6f && *y_value < -1.4f){        
 			spacePointer = spacePointer + 1746 + (x + 48);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 1746 - (x + 48);
		} else if (*y_value >= -1.4f && *y_value < -1.2f){        
 			spacePointer = spacePointer + 1649 + (x + 48);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 1649 - (x + 48);
		} else if (*y_value >= -1.2f && *y_value < -1.0f){        
 			spacePointer = spacePointer + 1552 + (x + 48);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 1552 - (x + 48);
		} else if (*y_value >= -1.0f && *y_value < -0.8f){        
 			spacePointer = spacePointer + 1455 + (x + 48);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 1455 - (x + 48);
		} else if (*y_value >= -0.8f && *y_value < -0.6f){        
 			spacePointer = spacePointer + 1358 + (x + 48);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 1358 - (x + 48);
		} else if (*y_value >= -0.6f && *y_value < -0.4f){        
 			spacePointer = spacePointer + 1261 + (x + 48);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 1261 - (x + 48);
		} else if (*y_value >= -0.4f && *y_value < -0.2f){        
 			spacePointer = spacePointer + 1164 + (x + 48);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 1164 - (x + 48);
		} else if (*y_value >= -0.2f && *y_value < -0.0001f){        
 			spacePointer = spacePointer + 1067 + (x + 48);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 1067 - (x + 48);
		} else if (*y_value >= -0.0001f && *y_value <= 0.0001f){        
 			spacePointer = spacePointer + 970 + (x + 48);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 970 - (x + 48);
		} else if (*y_value > 0.0001f && *y_value <= 0.2f){        
 			spacePointer = spacePointer + 873 + (x + 48);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 873 - (x + 48);
		} else if (*y_value > 0.2f && *y_value <= 0.4f){        
 			spacePointer = spacePointer + 776 + (x + 48);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 776 - (x + 48);
		} else if (*y_value > 0.4f && *y_value <= 0.6f){        
 			spacePointer = spacePointer + 679 + (x + 48);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 679 - (x + 48);
		} else if (*y_value > 0.6f && *y_value <= 0.8f){        
 			spacePointer = spacePointer + 582 + (x + 48);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 582 - (x + 48);
		} else if (*y_value > 0.8f && *y_value <= 1.0f){        
 			spacePointer = spacePointer + 485 + (x + 48);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 485 - (x + 48);
		} else if (*y_value > 1.0f && *y_value <= 1.2f){        
 			spacePointer = spacePointer + 388 + (x + 48);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 388 - (x + 48);
		} else if (*y_value > 1.2f && *y_value <= 1.4f){        
 			spacePointer = spacePointer + 291 + (x + 48);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 291 - (x + 48);
		} else if (*y_value > 1.4f && *y_value <= 1.6f){        
 			spacePointer = spacePointer + 194 + (x + 48);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 194 - (x + 48);
		} else if (*y_value > 1.6f && *y_value <= 1.8f){        
 			spacePointer = spacePointer + 97 + (x + 48);
                        *spacePointer = 1;
                        spacePointer = spacePointer - 97 - (x + 48);
		} else if (*y_value > 1.8f && *y_value <= 2.0f){        
 			spacePointer = spacePointer + (x + 48);
                        *spacePointer = 1;
                        spacePointer = spacePointer - (x + 48);
		}

		delete y_value;
	}
}
