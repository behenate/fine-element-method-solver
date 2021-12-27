#include "BL.h"
#pragma once
#ifndef GAUSSIAN_H    // To make sure you don't declare the function more than once by including the header multiple times.
#define GAUSSIAN_H

float gaussianQuadrature(float a, float b, FL *f, bool isB);

#endif