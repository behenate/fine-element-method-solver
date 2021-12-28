#include <iostream>
#include "headers/Gaussian_Quadrature.h"
#include "headers/GaussElimination.h"
#include <math.h>
#include "headers/BL.h"
using std::cout;

int main()
{
    int a = 0;
    int b = 2;
    int n = 3;

    float **arrayB;
    arrayB = new float *[n];
    for (int i = 0; i < n; ++i) {
        arrayB[i] = new float[n];
    }


    float arrayL[n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            arrayB[i][j] = B(i,j,n,a,b);
        }
        arrayL[i] = L(i, n, a, b);
    }
//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            printf("%f \t", arrayB[i][j]);
//        }
//        printf("\n");
//    }
//    printf("\n \n");
//    for (int i = 0; i < n; ++i) {
//        printf("%f \n", arrayL[i]);
//    }

    float *result = gaussElimination(n, arrayB, arrayL);
    for (int i = 0; i < n; ++i) {
        printf("%f ", result[i]);
    }


}