#include "e.h"
#include <stdio.h>
#pragma once
#ifndef BL_H
#define BL_H
using std::cout;
float L(int i, int n, int a, int b);
float B(int i, int j, int n, int a, int b);
// Structure for storing e dependent functions inside L and B
struct FL
{
    int i;
    int j;
    int n;
    int a;
    int b;
    float toIntegrateL(float x) {
        return 20 * e(i, n, a, b, 0);
    }
    float toIntegrateB(float x) {
        return eDerivative(i, n, a, b, x) * eDerivative(j, n, a, b, x);
    }
    float getOffset(float x){
        return e(i,n,a,b,x) * e(j,n,a,b,x);
    }
};


#endif