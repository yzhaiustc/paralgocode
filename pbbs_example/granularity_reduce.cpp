#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include "pbbslib/get_time.h"
#include "pbbslib/utilities.h"

using namespace std;

int threshold;

int reduce(int* A, int n) {
    if (n < threshold) {
      int ret = 0;
      for (int i = 0; i < n; i++) ret += A[i];
      return ret;
    }
	int L, R;
	par_do([&] () {L = reduce(A, n/2);}, 
	   		[&] () {R = reduce(A+n/2, n-n/2);});
	return (L+R);
}

int main(int argc, char** argv) {
	if (argc != 3) {
		cout << "Usage: ./reduce [num_elements] [threshold]" << endl;
		return 0;
	}
	int n = atoi(argv[1]);
    threshold = atoi(argv[2]);
	cout << n << " " << threshold << endl;
	int* A = new int[n];
	parallel_for (0, n, [&] (int i) {A[i] = i;}); 
	int x;
	timer t; t.start();
	x = reduce(A, n);
	t.stop();
	cout << "time: " << t.get_total() << endl;
	cout << x << endl;
	delete []A;
	return 0;
}
