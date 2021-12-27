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
	int side_i;
    int side_j;
	float functionInsideL(float x) {
		return x * e(i, n, a, b, side_i, x);
	}
	float functionInsideB(float x) {
		return eDerivative(i, n, a, b, side_i, x) * eDerivative(j, n, a, b, side_j, x);
	}
};

#endif