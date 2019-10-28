#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include <pbbslib/scheduler.h>

using namespace std;

int reduce(int* A, int n) {
	if (n == 1) return A[0];
	int L, R;
	pardo([&] () {reduce(A, n/2, L);}
	      [&] () {reduce(A+n/2, n-n/2, R);});
	return L+R;
}

int main() {
	int* A = new int[100];
	parfor (0, 100, [&] (int i) {A[i] = i;}); 
	int x = reduce(A, 100);
	cout << x << endl;
	
	return 0;
}