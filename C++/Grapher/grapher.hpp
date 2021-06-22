#include <iostream>
#include <string>

#define M_PIl          3.141592653589793238462643383279502884L /* pi */

void drawChart(int* spaceDrawer);
void drawTrigChart(int* spaceDrawer);
std::string quote();
void polynomial_10(float* factorTabPointer, size_t factorTabSize, float freeFactor, int* spacePointer, char isModulus_y, char isModulus_x, int ddx);
void polynomial_1(float* factorTabPointer, size_t factorTabSize, float freeFactor, int* spacePointer, char isModulus_y, char isModulus_x, int ddx);
void trigonometric(float* factorTabPointer, size_t factorTabSize, float freeFactor, int* spacePointer, char isModulus_y, char isModulus_x, float plusAngle);
void polyDerivative(float* factorTabPointer, size_t factorTabSize);
