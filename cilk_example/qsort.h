#include "scan.h"
using namespace std;

void qsort(int* A, int start, int end) {
	cout << "from " << start << " to " << end << endl;
	if (start == end) return;
	if (start == end-1) return;
	int pivot = A[start];
	int* A2 = new int[end-start];
	int* B = new int[end-start];
	int* F = new int[end-start];
	int* e1 = new int[end-start];
	int* e2 = new int[end-start];
	for (int i = start; i < end; i++) {
		A2[i] = A[i];
		cout << A[i] << " ";
	}
	cout << endl;
	
	cilk_for (int i = start; i < end; i++) {
		if (A2[i] < pivot) F[i-start] = 1; else F[i-start] = 0;
	}
	scan(F, B, e1, e2, end-start);
	cout << "scan1 ok" << endl;

	for (int i = start; i < end; i++) {
		cout << B[i-start] << " ";
	}
	cout << endl;
	
	cilk_for (int i = start+1; i < end; i++) {
		if (F[i-start]) A[start+B[i-start]-1] = A2[i];
	}
	
	int x = B[end-start-1];
	cout << "x = " << x << endl;
	A[start+x] = pivot;

	cilk_for (int i = start+1; i < end; i++) {
		if (A2[i] >= pivot) F[i-start] = 1; else F[i-start] = 0;
	}
	scan(F, B, e1, e2, end-start);
	cout << "scan2 ok" << endl;
	
	cilk_for (int i = start+1; i < end; i++) {
		if (F[i-start]) A[start+x+B[i-start]] = A2[i];
	}	
	
	cout << "After filter: " << endl;
	for (int i = start; i < end; i++) {
		cout << A[i] << " ";
	}
	cout << endl;
	
	cilk_spawn
	qsort(A, start, start+x);
	qsort(A, start+x+1, end);
	cilk_sync;
	
	return;
}