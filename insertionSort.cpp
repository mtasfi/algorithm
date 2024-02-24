#include<iostream>
using namespace std;

int main() {
	int n = 6;
	int a[n] = {10, 1, 100, 1, 2, 34};

	for (int i = 0; i < n; ++i)
	{
		int x = a[i];
		int j = i;
		for (j = i - 1; j >= 0; j--) {
			if (a[j] <= x)break;
			a[j + 1] = a[j];
		}
		a[j + 1] = x;
	}
	for (int i = 0; i < n; ++i)
	{
		cout << a[i] << " ";
	}

	return 0;
}
