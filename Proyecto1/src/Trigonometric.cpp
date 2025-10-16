#include "Trigonometric.h"
#include <iostream>

float Trigonometric::f(int x, int z){
    float y = cos(x)+sin(z);
    return y;
}

void Trigonometric::print(){
    std::cout<< "La función es: f(x,z)= cos(x)+sin(z);\n";
}