#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <cilk/cilk.h>
#include <cilk/cilk_api.h>
using namespace std;

int reduce(int* A, int n) {
	if (n == 1) return A[0];
	int L, R;
	L = cilk_spawn reduce(A, n/2);
	R = reduce(A+n/2, n-n/2);
	cilk_sync;
	return L+R;
}

int main() {
	int* A = new int[100];
	cilk_for (int i = 0; i < 100; i++) A[i] = i;
	int x = reduce(A, 100);
	cout << x << endl;
	
	return 0;
}