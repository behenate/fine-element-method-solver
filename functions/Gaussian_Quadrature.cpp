#include <iostream>
#include "../headers/Gaussian_Quadrature.h"
#include <math.h>
#include "../headers/BL.h"
using std::cout;



float gaussianQuadrature(float a, float b, FL *f, bool isB){
	// predefined points for gaussian quadrature
	float points[3] = { -0.774597, 0, 0.774597 };
	float weights[3] = { 0.555556, 0.888889, 0.555556 };
	// change the side_i from https://en.wikipedia.org/wiki/Gaussian_quadrature, paragraph "change of side_i"
	float sum = 0;
	for (int i = 0; i < 3; i++)
	{
		float normalized_point = points[i] * ((b - a) / 2) + ((a + b) / 2);
		if (isB)
		{
			sum += f->functionInsideB(normalized_point) * weights[i];
		}
		else {
			sum += f->functionInsideL(normalized_point) * weights[i];
		}
	}
	sum = ((b - a) / 2) * sum;
	return sum;
}


