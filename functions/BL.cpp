#include <iostream>
#include <math.h>
#include "../headers/BL.h"
#include "../headers/Gaussian_Quadrature.h"

using std::cout;
using std::min;
using std::max;

float L(int i, int n, int a, int b){
	struct FL fl = { i,0,n,a,b};
	return fl.toIntegrateL(0);
}

float B(int i,int j, int n, int a, int b)
{
    float result = 0;
	struct FL fl = { i,j,n,a,b};

	float flOne_s1 = e_a(i, n, a, b, 0);
    float flOne_e1 = e_b(i, n, a, b, 0);

	float flOne_s2 = e_a(i, n, a, b, 1);
	float flOne_e2 = e_b(i, n, a, b, 1);

	float flTwo_s1 = e_a(j, n, a, b, 0);
    float flTwo_e1 = e_b(j, n, a, b, 0);

    float flTwo_s2 = e_a(j, n, a, b, 1);
    float flTwo_e2 = e_b(j, n, a, b, 1);

//    Check crossing of first range of flOne and first range of flTwo
    float range_start = max(flOne_s1,flTwo_s1);
    float range_end = min(flOne_e1, flTwo_e1);
    if (range_end > range_start)
        result +=  -gaussianQuadrature(range_start, range_end, &fl, true) + fl.getOffset(0);

    //    Check crossing of second range of flOne and first range of flTwo
    range_start = max(flOne_s2,flTwo_s1);
    range_end = min(flOne_e2, flTwo_e1);
    if (range_end > range_start)
        result += -gaussianQuadrature(range_start, range_end, &fl, true) + fl.getOffset(0);

    //    Check crossing of first range of flOne and second range of flTwo
    range_start = max(flOne_s1,flTwo_s2);
    range_end = min(flOne_e1, flTwo_e2);
    if (range_end > range_start)
        result += -gaussianQuadrature(range_start, range_end, &fl, true) + fl.getOffset(0);

    //    Check crossing of first range of flOne and second range of flTwo
    range_start = max(flOne_s2,flTwo_s2);
    range_end = min(flOne_e2, flTwo_e2);
    if (range_end > range_start)
        result += -gaussianQuadrature(range_start, range_end, &fl, true) + fl.getOffset(0);

	return result;
}

