#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include "pbbslib/utilities.h"
#include "pbbslib/get_time.h"

using namespace std;


using namespace std;

void scan(int* In, int* Out, int* B, int* C, int n) {
	int i;
    if (n==0) return;
	if (n == 1) {
		Out[0] = In[0];
		return;
	}
    for (i = 0; i < n/2; i++)
    {
        B[i] = In[2*i] + In[2*i+1];
    }	
	
	scan(B, C, B+n/2, C+n/2, n/2);	
	Out[0] = In[0];

    for (i = 1; i < n; i++)
    {
		if (i%2) Out[i] = C[i/2];
		else Out[i] = C[i/2-1] + In[i];
    }	

}


int main(int argc, char** argv) {
	if (argc != 2) {
		cout << "Usage: ./scan [num_elements]" << endl;
		return 0;
	}
	int n = atoi(argv[1]);
	cout << n << endl;
	int* A = new int[n];
	int* B = new int[n];
	int* e1 = new int[n];
	int* e2 = new int[n];
	parallel_for (0, n, [&](int i) {A[i] = i;});
	
	timer t; t.start();
	scan(A, B, e1, e2, n);
	t.stop(); cout << "time: " << t.get_total() << endl;
	
	//for (int i = 0; i < n; i++) cout << B[i] << " ";
	//cout << endl;
	
	return 0;
}