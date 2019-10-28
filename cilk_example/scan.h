void scan(int* In, int* Out, int* extra1, int* extra 2, int n) {
	if (n==1) Out[0] = In[0];
	cilk_for (int i = 0; i < n/2; i++) B[i] = In[2*i] + In[2*i+1];
	scan(B, C, B+n/2, C+n/2, n/2);
	Out[0] = In[0];
	cilk_for (int i = 0; i < n; i++) {
		if (i%2) Out[i] = C[(i-1)/2] + In[i];
		else Out[i] = C[i/2];
	}
}