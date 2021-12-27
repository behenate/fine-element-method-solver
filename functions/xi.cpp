#include "../headers/xi.h"
float xi(int i, int n, int from, int to) {
	return ((to - from) / (float)n) * i;
}