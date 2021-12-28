#pragma once
#ifndef E_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define E_H

float e(int i, int n, int a, int b, float x);
float eDerivative(int i, int n, int a, int b, float x);
float e_a(int i, int n, int a, int b, int rangeSide);
float e_b(int i, int n, int a, int b, int rangeSide);
#endif