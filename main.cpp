#include <iostream>
#include "headers/Gaussian_Quadrature.h"
#include "headers/GaussElimination.h"
#include <math.h>
#include <vector>
#include "headers/BL.h"
#include <fstream>
#include <iostream>
using std::cout;

int main()
{
    int a = 0;
    int b = 2;
    int n = 15;

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
    std::ofstream outfile;
    outfile.open("../result.txt", std::ofstream::out | std::ofstream::trunc);//std::ios_base::app
    float *result = gaussElimination(n, arrayB, arrayL);
    outfile << n;
    outfile <<";";
    outfile << a;
    outfile << ";";
    outfile << b;
    outfile << ";";
    for (int i = 0; i < n; ++i) {
        outfile << result[i];
        if (i != n-1)
            outfile << ";";
        printf("%f ", result[i]);
    }

    outfile.close();
}