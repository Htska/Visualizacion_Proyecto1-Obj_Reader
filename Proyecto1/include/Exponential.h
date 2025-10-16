#ifndef EXPONENTIAL_H
#define EXPONENTIAL_H

#include "Function.h"

class Exponential:public Function
{
public:
    float f(int x, int z) override;
    
    void print() override;
};

#endif