#include <iostream>
#include "../headers/e.h"
#include "../headers/xi.h"
#include <math.h>
using std::cout;
typedef void (*FuncSig)(float param);

float e_a(int i, int n, int a, int b, int rangeSide) {
	if (rangeSide == 0){
		return xi(i - 1, n, a, b);
	}else
	{
		return xi(i, n, a, b);
	}
}
float e_b(int i, int n, int a, int b, int rangeSide) {
	if (rangeSide == 0) {
		return xi(i, n, a, b);
	}
	else
	{
		return xi(i+1, n, a, b);
	}
}

float e(int i, int n, int a, int b, int rangeSide, float x) {
	if (rangeSide == 0) {
		if (i - 1 < 0) {
			return 0;
		}
		return((x - xi(i - 1, n, a, b)) / (xi(i, n, a, b) - xi(i - 1, n, a, b)));
	}
	else {
		if (i + 1 > n) {
			return 0;
		}
		return (xi(i + 1, n, a, b) - x) / (xi(i + 1, n, a, b) - xi(i, n, a, b));
	}
}

float eDerivative(int i, int n, int a, int b, int rangeSide, float x) {
	if (rangeSide == 0) {
		if (i - 1 < 0) {
			return 0;
		}
		return (1) / (xi(i, n, a, b) - xi(i - 1, n, a, b));
	}
	else {
		if (i + 1 > n) {
			return 0;
		}
		return (-1) / (xi(i + 1, n, a, b) - xi(i, n, a, b));
	}
}