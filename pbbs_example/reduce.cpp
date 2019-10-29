#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include "pbbslib/utilities.h"

using namespace std;

void reduce(int* A, int n, int& ret) {
	if (n == 1) ret = A[0]; else {
		int L, R;
		par_do([&] () {reduce(A, n/2, L);}, 
	      		[&] () {reduce(A+n/2, n-n/2, R);});
		ret = L+R;
	}
}

int main() {
	int* A = new int[100];
	parallel_for (0, 100, [&] (int i) {A[i] = i;}); 
	int x;
	reduce(A, 100, x);
	cout << x << endl;
	
	return 0;
}
