#include <iostream>
#include "../headers/e.h"
#include "../headers/xi.h"
#include <math.h>
using std::cout;
typedef void (*FuncSig)(float param);

float e_a(int i, int n, int a, int b, int rangeSide) {
	if (rangeSide == 0 && i-1 >= 0){
		return xi(i - 1, n, a, b);
	}else if(i <= n)
	{
		return xi(i, n, a, b);
	}else{
        return -1000;
    }
}
float e_b(int i, int n, int a, int b, int rangeSide) {
	if (rangeSide == 0) {
		return xi(i, n, a, b);
	}
	else if (i+1 <= n)
	{
		return xi(i+1, n, a, b);
	}else{
        return -1000;
    }
}

float e(int i, int n, int a, int b, float x) {
    if (i-1 >=0 && x >= xi(i-1, n,a,b) && x <= xi(i,n,a,b)){
        return((x - xi(i - 1, n, a, b)) / (xi(i, n, a, b) - xi(i - 1, n, a, b)));
    }else if (i+1 <=n && x >= xi(i, n,a,b) && x <= xi(i+1,n,a,b)){
		return (xi(i + 1, n, a, b) - x) / (xi(i + 1, n, a, b) - xi(i, n, a, b));
	}else{
        return 0;
    }
}

float eDerivative(int i, int n, int a, int b, float x) {
    if (i-1 >=0 && x >= xi(i-1, n,a,b) && x <= xi(i,n,a,b)){
        return (1) / (xi(i, n, a, b) - xi(i - 1, n, a, b));
    }else if (i+1 <=n && x >= xi(i, n,a,b) && x <= xi(i+1,n,a,b)){
        return (-1) / (xi(i + 1, n, a, b) - xi(i, n, a, b));
    }else{
        return 0;
    }
}