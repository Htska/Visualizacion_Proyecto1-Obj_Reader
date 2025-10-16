#ifndef TRIGONOMETRIC_H
#define TRIGONOMETRIC_H

#include "Function.h"

class Trigonometric:public Function
{
public:
    float f(int x, int z) override;
    
    void print() override;
};

#endif