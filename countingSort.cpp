#include<iostream>
using namespace std;

void countingSort(int a[], int n) {
	int mx = a[0];

	for (int i = 0; i < n; ++i)
		mx = max(mx, a[i]);

	int b[mx + 1];

	for (int i = 0; i < mx + 1; ++i)b[i] = 0;
	for (int i = 0; i < n; ++i)b[a[i]]++;
	for (int i = 1; i < mx + 1; ++i)b[i] += b[i - 1];

	int c[n];

	for (int i = n - 1; i >= 0; i--) {
		c[b[a[i]] - 1] = a[i];
		b[a[i]]--;
	}

	for (int i = 0; i < n; ++i)a[i] = c[i];
}

int main() {
	int n = 6;
	int a[n] = {4, 1, 5, 1, 6, 4};
	countingSort(a, n);

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	return 0;
}

