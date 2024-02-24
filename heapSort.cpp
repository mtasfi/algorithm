#include<iostream>
#define left(x) 2*x+1
#define right(x) 2*x+2
#define parent(x) x/2
using namespace std;

void heapify(int a[], int n, int idx) {
	if (idx >= n)return;
	int mn = idx;
	if (left(idx)<n and a[left(idx)]>a[mn])mn = left(idx);
	if (right(idx)<n and a[right(idx)]>a[mn])mn = right(idx);

	if (mn != idx) {
		swap(a[mn], a[idx]);
		heapify(a, n, mn);
	}
}

void heapSort(int a[], int n) {
	for (int i = n / 2; i >= 0; i--)heapify(a, n, i);
	int m = n;
	for (int i = n - 1; i >= 0; i--) {
		swap(a[i], a[0]);
		m--;
		heapify(a, m, 0);
	}
}

int main() {
	int n = 6;
	int a[n] = {10, 1, 100, -15, 2, 34};

	heapSort(a, n);

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}

	return 0;
}
