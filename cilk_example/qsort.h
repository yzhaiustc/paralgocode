#include "scan.h"

void qsort(int* A, int start, int end) {
	if (start == end) return;
	if (start == end-1) return;
	int pivot = A[start];
	int* A2 = new int[end-start];
	int* B = new int[end-start];
	int* F = new int[end-start];
	int* e1 = new int[end-start];
	int* e2 = new int[end-start];
	cilk_for (int i = start; i < end; i++) {
		A2[i] = A[i];
	}
	
	cilk_for (int i = start; i < end; i++) {
		if (A2[i] < pivot) F[i-start] = 1; else F[i-start] = 0;
	}
	scan(F, B, e1, e2, end-start);
	
	cilk_for (int i = start; i < end; i++) {
		if (F[i-start]) A[B[i-start]-1] = A2[i];
	}
	
	int x = F[end-start];
	A[x] = pivot;

	cilk_for (int i = start; i < end; i++) {
		if (A2[i] >= pivot) F[i-start] = 1; else F[i-start] = 0;
	}
	scan(F, B, e1, e2, end-start);
	
	cilk_for (int i = start; i < end; i++) {
		if (F[i-start]) A[x+B[i-start]] = A2[i];
	}	
	
	cilk_spawn
	qsort(A, start, x);
	qsort(A, x+1, end);
	cilk_sync;
	
	return;
}