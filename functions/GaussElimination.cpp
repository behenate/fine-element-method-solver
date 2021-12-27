//
// Created by behen on 27.12.2021.
//
#include "stdio.h"
#include "GaussElimination.h"
float *gaussElimination(int n, float **matrixB, float *matrixL){
//    Make the initial triangle
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
//            Select the multiply factor
            float c = matrixB[j][i] / matrixB[i][i];

//            Multiply each element in the row and the L array by the factor
            for (int k = 0; k < n; ++k) {
                matrixB[j][k] -= c*matrixB[i][k];
            }
            matrixL[j] -= c*matrixL[i];
//            Print for debugging
//            printf("\n");printf("\n");
//            for (int i = 0; i < n; ++i) {
//                for (int j = 0; j < n; ++j) {
//                    printf("%f \t", matrixB[i][j]);
//                }
//                printf("\n");
//            }
        }
    }
    printf("\n");printf("\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("%f \t", matrixB[i][j]);
        }
        printf("\n");
    }
//    Same process as above, just starts from the bottom
    for (int i = n-1; i >= 1; --i) {
        for (int j = i-1; j >= 0; --j) {
            float c = matrixB[j][i] / matrixB[i][i];
            for (int k = 0; k < n; ++k) {
                matrixB[j][k] -= c*matrixB[i][k];
            }
            matrixL[j] -= c*matrixL[i];

        }
    }
//    Get the x multiplications to 1
    for (int i = 0; i < n; ++i) {
        matrixL[i] /= matrixB[i][i];
    }

    return matrixL;
}