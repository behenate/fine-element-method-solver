#include <iostream>
#include "headers/GaussElimination.h"
#include <math.h>
#include <vector>
#include <fstream>
#include "BL.h"
using std::cout;
using std::cin;
int main()
{
    cout << "Enter n: ";
    int a = 0;
    int b = 2;
    int n = 50;
    cin >> n;
    float **arrayB;
    arrayB = new float *[n];
    for (int i = 0; i < n; ++i) {
        arrayB[i] = new float[n];
    }


    float arrayL[n];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
//            always calculate the only 3 relevant values, rest is zeroes
            if (abs(i-j) < 2){
                arrayB[i][j] = B(i,j,n,a,b);
            }else{
                arrayB[i][j] = 0;
            }

        }
        arrayL[i] = L(i, n, a, b);
//        printf("%f \n", ((float)i)/(float)n);
    }
//    printf("\n");
//    for(int i; i<n; ++i){
//        printf("%f ", arrayL[i]);
//    }
//    printf("\n");

//    for (int i = 0; i < n; ++i) {
//        for (int j = 0; j < n; ++j) {
//            printf("%f ", arrayB[i][j]);
//        }
//        printf("\n");
//    }
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
    }

    outfile.close();

    system("python ../graph.py");
}