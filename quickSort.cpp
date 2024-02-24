#include<iostream>
using namespace std;

int partition(int a[], int low, int high) {
	int x = low;
	int pivot = high;
	for (int i = low; i < high; i++) {
		if (a[i] < a[pivot]) {
			swap(a[i], a[x]);
			x++;
		}
	}
	swap(a[x], a[pivot]);
	return x;
}

void quicksort(int a[], int low, int high) {
	if (low > high)return;
	int idx = partition(a, low, high);
	quicksort(a, low, idx - 1);
	quicksort(a, idx + 1, high);
}

int main() {
	int n = 6;
	int a[n] = {1, 20, 3, 40, 5, 0};
	quicksort(a, 0, n - 1);

	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}
	return 0;
}

