#include <iostream>
#include "headers/GaussElimination.h"
#include <math.h>
#include <vector>
#include <fstream>
#include "BL.h"
using std::cout;

int main()
{
    int a = 0;
    int b = 2;
    int n = 500;

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

    float *result = gaussElimination(n, arrayB, arrayL);
    for (int i = 0; i < n; ++i) {
        printf("%f ", result[i]);
    }


    std::ofstream outfile;
    outfile.open("../result.txt", std::ofstream::out | std::ofstream::trunc);//std::ios_base::app
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

    system("cd .. & python graph.py");
}