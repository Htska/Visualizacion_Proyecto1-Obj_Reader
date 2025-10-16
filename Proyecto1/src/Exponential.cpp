#include "Exponential.h"
#include <iostream>

float Exponential::f(int x, int z){
    float y = exp((x*x)+(z*z));
    return y;
}

void Exponential::print(){
    std::cout<< "La función es: e^(x^2+z^2)\n";
}