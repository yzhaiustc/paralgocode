using namespace std;

void scan(int* In, int* Out, int* B, int* C, int n) {
	cout << "n = " << n << endl;
	if (n==0) return;
	if (n==1) {
		Out[0] = In[0];
		return;
	}
	cout << "In:" << endl;
	for (int i = 0; i < n; i++) cout << In[i] << " ";
	cout << endl;
	
	cilk_for (int i = 0; i < n/2; i++) B[i] = In[2*i] + In[2*i+1];
	cout << "B:" << endl;
	for (int i = 0; i < n/2; i++) cout << B[i] << " ";
	cout << endl;
	
	scan(B, C, B+n/2, C+n/2, n/2);
	cout << "C:" << endl;
	for (int i = 0; i < n/2; i++) cout << C[i] << " ";
	cout << endl;
	
	Out[0] = In[0];
	cout << "In:" << endl;
	for (int i = 0; i < n; i++) cout << In[i] << " ";
	cout << endl;
	
	cilk_for (int i = 1; i < n; i++) {
		cout << i << " " << C[(i-1)/2] << " " << In[i] << endl;
		if (i%2) Out[i] = C[(i-1)/2] + In[i];
		else Out[i] = C[i/2];
	}
	cout << "Out:" << endl;
	for (int i = 0; i < n; i++) cout << Out[i] << " ";
	cout << endl;
}