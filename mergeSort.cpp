#include<iostream>
using namespace std;

void merge(int a[], int l, int mid, int r) {
	int x[mid - l + 1 + 10], y[r - mid + 10];
	for (int i = l; i <= mid; i++)x[i - l] = a[i];
	for (int i = mid + 1; i <= r; i++)y[i - mid - 1] = a[i];

	x[mid - l + 1] = INT_MAX, y[r - mid] = INT_MAX;

	int posx = 0, posy = 0;
	for (int i = l; i <= r; ++i)
	{
		if (x[posx] < y[posy]) {
			a[i] = x[posx];
			posx++;
		} else {
			a[i] = y[posy];
			posy++;
		}
	}
}

void mergeSort(int a[], int l, int r) {
	if (l == r)return;
	if (r < l)return;

	int mid = (l + r) / 2;
	mergeSort(a, l, mid);
	mergeSort(a, mid + 1, r);
	merge(a, l, mid, r);
}

int main() {
	int n = 6;
	int a[n] = {10, 1, 1, 15, 0, 34};

	mergeSort(a, 0, n - 1);

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}

	return 0;
}
