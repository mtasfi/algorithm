#include<iostream>
using namespace std;

int main() {
	int n = 6;
	int a[n] = {10, 1, 1, 15, 2, 34};

	for (int i = n - 1; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			if (a[j] > a[j + 1])swap(a[j], a[j + 1]);
		}
	}
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}

	return 0;
}
